/****************************************************************************
** Meta object code from reading C++ file 'poincareview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "poincareview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'poincareview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PoincareView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      38,   33,   13,   13, 0x08,
      65,   53,   13,   13, 0x08,
      93,   87,   13,   13, 0x08,
     111,   13,   13,   13, 0x08,
     122,   13,   13,   13, 0x08,
     134,   13,   13,   13, 0x08,
     145,   13,   13,   13, 0x08,
     156,   13,   13,   13, 0x08,
     167,   13,   13,   13, 0x08,
     192,  186,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PoincareView[] = {
    "PoincareView\0\0onDocumentChange()\0type\0"
    "zoom(ZoomType)\0layer,state\0"
    "toggleLayer(int,bool)\0state\0"
    "toggleFrame(bool)\0animPlay()\0animPause()\0"
    "animStop()\0animNext()\0animPrev()\0"
    "animateTimerDone()\0ptype\0pan(PanType)\0"
};

void PoincareView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PoincareView *_t = static_cast<PoincareView *>(_o);
        switch (_id) {
        case 0: _t->onDocumentChange(); break;
        case 1: _t->zoom((*reinterpret_cast< ZoomType(*)>(_a[1]))); break;
        case 2: _t->toggleLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->toggleFrame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->animPlay(); break;
        case 5: _t->animPause(); break;
        case 6: _t->animStop(); break;
        case 7: _t->animNext(); break;
        case 8: _t->animPrev(); break;
        case 9: _t->animateTimerDone(); break;
        case 10: _t->pan((*reinterpret_cast< PanType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PoincareView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PoincareView::staticMetaObject = {
    { &Q3CanvasView::staticMetaObject, qt_meta_stringdata_PoincareView,
      qt_meta_data_PoincareView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PoincareView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PoincareView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PoincareView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PoincareView))
        return static_cast<void*>(const_cast< PoincareView*>(this));
    if (!strcmp(_clname, "DiagramView"))
        return static_cast< DiagramView*>(const_cast< PoincareView*>(this));
    return Q3CanvasView::qt_metacast(_clname);
}

int PoincareView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3CanvasView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
