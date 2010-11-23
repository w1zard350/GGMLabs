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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QBasicTimer;
namespace Ui {
    class MainWindow;
}
class AGFGrid;
class Shape;
/**
 * Класс главного окна приложения, в котором содержиться виджет рисования
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @var Объект сетки (грида)
     */
    AGFGrid* grid;

    /**
     * @var Объект фигуры по варианту
     */
    Shape* shape;

    /**
     * @var Таймер для анимации
     */
    QBasicTimer* timer;

    /**
     * @var Скорость анимации (обновление таймера)
     */
    int speed;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @var События
     */
    void resizeEvent(QResizeEvent* event);
    void timerEvent(QTimerEvent *event);

private slots:
    void play();
    void stop();
    void reset();
    void setSpeed(int value);
    void setCharacteristics(bool value);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
