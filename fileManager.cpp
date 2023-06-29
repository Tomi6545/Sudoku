#include "fileManager.h"
#include <iostream>
#include <fstream>

void saveHighscore(const std::vector<Player>& playerList, const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);

    if (file.is_open()) {
        for (const Player& player : playerList) {
            file.write(player.name.toStdString().c_str(), player.name.length() * sizeof(QChar));
            file.write(reinterpret_cast<const char*>(&player.score), sizeof(int));
        }
        file.close();
        std::cout << "Player-Liste erfolgreich in Datei gespeichert." << std::endl;
    } else {
        std::cerr << "Fehler beim Öffnen der Datei zum Speichern der Player-Liste." << std::endl;
    }
}

std::vector<Player> addToHighscore(const std::string& filename) {
    std::vector<Player> playerList;
    std::ifstream file(filename, std::ios::in | std::ios::binary);

    if (file.is_open()) {
        while (!file.eof()) {
            Player player;
            file.read(reinterpret_cast<char*>(&player.name), sizeof(QChar));
            int nameLength = player.name.length();
            player.name.resize(nameLength);
            file.read(reinterpret_cast<char*>(&player.score), sizeof(int));
            playerList.push_back(player);
        }
        file.close();
        std::cout << "Player-Liste erfolgreich aus Datei geladen." << std::endl;
    } else {
        std::cerr << "Fehler beim Öffnen der Datei zum Laden der Player-Liste." << std::endl;
    }

    return playerList;
}
