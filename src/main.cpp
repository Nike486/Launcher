#include <iostream>
#include <vector>
#include "Game.h"



int main() {

    Game game("GTA");
    std::vector <Game> gameList;

    gameList.push_back(game);
    game.classClear();

    auto gamePointer = &gameList[0];
    gamePointer->gameInfo();

    gamePointer->setName("GTA2");

    gamePointer->gameInfo();


    return 0;
}
