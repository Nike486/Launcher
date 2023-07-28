#pragma once

#include "nlohmann/json.hpp"
#include "map"
#include <fstream>
#include <utility>
#include <vector>
#include <iostream>



class ConfigGames
{
private:

    std::vector <std::string> listGames;    // Список всех игр
    std::vector <std::string> listGameJson; // Список JSON файлов с играми


    std::string nameGame;                   // Название игры
    std::string description;                // Описание
    int estimation;                         // Оценка
    std::vector <std::string> genre;        // Жанр (может быть несколько)
    std::vector <std::string> developer;    // Разработчик (может быть несколько)
    std::vector <std::string> publisher;    // Издатель (может быть несколько)
    int price;                              // Цена
    std::string information;                // Об игре


public:

    ConfigGames()
    {
        nameGame = "";
        description = "";
        estimation = 0;
        genre = {};
        developer = {};
        publisher = {};
        price = 0;
        information = "";
    }

    ConfigGames(std::string nameGame, std::string description, int estimation, std::vector <std::string> genre, std::vector <std::string> developer, std::vector <std::string> publisher, int price,  std::string information)
    {
        this->nameGame = std::move(nameGame);
        this->description = std::move(description);
        this->estimation = estimation;
        this->genre = std::move(genre);
        this->developer = std::move(developer);
        this->publisher = std::move(publisher);
        this->price = price;
        this->information = std::move(information);
    }

    /// Создаём файл либо заполненый либо пустой (зависит от конструктора класса)
    void createFile ();

    /// Функция возвращает Цену игры по названию
    int getPrice(std::string nameGame);

    /// Функция возвращает список игр
    std::vector <std::string> getlistGames();

    /// Функция возвращает список JSON со всеми играми
    std::vector<std::string> getListGameJson();
};