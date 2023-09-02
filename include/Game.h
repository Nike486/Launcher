#pragma once

#include "nlohmann/json.hpp"
#include "map"
#include <fstream>
#include <vector>
#include <iostream>



class ConfigGames
{
private:

    std::vector <std::string> listGames;        // Список всех игр
    std::vector <std::string> listGameJson;     // Список JSON файлов с играми

    std::string nameGame;                       // Название игры
    std::string description;                    // Описание
    int estimation;                             // Оценка
    std::vector <std::string> genre;            // Жанр (может быть несколько)
    std::vector <std::string> developer;        // Разработчик (может быть несколько)
    std::vector <std::string> publisher;        // Издатель (может быть несколько)
    int price;                                  // Цена
    std::string information;                    // Об игре
    std::vector<std::string> images;            // Путь до картинок




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
        images = {};
    }

//    ConfigGames(std::string nameGame, std::string description, int estimation, std::vector <std::string> genre, std::vector <std::string> developer, std::vector <std::string> publisher, int price,  std::string information)
//    {
//        this->nameGame = std::move(nameGame);
//        this->description = std::move(description);
//        this->estimation = estimation;
//        this->genre = std::move(genre);
//        this->developer = std::move(developer);
//        this->publisher = std::move(publisher);
//        this->price = price;
//        this->information = std::move(information);
//    }

    /// Создаём файл либо заполненый, либо пустой (зависит от конструктора класса)
    void createFile();
    void createFile(std::string _nameGame,
                   std::string _description,
                   int _estimation,
                   std::vector <std::string> _genre,
                   std::vector <std::string> _developer,
                   std::vector <std::string> _publisher,
                   int _price,
                   std::string _information,
                   std::vector<std::string> _images);



    /// Функция возвращает список игр
    std::vector <std::string> getlistGames();

    /// Функция возвращает список JSON со всеми играми
    std::vector<std::string> getListGameJson();

    /// Функция получает информацию об игре по названию
    void parsingJSON(std::string _nameGame);


    /// Функция возвращает ОПИСАНИЕ по названию
    std::string getDescription(std::string _nameGame);

    /// Функция возвращает ОЦЕНКУ по названию
    int getEstimation(std::string _nameGame);

    /// Функция возвращает ЖАНР по названию
    std::vector <std::string> getGenre(std::string _nameGame);

    /// Функция возвращает РАЗРАБОТЧИКА по названию
    std::vector <std::string> getDeveloper(std::string _nameGame);

    /// Функция возвращает ИЗДАТЕЛЯ по названию
    std::vector <std::string> getPublisher(std::string _nameGame);

    /// Функция возвращает ЦЕНУ игры по названию
    int getPrice(std::string _nameGame);

    /// Функция возвращает ИНФОРМАЦИЮ ОБ ИГРЕ по названию
    std::string getInformation(std::string _nameGame);

    /// Функция возвращает ПУТИ ДО КАРТИНОК по названию
    std::vector <std::string> getImages(std::string _nameGame);

    /// Функция возвращает пути до картинок для РЕКОМЕНДАЦИЙ по названиям игр (от 3х)
    std::vector<std::vector<std::string>> getRecommendations(std::vector<std::string> _nameGame);

};