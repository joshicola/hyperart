/***************************************************************************
 *   Copyright (C) 2005 by Ajit Datar, Dr. Douglas Dunham   *
 *   ajitdatar@gmail.com, ddunham@d.umn.edu   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "canvaselements.h"
#include <QPainterPath>
#include <QtWidgets/QGraphicsPolygonItem>

#include <iostream>
#include <cmath>
using namespace std;

CanvasPolyLine::CanvasPolyLine(QGraphicsScene *canvas)
    :  QGraphicsPolygonItem()
{
    canvas->addItem(this);
}

void CanvasPolyLine::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(Qt::NoBrush);
    painter.drawPolyline(polygon());
}

//============================================================================
CanvasPoly::CanvasPoly(QGraphicsScene *canvas, bool fill)
    : QGraphicsPolygonItem(), filled_(fill)
    //TODO: add to Scene
{
    canvas->addItem(this);
}

void CanvasPoly::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(brush());
    if (filled_)
        painter.drawPolygon(polygon());
    else
    {
        painter.drawPolyline(polygon());
        painter.drawLine(polygon().at(polygon().size() - 1), polygon().at(0));
    }
}

//============================================================================

void CanvasEllipse::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(brush());
    if (filled_)
        painter.drawEllipse(x(), y(), rect().width(), rect().height());
    else
        painter.drawArc(x(), y(), rect().width(), rect().height(), 0, 360 * 16);
}
//============================================================================

CanvasHyperLine::CanvasHyperLine()
    : approximate_(false)
{
}

void CanvasHyperLine::setParameters(const QPoint &topleft, const QSize &size, int startAngle, int alen)
{
    rect_.setTopLeft(topleft);
    rect_.setWidth(size.width());
    rect_.setHeight(size.height());
    angle1_ = startAngle;
    angle2_ = alen;
    approximate_ = false;

    //TODO: The parameters above are set but not used here.
    // find out the bounding rectangle using the points in the arc
    // QPolygon points;
    // points.makeArc(topleft.x(), topleft.y(), size.width(), size.height(), angle1_ * 16, angle2_ * 16);
    // boundingRect_ = points.boundingRect();
}

void CanvasHyperLine::setParameters(const QPoint &a, const QPoint &b)
{
    a_ = a;
    b_ = b;
    approximate_ = true;
    QPolygon pa(2);
    pa.setPoint(0, a_);
    pa.setPoint(1, b_);
    boundingRect_ = pa.boundingRect();
}

void CanvasHyperLine::drawShape(QPainter &painter)
{
    if (approximate_)
    {
        painter.drawLine(a_, b_);
    }
    else
    {
        painter.drawArc(rect_, angle1_ * 16, angle2_ * 16);
    }
}

//============================================================================

// TODO destructor??
CanvasHyperPolyLine::CanvasHyperPolyLine(QGraphicsScene *canvas)
: QGraphicsPolygonItem()
{
    //TODO: I may need to set the scene here with the *canvas pointer
    canvas->addItem(this);
}

CanvasHyperPolyLine::~CanvasHyperPolyLine()
{
    lines_.clear();
}

void CanvasHyperPolyLine::addLine(CanvasHyperLine *line)
{
    // line->setCanvas(canvas());
    lines_.push_back(line);
    if (lines_.size() > 1)
    {
        boundingRect_ = boundingRect_.united(line->boundingRect().toRect());
    }
    else
    { // first time setting
        boundingRect_ = line->boundingRect().toRect();
    }
}

void CanvasHyperPolyLine::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(Qt::NoBrush);
    vector<CanvasHyperLine *>::iterator iter;
    for (iter = lines_.begin(); iter != lines_.end(); ++iter)
    {
        (*iter)->draw(painter);
    }
}

QPolygon CanvasHyperPolyLine::areaPoints() const
{
    QPolygon points(4);
    points.setPoint(0, boundingRect_.topLeft());
    points.setPoint(1, boundingRect_.topRight());
    points.setPoint(2, boundingRect_.bottomRight());
    points.setPoint(3, boundingRect_.bottomLeft());
    return points;
}

//============================================================================
void CanvasHyperPoly::addLine(CanvasHyperLine *l)
{
    CanvasHyperPolyLine::addLine(l);
    // add points of arc/straight line to approximate us with a euclidian polygon
    if (l->isApproximated())
    {
        points_.putPoints(int(points_.count()), 2, l->a().x(), l->a().y(), l->b().x(), l->b().y());
    }
    else
    {
        // Convert CanvasHyperline to QPainterPath
        QPoint topleft = l->topLeft();
        QSize size = l->size();
        int angle1 = l->startAngle(), angle2 = l->lenAngle();
        QPainterPath pOrig;
        pOrig.arcTo(topleft.x(), topleft.y(), size.width(), size.height(), angle1 * 16, angle2 * 16);
        // Convert QPainterPath to QPolygon
        QPolygon poly = pOrig.toFillPolygon().toPolygon();
        points_.putPoints(int(points_.count()), poly.size(), poly);

        // unsigned int pointsInSegment = pOrig.elementCount() / 8;
        // if (pointsInSegment == 0)
        //     pointsInSegment = 1;
        // QPainterPath pNew;
        // //TODO: This is going to take some thought and work to get right.
        // pNew.addPolygon(pOrig.toSubpathPolygons().at(0));
        // for (unsigned int i = 0, j = 0; i < pOrig.elementCount(); i += pOrig.elementCount() / pointsInSegment, j++)
        // {
        //     pNew.putPoints(j, 1, pOrig.point(i).x(), pOrig.point(i).y());
        // }
        // points_.putPoints(int(points_.count()), pNew.elementCount(), pNew);
    }
}

void CanvasHyperPoly::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(brush());
    if (filled_)
        painter.drawPolygon(points_);
    else
        painter.drawPolyline(points_);
}
