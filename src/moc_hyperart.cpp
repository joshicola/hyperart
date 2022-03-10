/****************************************************************************
** Meta object code from reading C++ file 'hyperart.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hyperart.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hyperart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HyperArt[] = {

    // content:
    6,      // revision
    0,      // classname
    0, 0,   // classinfo
    38, 14, // methods
    0, 0,   // properties
    0, 0,   // enums/sets
    0, 0,   // constructors
    0,      // flags
    9,      // signalCount

    // signals: signature, parameters, type, tag, flags
    10, 9, 9, 9, 0x05,
    26, 9, 9, 9, 0x05,
    43, 9, 9, 9, 0x05,
    59, 9, 9, 9, 0x05,
    75, 9, 9, 9, 0x05,
    91, 9, 9, 9, 0x05,
    108, 9, 9, 9, 0x05,
    130, 128, 9, 9, 0x05,
    154, 9, 9, 9, 0x05,

    // slots: signature, parameters, type, tag, flags
    173, 9, 9, 9, 0x0a,
    183, 9, 9, 9, 0x0a,
    193, 9, 9, 9, 0x0a,
    204, 9, 9, 9, 0x0a,
    215, 9, 9, 9, 0x0a,
    228, 9, 9, 9, 0x0a,
    240, 9, 9, 9, 0x0a,
    251, 9, 9, 9, 0x0a,
    262, 9, 9, 9, 0x0a,
    273, 9, 9, 9, 0x0a,
    283, 9, 9, 9, 0x0a,
    294, 9, 9, 9, 0x0a,
    306, 9, 9, 9, 0x0a,
    317, 9, 9, 9, 0x0a,
    329, 9, 9, 9, 0x0a,
    344, 9, 9, 9, 0x0a,
    356, 9, 9, 9, 0x0a,
    363, 9, 9, 9, 0x0a,
    377, 9, 9, 9, 0x0a,
    392, 9, 9, 9, 0x0a,
    406, 9, 9, 9, 0x0a,
    420, 9, 9, 9, 0x0a,
    440, 434, 9, 9, 0x0a,
    477, 9, 9, 9, 0x0a,
    507, 9, 9, 9, 0x0a,
    537, 9, 9, 9, 0x0a,
    568, 434, 9, 9, 0x0a,
    586, 9, 9, 9, 0x0a,
    636, 9, 9, 9, 0x09,

    0 // eod
};

static const char qt_meta_stringdata_HyperArt[] = {
    "HyperArt\0\0doAnimatePlay()\0doAnimatePause()\0"
    "doAnimateNext()\0doAnimatePrev()\0"
    "doAnimateStop()\0doZoom(ZoomType)\0"
    "doToggleFrame(bool)\0,\0doToggleLayer(int,bool)\0"
    "doPanning(PanType)\0destroy()\0fileNew()\0"
    "fileOpen()\0fileSave()\0fileSaveAs()\0"
    "filePrint()\0fileExit()\0editUndo()\0"
    "editRedo()\0editCut()\0editCopy()\0"
    "editPaste()\0editFind()\0helpIndex()\0"
    "helpContents()\0helpAbout()\0init()\0"
    "animatePlay()\0animatePause()\0animateStop()\0"
    "animateNext()\0animatePrev()\0state\0"
    "viewToggle_FrameAction_toggled(bool)\0"
    "zoomDefaultAction_activated()\0"
    "zoomZoom_InAction_activated()\0"
    "zoomZoom_outAction_activated()\0"
    "toggleLayer(bool)\0"
    "editPreferencesNumber_of_LayersAction_activated()\0"
    "languageChange()\0"};

void HyperArt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        Q_ASSERT(staticMetaObject.cast(_o));
        HyperArt *_t = static_cast<HyperArt *>(_o);
        switch (_id)
        {
        case 0:
            _t->doAnimatePlay();
            break;
        case 1:
            _t->doAnimatePause();
            break;
        case 2:
            _t->doAnimateNext();
            break;
        case 3:
            _t->doAnimatePrev();
            break;
        case 4:
            _t->doAnimateStop();
            break;
        case 5:
            _t->doZoom((*reinterpret_cast<ZoomType(*)>(_a[1])));
            break;
        case 6:
            _t->doToggleFrame((*reinterpret_cast<bool(*)>(_a[1])));
            break;
        case 7:
            _t->doToggleLayer((*reinterpret_cast<int(*)>(_a[1])), (*reinterpret_cast<bool(*)>(_a[2])));
            break;
        case 8:
            _t->doPanning((*reinterpret_cast<PanType(*)>(_a[1])));
            break;
        case 9:
            _t->destroy();
            break;
        case 10:
            _t->fileNew();
            break;
        case 11:
            _t->fileOpen();
            break;
        case 12:
            _t->fileSave();
            break;
        case 13:
            _t->fileSaveAs();
            break;
        case 14:
            _t->filePrint();
            break;
        case 15:
            _t->fileExit();
            break;
        case 16:
            _t->editUndo();
            break;
        case 17:
            _t->editRedo();
            break;
        case 18:
            _t->editCut();
            break;
        case 19:
            _t->editCopy();
            break;
        case 20:
            _t->editPaste();
            break;
        case 21:
            _t->editFind();
            break;
        case 22:
            _t->helpIndex();
            break;
        case 23:
            _t->helpContents();
            break;
        case 24:
            _t->helpAbout();
            break;
        case 25:
            _t->init();
            break;
        case 26:
            _t->animatePlay();
            break;
        case 27:
            _t->animatePause();
            break;
        case 28:
            _t->animateStop();
            break;
        case 29:
            _t->animateNext();
            break;
        case 30:
            _t->animatePrev();
            break;
        case 31:
            _t->viewToggle_FrameAction_toggled((*reinterpret_cast<bool(*)>(_a[1])));
            break;
        case 32:
            _t->zoomDefaultAction_activated();
            break;
        case 33:
            _t->zoomZoom_InAction_activated();
            break;
        case 34:
            _t->zoomZoom_outAction_activated();
            break;
        case 35:
            _t->toggleLayer((*reinterpret_cast<bool(*)>(_a[1])));
            break;
        case 36:
            _t->editPreferencesNumber_of_LayersAction_activated();
            break;
        case 37:
            _t->languageChange();
            break;
        default:;
        }
    }
}

const QMetaObjectExtraData HyperArt::staticMetaObjectExtraData = {
    0, qt_static_metacall};

const QMetaObject HyperArt::staticMetaObject = {
    {&QMainWindow::staticMetaObject, qt_meta_stringdata_HyperArt,
     qt_meta_data_HyperArt, &staticMetaObjectExtraData}};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HyperArt::getStaticMetaObject()
{
    return staticMetaObject;
}
#endif // Q_NO_DATA_RELOCATION

const QMetaObject *HyperArt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HyperArt::qt_metacast(const char *_clname)
{
    if (!_clname)
        return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HyperArt))
        return static_cast<void *>(const_cast<HyperArt *>(this));
    if (!strcmp(_clname, "Ui::HyperArt"))
        return static_cast<Ui::HyperArt *>(const_cast<HyperArt *>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HyperArt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void HyperArt::doAnimatePlay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void HyperArt::doAnimatePause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void HyperArt::doAnimateNext()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void HyperArt::doAnimatePrev()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void HyperArt::doAnimateStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void HyperArt::doZoom(ZoomType _t1)
{
    void *_a[] = {0, const_cast<void *>(reinterpret_cast<const void *>(&_t1))};
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void HyperArt::doToggleFrame(bool _t1)
{
    void *_a[] = {0, const_cast<void *>(reinterpret_cast<const void *>(&_t1))};
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void HyperArt::doToggleLayer(int _t1, bool _t2)
{
    void *_a[] = {0, const_cast<void *>(reinterpret_cast<const void *>(&_t1)), const_cast<void *>(reinterpret_cast<const void *>(&_t2))};
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void HyperArt::doPanning(PanType _t1)
{
    void *_a[] = {0, const_cast<void *>(reinterpret_cast<const void *>(&_t1))};
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
