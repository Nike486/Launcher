#include "Game.h"


std::string Game::getName()
{
    return name;
}

void Game::setName(std::string setName)
{
    name = std::move(setName);
}


void Game::classClear()
{
    name = "";
}

void Game::gameInfo ()
{
    std::cout << "Name: " << getName() << std::endl;
}