/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenu>
#include <QKeyEvent>
#include "hyperart.h"
#include "defs.h"

HyperArt::HyperArt(QWidget*, char const*, QFlags<Qt::WindowType>)
    : QMainWindow(0, Qt::Window)
{
    setupUi(this);
    init();
}

HyperArt::~HyperArt()
{
    destroy();
}

void HyperArt::destroy()
{
  delete printer;
}

void HyperArt::fileNew()
{
  HyperArt *ed = new HyperArt();
  ed->setWindowTitle(tr("HyperArt"));
  ed->show();
}

void HyperArt::fileOpen()
{
  QString fn = QFileDialog::getOpenFileName(this, QString::null,"./" "*.had");
  if (!fn.isEmpty())
    load(fn);
  else
    statusBar()->showMessage(tr("Loading aborted"), 2000);
}

void HyperArt::fileSave()
{
}

void HyperArt::fileSaveAs()
{
  QFileDialog *fd = new QFileDialog(this,"Save design as ...","./","Images (*.png *.jpg)"); // a modal file dialog
  fd->setModal(QFileDialog::AnyFile);                                    // allow new filename creation
  //fd->setFilter("Images (*.png *.jpg)");
  QFileInfo fi(curFile);
  QString saveName = fi.baseName() + ".jpg";
  fd->selectFile(saveName);
  if (fd->exec() == QDialog::Accepted)
  {
    saveName = fd->selectedFiles().at(0);
    DiagramView *view = resolveViewType(centralWidget());
    if (!view)
    {
      qWarning("HyperArt::load : invalid view object");
      return;
    }
    view->saveAs(saveName);
  }
}

void HyperArt::filePrint()
{
  // if (printer->begin(this))
  // { // printer dialog
  //   statusBar()->showMessage(tr("Printing..."));
  //   QPainter p(printer);

  //   DiagramView *view = resolveViewType(centralWidget());
  //   if (!view)
  //   {
  //     qWarning("HyperArt::load : invalid view object");
  //     return;
  //   }

  //   view->print(p);
  //   statusBar()->showMessage(tr("Printing completed"), 2000);
  // }
  // else
  // {
  //   statusBar()->showMessage(tr("Printing aborted"), 2000);
  // }
}

void HyperArt::fileExit()
{
  close();
}

void HyperArt::editUndo()
{
}

void HyperArt::editRedo()
{
}

void HyperArt::editCut()
{
}

void HyperArt::editCopy()
{
}

void HyperArt::editPaste()
{
}

void HyperArt::editFind()
{
}

void HyperArt::helpIndex()
{
}

void HyperArt::helpContents()
{
}

void HyperArt::helpAbout()
{
  QMessageBox::about(this, tr("Hyper by Ajit Datar"),
                     tr("Hyper lets you view and create repeating hyperbolic patterns"
                        "\nusing algorithms developed by Dr Douglas Dunham"));
}

void HyperArt::load(const QString &fileName)
{
  // determine type of document to be created and create it

  Diagram *d = DataReader::createDiagram(fileName);
  if (d)
  {
    delete dgram; // remove old
    DiagramView *view = resolveViewType(centralWidget());
    if (!view)
    {
      qWarning("HyperArt::load : invalid view object");
      return;
    }
    view->setDocument(d);
    d->setNumLayers(numLayers);
    d->updateAllViews();
    dgram = d;
    setWindowTitle(fileName);
    curFile = fileName;

    animatePlayAction->setEnabled(true);
    animatePauseAction->setEnabled(true);
    animateStopAction->setEnabled(true);
    animatePrevAction->setEnabled(true);
    animateNextAction->setEnabled(true);
    zoomDefaultAction->setEnabled(true);
    zoomZoom_InAction->setEnabled(true);
    zoomZoom_outAction->setEnabled(true);
    viewToggle_FrameAction->setEnabled(true);
    filePrintAction->setEnabled(true);
    fileSaveAsAction->setEnabled(true);

    editPreferencesNumber_of_LayersAction->setEnabled(true);
    for (int i = 0; i < 9; i++)
    {
      if (i < numLayers)
      {
        viewLayerActions[i]->setEnabled(true);
        viewLayerActions[i]->setEnabled(true);
      }
      else
      {
        viewLayerActions[i]->setEnabled(false);
        viewLayerActions[i]->setEnabled(false);
      }
    }

    statusBar()->showMessage(tr("Loaded document %1").arg(fileName), 2000);
  }
  else
  {
    delete d;
    statusBar()->showMessage(tr("Failed to load document %1").arg(fileName), 2000);
  }
}

void HyperArt::init()
{
  printer = new QPrinter;
  // by default show the poincare view
  //(currently the only one implemented)
  viewLayerAction = new QAction("viewLayerAction",this);

  QMenu *viewLayerPopupMenu = new QMenu(this);
  //View->addAction(viewLayerAction->iconSet(), tr("&Layer"), viewLayerPopupMenu);
  //View->addAction("&Layer", viewLayerPopupMenu);
  numLayers = 3;
  viewLayerActions.resize(9);
  for (int i = 0; i < 9; ++i)
  {
    QString layerId = QString::number(i + 1);
    QString text = "Toggle Layer " + layerId;
    QString menuText = "&" + layerId;

    QAction *layerAction = new QAction(menuText, this);
    layerAction->setText(text);
    layerAction->setEnabled(true);
    if (i < numLayers)
    {
      layerAction->setEnabled(true);
    }
    layerAction->setEnabled(false);
    QObject::connect(layerAction, SIGNAL(toggled(bool)), this, SLOT(toggleLayer(bool)));
    viewLayerPopupMenu->addAction(layerAction);
    viewLayerActions[i] = layerAction;
  }

  dgram = new RegularPgon();
  dgram->setNumLayers(numLayers);
  PoincareView *poincare = new PoincareView(this, "Poincare Disk View");
  poincare->setDocument(dgram);
  poincare->setFocus();
  setCentralWidget(poincare);
}

// ref: http://bioinformatics.org/pipermail/wcurve-devel/2002-September/000001.html
DiagramView *HyperArt::resolveViewType(QWidget *view)
{
  if(PoincareView *poincare = qobject_cast<PoincareView *>(view))
    return (DiagramView *)poincare;
  // else if(SomeOtherView* other = dynamic_cast<SomeOtherView*>(view))
  //     return (DiagramView*)other;
  else
    return 0;
}

void HyperArt::animatePlay()
{
  emit doAnimatePlay();
  animatePrevAction->setEnabled(false);
  animateNextAction->setEnabled(false);
  animateStopAction->setEnabled(true);
  animatePauseAction->setEnabled(true);
  animatePlayAction->setEnabled(false);
}

void HyperArt::animatePause()
{
  emit doAnimatePause();
  animatePrevAction->setEnabled(true);
  animateNextAction->setEnabled(true);
  animatePauseAction->setEnabled(false);
  animatePlayAction->setEnabled(true);
}

void HyperArt::animateStop()
{
  emit doAnimateStop();
  animatePrevAction->setEnabled(false);
  animateNextAction->setEnabled(false);
  animateStopAction->setEnabled(false);
  animatePauseAction->setEnabled(false);
  animatePlayAction->setEnabled(true);
}

void HyperArt::animateNext()
{
  emit doAnimateNext();
}

void HyperArt::animatePrev()
{
  emit doAnimatePrev();
}

void HyperArt::viewToggle_FrameAction_toggled(bool state)
{
  emit doToggleFrame(state);
}

void HyperArt::zoomDefaultAction_activated()
{
  emit doZoom(DEFAULT);
}

void HyperArt::zoomZoom_InAction_activated()
{
  emit doZoom(IN);
}

void HyperArt::zoomZoom_outAction_activated()
{
  emit doZoom(OUT);
}

void HyperArt::toggleLayer(bool state)
{
  QString text = ((QAction *)sender())->text();
  int layerNum = text.toInt();
  emit doToggleLayer(layerNum, state);
}

void HyperArt::editPreferencesNumber_of_LayersAction_activated()
{
  bool ok;
  int res = QInputDialog::getInt(this, tr("Number of layers"), tr("Enter how many layers to generate. \nPlease note that successful generation of 4 or more layers\ndepends on your system resources.\nThe value set here will be used for designs loaded from now on."), numLayers, 1, 9, 1, &ok);

  if (ok)
  {
    if (numLayers != res)
    {
      numLayers = res;
      DiagramView *view = resolveViewType(centralWidget());
      if (!view)
      {
        qWarning("HyperArt::load : invalid view object");
        return;
      }
      for (int i = 0; i < 9; i++)
      {
        if (i < numLayers)
        {
          viewLayerActions[i]->setEnabled(true);
          viewLayerActions[i]->setEnabled(true);
        }
        else
        {
          viewLayerActions[i]->setEnabled(false);
          viewLayerActions[i]->setEnabled(false);
        }
      }
      dgram->setNumLayers(numLayers);
      dgram->updateAllViews();
    }
  }
}

void HyperArt::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
  {
  case Qt::Key_Left:
    emit doPanning(PAN_LEFT);
    break;
  case Qt::Key_Right:
    emit doPanning(PAN_RIGHT);
    break;
  case Qt::Key_Up:
    emit doPanning(PAN_UP);
    break;
  case Qt::Key_Down:
    emit doPanning(PAN_DOWN);
    break;
  default:
    e->ignore();
  }
}
