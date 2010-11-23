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
#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include "AGF/agfgraphicsitem.h"

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE


/**
 * Геометрическая фигура, любая.
 */
class Shape: public AGFGraphicsItem
{

protected:
    /**
     * @var Перо для фигуры
     */
    QPen pen;

    /**
     * @var Перо для характеристических многоугольников
     */
    QPen penCharPolygon;

    /**
     * @var Списки точек для первой и второй фигуры
     */
    QList<QPointF> shape1Points;
    QList<QPointF> shape2Points;

    /**
     * @var Последний индекс точки, которая была активирована перемещением
     */
    int lastPointNumber;

    /**
     * @var Время перехода одной фигуры в другую
     */
    qreal t;

    /**
     * @var Состояние включенности характеристического многоугольника
     */
    bool characteristicPolygon;

public:
    Shape(AGFGraphicsItem* parent = 0);

    //--------------------------------------------------------------------------------//
    /**
     * Событие полной перерисовки объекта
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Определяет прямоугольник, в котором производиться рисование
     */
    QRectF boundingRect() const;

    /**
     * События
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    /**
     * Пересчет всех точек фигур
     */
    void setUp();

    /**
     * Переход одной фигуры в другую на единицу времени
     */
    void transform();

    /**
     * Прорисовка характиристических многоугольников
     */
    void drawCharPolygon(QPainter* painter);

    /**
     * Сглаживает выбранную точку
     */
    void smooth();

    /**
     * Находит расстояние между двумя точками
     * @param x1, y1 координаты первой точки
     * @param x2, y2 координаты второй точки
     */
    qreal d(qreal x1, qreal y1, qreal x2, qreal y2);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setPen(QPen value);
    void setT(qreal value);
    void setCharPolygon(bool value);
    void setPenCharPolygon(QPen value);

    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    QPen getPen() const;
    qreal getT() const;
    bool getCharPolygon() const;
    QPen getPenCharPolygon() const;
};

#endif // SHAPE_H
