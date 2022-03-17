#ifndef HYPERART_H
#define HYPERART_H

#include <qvariant.h>

class DiagramView;

#include <Qt3Support/QMainWindow>
#include <Qt3Support/QToolBar>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>
#include <QtGui/QInputDialog>
#include <QtGui/QMessageBox>
#include <QtGui/QPrinter>
#include "datareader.h"
#include "defs.h"
#include "diagram.h"
#include "diagramview.h"
#include "poincareview.h"
#include "regularpgon.h"
#include "ui_hyperart.h"
class HyperArt : public QMainWindow, public Ui::HyperArt
{
    Q_OBJECT

public:
    HyperArt(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = Qt::WType_TopLevel);
    ~HyperArt();

public slots:
    virtual void destroy();
    virtual void fileNew();
    virtual void fileOpen();
    virtual void fileSave();
    virtual void fileSaveAs();
    virtual void filePrint();
    virtual void fileExit();
    virtual void editUndo();
    virtual void editRedo();
    virtual void editCut();
    virtual void editCopy();
    virtual void editPaste();
    virtual void editFind();
    virtual void helpIndex();
    virtual void helpContents();
    virtual void helpAbout();
    virtual void init();
    virtual void animatePlay();
    virtual void animatePause();
    virtual void animateStop();
    virtual void animateNext();
    virtual void animatePrev();
    virtual void viewToggle_FrameAction_toggled( bool state );
    virtual void zoomDefaultAction_activated();
    virtual void zoomZoom_InAction_activated();
    virtual void zoomZoom_outAction_activated();
    virtual void toggleLayer( bool state );
    virtual void editPreferencesNumber_of_LayersAction_activated();

signals:
    void doAnimatePlay();
    void doAnimatePause();
    void doAnimateNext();
    void doAnimatePrev();
    void doAnimateStop();
    void doZoom(ZoomType);
    void doToggleFrame(bool);
    void doToggleLayer(int,bool);
    void doPanning(PanType);

protected:
    QString curFile;
    QAction* viewLayerAction;
    vector<QAction*> viewLayerActions;
    int numLayers;
    QPrinter* printer;
    Diagram* dgram;

    virtual void load( const QString & fileName );
    virtual DiagramView * resolveViewType( QWidget * view );
    virtual void keyPressEvent( QKeyEvent * e );

protected slots:
    virtual void languageChange();

};

#endif // HYPERART_H
