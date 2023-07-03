//
// Created by 21caog1bif on 16.06.23.
//
#include "ui_startwindow.h"
#include "Sudoku.h"


StartWindow::StartWindow(QWidget *parent)
        : QMainWindow(parent),
          ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    ui->errorLabel->setStyleSheet("color: red");
    connect(ui->startButton, &QPushButton::clicked, this, &StartWindow::startClicked);
}

StartWindow::~StartWindow()
{
    delete ui;
}


    void StartWindow::startClicked()
    {
        ui->errorLabel->clear();
        //Extrahiere die Größe des Sudokufelds
        QString fieldSize = ui->gridSizeComboBox->currentText();
        if (fieldSize.isEmpty()) {
            fieldSize = "9x9"; // Setze Standardwert auf 9x9
        }
        QStringList sizeParts = fieldSize.split("x");
        int size = sizeParts[0].toInt();

        //Extrahiere Spielernamen in Liste; Prüfe Input auf Güligkeit
        QString inputText = ui->nameInput->text();
        if(inputText.count(',') > 3){
            ui->errorLabel->setText("Too many comma's");
            return;
        }
        inputText.remove(' ');
        if(inputText.isEmpty()){
            ui->errorLabel->setText("Pick a name");
            return;
        }
        QStringList nameList = inputText.split(',',QString::SkipEmptyParts);

        int difficulty = ui->difficultyComboBox->currentIndex() + 1;

        //Sudoku-Fenster
        Sudoku* sudoku = new Sudoku(size, difficulty, nameList, this, this);
        sudoku->move(pos());
        hide();
        sudoku->show();
    }

