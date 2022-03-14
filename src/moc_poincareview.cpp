/****************************************************************************
** Meta object code from reading C++ file 'poincareview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "poincareview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'poincareview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PoincareView_t {
    QByteArrayData data[19];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PoincareView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PoincareView_t qt_meta_stringdata_PoincareView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PoincareView"
QT_MOC_LITERAL(1, 13, 16), // "onDocumentChange"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "zoom"
QT_MOC_LITERAL(4, 36, 8), // "ZoomType"
QT_MOC_LITERAL(5, 45, 4), // "type"
QT_MOC_LITERAL(6, 50, 11), // "toggleLayer"
QT_MOC_LITERAL(7, 62, 5), // "layer"
QT_MOC_LITERAL(8, 68, 5), // "state"
QT_MOC_LITERAL(9, 74, 11), // "toggleFrame"
QT_MOC_LITERAL(10, 86, 8), // "animPlay"
QT_MOC_LITERAL(11, 95, 9), // "animPause"
QT_MOC_LITERAL(12, 105, 8), // "animStop"
QT_MOC_LITERAL(13, 114, 8), // "animNext"
QT_MOC_LITERAL(14, 123, 8), // "animPrev"
QT_MOC_LITERAL(15, 132, 16), // "animateTimerDone"
QT_MOC_LITERAL(16, 149, 3), // "pan"
QT_MOC_LITERAL(17, 153, 7), // "PanType"
QT_MOC_LITERAL(18, 161, 5) // "ptype"

    },
    "PoincareView\0onDocumentChange\0\0zoom\0"
    "ZoomType\0type\0toggleLayer\0layer\0state\0"
    "toggleFrame\0animPlay\0animPause\0animStop\0"
    "animNext\0animPrev\0animateTimerDone\0"
    "pan\0PanType\0ptype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PoincareView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       6,    2,   73,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,
      15,    0,   86,    2, 0x08 /* Private */,
      16,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void PoincareView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PoincareView *>(_o);
        Q_UNUSED(_t)
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

QT_INIT_METAOBJECT const QMetaObject PoincareView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_PoincareView.data,
    qt_meta_data_PoincareView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PoincareView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PoincareView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PoincareView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "DiagramView"))
        return static_cast< DiagramView*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int PoincareView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
