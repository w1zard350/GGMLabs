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
    QList<QPointF> pointsBezier;
    QPointF lastPos;
    int lastPointNumber;
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

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void setUp();
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setPen(QPen value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    QPen getPen() const;
};

#endif // SHAPE_H
