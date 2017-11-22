/********************************************************************************
** Form generated from reading ui file 'visualize_try_2.ui'
**
** Created: Mon Nov 20 19:10:10 2017
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VISUALIZE_TRY_2_H
#define UI_VISUALIZE_TRY_2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visualize_try_2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *visualize_try_2Class)
    {
    if (visualize_try_2Class->objectName().isEmpty())
        visualize_try_2Class->setObjectName(QString::fromUtf8("visualize_try_2Class"));
    visualize_try_2Class->resize(600, 400);
    menuBar = new QMenuBar(visualize_try_2Class);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    visualize_try_2Class->setMenuBar(menuBar);
    mainToolBar = new QToolBar(visualize_try_2Class);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    visualize_try_2Class->addToolBar(mainToolBar);
    centralWidget = new QWidget(visualize_try_2Class);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    visualize_try_2Class->setCentralWidget(centralWidget);
    statusBar = new QStatusBar(visualize_try_2Class);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    visualize_try_2Class->setStatusBar(statusBar);

    retranslateUi(visualize_try_2Class);

    QMetaObject::connectSlotsByName(visualize_try_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *visualize_try_2Class)
    {
    visualize_try_2Class->setWindowTitle(QApplication::translate("visualize_try_2Class", "visualize_try_2", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(visualize_try_2Class);
    } // retranslateUi

};

namespace Ui {
    class visualize_try_2Class: public Ui_visualize_try_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZE_TRY_2_H
