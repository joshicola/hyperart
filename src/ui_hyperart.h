/********************************************************************************
** Form generated from reading UI file 'hyperart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYPERART_H
#define UI_HYPERART_H

#include <QtCore/QVariant>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>
#include "datareader.h"
#include "defs.h"
#include "diagram.h"
#include "diagramview.h"
#include "poincareview.h"
#include "regularpgon.h"

QT_BEGIN_NAMESPACE

class Ui_HyperArt
{
public:
    QAction *fileNewAction;
    QAction *fileOpenAction;
    QAction *fileSaveAction;
    QAction *fileSaveAsAction;
    QAction *filePrintAction;
    QAction *fileExitAction;
    QAction *editUndoAction;
    QAction *editRedoAction;
    QAction *editCutAction;
    QAction *editCopyAction;
    QAction *editPasteAction;
    QAction *editFindAction;
    QAction *helpContentsAction;
    QAction *helpIndexAction;
    QAction *helpAboutAction;
    QAction *animatePlayAction;
    QAction *animatePauseAction;
    QAction *animateStopAction;
    QAction *animatePrevAction;
    QAction *animateNextAction;
    QAction *zoomZoom_InAction;
    QAction *zoomZoom_outAction;
    QAction *zoomDefaultAction;
    QAction *viewToggle_FrameAction;
    QAction *editPreferencesAction;
    QAction *editPreferencesNumber_of_LayersAction;
    QWidget *widget;
    QToolBar *Toolbar;
    QToolBar *ZoomToolbar;
    QToolBar *AnimateToolbar;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *Edit;
    QMenu *popupMenu_10;
    QMenu *View;
    QMenu *Zoom;
    QMenu *Animate;
    QMenu *helpMenu;

    void setupUi(QMainWindow *HyperArt)
    {
        if (HyperArt->objectName().isEmpty())
            HyperArt->setObjectName(QString::fromUtf8("HyperArt"));
        HyperArt->resize(754, 627);
        fileNewAction = new QAction(HyperArt);
        fileNewAction->setObjectName(QString::fromUtf8("fileNewAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("butter.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        fileNewAction->setIcon(icon);
        fileNewAction->setProperty("name", QVariant(QByteArray("fileNewAction")));
        fileOpenAction = new QAction(HyperArt);
        fileOpenAction->setObjectName(QString::fromUtf8("fileOpenAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("fileopen.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        fileOpenAction->setIcon(icon1);
        fileOpenAction->setProperty("name", QVariant(QByteArray("fileOpenAction")));
        fileSaveAction = new QAction(HyperArt);
        fileSaveAction->setObjectName(QString::fromUtf8("fileSaveAction"));
        fileSaveAction->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("filesave.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        fileSaveAction->setIcon(icon2);
        fileSaveAction->setProperty("name", QVariant(QByteArray("fileSaveAction")));
        fileSaveAsAction = new QAction(HyperArt);
        fileSaveAsAction->setObjectName(QString::fromUtf8("fileSaveAsAction"));
        fileSaveAsAction->setEnabled(false);
        fileSaveAsAction->setProperty("name", QVariant(QByteArray("fileSaveAsAction")));
        filePrintAction = new QAction(HyperArt);
        filePrintAction->setObjectName(QString::fromUtf8("filePrintAction"));
        filePrintAction->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("fileprint.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        filePrintAction->setIcon(icon3);
        filePrintAction->setProperty("name", QVariant(QByteArray("filePrintAction")));
        fileExitAction = new QAction(HyperArt);
        fileExitAction->setObjectName(QString::fromUtf8("fileExitAction"));
        fileExitAction->setProperty("name", QVariant(QByteArray("fileExitAction")));
        editUndoAction = new QAction(HyperArt);
        editUndoAction->setObjectName(QString::fromUtf8("editUndoAction"));
        editUndoAction->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("image5"), QSize(), QIcon::Normal, QIcon::Off);
        editUndoAction->setIcon(icon4);
        editUndoAction->setProperty("name", QVariant(QByteArray("editUndoAction")));
        editRedoAction = new QAction(HyperArt);
        editRedoAction->setObjectName(QString::fromUtf8("editRedoAction"));
        editRedoAction->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("image6"), QSize(), QIcon::Normal, QIcon::Off);
        editRedoAction->setIcon(icon5);
        editRedoAction->setProperty("name", QVariant(QByteArray("editRedoAction")));
        editCutAction = new QAction(HyperArt);
        editCutAction->setObjectName(QString::fromUtf8("editCutAction"));
        editCutAction->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("image7"), QSize(), QIcon::Normal, QIcon::Off);
        editCutAction->setIcon(icon6);
        editCutAction->setProperty("name", QVariant(QByteArray("editCutAction")));
        editCopyAction = new QAction(HyperArt);
        editCopyAction->setObjectName(QString::fromUtf8("editCopyAction"));
        editCopyAction->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("image8"), QSize(), QIcon::Normal, QIcon::Off);
        editCopyAction->setIcon(icon7);
        editCopyAction->setProperty("name", QVariant(QByteArray("editCopyAction")));
        editPasteAction = new QAction(HyperArt);
        editPasteAction->setObjectName(QString::fromUtf8("editPasteAction"));
        editPasteAction->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("image9"), QSize(), QIcon::Normal, QIcon::Off);
        editPasteAction->setIcon(icon8);
        editPasteAction->setProperty("name", QVariant(QByteArray("editPasteAction")));
        editFindAction = new QAction(HyperArt);
        editFindAction->setObjectName(QString::fromUtf8("editFindAction"));
        editFindAction->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("image10"), QSize(), QIcon::Normal, QIcon::Off);
        editFindAction->setIcon(icon9);
        editFindAction->setProperty("name", QVariant(QByteArray("editFindAction")));
        helpContentsAction = new QAction(HyperArt);
        helpContentsAction->setObjectName(QString::fromUtf8("helpContentsAction"));
        helpContentsAction->setEnabled(false);
        helpContentsAction->setProperty("name", QVariant(QByteArray("helpContentsAction")));
        helpIndexAction = new QAction(HyperArt);
        helpIndexAction->setObjectName(QString::fromUtf8("helpIndexAction"));
        helpIndexAction->setEnabled(false);
        helpIndexAction->setProperty("name", QVariant(QByteArray("helpIndexAction")));
        helpAboutAction = new QAction(HyperArt);
        helpAboutAction->setObjectName(QString::fromUtf8("helpAboutAction"));
        helpAboutAction->setProperty("name", QVariant(QByteArray("helpAboutAction")));
        animatePlayAction = new QAction(HyperArt);
        animatePlayAction->setObjectName(QString::fromUtf8("animatePlayAction"));
        animatePlayAction->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("anim-play.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        animatePlayAction->setIcon(icon10);
        animatePlayAction->setProperty("name", QVariant(QByteArray("animatePlayAction")));
        animatePauseAction = new QAction(HyperArt);
        animatePauseAction->setObjectName(QString::fromUtf8("animatePauseAction"));
        animatePauseAction->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("anim-pause.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        animatePauseAction->setIcon(icon11);
        animatePauseAction->setProperty("name", QVariant(QByteArray("animatePauseAction")));
        animateStopAction = new QAction(HyperArt);
        animateStopAction->setObjectName(QString::fromUtf8("animateStopAction"));
        animateStopAction->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("anim-stop.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        animateStopAction->setIcon(icon12);
        animateStopAction->setProperty("name", QVariant(QByteArray("animateStopAction")));
        animatePrevAction = new QAction(HyperArt);
        animatePrevAction->setObjectName(QString::fromUtf8("animatePrevAction"));
        animatePrevAction->setEnabled(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("anim-prev.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        animatePrevAction->setIcon(icon13);
        animatePrevAction->setProperty("name", QVariant(QByteArray("animatePrevAction")));
        animateNextAction = new QAction(HyperArt);
        animateNextAction->setObjectName(QString::fromUtf8("animateNextAction"));
        animateNextAction->setEnabled(false);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("anim-next.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        animateNextAction->setIcon(icon14);
        animateNextAction->setProperty("name", QVariant(QByteArray("animateNextAction")));
        zoomZoom_InAction = new QAction(HyperArt);
        zoomZoom_InAction->setObjectName(QString::fromUtf8("zoomZoom_InAction"));
        zoomZoom_InAction->setEnabled(false);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("zoom-in.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        zoomZoom_InAction->setIcon(icon15);
        zoomZoom_InAction->setProperty("name", QVariant(QByteArray("zoomZoom_InAction")));
        zoomZoom_outAction = new QAction(HyperArt);
        zoomZoom_outAction->setObjectName(QString::fromUtf8("zoomZoom_outAction"));
        zoomZoom_outAction->setEnabled(false);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("zoom-out.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        zoomZoom_outAction->setIcon(icon16);
        zoomZoom_outAction->setProperty("name", QVariant(QByteArray("zoomZoom_outAction")));
        zoomDefaultAction = new QAction(HyperArt);
        zoomDefaultAction->setObjectName(QString::fromUtf8("zoomDefaultAction"));
        zoomDefaultAction->setEnabled(false);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8("zoom-default.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        zoomDefaultAction->setIcon(icon17);
        zoomDefaultAction->setProperty("name", QVariant(QByteArray("zoomDefaultAction")));
        viewToggle_FrameAction = new QAction(HyperArt);
        viewToggle_FrameAction->setObjectName(QString::fromUtf8("viewToggle_FrameAction"));
        viewToggle_FrameAction->setCheckable(true);
        viewToggle_FrameAction->setEnabled(false);
        viewToggle_FrameAction->setProperty("name", QVariant(QByteArray("viewToggle_FrameAction")));
        editPreferencesAction = new QAction(HyperArt);
        editPreferencesAction->setObjectName(QString::fromUtf8("editPreferencesAction"));
        editPreferencesAction->setProperty("name", QVariant(QByteArray("editPreferencesAction")));
        editPreferencesNumber_of_LayersAction = new QAction(HyperArt);
        editPreferencesNumber_of_LayersAction->setObjectName(QString::fromUtf8("editPreferencesNumber_of_LayersAction"));
        editPreferencesNumber_of_LayersAction->setEnabled(false);
        editPreferencesNumber_of_LayersAction->setProperty("name", QVariant(QByteArray("editPreferencesNumber_of_LayersAction")));
        widget = new QWidget(HyperArt);
        widget->setObjectName(QString::fromUtf8("widget"));
        HyperArt->setCentralWidget(widget);
        Toolbar = new QToolBar(HyperArt);
        Toolbar->setObjectName(QString::fromUtf8("Toolbar"));
        HyperArt->addToolBar(Qt::TopToolBarArea, Toolbar);
        ZoomToolbar = new QToolBar(HyperArt);
        ZoomToolbar->setObjectName(QString::fromUtf8("ZoomToolbar"));
        HyperArt->addToolBar(Qt::TopToolBarArea, ZoomToolbar);
        AnimateToolbar = new QToolBar(HyperArt);
        AnimateToolbar->setObjectName(QString::fromUtf8("AnimateToolbar"));
        HyperArt->addToolBar(Qt::TopToolBarArea, AnimateToolbar);
        menubar = new QMenuBar(HyperArt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 754, 27));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        Edit = new QMenu(menubar);
        Edit->setObjectName(QString::fromUtf8("Edit"));
        popupMenu_10 = new QMenu(Edit);
        popupMenu_10->setObjectName(QString::fromUtf8("popupMenu_10"));
        View = new QMenu(menubar);
        View->setObjectName(QString::fromUtf8("View"));
        Zoom = new QMenu(menubar);
        Zoom->setObjectName(QString::fromUtf8("Zoom"));
        Animate = new QMenu(menubar);
        Animate->setObjectName(QString::fromUtf8("Animate"));
        helpMenu = new QMenu(menubar);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        HyperArt->setMenuBar(menubar);

        Toolbar->addAction(fileNewAction);
        Toolbar->addAction(fileOpenAction);
        Toolbar->addAction(filePrintAction);
        ZoomToolbar->addAction(zoomDefaultAction);
        ZoomToolbar->addAction(zoomZoom_InAction);
        ZoomToolbar->addAction(zoomZoom_outAction);
        AnimateToolbar->addAction(animatePlayAction);
        AnimateToolbar->addAction(animatePauseAction);
        AnimateToolbar->addAction(animateStopAction);
        AnimateToolbar->addAction(animatePrevAction);
        AnimateToolbar->addAction(animateNextAction);
        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(Edit->menuAction());
        menubar->addAction(View->menuAction());
        menubar->addAction(Zoom->menuAction());
        menubar->addAction(Animate->menuAction());
        menubar->addAction(helpMenu->menuAction());
        fileMenu->addAction(fileNewAction);
        fileMenu->addAction(fileOpenAction);
        fileMenu->addAction(fileSaveAction);
        fileMenu->addAction(fileSaveAsAction);
        fileMenu->addSeparator();
        fileMenu->addAction(filePrintAction);
        fileMenu->addSeparator();
        fileMenu->addAction(fileExitAction);
        Edit->addSeparator();
        Edit->addAction(editPreferencesAction);
        Edit->addAction(popupMenu_10->menuAction());
        Edit->addSeparator();
        Edit->addAction(editUndoAction);
        Edit->addAction(editRedoAction);
        Edit->addSeparator();
        Edit->addAction(editCutAction);
        Edit->addAction(editCopyAction);
        Edit->addAction(editPasteAction);
        Edit->addSeparator();
        Edit->addAction(editFindAction);
        Edit->addSeparator();
        popupMenu_10->addAction(editPreferencesNumber_of_LayersAction);
        View->addAction(viewToggle_FrameAction);
        Zoom->addAction(zoomZoom_InAction);
        Zoom->addAction(zoomZoom_outAction);
        Zoom->addAction(zoomDefaultAction);
        Animate->addAction(animatePlayAction);
        Animate->addAction(animatePauseAction);
        Animate->addAction(animateStopAction);
        Animate->addAction(animatePrevAction);
        Animate->addAction(animateNextAction);
        helpMenu->addAction(helpContentsAction);
        helpMenu->addAction(helpIndexAction);
        helpMenu->addSeparator();
        helpMenu->addAction(helpAboutAction);

        retranslateUi(HyperArt);
        QObject::connect(fileNewAction, SIGNAL(triggered()), HyperArt, SLOT(fileNew()));
        QObject::connect(fileOpenAction, SIGNAL(triggered()), HyperArt, SLOT(fileOpen()));
        QObject::connect(fileSaveAction, SIGNAL(triggered()), HyperArt, SLOT(fileSave()));
        QObject::connect(fileSaveAsAction, SIGNAL(triggered()), HyperArt, SLOT(fileSaveAs()));
        QObject::connect(filePrintAction, SIGNAL(triggered()), HyperArt, SLOT(filePrint()));
        QObject::connect(fileExitAction, SIGNAL(triggered()), HyperArt, SLOT(fileExit()));
        QObject::connect(editUndoAction, SIGNAL(triggered()), HyperArt, SLOT(editUndo()));
        QObject::connect(editRedoAction, SIGNAL(triggered()), HyperArt, SLOT(editRedo()));
        QObject::connect(editCutAction, SIGNAL(triggered()), HyperArt, SLOT(editCut()));
        QObject::connect(editCopyAction, SIGNAL(triggered()), HyperArt, SLOT(editCopy()));
        QObject::connect(editPasteAction, SIGNAL(triggered()), HyperArt, SLOT(editPaste()));
        QObject::connect(editFindAction, SIGNAL(triggered()), HyperArt, SLOT(editFind()));
        QObject::connect(helpIndexAction, SIGNAL(triggered()), HyperArt, SLOT(helpIndex()));
        QObject::connect(helpContentsAction, SIGNAL(triggered()), HyperArt, SLOT(helpContents()));
        QObject::connect(helpAboutAction, SIGNAL(triggered()), HyperArt, SLOT(helpAbout()));
        QObject::connect(animatePlayAction, SIGNAL(triggered()), HyperArt, SLOT(animatePlay()));
        QObject::connect(animatePauseAction, SIGNAL(triggered()), HyperArt, SLOT(animatePause()));
        QObject::connect(animateStopAction, SIGNAL(triggered()), HyperArt, SLOT(animateStop()));
        QObject::connect(animateNextAction, SIGNAL(triggered()), HyperArt, SLOT(animateNext()));
        QObject::connect(animatePrevAction, SIGNAL(triggered()), HyperArt, SLOT(animatePrev()));
        QObject::connect(viewToggle_FrameAction, SIGNAL(toggled(bool)), HyperArt, SLOT(viewToggle_FrameAction_toggled(bool)));
        QObject::connect(zoomDefaultAction, SIGNAL(triggered()), HyperArt, SLOT(zoomDefaultAction_activated()));
        QObject::connect(zoomZoom_InAction, SIGNAL(triggered()), HyperArt, SLOT(zoomZoom_InAction_activated()));
        QObject::connect(zoomZoom_outAction, SIGNAL(triggered()), HyperArt, SLOT(zoomZoom_outAction_activated()));
        QObject::connect(editPreferencesNumber_of_LayersAction, SIGNAL(triggered()), HyperArt, SLOT(editPreferencesNumber_of_LayersAction_activated()));

        QMetaObject::connectSlotsByName(HyperArt);
    } // setupUi

    void retranslateUi(QMainWindow *HyperArt)
    {
        HyperArt->setWindowTitle(QApplication::translate("HyperArt", "HyperArt", nullptr));
        fileNewAction->setText(QApplication::translate("HyperArt", "&New", nullptr));
        fileNewAction->setIconText(QApplication::translate("HyperArt", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        fileNewAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        fileOpenAction->setText(QApplication::translate("HyperArt", "&Open...", nullptr));
        fileOpenAction->setIconText(QApplication::translate("HyperArt", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        fileOpenAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        fileSaveAction->setText(QApplication::translate("HyperArt", "&Save", nullptr));
        fileSaveAction->setIconText(QApplication::translate("HyperArt", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        fileSaveAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        fileSaveAsAction->setText(QApplication::translate("HyperArt", "Save &As...", nullptr));
        fileSaveAsAction->setIconText(QApplication::translate("HyperArt", "Save As", nullptr));
#ifndef QT_NO_SHORTCUT
        fileSaveAsAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        filePrintAction->setText(QApplication::translate("HyperArt", "&Print...", nullptr));
        filePrintAction->setIconText(QApplication::translate("HyperArt", "Print", nullptr));
#ifndef QT_NO_SHORTCUT
        filePrintAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        fileExitAction->setText(QApplication::translate("HyperArt", "E&xit", nullptr));
        fileExitAction->setIconText(QApplication::translate("HyperArt", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        fileExitAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        editUndoAction->setText(QApplication::translate("HyperArt", "&Undo", nullptr));
        editUndoAction->setIconText(QApplication::translate("HyperArt", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        editUndoAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        editRedoAction->setText(QApplication::translate("HyperArt", "&Redo", nullptr));
        editRedoAction->setIconText(QApplication::translate("HyperArt", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        editRedoAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        editCutAction->setText(QApplication::translate("HyperArt", "&Cut", nullptr));
        editCutAction->setIconText(QApplication::translate("HyperArt", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        editCutAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        editCopyAction->setText(QApplication::translate("HyperArt", "C&opy", nullptr));
        editCopyAction->setIconText(QApplication::translate("HyperArt", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        editCopyAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        editPasteAction->setText(QApplication::translate("HyperArt", "&Paste", nullptr));
        editPasteAction->setIconText(QApplication::translate("HyperArt", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        editPasteAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        editFindAction->setText(QApplication::translate("HyperArt", "&Find...", nullptr));
        editFindAction->setIconText(QApplication::translate("HyperArt", "Find", nullptr));
#ifndef QT_NO_SHORTCUT
        editFindAction->setShortcut(QApplication::translate("HyperArt", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        helpContentsAction->setText(QApplication::translate("HyperArt", "&Contents...", nullptr));
        helpContentsAction->setIconText(QApplication::translate("HyperArt", "Contents", nullptr));
#ifndef QT_NO_SHORTCUT
        helpContentsAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        helpIndexAction->setText(QApplication::translate("HyperArt", "&Index...", nullptr));
        helpIndexAction->setIconText(QApplication::translate("HyperArt", "Index", nullptr));
#ifndef QT_NO_SHORTCUT
        helpIndexAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        helpAboutAction->setText(QApplication::translate("HyperArt", "&About", nullptr));
        helpAboutAction->setIconText(QApplication::translate("HyperArt", "About", nullptr));
#ifndef QT_NO_SHORTCUT
        helpAboutAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        animatePlayAction->setText(QApplication::translate("HyperArt", "&Play", nullptr));
        animatePlayAction->setIconText(QApplication::translate("HyperArt", "Play", nullptr));
#ifndef QT_NO_SHORTCUT
        animatePlayAction->setShortcut(QApplication::translate("HyperArt", "X", nullptr));
#endif // QT_NO_SHORTCUT
        animatePauseAction->setText(QApplication::translate("HyperArt", "P&ause", nullptr));
        animatePauseAction->setIconText(QApplication::translate("HyperArt", "Pause", nullptr));
#ifndef QT_NO_SHORTCUT
        animatePauseAction->setShortcut(QApplication::translate("HyperArt", "C", nullptr));
#endif // QT_NO_SHORTCUT
        animateStopAction->setText(QApplication::translate("HyperArt", "&Stop", nullptr));
        animateStopAction->setIconText(QApplication::translate("HyperArt", "Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        animateStopAction->setShortcut(QApplication::translate("HyperArt", "V", nullptr));
#endif // QT_NO_SHORTCUT
        animatePrevAction->setText(QApplication::translate("HyperArt", "&Back step", nullptr));
        animatePrevAction->setIconText(QApplication::translate("HyperArt", "Back step", nullptr));
#ifndef QT_NO_SHORTCUT
        animatePrevAction->setShortcut(QApplication::translate("HyperArt", "B", nullptr));
#endif // QT_NO_SHORTCUT
        animateNextAction->setText(QApplication::translate("HyperArt", "&Next step", nullptr));
        animateNextAction->setIconText(QApplication::translate("HyperArt", "Next step", nullptr));
#ifndef QT_NO_SHORTCUT
        animateNextAction->setShortcut(QApplication::translate("HyperArt", "N", nullptr));
#endif // QT_NO_SHORTCUT
        zoomZoom_InAction->setText(QApplication::translate("HyperArt", "Zoom &In", nullptr));
        zoomZoom_InAction->setIconText(QApplication::translate("HyperArt", "Zoom In", nullptr));
#ifndef QT_NO_SHORTCUT
        zoomZoom_InAction->setShortcut(QApplication::translate("HyperArt", "=", nullptr));
#endif // QT_NO_SHORTCUT
        zoomZoom_outAction->setText(QApplication::translate("HyperArt", "Zoom &out", nullptr));
        zoomZoom_outAction->setIconText(QApplication::translate("HyperArt", "Zoom out", nullptr));
#ifndef QT_NO_SHORTCUT
        zoomZoom_outAction->setShortcut(QApplication::translate("HyperArt", "-", nullptr));
#endif // QT_NO_SHORTCUT
        zoomDefaultAction->setText(QApplication::translate("HyperArt", "&Default", nullptr));
        zoomDefaultAction->setIconText(QApplication::translate("HyperArt", "Default", nullptr));
#ifndef QT_NO_SHORTCUT
        zoomDefaultAction->setShortcut(QApplication::translate("HyperArt", "0", nullptr));
#endif // QT_NO_SHORTCUT
        viewToggle_FrameAction->setText(QApplication::translate("HyperArt", "&Frame", nullptr));
        viewToggle_FrameAction->setIconText(QApplication::translate("HyperArt", "Frame", nullptr));
#ifndef QT_NO_SHORTCUT
        viewToggle_FrameAction->setShortcut(QApplication::translate("HyperArt", "F", nullptr));
#endif // QT_NO_SHORTCUT
        editPreferencesAction->setText(QApplication::translate("HyperArt", "&Preferences", nullptr));
        editPreferencesAction->setIconText(QApplication::translate("HyperArt", "Preferences", nullptr));
        editPreferencesNumber_of_LayersAction->setText(QApplication::translate("HyperArt", "&Number of Layers", nullptr));
        editPreferencesNumber_of_LayersAction->setIconText(QApplication::translate("HyperArt", "Number of Layers", nullptr));
#ifndef QT_NO_SHORTCUT
        editPreferencesNumber_of_LayersAction->setShortcut(QApplication::translate("HyperArt", "L", nullptr));
#endif // QT_NO_SHORTCUT
        Toolbar->setProperty("label", QVariant(QApplication::translate("HyperArt", "File Tools", nullptr)));
        ZoomToolbar->setProperty("label", QVariant(QApplication::translate("HyperArt", "Zoom Tools", nullptr)));
        AnimateToolbar->setProperty("label", QVariant(QApplication::translate("HyperArt", "Animation Tools", nullptr)));
        fileMenu->setTitle(QApplication::translate("HyperArt", "&File", nullptr));
        Edit->setTitle(QApplication::translate("HyperArt", "&Edit", nullptr));
        popupMenu_10->setTitle(QApplication::translate("HyperArt", "&Preferences", nullptr));
        View->setTitle(QApplication::translate("HyperArt", "&View", nullptr));
        Zoom->setTitle(QApplication::translate("HyperArt", "&Zoom", nullptr));
        Animate->setTitle(QApplication::translate("HyperArt", "&Animate", nullptr));
        helpMenu->setTitle(QApplication::translate("HyperArt", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HyperArt: public Ui_HyperArt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYPERART_H
