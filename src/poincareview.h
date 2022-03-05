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
#ifndef POINCAREVIEW_H
#define POINCAREVIEW_H

#include <qcanvas.h>
#include <qtimer.h>
#include "canvaselements.h"
#include "qdocviewer.h"
#include "transformation.h"
#include "element.h"
#include "diagram.h"
#include "diagramview.h"
class Pattern;

/**
Poincare disk view of the diagram.
All the drawing is done using a QCanvas.
@author Ajit Datar
*/
class PoincareView : public QCanvasView, public DiagramView
{
Q_OBJECT
public: //static methods
    //static set methods
    static int setDefaultCanvasHeight(int h);
    static int setDefaultCanvasWidth(int w);
    
    //static get methods
    static int canvasWidth() { return PoincareView::canvasWidth_; }
    static int canvasHeight() { return PoincareView::canvasHeight_; }
    static int diameter() { return diameter_; } //poincare disk Diamater
    static QPoint origin() { return origin_; }
private: //static methods
    static int calcDiameter();
private: //static data
    static int canvasWidth_;
    static int canvasHeight_;
    static int diameter_;
    static QPoint origin_; 
public:
    PoincareView(QWidget* parent=0, const char* name=0, WFlags f=0);

    ~PoincareView();
    void print(QPainter& p);
    void saveAs(QString fileName);
    //set methods
private: //methods
    void init();
    /**
    draws the poincare disk. 
    TODO Right now the background color is set to an arbitrary
    shade. Maybe this color should be specified in the input XML file.
    */
    void drawBoundingCircle(bool visible=true, bool init = false);
    void drawFrame(bool visible=true, bool init=false);
    void restoreDiagramState();
    /**
    draws the whole diagram showing all generated layers
    */
    void drawDiagram(bool visible=true, bool init = false);
    /**
    draw only the given layer
    */
    void drawLayer(const int layerId, bool visible=true, bool init = false);
    /**
    Draws a pattern using the drawing framework.
    A pattern contains Elements. Elements are mapped to
    appropriate screen objects.
    calls drawElement for each element in the pattern.
    */
    void drawPattern(const Pattern& pat, bool visible=true, bool init = false);
    void drawPatternFrame(const Pattern& pat, bool visible=true, bool init = false);
    /**
    All the points in the Element that is passed should be already transformed
    to their intended coords in the weierstrass/poincare model (this is the job of other
    funtions in the Diagram class). drawPattern will map it to the canvas coordinates and draw the elements.
    */
    void drawElement(const ElementPtr e, bool visible=true, bool init = false);
private slots:
    void onDocumentChange();
    void zoom(ZoomType type);
    void toggleLayer(int layer, bool state);
    void toggleFrame(bool state);
    void animPlay();
    void animPause();
    void animStop();
    void animNext();
    void animPrev();
    void animateTimerDone();
    void pan(PanType ptype);
private: //utility functions not part of the general view interface
    /**
    Make a QPoint (screen point) from a Point
    Utility function. Used as a point on the QCanvas.
    */
    QPoint makeQPoint(const Point& mp);
    CanvasHyperLine* makeCanvasHyperLine(const HyperLine& mhl);
private: //data
    QCanvas* canvas_;
    QCanvasEllipse* disk; //the poincare disk
    ViewMode viewMode_;
    QWMatrix defaultView;
    bool showFrame_;
    
    QMap<int, bool> isLayerVisible;

    typedef QMap<UId, QCanvasItem*> ItemStore;
    typedef QMap<UId, QCanvasItem*>::Iterator ItemStoreIter;
    ItemStore items_;

    QTimer *animateTimer;
    int animateNext_;
    bool paused_;
    int animDelay_; //(in msec)
};

#endif
