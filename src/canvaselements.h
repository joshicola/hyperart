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

#ifndef CANVASELEMENTS_H
#define CANVASELEMENTS_H

#include <q3canvas.h>
#include <qpainter.h>
#include <qpoint.h>
#include <qsize.h>
//Added by qt3to4:
#include <Q3PointArray>
#include "defs.h"

/**
Declares various canvas elements used by PoincareView.
These are essentially mappings from corresponding Element to its
screen representation on a QCanvas
*/

/**
A CanvasPolyLine is a Euclid polyline.
Derived from QCanvasPolygon.
Use setPoints to set polyline points. setPen to set the pen.
Brush is not used.
*/
class CanvasPolyLine : public Q3CanvasPolygon
{
public:
    CanvasPolyLine(Q3Canvas* canvas);
    virtual int rtti() const { return EUCLID_POLYLINE; }
protected:
    virtual void drawShape(QPainter &painter);
};

//===========================================================================

class CanvasPoly : public Q3CanvasPolygon
{
public:
    CanvasPoly(Q3Canvas* canvas, bool fill=true);
    virtual int rtti() const { return EUCLID_POLY; }
    virtual bool isFilled() { return filled_; }
    virtual void setFilled(bool f) { filled_ = f; }
protected:
    virtual void drawShape(QPainter &painter);
    bool filled_;
};

//===========================================================================

class CanvasEllipse : public Q3CanvasEllipse
{
public:
    CanvasEllipse(Q3Canvas* canvas, bool fill=true) : Q3CanvasEllipse(canvas), filled_(fill) { }
    CanvasEllipse( int width, int height, Q3Canvas * canvas ) : Q3CanvasEllipse(width,height,canvas), filled_(true) { }
    virtual int rtti() const { return CIRCLE; }
    virtual bool isFilled() { return filled_; }
    virtual void setFilled(bool f) { filled_ = f; }
protected:
    virtual void drawShape(QPainter &painter);
    bool filled_;
};
//===========================================================================

/**
A Hyperbolic Line. 
Makes sense only on a poincare or other hyperbolic models.
*/
class CanvasHyperLine //: public QCanvasPolygonalItem
{
public:
    //friend class CanvasHyperPolyLine;
    CanvasHyperLine();
    void setParameters(const QPoint& topleft, const QSize& size, int startAngle, int alen);
    void setParamters(const QPoint& a, const QPoint& b);
    //virtual QPointArray areaPoints() const;
    /**
    Doesn't make sense to use this without calling one of the setparamters() method first
    */
    virtual QRect boundingRect() const { return boundingRect_; }
    bool isApproximated() { return approximate_; }
    //make sense if isApproximated()
    QPoint a() { return a_; }
    QPoint b() { return b_; }
    //make sense if not isApproximated()
    QPoint topLeft() { return rect_.topLeft(); }
    QSize size() { return rect_.size(); }
    int startAngle() { return angle1_; }
    int lenAngle() { return angle2_; }
    virtual void draw(QPainter& painter) { drawShape(painter); }
protected:
    virtual void drawShape(QPainter &painter);
    QRect rect_; //the ellipse for drawing this arc
    int angle1_, angle2_;
    QPoint a_,b_; //if approximated using a straight line
    bool approximate_;
    QRect boundingRect_;
};

//===========================================================================

/**
It is like a Euclid Polyline but individual lines are
hyperbolic lines in the poincare disk.
*/
class CanvasHyperPolyLine : public Q3CanvasPolygonalItem
{
public:
    CanvasHyperPolyLine(Q3Canvas* canvas);
    virtual ~CanvasHyperPolyLine();
    void addLine(CanvasHyperLine* line);
    virtual int rtti() const { return HYPER_POLYLINE; }
    virtual Q3PointArray areaPoints() const;
    /**
    Doesn't make sense to use this without calling setLines() method first
    */
    virtual QRect boundingRect() const { return boundingRect_; }
protected:
    virtual void drawShape(QPainter &painter);
    vector<CanvasHyperLine*> lines_;
    QRect boundingRect_;
};

//===========================================================================

/**
It is like a Euclid Poly but polygon edges are
hyperbolic lines in the poincare disk
*/
class CanvasHyperPoly : public CanvasHyperPolyLine
{
public:
    CanvasHyperPoly(Q3Canvas* canvas, bool fill=true) : CanvasHyperPolyLine(canvas), filled_(fill) { }
    virtual ~CanvasHyperPoly() { }
    virtual int rtti() const { return HYPER_POLY; }
    bool isFilled() { return filled_; }
    void addLine(CanvasHyperLine* line);
    void setFilled(bool f) { filled_ = f; }
protected:
    virtual void drawShape(QPainter &painter);
    Q3PointArray points_;
    bool filled_;
};
//===========================================================================

#endif
