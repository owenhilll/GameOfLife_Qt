#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QColor>
#include <QtWidgets>

#include "Cell.h"

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}


void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        emit CellSelected(this);
        if(this->alive_ == false){
            this->alive_ = true;
            this->color_ = QColor(255, 255, 255);
        } else {
            this->alive_ = false;
            this->color_ = QColor(255, 16, 240);
        }
    }
    update();
}

// define the actual shape of the object
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(this->x_, this->y_, 20, 20));
    return path;
}
