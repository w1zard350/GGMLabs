/**
 * AGF - Advanced Graphic Framework
 * Copyright (C) 2010 Yuriy Buchchenko,
 * Copyright (C) 2010 Andrew Krasnogolovets
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details in LICENSE.txt.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AGF/items/agfgrid.h"
#include "AGF/transformations/agfaffine.h"
#include "shape.h"
#include <QBasicTimer>

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->graphicsView->setAffineEnabled(true);
    ui->graphicsView->getAffine()->setMg(10);
    ui->graphicsView->setCenterX(-300);
    ui->graphicsView->setCenterY(-300);

    // таймер
    timer = new QBasicTimer();

    // конфигурируем сетку
    grid = new AGFGrid();
    grid->setCellSize(1);
    grid->setQuarterVisible(2, false);
    grid->setQuarterVisible(3, false);
    grid->setQuarterVisible(4, false);
    grid->setCellNumX(50);
    grid->setCellNumY(60);
    ui->graphicsView->addItem(grid);

    shape = new Shape();
    ui->graphicsView->addItem(shape);

    setSpeed(ui->speed->value());

    // анимация
    connect(ui->play, SIGNAL(clicked()), this, SLOT(play()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->reset, SIGNAL(clicked()), this, SLOT(reset()));

    // скорость
    connect(ui->speed, SIGNAL(valueChanged(int)), this, SLOT(setSpeed(int)));

    // характеристические многоугольники
    connect(ui->characteristics, SIGNAL(clicked(bool)), this, SLOT(setCharacteristics(bool)));

}

void MainWindow::setCharacteristics(bool value) {
    shape->setCharPolygon(value);
    ui->graphicsView->scene()->update();
}

void MainWindow::timerEvent(QTimerEvent* event) {
    Q_UNUSED(event);
    if(shape->getT() < 1) shape->transform();
    else timer->stop();
}

void MainWindow::play() {
    timer->start(speed, this);
}

void MainWindow::stop() {
    timer->stop();
}

void MainWindow::reset() {
    shape->setUp();
    ui->graphicsView->scene()->update();
}

void MainWindow::setSpeed(int value) {
    speed = value;
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    shape->setUp();
    QMainWindow::resizeEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
    delete grid;
    delete shape;
}
