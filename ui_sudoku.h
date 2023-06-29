/********************************************************************************
** Form generated from reading UI file 'sudoku.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKU_H
#define UI_SUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuClass
{
public:
    QWidget *centralWidget;
    QLabel *OutputLabel1;
    QLabel *ErrorLabel;
    QTableWidget *playerTable;
    QTableWidget *sudokuTable;
    QLabel *label;
    QLabel *currentName;
    QTableWidget *playerTable_2;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokuClass)
    {
        if (SudokuClass->objectName().isEmpty())
            SudokuClass->setObjectName(QString::fromUtf8("SudokuClass"));
        SudokuClass->resize(1370, 929);
        SudokuClass->setLayoutDirection(Qt::RightToLeft);
        centralWidget = new QWidget(SudokuClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        OutputLabel1 = new QLabel(centralWidget);
        OutputLabel1->setObjectName(QString::fromUtf8("OutputLabel1"));
        OutputLabel1->setGeometry(QRect(830, 30, 49, 16));
        OutputLabel1->setLayoutDirection(Qt::LeftToRight);
        ErrorLabel = new QLabel(centralWidget);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(890, 440, 211, 51));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        ErrorLabel->setFont(font);
        playerTable = new QTableWidget(centralWidget);
        if (playerTable->columnCount() < 2)
            playerTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        playerTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        playerTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        playerTable->setObjectName(QString::fromUtf8("playerTable"));
        playerTable->setEnabled(true);
        playerTable->setGeometry(QRect(890, 300, 211, 144));
        playerTable->setFocusPolicy(Qt::NoFocus);
        playerTable->setLayoutDirection(Qt::LeftToRight);
        playerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        playerTable->setTabKeyNavigation(false);
        playerTable->setProperty("showDropIndicator", QVariant(false));
        playerTable->setDragDropOverwriteMode(false);
        playerTable->setSelectionMode(QAbstractItemView::NoSelection);
        playerTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        playerTable->setRowCount(0);
        playerTable->setColumnCount(2);
        playerTable->horizontalHeader()->setVisible(true);
        playerTable->horizontalHeader()->setCascadingSectionResizes(false);
        playerTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        playerTable->horizontalHeader()->setStretchLastSection(true);
        playerTable->verticalHeader()->setVisible(false);
        playerTable->verticalHeader()->setCascadingSectionResizes(false);
        playerTable->verticalHeader()->setHighlightSections(false);
        playerTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        playerTable->verticalHeader()->setStretchLastSection(false);
        sudokuTable = new QTableWidget(centralWidget);
        sudokuTable->setObjectName(QString::fromUtf8("sudokuTable"));
        sudokuTable->setGeometry(QRect(20, 20, 800, 800));
        sudokuTable->setLayoutDirection(Qt::LeftToRight);
        sudokuTable->setLineWidth(0);
        sudokuTable->setShowGrid(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(860, 60, 281, 51));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        currentName = new QLabel(centralWidget);
        currentName->setObjectName(QString::fromUtf8("currentName"));
        currentName->setEnabled(true);
        currentName->setGeometry(QRect(830, 100, 341, 101));
        QFont font2;
        font2.setPointSize(40);
        currentName->setFont(font2);
        currentName->setScaledContents(false);
        currentName->setAlignment(Qt::AlignCenter);
        playerTable_2 = new QTableWidget(centralWidget);
        if (playerTable_2->columnCount() < 2)
            playerTable_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        playerTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        playerTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        playerTable_2->setObjectName(QString::fromUtf8("playerTable_2"));
        playerTable_2->setEnabled(true);
        playerTable_2->setGeometry(QRect(890, 540, 211, 281));
        playerTable_2->setFocusPolicy(Qt::NoFocus);
        playerTable_2->setLayoutDirection(Qt::LeftToRight);
        playerTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        playerTable_2->setTabKeyNavigation(false);
        playerTable_2->setProperty("showDropIndicator", QVariant(false));
        playerTable_2->setDragDropOverwriteMode(false);
        playerTable_2->setSelectionMode(QAbstractItemView::NoSelection);
        playerTable_2->setSelectionBehavior(QAbstractItemView::SelectItems);
        playerTable_2->setRowCount(0);
        playerTable_2->setColumnCount(2);
        playerTable_2->horizontalHeader()->setVisible(true);
        playerTable_2->horizontalHeader()->setCascadingSectionResizes(false);
        playerTable_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        playerTable_2->horizontalHeader()->setStretchLastSection(true);
        playerTable_2->verticalHeader()->setVisible(false);
        playerTable_2->verticalHeader()->setCascadingSectionResizes(false);
        playerTable_2->verticalHeader()->setHighlightSections(false);
        playerTable_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        playerTable_2->verticalHeader()->setStretchLastSection(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(850, 490, 281, 51));
        label_2->setFont(font1);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        SudokuClass->setCentralWidget(centralWidget);
        sudokuTable->raise();
        OutputLabel1->raise();
        ErrorLabel->raise();
        playerTable->raise();
        label->raise();
        currentName->raise();
        playerTable_2->raise();
        label_2->raise();
        menuBar = new QMenuBar(SudokuClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1370, 22));
        SudokuClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokuClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SudokuClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SudokuClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SudokuClass->setStatusBar(statusBar);

        retranslateUi(SudokuClass);

        QMetaObject::connectSlotsByName(SudokuClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuClass)
    {
        SudokuClass->setWindowTitle(QApplication::translate("SudokuClass", "Sudoku", nullptr));
        OutputLabel1->setText(QString());
        ErrorLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = playerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SudokuClass", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = playerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SudokuClass", "Score", nullptr));
        label->setText(QApplication::translate("SudokuClass", "CURRENT PLAYER:", nullptr));
        currentName->setText(QString());
        QTableWidgetItem *___qtablewidgetitem2 = playerTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("SudokuClass", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = playerTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("SudokuClass", "Score", nullptr));
        label_2->setText(QApplication::translate("SudokuClass", "High-Score:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SudokuClass: public Ui_SudokuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
