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

#include <iostream>
#include <cmath>
using namespace std;

CanvasPolyLine::CanvasPolyLine(QCanvas *canvas)
    : QCanvasPolygon(canvas)
{
}

void CanvasPolyLine::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(Qt::NoBrush);
    painter.drawPolyline(poly);
}

//============================================================================
CanvasPoly::CanvasPoly(QCanvas *canvas, bool fill)
    : QCanvasPolygon(canvas), filled_(fill)
{
}

void CanvasPoly::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(brush());
    if (filled_)
        painter.drawPolygon(poly);
    else
    {
        painter.drawPolyline(poly);
        painter.drawLine(poly.point(poly.size() - 1), poly.point(0));
    }
}

//============================================================================

void CanvasEllipse::drawShape(QPainter &painter)
{
    painter.setPen(pen());
    painter.setBrush(brush());
    if (filled_)
        painter.drawEllipse(x(), y(), width(), height());
    else
        painter.drawArc(x(), y(), width(), height(), 0, 360 * 16);
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

    // find out the bounding rectangle using the points in the arc
    QPolygon points;
    points.makeArc(topleft.x(), topleft.y(), size.width(), size.height(), angle1_ * 16, angle2_ * 16);
    boundingRect_ = points.boundingRect();
}

void CanvasHyperLine::setParamters(const QPoint &a, const QPoint &b)
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
CanvasHyperPolyLine::CanvasHyperPolyLine(QCanvas *canvas)
    : QCanvasPolygonalItem(canvas)
{
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
        boundingRect_ = boundingRect_.unite(line->boundingRect());
    }
    else
    { // first time setting
        boundingRect_ = line->boundingRect();
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
    // add points of arc/straight line to approximate us with a euclid polygon
    if (l->isApproximated())
    {
        points_.putPoints(int(points_.count()), 2, l->a().x(), l->a().y(), l->b().x(), l->b().y());
    }
    else
    {
        QPainterPath pNew;
        QPoint topleft = l->topLeft();
        QSize size = l->size();
        int angle1 = l->startAngle(), angle2 = l->lenAngle();
        QPainterPath pOrig;
        pOrig.makeArc(topleft.x(), topleft.y(), size.width(), size.height(), angle1 * 16, angle2 * 16);
        unsigned int pointsInSegment = pOrig.count() / 8;
        if (pointsInSegment == 0)
            pointsInSegment = 1;
        for (unsigned int i = 0, j = 0; i < pOrig.count(); i += pOrig.count() / pointsInSegment, j++)
        {
            pNew.putPoints(j, 1, pOrig.point(i).x(), pOrig.point(i).y());
        }
        points_.putPoints(int(points_.count()), pNew.count(), pNew);
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
