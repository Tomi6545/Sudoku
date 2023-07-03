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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuClass
{
public:
    QWidget *centralWidget;
    QTableWidget *playerTable;
    QTableWidget *sudokuTable;
    QLabel *label;
    QLabel *currentName;
    QPushButton *restartButton;
    QTextEdit *console;
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
        playerTable->setGeometry(QRect(920, 200, 211, 144));
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
        label->setGeometry(QRect(890, 20, 281, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        currentName = new QLabel(centralWidget);
        currentName->setObjectName(QString::fromUtf8("currentName"));
        currentName->setEnabled(true);
        currentName->setGeometry(QRect(860, 60, 321, 101));
        QFont font1;
        font1.setPointSize(40);
        currentName->setFont(font1);
        currentName->setScaledContents(false);
        currentName->setAlignment(Qt::AlignCenter);
        restartButton = new QPushButton(centralWidget);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(920, 770, 211, 51));
        console = new QTextEdit(centralWidget);
        console->setObjectName(QString::fromUtf8("console"));
        console->setGeometry(QRect(920, 470, 211, 261));
        console->setReadOnly(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(920, 430, 211, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        SudokuClass->setCentralWidget(centralWidget);
        sudokuTable->raise();
        playerTable->raise();
        label->raise();
        currentName->raise();
        restartButton->raise();
        console->raise();
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
        QTableWidgetItem *___qtablewidgetitem = playerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SudokuClass", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = playerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SudokuClass", "Score", nullptr));
        label->setText(QApplication::translate("SudokuClass", "CURRENT PLAYER:", nullptr));
        currentName->setText(QString());
        restartButton->setText(QApplication::translate("SudokuClass", "RESTART", nullptr));
        label_2->setText(QApplication::translate("SudokuClass", "CONSOLE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SudokuClass: public Ui_SudokuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
