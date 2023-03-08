#include <QtWidgets>

#include "classwizard.h"

ClassWizard::ClassWizard(QWidget *parent)
    : QWizard(parent)
{
    addPage(new IntroPage);
    addPage(new LookAndFeelPage);
    addPage(new WorkbenchesPage);
    addPage(new ConclusionPage);

    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner_big.png"));
    setPixmap(QWizard::BackgroundPixmap, QPixmap(""));

    setWindowTitle(tr("Freecad Getting started"));
}

IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    setPixmap(QWizard::LogoPixmap, QPixmap(""));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner_big.png"));
    setTitle(tr(" "));
    setSubTitle(tr(" "));
    label = new QLabel(tr("Press next to start your configuration process!"));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

LookAndFeelPage::LookAndFeelPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Look and Feel"));
   //* ClassWizard::setTitleFormat(BOLD_FONTTYPE)
    setSubTitle(tr("Set the look and feel of freecad"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/icon-freecad.png"));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));

    langLabel = new QLabel(tr("Select Language:"));
    selectlangcom = new QComboBox();
    selectlangcom->addItem("Auto");
    selectlangcom->addItem("Dutch");
    selectlangcom->addItem("English");
    selectlangcom ->setCurrentIndex(2);

    languageBox = new QGroupBox(tr("Language"));

    setUnitLabel = new QLabel(tr("Select Units:"));
    selectUnitcom = new QComboBox();
    selectUnitcom ->addItem("mm/g/s");
    selectUnitcom ->addItem("mm/kg/s");
    selectUnitcom ->addItem("In/Pound/s");
    selectUnitcom ->addItem("m/kg/h");
    selectUnitcom ->setCurrentIndex(0);

    unitsBox = new QGroupBox(tr("Units"));

    setthemeLabel = new QLabel(tr("Select theme mode"));
    selectthemecom = new QComboBox();
    selectthemecom ->addItem("System");
    selectthemecom ->addItem("Dark");
    selectthemecom ->addItem("Light");
    selectthemecom ->setCurrentIndex(0);

    setHighlights = new QLabel(tr("Select Highlight"));
    selectHighlightsCom = new QComboBox();
    selectHighlightsCom ->addItem("Blue");
    selectHighlightsCom ->addItem("Red");
    selectHighlightsCom ->addItem("Pink");
    selectHighlightsCom ->setCurrentIndex(0);

    setIconSize = new QLabel(tr("Select Icon size"));
    selectIconsSizeCom = new QComboBox();
    selectIconsSizeCom->addItem("Small");
    selectIconsSizeCom->addItem("Medium");
    selectIconsSizeCom->addItem("Big");
    selectIconsSizeCom ->setCurrentIndex(1);

    ThemeAndStyleBox = new QGroupBox(tr("Themes and Styles"));

    setNavigationStyle = new QLabel(tr("Select Navigation Style"));
    selectNavigationStyleCom = new QComboBox();
    selectNavigationStyleCom->addItem("CAD");
    selectNavigationStyleCom->addItem("Blender");
    selectNavigationStyleCom->addItem("Inventor");
    selectNavigationStyleCom ->setCurrentIndex(1);

    NavigationStyleBox = new QGroupBox(tr("Navigation"));

    QGridLayout *NavigationStyleBoxLayout = new QGridLayout;
    NavigationStyleBoxLayout->addWidget(setNavigationStyle, 0, 0);
    NavigationStyleBoxLayout->addWidget(selectNavigationStyleCom, 0, 1);
    NavigationStyleBox->setLayout(NavigationStyleBoxLayout);

    QGridLayout *languageBoxLayout = new QGridLayout;
    languageBoxLayout->addWidget(selectlangcom, 0, 1);
    languageBoxLayout->addWidget(langLabel, 0, 0);
    languageBox->setLayout(languageBoxLayout);

    QGridLayout *unitsBoxLayout = new QGridLayout;
    unitsBoxLayout->addWidget(selectUnitcom, 0, 1);
    unitsBoxLayout->addWidget(setUnitLabel, 0, 0);
    unitsBox->setLayout(unitsBoxLayout);

    QGridLayout *ThemeAndStyleBoxLayout = new QGridLayout;
    ThemeAndStyleBoxLayout->addWidget(selectthemecom, 0, 1);
    ThemeAndStyleBoxLayout->addWidget(setthemeLabel, 0, 0);
    ThemeAndStyleBoxLayout->addWidget(selectHighlightsCom, 1, 1);
    ThemeAndStyleBoxLayout->addWidget(setHighlights, 1, 0);
    ThemeAndStyleBoxLayout->addWidget(selectIconsSizeCom, 2, 1);
    ThemeAndStyleBoxLayout->addWidget(setIconSize, 2, 0);
    ThemeAndStyleBox->setLayout(ThemeAndStyleBoxLayout);

    QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(languageBox);
        layout->addWidget(unitsBox);
        layout->addWidget(NavigationStyleBox);
        layout->addWidget(ThemeAndStyleBox);

    setLayout(layout);
}

WorkbenchesPage::WorkbenchesPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Select the workbenches you need."));
    setSubTitle(tr("Choose the formatting of the generated code."));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/icon-freecad.png"));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
    workbenchexplain = new QLabel(tr("Please select the workbenches you want to use:"));
    createListWidget();
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(workbenchexplain);
    layout->addWidget(workbenchlist);
    setLayout(layout);
}

void WorkbenchesPage::createListWidget(){
    workbenchlist = new QListWidget;
    QStringList strList;
    strList << "PartDesign" << "Part" << "A2 plus" << "Assembly3"
            << "Assembly4" << "FEM" << "Draft" << "Lattice2" << "Path";

    workbenchlist->addItems(strList);

    QListWidgetItem* item = 0;
    for(int i = 0; i < workbenchlist->count(); ++i){
        item = workbenchlist->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

ConclusionPage::ConclusionPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("You are ready to go"));
    setSubTitle(tr("Press exit to exit the wizard and start using Freecad"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/icon-freecad.png"));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));

    label = new QLabel;
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

void ConclusionPage::initializePage()
{
    QString finishText = wizard()->buttonText(QWizard::FinishButton);
    finishText.remove('&');
    label->setText(tr("Click %1 to exit the wizard")
                   .arg(finishText));
}
