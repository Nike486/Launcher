#pragma once

#include <iostream>

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


    /// Возвращяет имя игры
    std::string getName();

    /// Изменяем или добавляем имя игры
    void setName(std::string setName);

    /// Чистим класс для записи новой игры в вектор (используем обязательно после записи новой игры)
    void classClear();

    /// Получаем информацию игры
    void gameInfo ();

};