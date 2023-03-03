#include <QtWidgets>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QWizard>
#include <QListWidget>
#include <QPixmap>
#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QMenu>
#include <QPushButton>
#include <QRadioButton>
#include <QApplication>


#include "classwizard.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(classwizard);
    
    QApplication app(argc, argv);

#ifndef QT_NO_TRANSLATION
    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);
#endif

    ClassWizard wizard;
    wizard.setWizardStyle(QWizard::WizardStyle::ModernStyle);
    wizard.show();
    return app.exec();
}
