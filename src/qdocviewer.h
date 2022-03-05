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

#ifndef __QDOCVIEWER_H__
#define __QDOCVIEWER_H__


#include <qobject.h>
#include "qdocument.h"


/**
 * @class  QDocViewer
 * @author Stephan Stapel, <stephan.stapel@web.de>
 *
 * this class is the interface class between the backend QDocument part of the
 * hierarchy and the front-end parts, namely the gui elements each displaying 
 * some of the data of the document.
 *
 * <br>
 * Because Qt doen't allow 'free' multiple inheritance (only if you include some
 * special considerations which might be easily forgotten), this class exists
 * as an interface. <br>
 * Therefore it passes through different method calls as well as signals emitted
 * by the document.<br>
 * In future versions of this object, filtering may be included in the signal/ slot
 * pass-through to reduce update traffic to the distinct gui element.
 *
 * <br>
 * Example for the registration to a document where QView is an arbitrary gui view object
 * and QDocumentImplementation is a document object of a certain type (implementation of the
 * abstract QDocument class:
 *
 * @code
 *  QView::QView(QDocumentImplementation *thisDoc) 
 *  {
 *     // new interface object either through
 *     // a:
 *    docViewer = new QDocViewer();
 *    docViewer->setDocument(thisDoc);
 *
 *     // or b:
 *    docViewer = new QDocViewer(thisDoc);
 *     
 *     // connect to docViewer signals
 *    QObject::connect(docViewer, SIGNAL(onDocumentChange(unsigned int, unsigned long)), 
 *                     this, SLOT(slotOnDocumentChange(unsigned int, unsigned long)) );
 *  } // !QView()
 *
 *
 *  QView::onDocumentChange(unsigned int wParam, unsigned long lParam) 
 *  {
 *    // process changes of the document
 *    QDocumentImplementation* currentDoc = (QDocumentImplementation*)docViewer->getDocument();
 *    
 *    if (!currentDoc)
 *      return;
 *
 *    // read data from the document and print it on the gui element
 *  } // !onDocumentChange() 
 * @endcode
 * 
 */



class QDocViewer : public QObject 
{
    Q_OBJECT 

	public:
    /**
     * creates a new QDocViewer object.
     * 
     * @param thisDocument   target document, where the object should be associated
     *                       with. If this is not yet known on initializiation time,
     *                       NULL be given as a parameter or the parameters may be
     *                       left blank.
     *
     * @see   setDocument()
     */
    QDocViewer(QDocument* thisDocument = NULL);

    /**
     * destroys a docViewer object and deregisters from the document, if still
     * registered.
     */
    virtual ~QDocViewer();

    /**
     * returns the currently associated document, otherwise NULL
     * 
     * @see setDocument()
     */
    QDocument* getDocument();

    /**
     * associates the docViewer object to a new document and deregisters from
     * the previous document, if there was one.
     *
     * @param     new document to be associated with
     *
     * @return    wasRegistered  true, if the registration
     *
     * @see getDocument()
     */
    bool setDocument(QDocument* newDocument);

    /**
     * This function sets the modified-flag of the associated document and initiates the 
     * emission of the onChange() signal.
     *
     * @param wParam,lParam   token items which might give informations for
     *                        the views for what exactly to update
     */
    bool demandChangeNotify(unsigned int wParam, unsigned long lParam);

 private:
    QDocument* currentDocument;

    /**
     * internal function for registering the object to a certain component.
     * This function is being called by QDocViewer() and setDocument()
     * @return    true if the document was registered, false otherwise
     */
    bool _register(QDocument* thisDocument);

    /**
     * internal function for deregistering the object from a certain document component.
     * This function is being called by ~QDocViewer() and setDocument()
     * 
     * @return      true, if the docViewer was successfully unregistered
     *              from the document
     */
    bool _deregister(QDocument* thisDocument);

 public slots:
    /**
     * internal function for receiving the onDocChange() signal from the QDocument component.
     *
     * @param wParam,lParam   token items which might give informations for
     *                        the views for what exactly to update
     *
     */ 
    void slotOnDocumentChange(unsigned int wParam, unsigned long lParam);
 
    /**
     * internal function for receiving the onDocFirstChange() signal from the QDocument component.
     *
     * @param wParam,lParam   token items which might give informations for
     *                        the views for what exactly to update
     */
    void slotOnDocumentFirstChange(unsigned int wParam, unsigned long lParam);

 signals:
    /**
     * part of a signal-slot hierarchy.
     * When a document is changed, this object emits the signal onChange()
     * ( through a call of QDocument::updateAllView() ).
     * This signal is being received by the docViewer slot slotOnDocumentChange()
     * which passes the document's signal to its own signal onDocumentChange() which
     * might be received by the parent object, most likely a gui object which
     * then might update its data.
     *
     * @param wParam,lParam   token items which might give informations for
     *                        the views for what exactly to update
     *
     * @see onDocumentFirstChange()
     */
    void onDocumentChange(unsigned int wParam, unsigned long lParam);
    /**
     * same as onDocumentChange() but only applies to the 
     * initial change of the document class.
     *
     * @param wParam,lParam   token items which might give informations for
     *                        the views for what exactly to update
     *
     * @see onDocumentChange()
     */
    void onDocumentFirstChange(unsigned int wParam, unsigned long lParam);
};


#endif /* __QDOCVIEWER_H__ */
