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
#include <QGraphicsScene>
#include "shape.h"
#include <math.h>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "AGF/agfgraphicsview.h"
Shape::Shape(AGFGraphicsItem* parent): AGFGraphicsItem(parent) {
    setPen(QPen(Qt::red, 2));
    lastPointNumber = -1;
    setFlag(ItemIsMovable, false);
}

void Shape::setUp() {
//    pointsBezier << QPointF(0,0) << QPointF(1,-5) << QPointF(2,2) << QPointF(3,3) << QPointF(4,4) << QPointF(5,0);
    pointsBezier.clear();
    pointsBezier << tc(0,0) << tc(1,-5) << tc(2,2) << tc(3,3) << tc(4,4) << tc(5,0);
}

void Shape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    qreal x0=0, x1=0, x2=0, x3=0, x4=0, x5=0;
    qreal y0=0, y1=0, y2=0, y3=0, y4=0, y5=0;

    QPointF point;
    QPainterPath path;
    QPainterPath path1;

    qreal x = 0, y = 0, t = 0;
//    path.moveTo(tc(pointsBezier[0].x(), pointsBezier[0].y()));
//    path1.moveTo(tc(pointsBezier[0].x(), pointsBezier[0].y()));

    path.moveTo(pointsBezier[0].x(), pointsBezier[0].y());
    path1.moveTo(pointsBezier[0].x(), pointsBezier[0].y());

    for(int i = 0; i < pointsBezier.size(); i++) {
//        point = tc(pointsBezier[i].x(), pointsBezier[i].y());
        point = pointsBezier[i];
        painter->drawEllipse(point, 5, 5);
        path1.lineTo(point);
    }

    for(int i = 0; i < pointsBezier.size()-2; i+=5) {

        for(t = 0.01; t < 1; t+=0.01) {
            x0 = pointsBezier[i].x();
            x1 = pointsBezier[i+1].x();
            x2 = pointsBezier[i+2].x();
            x3 = pointsBezier[i+3].x();
            x4 = pointsBezier[i+4].x();
            x5 = pointsBezier[i+5].x();

            y0 = pointsBezier[i].y();
            y1 = pointsBezier[i+1].y();
            y2 = pointsBezier[i+2].y();
            y3 = pointsBezier[i+3].y();
            y4 = pointsBezier[i+4].y();
            y5 = pointsBezier[i+5].y();

            x = pow(1-t,5)*x0 + 5*t*pow(1-t,4)*x1 + 10*t*t*pow(1-t,3)*x2 + 10*t*t*t*pow(1-t,2)*x3 + 5*pow(t,4)*(1-t)*x4 + pow(t,5)*x5;
            y = pow(1-t,5)*y0 + 5*t*pow(1-t,4)*y1 + 10*t*t*pow(1-t,3)*y2 + 10*t*t*t*pow(1-t,2)*y3 + 5*pow(t,4)*(1-t)*y4 + pow(t,5)*y5;
            path.lineTo(x,y);
//            path.lineTo(tc(x,y));
        }
    }

    painter->setPen(pen);
    painter->drawPath(path);
    painter->setPen(QPen(Qt::green, 1));
    painter->drawPath(path1);
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF point;
    QGraphicsEllipseItem ellipse;
    for(int i = 0; i < pointsBezier.size(); i++) {
        point = pointsBezier[i];
        ellipse.setRect(point.x()-5, point.y()-5, 10, 10);
        if(ellipse.contains(event->pos())) {
            lastPos = event->pos();
            lastPointNumber = i;
            break;
        }
    }

    update();
//    QGraphicsItem::mousePressEvent(event);
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if(lastPointNumber != -1)
        pointsBezier.replace(lastPointNumber, event->pos());
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    lastPointNumber = -1;
//       QGraphicsItem::mouseReleaseEvent( event );

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QRectF Shape::boundingRect() const {
    return scene()->sceneRect();
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void Shape::setPen(QPen value) {
    pen = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
QPen Shape::getPen() const {
    return pen;
}
