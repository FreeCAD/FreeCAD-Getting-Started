#ifndef CLASSWIZARD_H
#define CLASSWIZARD_H

#include <QWizard>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QComboBox;
class QLabel;
class QLineEdit;
class QRadioButton;
class QListWidget;
QT_END_NAMESPACE

//! [0]
class ClassWizard : public QWizard
{
    Q_OBJECT

public:
    ClassWizard(QWidget *parent = 0);

    //void accept();
};
//! [0]

//! [1]
class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

private:
    QLabel *label;
};
//! [1]

//! [2]
class LookAndFeelPage : public QWizardPage
{
    Q_OBJECT

public:
    LookAndFeelPage(QWidget *parent = 0);

private:
    //QLabel *classNameLabel;
    QLabel *langLabel;
    QComboBox *selectlangcom;
    QGroupBox *languageBox;

    QLabel *setUnitLabel;
    QComboBox *selectUnitcom;
    QGroupBox *unitsBox;

    QLabel *setthemeLabel;
    QComboBox *selectthemecom;
    QLabel *setHighlights;
    QComboBox *selectHighlightsCom;
    QLabel *setIconSize;
    QComboBox *selectIconsSizeCom;
    QGroupBox *ThemeAndStyleBox;

    QLabel *setNavigationStyle;
    QComboBox *selectNavigationStyleCom;
    QGroupBox *NavigationStyleBox;

    //QLineEdit *classNameLineEdit;
    QLineEdit *baseClassLineEdit;
    QCheckBox *qobjectMacroCheckBox;
    QGroupBox *groupBox;
    QRadioButton *qobjectCtorRadioButton;
    QRadioButton *qwidgetCtorRadioButton;
    QRadioButton *defaultCtorRadioButton;
    QCheckBox *copyCtorCheckBox;
};
//! [2]

//! [3]
class WorkbenchesPage : public QWizardPage
{
    Q_OBJECT

public:
    WorkbenchesPage(QWidget *parent = 0);

public slots:
    //void highlightChecked(QListWidget* item);
//    void save();

protected:
    //void initializePage();
    void createListWidget();

private:
    QListWidget *workbenchlist;
    QLabel *workbenchexplain;

};
//! [3]

//class OutputFilesPage : public QWizardPage
//{
//    Q_OBJECT

//public:
//    OutputFilesPage(QWidget *parent = 0);

//protected:
//    void initializePage();

//private:
//    QLabel *outputDirLabel;
//    QLabel *headerLabel;
//    QLabel *implementationLabel;
//    QLineEdit *outputDirLineEdit;
//    QLineEdit *headerLineEdit;
//    QLineEdit *implementationLineEdit;
//};

class ConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    ConclusionPage(QWidget *parent = 0);

protected:
    void initializePage();

private:
    QLabel *label;
};

#endif
