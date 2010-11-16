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

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->graphicsView->setAffineEnabled(true);
    ui->graphicsView->getAffine()->setMx(20);
    ui->graphicsView->getAffine()->setMy(20);

    // конфигурируем сетку
    grid = new AGFGrid();
    grid->setCellSize(1);
    ui->graphicsView->addItem(grid);

    shape = new Shape();
    ui->graphicsView->addItem(shape);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    shape->setUp();
    QMainWindow::resizeEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
    delete grid;
}
