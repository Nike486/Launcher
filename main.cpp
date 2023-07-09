#include <iostream>
#include <vector>

class Game
{
private:
std::string name;


public:
    Game()
    {
        name = "";
    }

    Game(std::string _name) : name(std::move(_name)) {};

    std::string getName()
    {
        return name;
    }

    void setName(std::string setName)
    {
        name = std::move(setName);
    }

    ////Чистим класс для записи новой игры в вектор (используем обязательно после записи новой игры)
    void classClear()
    {
        name = "";
    }

    void gameInfo ()
    {
        std::cout << "Name: " << getName() << std::endl;
    };
};

int main() {

    Game game("GTA");
    std::vector <Game> gameList;

    gameList.push_back(game);
    game.classClear();

    auto gamePointer = &gameList[0];
    gamePointer->gameInfo();

    gamePointer->setName("GTA2");

    gamePointer->gameInfo();




/*
    1. Сделать класс для записи новой игры
    2. Сделать список жанров (что бы потом легче сортировать или проводить поиск по жанру)

*/

    return 0;
}
