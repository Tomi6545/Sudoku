#ifndef SUDOKU_H
#define SUDOKU_H


#include <QWidget>
#include <QTableWidget>
#include "ui_sudoku.h"
#include "cmath"
#include "set"
#include "StartWindow.h"


class Sudoku : public QMainWindow
{
Q_OBJECT

public:
    explicit Sudoku(int size, int difficulty, const QStringList& nameList, StartWindow* startWindow, QWidget *parent = nullptr);
    struct Player{
        QString name;
        int score;
    };
    struct SudokuPos {
        int row;
        int column;
        int block;
    };
    void addPlayer(const QString& name);

public slots:
    void onTableClicked(const QModelIndex &index);
    void keyPressEvent(QKeyEvent *event) override;
    void restartClicked();

private:
    StartWindow* startWindow;
    Ui::SudokuClass *ui;
    QLabel currentName;
    QTableWidget* sudokuTable;
    QTableWidget* playerTable;
    QList<Player> playerList;

    std::vector<Player> players;
    const int size;
    const int difficulty;
    std::vector<char> fields;
    std::unordered_map<int, char> missing;
    int currentPlayer = 0;
    int selectedField = -1;
    std::set<char> previousGuesses;
    char guess = ' ';
    bool finished = false;

    [[nodiscard]] int gridSize() const {
        return sqrt(size);
    }

    [[nodiscard]] int blockSize() const {
        return sqrt(gridSize());
    }

    [[nodiscard]] SudokuPos getPos(int pos) const {
        SudokuPos sudokuPos{
        };
        sudokuPos.row = pos / gridSize();
        sudokuPos.column = pos % gridSize();
        sudokuPos.block = (pos/(gridSize()*blockSize()))*blockSize() + sudokuPos.column/blockSize();
        return sudokuPos;
    }

    [[nodiscard]] std::vector<char> getAllowedCharacters() const {
        std::vector<char> allowed;
        for(int i = 0; i < gridSize(); i++) {
            //zuerst alle Zahlen, dann ab Ascii Code für A weiter
            int base;
            if(i < 9) {
                //49 ist Ascii Code für 1
                allowed.push_back(char(49 + i));
            } else {
                //65 ist Ascii Code für A
                allowed.push_back(char(65-9+i));
            }
        }
        return allowed;
    }

    void handleTurn();
    void updateVisual();
    void createSolution();
    void initalizeBlock(int pos);
    int complete(int maxSolutions);
    [[nodiscard]] int findFree() const;
    [[nodiscard]] bool isPossible(int pos, char guess) const;
    [[nodiscard]] int isOptimal(int pos, char guess) const;

    void updateScore(const std::vector<Player> &players, QTableWidget *playerTable);


};

#endif // SUDOKU_H



