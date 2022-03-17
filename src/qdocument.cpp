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

#include "qdocument.h"
#include "qdocviewer.h"
// Added by qt3to4:
#include <QList>

QDocument::QDocument()
{
    m_rgViews = new QList<QObject*>;
    modifiedFlag = false;
    firstUpdate = true;
} // !QDocument()

QDocument::~QDocument()
{
    if (m_rgViews)
    {
        delete m_rgViews;
        m_rgViews = 0;
    }
} // !~QDocument()

bool QDocument::addView(QObject *newView)
{
    QObject *previousCurrent = NULL;

    /* Fehler checken */
    if (!m_rgViews)
    {
        qWarning("QDocument::addView: view structure invalid");
        m_rgViews = new QList<QObject*>;
    }

    if (!newView)
    {
        qDebug("QDocument::addView: new view invalid");
        return false;
    }

    /* add the new view item to the list and jump back to the old position
       in the view list (-> maintain a save iteration state) */
    //previousCurrent = m_rgViews->last();
    m_rgViews->append(newView);
    //m_rgViews->find(previousCurrent);

    return true;
} // !addView()

bool QDocument::removeView(QObject *oldView)
{
    if (!m_rgViews)
    {
        qWarning("QDocument::removeView: view structure invalid");
        m_rgViews = new QList<QObject*>;
    }

    if (!oldView)
    {
        qDebug("QDocument::removeView: view invalid");
        return false;
    }

    return m_rgViews->removeAll(oldView);
} // !removeView()

QObject *QDocument::getFirstView()
{
    if (!m_rgViews)
    {
        qDebug("QDocument: view structure invalid");
        return 0;
    }

    return (m_rgViews->first());
} // !getFirstView()

QObject *QDocument::getNextView()
{
    if (!m_rgViews)
    {
        qWarning("QDocument: view structure invalid");
    }

    return (m_rgViews->last());
} // !getNextView()

bool QDocument::updateAllViews(unsigned int wParam, unsigned long lParam)
{
    if (!m_rgViews)
        return false;

    if (firstUpdate)
    {
        emit onDocFirstChange(wParam, lParam);
        firstUpdate = false;
    }
    else
        emit onDocChange(wParam, lParam);

    return true;
} // !UpdateAllViews()

bool QDocument::isModified()
{
    return modifiedFlag;
} // !IsModified()

bool QDocument::setModifiedFlag(bool newValue)
{
    bool oldValue = modifiedFlag;

    modifiedFlag = newValue;

    return oldValue;
} // !SetModifiedFlag()
