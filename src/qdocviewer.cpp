/*
QDocument-View class set
Copyright (C) 2002-2003		Stephan Stapel
                                stephan.stapel@web.de

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/



#include "qdocviewer.h"


QDocViewer::QDocViewer(QDocument* thisDocument) 
{
  currentDocument = NULL;

  if (thisDocument)
      _register(thisDocument);
} // !QDocViewer()



QDocViewer::~QDocViewer() 
{
  _deregister(currentDocument);
} // !~QDocViewer()



QDocument* QDocViewer::getDocument() 
{
  return currentDocument;
} // !getDocument()



bool QDocViewer::setDocument(QDocument* newDocument) 
{
  _deregister( getDocument() );
  _register(newDocument);

  return true;
} // !setDocument()



bool QDocViewer::_register(QDocument* thisDocument) 
{
  currentDocument = thisDocument;

  if (!thisDocument) 
  {
    qDebug("QDocViewer: document invalid");
    return false;
  }

  QObject::connect(thisDocument, SIGNAL(onDocChange(unsigned int, unsigned long)),      
		   this, SLOT(slotOnDocumentChange(unsigned int, unsigned long)) );
  QObject::connect(thisDocument, SIGNAL(onDocFirstChange(unsigned int, unsigned long)), 
		   this, SLOT(slotOnDocumentFirstChange(unsigned int, unsigned long)) );

  return thisDocument->addView(this);
} // !_register()



bool QDocViewer::_deregister(QDocument* thisDocument) 
{
  if (!thisDocument) return false;

  /* den View vom Dokument de-registrieren */
  thisDocument->removeView(this);
  return true;
} // !_deregister()



void QDocViewer::slotOnDocumentChange(unsigned int wParam, unsigned long lParam) 
{
  emit onDocumentChange(wParam, lParam);
} // !slotOnDocumentChange()



void QDocViewer::slotOnDocumentFirstChange(unsigned int wParam, unsigned long lParam) 
{
  emit onDocumentFirstChange(wParam, lParam);
} // !slotOnDocumentFirstChange()



bool QDocViewer::demandChangeNotify(unsigned int wParam, unsigned long lParam) 
{
  if (!currentDocument) 
  {
    qDebug("QDocument: No document available");
    return false;
  }
  
  currentDocument->setModifiedFlag(true);
  currentDocument->updateAllViews(wParam, lParam);

  return true;
} // !demandChangeNotify()
