#include "hyperart.h"

#include <qvariant.h>
#include "hyperart.ui.h"
/*
 *  Constructs a HyperArt as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
HyperArt::HyperArt(QWidget *parent, const char *name, Qt::WindowFlags fl)
    : QMainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
HyperArt::~HyperArt()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void HyperArt::languageChange()
{
    retranslateUi(this);
}
