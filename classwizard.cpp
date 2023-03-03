/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QtWidgets>

#include "classwizard.h"

//! [0] //! [1]
ClassWizard::ClassWizard(QWidget *parent)
    : QWizard(parent)
{
    addPage(new IntroPage);
    addPage(new LookAndFeelPage);
    addPage(new WorkbenchesPage);
//    addPage(new OutputFilesPage);
    addPage(new ConclusionPage);
//! [0]

    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
    setPixmap(QWizard::BackgroundPixmap, QPixmap(":/images/background.png"));

    setWindowTitle(tr("Freecad Wizard"));
//! [2]
}
//! [1] //! [2]

////! [3]
//void ClassWizard::accept()
////! [3] //! [4]
//{
//    QByteArray className = field("className").toByteArray();
//    QByteArray baseClass = field("baseClass").toByteArray();
//    QByteArray macroName = field("macroName").toByteArray();
//    QByteArray baseInclude = field("baseInclude").toByteArray();

//    QString outputDir = field("outputDir").toString();
//    QString header = field("header").toString();
//    QString implementation = field("implementation").toString();
////! [4]

//    QByteArray block;

//    if (field("comment").toBool()) {
//        block += "/*\n";
//        block += "    " + header.toLatin1() + "\n";
//        block += "*/\n";
//        block += "\n";
//    }
//    if (field("protect").toBool()) {
//        block += "#ifndef " + macroName + "\n";
//        block += "#define " + macroName + "\n";
//        block += "\n";
//    }
//    if (field("includeBase").toBool()) {
//        block += "#include " + baseInclude + "\n";
//        block += "\n";
//    }

//    block += "class " + className;
//    if (!baseClass.isEmpty())
//        block += " : public " + baseClass;
//    block += "\n";
//    block += "{\n";

//    /* qmake ignore Q_OBJECT */

//    if (field("qobjectMacro").toBool()) {
//        block += "    Q_OBJECT\n";
//        block += "\n";
//    }
//    block += "public:\n";

//    if (field("qobjectCtor").toBool()) {
//        block += "    " + className + "(QObject *parent = 0);\n";
//    } else if (field("qwidgetCtor").toBool()) {
//        block += "    " + className + "(QWidget *parent = 0);\n";
//    } else if (field("defaultCtor").toBool()) {
//        block += "    " + className + "();\n";
//        if (field("copyCtor").toBool()) {
//            block += "    " + className + "(const " + className + " &other);\n";
//            block += "\n";
//            block += "    " + className + " &operator=" + "(const " + className
//                     + " &other);\n";
//        }
//    }
//    block += "};\n";

//    if (field("protect").toBool()) {
//        block += "\n";
//        block += "#endif\n";
//    }

//    QFile headerFile(outputDir + "/" + header);
//    if (!headerFile.open(QFile::WriteOnly | QFile::Text)) {
//        QMessageBox::warning(0, QObject::tr("Simple Wizard"),
//                             QObject::tr("Cannot write file %1:\n%2")
//                             .arg(headerFile.fileName())
//                             .arg(headerFile.errorString()));
//        return;
//    }
//    headerFile.write(block);

//    block.clear();

//    if (field("comment").toBool()) {
//        block += "/*\n";
//        block += "    " + implementation.toLatin1() + "\n";
//        block += "*/\n";
//        block += "\n";
//    }
//    block += "#include \"" + header.toLatin1() + "\"\n";
//    block += "\n";

//    if (field("qobjectCtor").toBool()) {
//        block += className + "::" + className + "(QObject *parent)\n";
//        block += "    : " + baseClass + "(parent)\n";
//        block += "{\n";
//        block += "}\n";
//    } else if (field("qwidgetCtor").toBool()) {
//        block += className + "::" + className + "(QWidget *parent)\n";
//        block += "    : " + baseClass + "(parent)\n";
//        block += "{\n";
//        block += "}\n";
//    } else if (field("defaultCtor").toBool()) {
//        block += className + "::" + className + "()\n";
//        block += "{\n";
//        block += "    // missing code\n";
//        block += "}\n";

//        if (field("copyCtor").toBool()) {
//            block += "\n";
//            block += className + "::" + className + "(const " + className
//                     + " &other)\n";
//            block += "{\n";
//            block += "    *this = other;\n";
//            block += "}\n";
//            block += "\n";
//            block += className + " &" + className + "::operator=(const "
//                     + className + " &other)\n";
//            block += "{\n";
//            if (!baseClass.isEmpty())
//                block += "    " + baseClass + "::operator=(other);\n";
//            block += "    // missing code\n";
//            block += "    return *this;\n";
//            block += "}\n";
//        }
//    }

//    QFile implementationFile(outputDir + "/" + implementation);
//    if (!implementationFile.open(QFile::WriteOnly | QFile::Text)) {
//        QMessageBox::warning(0, QObject::tr("Simple Wizard"),
//                             QObject::tr("Cannot write file %1:\n%2")
//                             .arg(implementationFile.fileName())
//                             .arg(implementationFile.errorString()));
//        return;
//    }
//    implementationFile.write(block);

////! [5]
//    QDialog::accept();
////! [5] //! [6]
//}
//! [6]

//! [7]
IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    setPixmap(QWizard::LogoPixmap, QPixmap(" "));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/watermark1.png"));
    setTitle(tr(" "));
    setSubTitle(tr(" "));
    label = new QLabel(tr("Press next to start your configuration process!"));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}
//! [7]

//! [8] //! [9]
LookAndFeelPage::LookAndFeelPage(QWidget *parent)
    : QWizardPage(parent)
{
//! [8]
    setTitle(tr("Look and Feel"));
    setSubTitle(tr("Set the look and feel of freecad"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));


//! [10]
    //classNameLabel = new QLabel(tr("&Select Language:"));
   // classNameLineEdit = new QLineEdit;
   // classNameLabel->setBuddy(classNameLineEdit);
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

//! [9]

    QGridLayout *NavigationStyleBoxLayout = new QGridLayout;
//! [12]
    NavigationStyleBoxLayout->addWidget(setNavigationStyle, 0, 0);
    NavigationStyleBoxLayout->addWidget(selectNavigationStyleCom, 0, 1);
    NavigationStyleBox->setLayout(NavigationStyleBoxLayout);

    QGridLayout *languageBoxLayout = new QGridLayout;
//! [12]
    languageBoxLayout->addWidget(selectlangcom, 0, 1);
    languageBoxLayout->addWidget(langLabel, 0, 0);
    languageBox->setLayout(languageBoxLayout);

    QGridLayout *unitsBoxLayout = new QGridLayout;
//! [12]
    unitsBoxLayout->addWidget(selectUnitcom, 0, 1);
    unitsBoxLayout->addWidget(setUnitLabel, 0, 0);
    unitsBox->setLayout(unitsBoxLayout);

    QGridLayout *ThemeAndStyleBoxLayout = new QGridLayout;
//! [12]
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
//! [13]
}
//! [13]

//! [14]
WorkbenchesPage::WorkbenchesPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Select the workbenches you need."));
    setSubTitle(tr("Choose the formatting of the generated code."));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));
    setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
    workbenchexplain = new QLabel(tr("Please select the workbenches you want to use:"));

    //workbenchlist= new QListWidget();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(workbenchexplain);
    //layout->setLayout(languageBoxLayout);
   //     layout->addWidget(languageBox);
    setLayout(layout);
}
//! [15]

//! [16]
//void WorkbenchesPage::initializePage()
//{
    //createListWidget();
    //QString className = field("className").toString();
   // macroNameLineEdit->setText(className.toUpper() + "_H");

   // QString baseClass = field("baseClass").toString();

   // includeBaseCheckBox->setChecked(!baseClass.isEmpty());
    //includeBaseCheckBox->setEnabled(!baseClass.isEmpty());
   // baseIncludeLabel->setEnabled(!baseClass.isEmpty());
   // baseIncludeLineEdit->setEnabled(!baseClass.isEmpty());

  //  if (baseClass.isEmpty()) {
  //      baseIncludeLineEdit->clear();
  //  } else {
  //      baseIncludeLineEdit->setText("\"" + baseClass.toLower() + ".h\"");
   // }
//}

void WorkbenchesPage::createListWidget(){
    workbenchlist = new QListWidget;
    QStringList strList;
    strList << "monitor" << "mouse" << "keyboard" << "hard disk drive"
            << "graphic card" << "sound card" << "memory" << "motherboard";

    workbenchlist->addItems(strList);

    QListWidgetItem* item = 0;
    for(int i = 0; i < workbenchlist->count(); ++i){
        item = workbenchlist->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

//! [16]

//OutputFilesPage::OutputFilesPage(QWidget *parent)
//    : QWizardPage(parent)
//{
//    setTitle(tr("first title"));
//    setSubTitle(tr("Specify where you want the wizard to put the generated "
//                   "skeleton code."));
//    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));

//    outputDirLabel = new QLabel(tr("&Output directory:"));
//    outputDirLineEdit = new QLineEdit;
//    outputDirLabel->setBuddy(outputDirLineEdit);

//    headerLabel = new QLabel(tr("&Header file name:"));
//    headerLineEdit = new QLineEdit;
//    headerLabel->setBuddy(headerLineEdit);

//    implementationLabel = new QLabel(tr("&Implementation file name:"));
//    implementationLineEdit = new QLineEdit;
//    implementationLabel->setBuddy(implementationLineEdit);

//    registerField("outputDir*", outputDirLineEdit);
//    registerField("header*", headerLineEdit);
//    registerField("implementation*", implementationLineEdit);

//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(outputDirLabel, 0, 0);
//    layout->addWidget(outputDirLineEdit, 0, 1);
//    layout->addWidget(headerLabel, 1, 0);
//    layout->addWidget(headerLineEdit, 1, 1);
//    layout->addWidget(implementationLabel, 2, 0);
//    layout->addWidget(implementationLineEdit, 2, 1);
//    setLayout(layout);
//}

//! [17]
//void OutputFilesPage::initializePage()
//{
//    QString className = field("className").toString();
//    headerLineEdit->setText(className.toLower() + ".h");
//    implementationLineEdit->setText(className.toLower() + ".cpp");
//    outputDirLineEdit->setText(QDir::toNativeSeparators(QDir::tempPath()));
//}
////! [17]

ConclusionPage::ConclusionPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("You are ready to go"));
    setSubTitle(tr("Press exit to exit the wizard and start using Freecad"));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));
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
