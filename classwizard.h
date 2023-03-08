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

class ClassWizard : public QWizard
{
    Q_OBJECT

public:
    ClassWizard(QWidget *parent = 0);
};

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

private:
    QLabel *label;
};

class LookAndFeelPage : public QWizardPage
{
    Q_OBJECT

public:
    LookAndFeelPage(QWidget *parent = 0);

private:
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

};
//! [2]

//! [3]
class WorkbenchesPage : public QWizardPage
{
    Q_OBJECT

public:
    WorkbenchesPage(QWidget *parent = 0);

public slots:

protected:
    void createListWidget();

private:
    QListWidget *workbenchlist;
    QLabel *workbenchexplain;

};


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
