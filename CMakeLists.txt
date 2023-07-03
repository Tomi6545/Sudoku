cmake_minimum_required(VERSION 3.25)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)

# Finde und lade das erforderliche Qt-Paket
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Füge den Qt-Pfad hinzu
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Füge die erforderlichen Qt-Module zu deinem Ziel hinzu
add_executable(Sudoku main.cpp Sudoku.cpp Sudoku.h startwindow.ui StartWindow.cpp StartWindow.h sudoku.ui fileManager.cpp fileManager.h)
target_link_libraries(Sudoku PRIVATE Qt5::Core Qt5::Widgets)

#Teilnehmer: 21caog1bif  21gath1bif