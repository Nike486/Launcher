#include <iostream>
#include <vector>
#include "Game.h"
#include <Config.h>


int main() {


    std::string nameGame = "Elden Ring";
    int price = 2799;
    std::string description = "НОВЫЙ ФЭНТЕЗИЙНЫЙ РОЛЕВОЙ БОЕВИК. Восстань, погасшая душа! "
                              "Междуземье ждёт своего повелителя. "
                              "Пусть благодать приведёт тебя к Кольцу Элден.";
    int estimation = 9;

    std::vector <std::string> genre = {"Тёмное фэнтези",
                                       "Ролевая игра",
                                       "Открытый мир",
                                       "Ролевой экшен",
                                       "Фэнтези",
                                       "Экшен"};

    std::vector <std::string> developer = {"FromSoftware Inc."};

    std::vector <std::string> publisher = {"FromSoftware Inc.",
                                           "Bandai Namco Entertainment"};

    std::string information = "Огромный мир с открытыми полями, множеством ситуаций и гигантскими подземельями, "
                              "где сложные трёхмерные конструкции сочетаются воедино. "
                              "Путешествуйте, преодолевайте смертельные опасности и радуйтесь успехам."
                              "Вы можете не только изменить внешность персонажа, но также комбинировать оружие, броню и предметы. "
                              "Развивайте персонажа по своему вкусу. Наращивайте мышцы или постигайте таинства магии.Многослойная история, "
                              "разбитая на фрагменты. Эпическая драма, в которой мысли персонажей пересекаются в Междуземье.Помимо многопользовательского режима, "
                              "в котором вы напрямую подключаетесь к другим игрокам и путешествуете вместе, есть асинхронный сетевой режим, "
                              "позволяющий ощутить присутствие других игроков.";




    ConfigGames configGames;

//    configGames.createFile();
//    configGames.createFile(nameGame, description, 3, genre, developer, publisher, price, information);

    ConfigProgram configProgram;
//    configProgram.createConfigFile();


    auto listGames = configGames.getlistGames();

    for (auto game : listGames)
    {
        std::cout << configGames.getPrice(game) << std::endl;
    }


    return 0;
}
