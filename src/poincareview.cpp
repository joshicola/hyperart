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
#include "poincareview.h"
#include <qfileinfo.h>
#include <q3paintdevicemetrics.h>
// Added by qt3to4:
#include <QPolygon>
#include <QPixmap>
using namespace Qt;
//============================================================================
// initialize static data
int PoincareView::canvasHeight_(700);
int PoincareView::canvasWidth_(800);
int PoincareView::diameter_(PoincareView::canvasHeight() < PoincareView::canvasWidth() ? PoincareView::canvasHeight() : PoincareView::canvasWidth());
QPoint PoincareView::origin_(PoincareView::canvasWidth() / 2, PoincareView::canvasHeight() / 2);
//============================================================================
PoincareView::PoincareView(QWidget *parent, const char *name, Qt::WFlags f)
    : QCanvasView(parent, name, f), DiagramView(), viewMode_(NORMAL), showFrame_(false)
{
    QObject::connect(docViewer, SIGNAL(onDocumentChange(unsigned int, unsigned long)),
                     this, SLOT(onDocumentChange()));
    QObject::connect(docViewer, SIGNAL(onDocumentFirstChange(unsigned int, unsigned long)),
                     this, SLOT(onDocumentChange()));

    canvas_ = new QCanvas(PoincareView::canvasWidth_, PoincareView::canvasHeight_);
    this->setCanvas(canvas_);

    defaultView.scale(0.87, 0.87); // zoom out slightly to see the diagram properly
    // TODO translate so that canvas is always at the center of the window
    setWorldMatrix(defaultView);

    // connect signals from the MainWindow to our slots
    QObject::connect(parent, SIGNAL(doZoom(ZoomType)), this, SLOT(zoom(ZoomType)));
    QObject::connect(parent, SIGNAL(doToggleLayer(int, bool)), this, SLOT(toggleLayer(int, bool)));
    QObject::connect(parent, SIGNAL(doToggleFrame(bool)), this, SLOT(toggleFrame(bool)));
    QObject::connect(parent, SIGNAL(doAnimatePlay()), this, SLOT(animPlay()));
    QObject::connect(parent, SIGNAL(doAnimatePause()), this, SLOT(animPause()));
    QObject::connect(parent, SIGNAL(doAnimateStop()), this, SLOT(animStop()));
    QObject::connect(parent, SIGNAL(doAnimatePrev()), this, SLOT(animPrev()));
    QObject::connect(parent, SIGNAL(doAnimateNext()), this, SLOT(animNext()));
    QObject::connect(parent, SIGNAL(doPanning(PanType)), this, SLOT(pan(PanType)));

    animateTimer = new QTimer(this);
    connect(animateTimer, SIGNAL(timeout()), this, SLOT(animateTimerDone()));

    drawBoundingCircle(true, true);
    init();
}

PoincareView::~PoincareView()
{
    if (canvas_)
    {
        delete canvas_;
        canvas_ = 0;
    }
}

void PoincareView::print(QPainter &p)
{
    // fit to page printing -- ref: http://lists.trolltech.com/qt-interest/2004-12/thread00656-0.html
    QPaintDeviceMetrics pmetrics(p.device());
    int pageWidth = pmetrics.width();
    int pageHeight = pmetrics.height();

    // find out the bounding rectangle of all the canvas items
    // so that we can scale the design to fit the page
    QRect bounding;
    QCanvasItemList items = canvas()->allItems();
    QCanvasItemList::iterator it;
    for (it = items.begin(); it != items.end(); ++it)
    {
        bounding = bounding.unite((*it)->boundingRect());
    }
    double scaleX = (double)pageWidth / (double)bounding.width();
    double scaleY = (double)pageHeight / (double)bounding.height();
    double scale;
    scale = scaleX > scaleY ? scaleY : scaleX; // select smaller
    p.scale(scale, scale);
    p.translate(-bounding.left(), -bounding.top());
    canvas()->drawArea(bounding, &p, false);
}

void PoincareView::saveAs(QString fileName)
{
    QPainter painter;
    QPixmap pix;
    QCanvas *c = canvas();
    pix.resize(c->width(), c->height());
    painter.begin(&pix);
    c->drawArea(QRect(0, 0, c->width(), c->height()), &painter);
    painter.end();

    QFileInfo fi(fileName);
    QString ext = fi.extension(false); // get only the last extension
    if (ext == "jpg")
    {
        pix.save(fileName, "JPEG");
    }
    else if (ext == "png")
    {
        pix.save(fileName, "PNG");
    }
}

void PoincareView::pan(PanType ptype)
{
    // TODO fix this keyboad scrolling is not working in Linux atleast.
    const int stepSize = 50;
    int hScroll = 0, vScroll = 0;
    if (PAN_LEFT == ptype)
        hScroll = canvasWidth() / stepSize;
    else if (PAN_RIGHT == ptype)
        hScroll = -canvasWidth() / stepSize;
    else if (PAN_UP == ptype)
        vScroll = canvasHeight() / stepSize;
    else if (PAN_DOWN == ptype)
        vScroll = -canvasHeight() / stepSize;
    if (hScroll || vScroll)
    {
        QMatrix wm = worldMatrix();
        wm.translate(hScroll, vScroll);
        setWorldMatrix(wm);
        updateContents();
        // canvas()->update();
    }
}

void PoincareView::zoom(ZoomType type)
{
    QMatrix m = worldMatrix();
    if (IN == type)
    {
        m.scale(1.1, 1.1);
        setWorldMatrix(m);
    }
    else if (OUT == type)
    {
        m.scale(0.9, 0.9);
        setWorldMatrix(m);
    }
    else if (DEFAULT == type)
    {
        setWorldMatrix(defaultView);
    }
}

void PoincareView::toggleLayer(int layerId, bool state)
{
    if (NORMAL != viewMode_)
        return;
    layerId -= 1;
    if (layerId >= 0 && layerId < dgram->numLayers())
    {
        isLayerVisible[layerId] = state;
        drawLayer(layerId, isLayerVisible[layerId]);
        canvas()->update();
    }
}

void PoincareView::toggleFrame(bool state)
{
    showFrame_ = state;
    drawFrame(showFrame_);
    canvas()->update();
}

void PoincareView::animPlay()
{
    viewMode_ = ANIMATE;
    if (paused_)
    {
        animateTimer->start(animDelay_);
    }
    else
    { // for first time play
        drawBoundingCircle();
        drawDiagram(false); // hide the whole diagram
        animateNext_ = 0;
        animateTimer->start(animDelay_);
        canvas()->update();
    }
    paused_ = false;
}

void PoincareView::animPause()
{
    animateTimer->stop();
    paused_ = true;
}

void PoincareView::animStop()
{
    viewMode_ = NORMAL;
    animateTimer->stop();
    paused_ = false;
    drawBoundingCircle();
    restoreDiagramState(); // return to view state before animation started
    drawDiagram(true);     // show the whole diagram
    canvas()->update();

    // TODO eg only one layer might be visible before animation started
}

void PoincareView::animNext()
{
    if (paused_)
    {
        if (dgram->animq.size() == animateNext_)
        {
            drawBoundingCircle();
            drawDiagram(false); // hide the whole diagram
            animateNext_ = 0;
            canvas()->update();
        }
        PatternPtr p = dgram->pattern(dgram->animq.at(animateNext_));
        drawPattern(*p); // NOTE is ++ atomic?
        ++animateNext_;
        canvas()->update();
    }
}

void PoincareView::animPrev()
{
    if (paused_)
    {
        if (animateNext_ < 0)
        {
            drawBoundingCircle();
            drawDiagram(true); // show the whole diagram
            animateNext_ = dgram->animq.size() - 1;
            canvas()->update();
        }
        PatternPtr p = dgram->pattern(dgram->animq.at(animateNext_));
        drawPattern(*p, false); // NOTE is -- atomic?
        --animateNext_;
        canvas()->update();
    }
}

void PoincareView::animateTimerDone()
{
    if (dgram->animq.size() == animateNext_)
    {
        // animateTimer->stop();
        // animateNext_ = 0;
        paused_ = false;
        animPlay(); // TODO anim is in loop mode. ask user if loop mode or play once mode.
    }
    else
    {
        PatternPtr p = dgram->pattern(dgram->animq.at(animateNext_++));
        drawPattern(*p); // NOTE is ++ atomic?
        canvas()->update();
    }
}

void PoincareView::init()
{
    animDelay_ = 200;
    if (animateTimer)
    {
        animateTimer->stop();
        animateNext_ = 0;
        paused_ = false;
    }

    items_.clear(); // clear our item list

    // then delete all actual items on the underlaying canvas
    // this will also delete the boundingCircle
    // but onNewDocument will recreate it
    QCanvasItemList::iterator it;
    QCanvasItemList itemList = canvas()->allItems();
    for (it = itemList.begin(); it != itemList.end(); ++it)
    {
        (*it)->hide(); // this is needed
        delete *it;
    }
    viewMode_ = NORMAL;
}

void PoincareView::drawBoundingCircle(bool visible, bool init)
{
    if (init)
    {
        disk = new QCanvasEllipse(diameter(), diameter(), canvas());
        disk->setBrush(QColor(0xf6, 0xeb, 0x70));
        disk->setX(origin().x());
        disk->setY(origin().y());
        disk->setZ(-100);
    }
    disk->setVisible(visible);
}

void PoincareView::drawFrame(bool visible, bool init)
{
    PatternList patterns = dgram->allPatterns();
    for (PatternListIter it = patterns.begin(); it != patterns.end(); ++it)
    {
        drawPatternFrame(**it, visible, init);
    }
}

void PoincareView::restoreDiagramState()
{
    for (int i = 0; i < dgram->numLayers(); i++)
    {
        drawLayer(i, isLayerVisible[i]);
    }
}

void PoincareView::drawDiagram(bool visible, bool init)
{
    //        PatternList patterns = dgram->allPatterns();
    //        cerr<<"There are "<<patterns.count()<<" patterns in this diagram"<<endl;
    //        for(PatternListIter it = patterns.begin(); it != patterns.end(); ++it) {
    //             drawPattern(**it, visible, init);
    //        }
    for (int i = 0; i < dgram->numLayers(); i++)
    {
        drawLayer(i, visible, init);
    }
}

void PoincareView::drawLayer(const int layerId, bool visible, bool init)
{
    PatternList pats = dgram->layerPatterns(layerId);
    PatternListIter it;
    for (it = pats.begin(); it != pats.end(); ++it)
    {
        drawPattern(**it, visible, init);
    }
    isLayerVisible[layerId] = visible;
}

void PoincareView::drawPattern(const Pattern &pat, bool visible, bool init)
{
    ElemList elems = pat.elems();
    // DEBUG
    // cerr<<"There are "<<elems.count()<<" elements in this pattern"<<endl;
    for (ElemListIter it = elems.begin(); it != elems.end(); ++it)
    {
        drawElement(*it, visible, init);
    }
}

void PoincareView::drawPatternFrame(const Pattern &pat, bool visible, bool init)
{
    ElemList frame = pat.frame();
    for (ElemListIter it = frame.begin(); it != frame.end(); ++it)
    {
        drawElement(*it, visible, init);
    }
}

void PoincareView::drawElement(const ElementPtr e, bool visible, bool init)
{
    if (!init)
    { // only show/hide existing
        if (items_.contains(e->id()))
        {
            items_[e->id()]->setVisible(visible);
        }
        return;
    }

    QPen pen(dgram->colorMapVal(e->cid()));
    if (e->lineStyle() == DOTS)
    {
        pen.setStyle(Qt::DotLine);
    }
    // Initialization
    // TODO handle filled/not-filled, (assumes filled for now)
    if (CIRCLE == e->type())
    {
        // first point is the center and second is a point on the circumference
        // calculate radius and draw
        Point center = e->getPoint(0);
        Point circum = e->getPoint(1);
        QPoint p1 = makeQPoint(center);
        QPoint p2 = makeQPoint(circum);
        double radius = sqrt(pow(double(p1.x() - p2.x()), 2) + pow(double(p1.y() - p2.y()), 2));
        CanvasEllipse *circle = new CanvasEllipse(2 * radius, 2 * radius, canvas());
        circle->setX(p1.x());
        circle->setY(p2.y());
        circle->setZ(e->zorder());
        circle->setPen(pen);
        circle->setBrush(dgram->colorMapVal(e->cid()));
        circle->setFilled(e->filled());
        circle->setVisible(visible);
        items_.insert(e->id(), circle);
        // DEBUG
        // cerr<<"In drawElement CIRCLE radius = "<<radius<<endl;
    }
    else if (EUCLID_POLY == e->type())
    {
        // There are n points, last point should be joined to first
        CanvasPoly *poly = new CanvasPoly(canvas());
        QPolygon pa(e->numPoints());
        QPoint pt;
        int i = 0;
        for (i = 0; i < e->numPoints(); ++i)
        {
            pt = makeQPoint(e->getPoint(i));
            pa.setPoint(i, pt.x(), pt.y());
        }
        QRect boundingRect = pa.boundingRect();
        QPoint center = boundingRect.center();
        poly->setPoints(pa);
        poly->setX(0); // TODO set x,y to sane values other than 0
        poly->setY(0);
        poly->setZ(e->zorder());
        poly->setPen(pen);
        poly->setBrush(dgram->colorMapVal(e->cid()));
        poly->setFilled(e->filled());
        poly->setVisible(visible);
        items_.insert(e->id(), poly);
        // DEBUG
        // cerr<<"In drawElement EUCLID_POLY "<<center.x()<<","<<center.y()<<endl;
    }
    else if (EUCLID_POLYLINE == e->type())
    {
        CanvasPolyLine *polyline = new CanvasPolyLine(canvas());
        QPolygon pa(e->numPoints());
        QPoint pt;
        int i = 0;
        for (i = 0; i < e->numPoints(); ++i)
        {
            pt = makeQPoint(e->getPoint(i));
            pa.setPoint(i, pt.x(), pt.y());
        }
        QRect boundingRect = pa.boundingRect();
        QPoint center = boundingRect.center();
        polyline->setPoints(pa);
        polyline->setX(0); // TODO set x,y to sane values other than 0
        polyline->setY(0);
        polyline->setZ(e->zorder());
        polyline->setPen(pen);
        polyline->setVisible(visible);
        items_.insert(e->id(), polyline);
        // DEBUG
        // cerr<<"In drawElement EUCLID_POLYLINE "<<endl;
    }
    else if (HYPER_POLYLINE == e->type())
    {
        HyperPolyLine *hpl = (HyperPolyLine *)e;
        vector<HyperLine> &mhlines = hpl->hyperLines();
        CanvasHyperPolyLine *hpolyline = new CanvasHyperPolyLine(canvas());

        vector<HyperLine>::iterator it;
        for (it = mhlines.begin(); it != mhlines.end(); ++it)
        {
            CanvasHyperLine *chl = makeCanvasHyperLine(*it);
            hpolyline->addLine(chl);
        }
        hpolyline->setPen(pen);
        hpolyline->setX(0); // TODO set x,y to sane values other than 0
        hpolyline->setY(0);
        hpolyline->setZ(e->zorder());
        hpolyline->setVisible(visible);
        items_.insert(e->id(), hpolyline);
    }
    else if (HYPER_POLY == e->type())
    {
        HyperPoly *hp = (HyperPoly *)e;
        vector<HyperLine> &mhlines = hp->hyperLines();
        CanvasHyperPoly *hpoly = new CanvasHyperPoly(canvas());

        vector<HyperLine>::iterator it;
        for (it = mhlines.begin(); it != mhlines.end(); ++it)
        {
            CanvasHyperLine *chl = makeCanvasHyperLine(*it);
            hpoly->addLine(chl);
        }
        hpoly->setPen(pen);
        hpoly->setBrush(dgram->colorMapVal(e->cid()));
        hpoly->setX(0); // TODO set x,y to sane values other than 0
        hpoly->setY(0);
        hpoly->setZ(e->zorder());
        hpoly->setVisible(visible);
        hpoly->setFilled(hp->filled());
        items_.insert(e->id(), hpoly);
        // cerr<<"element type "<<e->type()<<" is not yet handled"<<endl;
    }
    else
    {
        throw "PoincareView::drawElement: Unknown element type!";
    }
}

void PoincareView::onDocumentChange()
{
    dgram = (Diagram *)docViewer->getDocument();

    dgram->make();
    init();
    drawBoundingCircle(true, true); // initialize disk
    drawDiagram(true, true);        // initialize
    drawFrame(showFrame_, true);    // initialize

    canvas()->update();
}

QPoint PoincareView::makeQPoint(const Point &mp)
{
    QPoint pt;
    Point tmp(mp);
    tmp.weierstrassToPoincare();

    double x, y;
    // map it to canvas coordinates
    x = (tmp.x() * diameter() / 2 + origin().x());
    y = diameter() - (tmp.y() * diameter() / 2 + origin().y());
    pt.setX(x);
    pt.setY(y);
    return pt;
}

CanvasHyperLine *PoincareView::makeCanvasHyperLine(const HyperLine &mhl)
{
    CanvasHyperLine *chl = new CanvasHyperLine();
    if (mhl.shouldDrawArc())
    {
        QPoint tl = makeQPoint(mhl.topLeft());
        QSize sz(mhl.width() * diameter() / 2, mhl.height() * diameter() / 2);
        chl->setParameters(tl, sz, mhl.startAngle(), mhl.endAngle());
    }
    else
    {
        chl->setParamters(makeQPoint(mhl.startPoint()), makeQPoint(mhl.endPoint()));
    }
    return chl;
}
