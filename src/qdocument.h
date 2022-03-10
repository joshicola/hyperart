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

#ifndef __QDOCUMENT_H__
#define __QDOCUMENT_H__

#include <q3ptrlist.h>
#include <qobject.h>

/**
 * @class    QDocument
 * @author   <stephan.stapel@web.de>
 *
 * This class represents the document part of the document view class hierarchy.
 * As it is abstract, you will not be able to instantiate it unless you create
 * a descendent of it.
 * This class is capable of
 *  <ul>
 *    <li> managing an arbitrary number of docViewers
 *    <li> notify the managed docViewers of changes on demand
 *  </ul>
 *
 * example implementation for the document class:
 * At first, the class definition:
 * @code
 * void test()
 * #include "QDocument.h"
 * class QDocImplementation : public QDocument {
 * public :
 *    QDocImplementation();
 *    char* data;
 * };
 * @endcode
 * <br>
 * The implementation of this definition is as easy as it gets:
 * @code
 * #include "QDocImplementation.h"
 * #include <stdlib.h>
 *
 *
 * QDocImplementation::QDocImplementation() {
 *   data = (char*)malloc(255);
 *
 *   strcpy(data, "this is a test.");
 * }
 * @endcode
 */

class QDocument : public QObject
{
  Q_OBJECT

public: // initialization
  /**
   *  initializes all child structures and local variables.
   */
  QDocument();

  /**
   *  destroys child structures -- if needed.
   */
  virtual ~QDocument();

private: // private variables
  QPtrList<QObject *> *m_rgViews;
  bool modifiedFlag;
  bool firstUpdate;

public:
  /**
   * Adds a new entry to the viewlist. This function is being called by
   * QDocViewer::_register()
   *
   * @param    newView   view to be added to the list
   *
   * @return     TRUE, if the new view was added to the list
   *
   * @see      removeView
   */
  bool addView(QObject *newView);

  /**
   * Removes a certain view from the viewlist. This function is being called
   * by QDocViewer::_deregister
   *
   * @param
   *
   * @return      true if the view was removed, false otherwise
   *
   * @see    addView()
   */
  bool removeView(QObject *oldView);

  /**
   * Iterator function. Returns the first view within the view list.
   * If no views exist, NULL is returned.
   *
   * @return           pointer to the first view (aka docViewer) object
   * @see     getNextView()
   */
  QObject *getFirstView();

  /**
   * Another iterator function. getFirstView() shoul be called in advance to set
   * the iterator to the first element of the viewlist. After doing so, you can
   * call getNextView() until it returns NULL to step through the viewlist.
   *
   * @return         the next docView object within the viewlist.
   *
   * @see     getFirstView()
   */
  QObject *getNextView();

  /**
   * This function emits a change signal which should be received by all docViewers
   * registered to the certain document.
   *
   * @param wParam,lParam   token items which might give informations for
   *                        the views for what exactly to update
   *
   * @return     true, if all views could be updated. Otherwise false
   */
  bool updateAllViews(unsigned int wParam = 0, unsigned long lParam = 0);

  /**
   * Returns whether the document has been modified since the last time the
   * document was saved.<br>
   * Caution: Saving documents is not yet implemented!
   *
   * @return     true, if the document was modified
   *
   * @see      setModifiedFlag
   */
  bool isModified();

  /**
   * Manually sets the modified flag of the document so that saving the document
   * to a file might be requested by the program when closing the document.
   *
   * @param     newValue     true, if the document needs to be set to modified.
   *                         false, if the documents needs to be set to not-modified.
   *
   * @return         returns the previous value of the flag
   *
   * @see       isModified
   */
  bool setModifiedFlag(bool newValue);

signals:
  /**
   * Qt signal which is being emitted when the member updateAllViews() is executed.
   * When this is the first call to updateAllViews(), onFirstChange() is emitted
   * instead.
   *
   * @param wParam,lParam   token items which might give informations for
   *                        the views for what exactly to update
   *
   * @see onDocFirstChange
   */
  void onDocChange(unsigned int wParam, unsigned long lParam);
  /**
   * Qt signal which is being emitted when the member updateAllViews() is executed.
   * In contrast to onChange(), this signal is only being emitted when the member is
   * executed for the first time.
   *
   * @param wParam,lParam   token items which might give informations for
   *                        the views for what exactly to update
   *
   * @see onDocChange()
   */
  void onDocFirstChange(unsigned int wParam, unsigned long lParam);
};

#endif /* __QDOCUMENT_H__ */
