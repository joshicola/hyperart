//
// C++ Implementation: diagramview
//
// Description: 
//
//
// Author: Ajit Datar <ajitdatar@gmail.com>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "diagramview.h"
// #include "qdocviewer.h"

DiagramView::DiagramView()
{
    //TODO: This is cludgy.  We should be able to use the QDocViewer but it doesn't work.
    docViewer = true;//new QDocViewer();
    //Derived class should connect
    //docViewer :: SIGNAL(onDocumentChange(unsigned int, unsigned long)
    //to DerivedClass :: SLOT(onDocumentChange())
    //
    //and
    //docViewer :: SIGNAL(onDocumentFirstChange(unsigned int, unsigned long)
    //to DerivedClass :: SLOT(onDocumentChange())
}

DiagramView::~DiagramView()
{
    if(docViewer) {
        //delete docViewer;
        docViewer = false;
    }
}

void DiagramView::setDocument(QTextDocument* doc)
{   
    
    if(docViewer) {
        dgram = (Diagram*)doc;
        //TODO: Another Cludgy hack.  We should be able to use the QDocViewer but it doesn't work.
        emit dgram->contentsChange(0, 0, 0);
        //docViewer->setDocument(doc);
        docViewer = true;
    }
    else {
        qWarning("Doc viewer does not exist");
    }
}

