/****************************************************************************
** Meta object code from reading C++ file 'qdocviewer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qdocviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdocviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDocViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   12,   11,   11, 0x05,
      55,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   12,   11,   11, 0x0a,
     122,   12,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QDocViewer[] = {
    "QDocViewer\0\0wParam,lParam\0"
    "onDocumentChange(uint,ulong)\0"
    "onDocumentFirstChange(uint,ulong)\0"
    "slotOnDocumentChange(uint,ulong)\0"
    "slotOnDocumentFirstChange(uint,ulong)\0"
};

void QDocViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QDocViewer *_t = static_cast<QDocViewer *>(_o);
        switch (_id) {
        case 0: _t->onDocumentChange((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 1: _t->onDocumentFirstChange((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 2: _t->slotOnDocumentChange((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 3: _t->slotOnDocumentFirstChange((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QDocViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QDocViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDocViewer,
      qt_meta_data_QDocViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDocViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDocViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDocViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDocViewer))
        return static_cast<void*>(const_cast< QDocViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int QDocViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QDocViewer::onDocumentChange(unsigned int _t1, unsigned long _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDocViewer::onDocumentFirstChange(unsigned int _t1, unsigned long _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
