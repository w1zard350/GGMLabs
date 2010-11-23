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
    setPenCharPolygon(QPen(Qt::green, 1));
    lastPointNumber = -1;
    setFlag(ItemIsMovable, false);
    setT(0);
    setCharPolygon(false);
}

void Shape::setUp() {

    setT(0);
    shape1Points.clear();
    shape2Points.clear();

    shape1Points << tc(7,21) << tc(6,18) << tc(5,19) << tc(4,15) << tc(3.5,17.5) << tc(4, 20.5)
                 << tc(3,23) << tc(7,23) << tc(4,28) << tc(7,28) << tc(13,31)
                 << tc(12,32) << tc(12,34) << tc(13,36) << tc(14,38) << tc(12,40)
                 << tc(10,36) << tc(10.5,37.5) << tc(10.5,35.5) << tc(11.5,35) << tc(11.5, 34)
                 << tc(11,31) << tc(9.5,32) << tc(5,33) << tc(9.5,27.5) << tc(4.5,40)
                 << tc(2,37) << tc(1,38) << tc(4,42) << tc(1,42) << tc(1,45)
                 << tc(3.5,43.5) << tc(4,43.5) << tc(5,43.5) << tc(5,46) << tc(6.5,47.5)
                 << tc(7,43) << tc(7.5,42.5) << tc(8,45) << tc(8,49) << tc(10.5,50)
                 << tc(9,47) << tc(10,47) << tc(12,47) << tc(13,52) << tc(16,50.5)
                 << tc(13,48.5) << tc(13,48) << tc(14.5,47.5) << tc(18,50.5) << tc(20,49)
                 << tc(17.5,48.5) << tc(17.5,48) << tc(18.5,47.5) << tc(21,48.5) << tc(22,47.5)
                 << tc(19,47) << tc(19,46) << tc(20.5,46) << tc(23,46) << tc(24,45)
                 << tc(20,45) << tc(21,43) << tc(26,40) << tc(34,42) << tc(39,41.5)
                 << tc(43,40) << tc(55,44) << tc(33,45) << tc(35,56) << tc(44.5,54.5)
                 << tc(42,53.5) << tc(42,53) << tc(44,53) << tc(45,53) << tc(45.5,52)
                 << tc(42,52) << tc(42,50) << tc(45,50) << tc(48,51) << tc(48,48.5)
                 << tc(45,48.5) << tc(45,47.5) << tc(48.5,47.5) << tc(48.5,46) << tc(48.5,45)
                 << tc(46,45) << tc(46,44) << tc(50,43) << tc(45,43) << tc(44.5,39)
                 << tc(47,35) << tc(46,32) << tc(44,30) << tc(43,27) << tc(46,21.5)
                 << tc(41,15) << tc(45.5,15) << tc(42,14) << tc(41.5,14) << tc(42,13)
                 << tc(43,11.5) << tc(43,11) << tc(43.5,11.5) << tc(38.5,9.5) << tc(38,10)
                 << tc(38,11) << tc(41.5,17) << tc(41.5,19) << tc(40.5,22.5) << tc(39,23)
                 << tc(37.5,22) << tc(38.5,19) << tc(39,20) << tc(34.5,16) << tc(34.5,14)
                 << tc(32,15) << tc(31,14) << tc(34,10) << tc(31,11.5) << tc(28,13)
                 << tc(36,20) << tc(35.5,25.5) << tc(35,26) << tc(33,26) << tc(33,29)
                 << tc(19,26) << tc(20,29) << tc(25,31) << tc(17,25.5) << tc(13.5,25.5)
                 << tc(16.5,19) << tc(14,24) << tc(17,24.5) << tc(17,23.5) << tc(19,22)
                 << tc(16,20) << tc(13,20) << tc(12,20) << tc(11,21) << tc(9.5,25.5)
                 << tc(8,24) << tc(8,22) << tc(5.5,22) << tc(5,22) << tc(7,21);

    shape2Points << tc(0,24) << tc(2.5,22) << tc(5,21) << tc(4,23) << tc(8,20) << tc(5, 22)
                 << tc(7,22.5) << tc(9,23.25) << tc(10.5,24) << tc(11.5,24.5) << tc(12.5,25)
                 << tc(13,25.25) << tc(14,25.75) << tc(15,26.2) << tc(16,26.6) << tc(17,27)
                 << tc(18,27.5) << tc(19,27.85) << tc(20,28.25) << tc(21,28.5) << tc(22, 28.85)
                 << tc(23,29.15) << tc(24,29.35) << tc(25,29.5) << tc(26,29.6) << tc(27,29.7)
                 << tc(27.75,29.8) << tc(28.5,29.8) << tc(29.25,29.7) << tc(30,29.6) << tc(31,29.5)
                 << tc(31.8,29.3) << tc(32.6,29.1) << tc(33.4,29) << tc(34.2,28.85) << tc(35,28.75)
                 << tc(34.5,29) << tc(34,30) << tc(33.5,31) << tc(33,32) << tc(32.4,35)
                 << tc(32.25,36) << tc(32.15,36.8) << tc(32.1,37.6) << tc(32,38.2) << tc(32,39)
                 << tc(32.10,40) << tc(32.20,41) << tc(32.45,42) << tc(32.75,43) << tc(33,44)
                 << tc(34,46) << tc(36.5,46) << tc(38.5,45.5) << tc(39.5,44.5) << tc(40,43.5)
                 << tc(41.05,44) << tc(41.55,43.75) << tc(41.55,43.25) << tc(41.15,42.5) << tc(41,42)
                 << tc(44,40.5) << tc(44.5,40) << tc(45,39.75) << tc(45,39) << tc(44,39)
                 << tc(43.5,39) << tc(42,40) << tc(40.5,40.5) << tc(39,41) << tc(36.5,39.5)
                 << tc(35,37) << tc(35.5,34) << tc(36.5,32) << tc(38,31) << tc(39.5,30)
                 << tc(41,29) << tc(42.5,28) << tc(43,27.5) << tc(44,26.5) << tc(45,25.5)
                 << tc(46.5,24) << tc(47.5,22.5) << tc(48,21.5) << tc(48,20) << tc(48,19)
                 << tc(47.5,17.5) << tc(47.2,16.2) << tc(46,15.5) << tc(45.5,15.5) << tc(44.5,15.5)
                 << tc(44,14) << tc(43.5,15) << tc(43.5,13.5) << tc(42,14) << tc(42.5,14.5)
                 << tc(41.5,12) << tc(40.5,12.5) << tc(40,12) << tc(39.5,12.5) << tc(39,13)
                 << tc(37,11.5) << tc(35.5,10.5) << tc(34.5,10.5) << tc(33,10.5) << tc(32,12)
                 << tc(30,10.5) << tc(29.5,10.5) << tc(28,10.5) << tc(27,10) << tc(26,11)
                 << tc(26,10) << tc(25,10) << tc(24,10) << tc(23,10) << tc(23,11)
                 << tc(22,10) << tc(20.5,10) << tc(19.5,10) << tc(18,10) << tc(17.5,11.5)
                 << tc(17,10) << tc(15.5,10.5) << tc(14,10.5) << tc(13,11) << tc(12,12.5)
                 << tc(11.5,12) << tc(11,12) << tc(10,12) << tc(9,12) << tc(8,13)
                 << tc(5,13) << tc(7,15) << tc(5,15) << tc(2,16) << tc(3,17.5)
                 << tc(1.5,18) << tc(1,18.5) << tc(0.5,19) << tc(0.5,20) << tc(1,21)
                 << tc(0,22) << tc(0,22.5) << tc(0,23) << tc(0,23.5) << tc(0,24);
}

void Shape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    qreal x0=0, x1=0, x2=0, x3=0, x4=0, x5=0;
    qreal y0=0, y1=0, y2=0, y3=0, y4=0, y5=0;
    QPainterPath path;
    qreal x = 0, y = 0, t = 0;

    drawCharPolygon(painter);

    path.moveTo(shape1Points[0].x(), shape1Points[0].y());
    for(int i = 0; i < shape1Points.size()-5; i+=5) {
//        qDebug() << "i = " << i ;
        for(t = 0.01; t < 1; t+=0.001) {
            x0 = shape1Points[i].x();
            x1 = shape1Points[i+1].x();
            x2 = shape1Points[i+2].x();
            x3 = shape1Points[i+3].x();
            x4 = shape1Points[i+4].x();
            x5 = shape1Points[i+5].x();

            y0 = shape1Points[i].y();
            y1 = shape1Points[i+1].y();
            y2 = shape1Points[i+2].y();
            y3 = shape1Points[i+3].y();
            y4 = shape1Points[i+4].y();
            y5 = shape1Points[i+5].y();

            x = pow(1-t,5)*x0 + 5*t*pow(1-t,4)*x1 + 10*t*t*pow(1-t,3)*x2 + 10*t*t*t*pow(1-t,2)*x3 + 5*pow(t,4)*(1-t)*x4 + pow(t,5)*x5;
            y = pow(1-t,5)*y0 + 5*t*pow(1-t,4)*y1 + 10*t*t*pow(1-t,3)*y2 + 10*t*t*t*pow(1-t,2)*y3 + 5*pow(t,4)*(1-t)*y4 + pow(t,5)*y5;
            path.lineTo(x,y);
        }
    }

    painter->setPen(pen);
    painter->drawPath(path);
}

void Shape::drawCharPolygon(QPainter* painter) {

    if(characteristicPolygon) {
        QPainterPath path;
        QPointF point;
        path.moveTo(shape1Points[0].x(), shape1Points[0].y());

        for(int i = 0; i < shape1Points.size(); i++) {
            point = shape1Points[i];
            painter->drawEllipse(point, 5, 5);
            path.lineTo(point);
        }
        painter->setPen(penCharPolygon);
        painter->drawPath(path);
    }
}

qreal Shape::d(qreal x1, qreal y1, qreal x2, qreal y2) {
    return sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
}

void Shape::smooth() {
    QPointF point;
    int i = lastPointNumber;
    if(i >= 0) {
        qreal x0 = 0, y0 = 0, x1 = 0, y1 = 0, x4 = 0, y4 = 0, x5 = 0, y5 = 0, x = 0, y = 0, alpha1 = 0, alpha2 = 0;

        x5 = shape1Points[i].x();
        y5 = shape1Points[i].y();

        x0 = x5;
        y0 = y5;

        x4 = shape1Points[i-1].x();
        y4 = shape1Points[i-1].y();

        x1 = shape1Points[i+1].x();
        y1 = shape1Points[i+1].y();

        alpha1 = d(x4, y4, x5, y5);
        alpha2 = d(x0, y0, x1, y1);

        x = (alpha2/alpha1)*(x5 - x4) + x0;
        y = (alpha2/alpha1)*(y5 - y4) + y0;

        point.setX(x);
        point.setY(y);

        shape1Points.replace(i+1, point);
        lastPointNumber = -1;
    }

    update();
}

void Shape::transform() {
    t+=0.1;
//    qDebug() << t;
    QPointF point;
    qreal x1 = 0, x2 = 0, y1 = 0, y2 = 0, x = 0, y = 0;
    for(int i = 0; i < shape1Points.size(); i++) {

        x1 = shape1Points[i].x();
        x2 = shape2Points[i].x();

        y1 = shape1Points[i].y();
        y2 = shape2Points[i].y();

        x = (1-t)*x1 + t*x2;
        y = (1-t)*y1 + t*y2;

        point.setX(x);
        point.setY(y);
        shape1Points.replace(i, point);
    }

    update();
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF point;
    QGraphicsEllipseItem ellipse;
    for(int i = 0; i < shape1Points.size(); i++) {
        point = shape1Points[i];
        ellipse.setRect(point.x()-5, point.y()-5, 10, 10);
        if(ellipse.contains(event->pos())) {
            lastPointNumber = i;
            break;
        }
    }

    if(event->buttons() & (Qt::MidButton | Qt::RightButton)) smooth();

    update();
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if(lastPointNumber != -1)
        shape1Points.replace(lastPointNumber, event->pos());
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    lastPointNumber = -1;
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
void Shape::setT(qreal value) {
    t = value;
}
void Shape::setCharPolygon(bool value) {
    characteristicPolygon = value;
}
void Shape::setPenCharPolygon(QPen value) {
    penCharPolygon = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
QPen Shape::getPen() const {
    return pen;
}
qreal Shape::getT() const {
    return t;
}
bool Shape::getCharPolygon() const {
    return characteristicPolygon;
}
QPen Shape::getPenCharPolygon() const {
    return penCharPolygon;
}
