#ifndef PLAYERFILEMANAGER_H
#define PLAYERFILEMANAGER_H

#include <vector>
#include <QString>

struct Player {
    QString name;
    int score;
};

void saveHighscore(const std::vector<Player>& playerList, const std::string& filename);
std::vector<Player> addToHighscore(const std::string& filename);

#endif // PLAYERFILEMANAGER_H

