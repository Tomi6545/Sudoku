#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <random>
#include "Sudoku.h"
#include "fileManager.h"
#include "cmath"
#include "set"

Sudoku::Sudoku(int size, QStringList nameList, QWidget *parent) : QMainWindow(parent),
                                                                  ui(new Ui::SudokuClass), size(size*size) {
    ui->setupUi(this);

    sudokuTable = ui->sudokuTable;
    playerTable = ui->playerTable;
    int playerCount = nameList.length();
    int gridSize = this->gridSize();



    QFont font;
    font.setPointSize(12);
    sudokuTable->setFont(font);
    sudokuTable->setMouseTracking(false);
    sudokuTable->setFrameShadow(QFrame::Plain);
    sudokuTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sudokuTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sudokuTable->setRowCount(gridSize); //auf size anpassen
    sudokuTable->setColumnCount(gridSize);
    sudokuTable->horizontalHeader()->setVisible(false);
    sudokuTable->horizontalHeader()->setMinimumSectionSize(10);
    sudokuTable->horizontalHeader()->setDefaultSectionSize(32);
    sudokuTable->horizontalHeader()->setHighlightSections(false);
    sudokuTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    sudokuTable->verticalHeader()->setVisible(false);
    sudokuTable->verticalHeader()->setMinimumSectionSize(10);
    sudokuTable->verticalHeader()->setDefaultSectionSize(32);
    sudokuTable->verticalHeader()->setHighlightSections(false);
    sudokuTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Initalisieren des Felds
    createSolution();

    // Schleife zur Initialisierung der Spieler in Playerlist
    Player players[playerCount];
    for (int i = 0; i < playerCount; i++){
        players[i].name = nameList.value(i);
        players[i].score = 0;
    }
    //Schleife zum Hinzufügen der Spieler in die playerTable
    for (int i = 0; i < playerCount; i++) {
        QString playerName = nameList.value(i);
        addPlayer(playerName);
    }
    showCurrentName(players[0].name);

    // Speichern der Highscores
    std::vector<Player> playerVector(players, players + playerCount); // Konvertiere Array in einen Vektor
    //saveHighscore(playerVector, "highscores.bin");

}


void Sudoku::addPlayer(const QString& name){
    Player player;
    player.name = name;
    player.score = 0;

    int row = playerTable->rowCount();
    playerTable->insertRow(row);

    QTableWidgetItem* nameItem = new QTableWidgetItem(player.name);
    QTableWidgetItem* scoreItem = new QTableWidgetItem(QString::number(player.score));
    scoreItem->setTextAlignment(Qt::AlignCenter);

    playerTable->setItem(row, 0, nameItem);
    playerTable->setItem(row, 1, scoreItem);

    playerList.append(player);
    playerTable->repaint();
}

void Sudoku::updateScore(const QString& name, int score){
    for (int i = 0; i < playerList.size(); ++i) {
        if (playerList[i].name == name) {
            playerList[i].score = score;
            QTableWidgetItem* scoreItem = playerTable->item(i, 1);
            if (scoreItem) {
                scoreItem->setText(QString::number(score));
            }
            break;
        }
    }
}

void Sudoku::showCurrentName(const QString& name){
    ui->currentName->setText(name);

}


void Sudoku::updateVisual() {
    for(int i = 0; i < size; i++) {
        SudokuPos pos = this->getPos(i);
        //TODO bessere umwandlung zu QString ?
        QTableWidgetItem *entry = new QTableWidgetItem(QString::fromStdString(std::string(1, fields.at(i))));
        entry->setTextAlignment(Qt::AlignCenter);
        sudokuTable->setItem(pos.row, pos.column, entry);
    }
}



void Sudoku::createSolution() {
    for(int i = 0; i < size; i++) {
        fields.push_back(' ');
    }
    for(int i = 0; i < blockSize(); i++) {
        initalizeBlock(i * blockSize() + i * blockSize() * gridSize());
    }

    complete(1);
    //TODO maxDelete
    int maxDelete = 40;
    std::set<int> deleted;
    while(true) {
        int rnd = std::rand() % size;
        if (deleted.find(rnd) != deleted.end()) {
            continue;
        }

        for(int iterator : deleted) {
            fields.at(iterator) = ' ';
        }
        char tmp = fields.at(rnd);
        fields.at(rnd) = ' ';
        deleted.insert(rnd);

        if(deleted.size() <= maxDelete && complete(2) != 2) {
            continue;
        }

        for(int iterator : deleted) {
            fields.at(iterator) = ' ';
        }
        fields.at(rnd) = tmp;
        break;
    }

    updateVisual();
}

void Sudoku::initalizeBlock(const int pos) {
    std::vector<char> characters = getAllowedCharacters();
    std::shuffle(characters.begin(), characters.end(), std::mt19937(std::random_device()()));
    for(int row = 0; row < blockSize(); row++) {
        for(int column = 0; column < blockSize(); column++) {
            fields.at(pos + column + (row * gridSize())) = characters.back();
            characters.pop_back();
        }
    }
}

class Attempt {
    public:
        Attempt(int pos, int charIndex) {
            this->pos = pos;
            this->charIndex = charIndex;
        }

    int pos;
    int charIndex;
    void next() {
        ++charIndex;
    }
};


int Sudoku::complete(const int maxSolutions) {
    std::vector<char> characters = getAllowedCharacters();
    std::vector<Attempt> attempts;
    int firstFree = findFree();
    if(firstFree != -1) {
        attempts.emplace_back(firstFree, 0);
        fields[firstFree] = characters.at(0);
    }

    int found = 0;
    while(!attempts.empty()) {
        Attempt current = attempts.back();
        //std::cout << "Current: " << current.pos << " " << characters.at(current.charIndex) << std::endl;
        //erzeugt der versuch ein gueltiges feld?
        if(isPossible(current.pos, characters.at(current.charIndex))) {
            //versuch ist gueltig
            //finde naechstes freies feld
            int nextFree = findFree();
            if ( nextFree == -1 ) {
                //keine freien felder mehr, fertig?
                if ( ++found == maxSolutions ) {
                    return found;
                }
                //mehr loesungen suchen
                current.next();
                while (current.charIndex >= characters.size()) {
                    //eingabe zu hoch, backtracking
                    attempts.pop_back();
                    fields.at(current.pos) = ' ';
                    if(attempts.empty()) {
                        //es geht nicht weiter zurueck
                        return found;
                    }
                    current = attempts.back();
                    current.next();
                }
                //naechster versuch gefunden
                attempts.back() = current;
                fields.at(current.pos) = characters.at(current.charIndex);
            }
            else {
                //es gibt noch freie felder, weiter machen
                attempts.emplace_back(nextFree, 0);
                fields.at(nextFree) = characters.at(0);
            }
        } else {
            //versuch ist nicht gueltig
            //erhoehe eingabe um 1
            current.next();
            while (current.charIndex >= characters.size()) {
                //eingabe zu hoch, backtracking
                attempts.pop_back();
                fields.at(current.pos) = ' ';
                if(attempts.empty()) {
                    //es geht nicht weiter zurueck
                    return found;
                }
                current = attempts.back();
                current.next();
            }
            //naechster versuch gefunden
            attempts.back() = current;
            fields.at(current.pos) = characters.at(current.charIndex);
        }
    }

    return -1;
}

int Sudoku::findFree() const {
    for(int i = 0; i < size; i++) {
        if(fields.at(i) == ' ') {
            return i;
        }
    }
    return -1;
}

bool Sudoku::isPossible(int pos, char guess) const {
    SudokuPos sudokuPos = getPos(pos);
    for(int i = 0; i < size; i++) {
        if(i == pos || fields.at(i) != guess) {
            continue;
        }
        SudokuPos other = getPos(i);
        if(sudokuPos.block == other.block || sudokuPos.row == other.row || sudokuPos.column == other.column) {
            return false;
        }
    }
    return true;
}

