#pragma once

#include "nlohmann/json.hpp"
#include "map"
#include <fstream>
#include <vector>
#include <iostream>



class ConfigGames
{
private:

    std::vector <std::string> listGames;    // ������ ���� ���
    std::vector <std::string> listGameJson; // ������ JSON ������ � ������


    std::string nameGame;                   // �������� ����
    std::string description;                // ��������
    int estimation;                         // ������
    std::vector <std::string> genre;        // ���� (����� ���� ���������)
    std::vector <std::string> developer;    // ����������� (����� ���� ���������)
    std::vector <std::string> publisher;    // �������� (����� ���� ���������)
    int price;                              // ����
    std::string information;                // �� ����


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

    /// ������ ���� ���� ���������� ���� ������ (������� �� ������������ ������)
    void createFile();
    void createFile(std::string nameGame,
                   std::string description,
                   int estimation,
                   std::vector <std::string> genre,
                   std::vector <std::string> developer,
                   std::vector <std::string> publisher,
                   int price,
                   std::string information);



    /// ������� ���������� ������ ���
    std::vector <std::string> getlistGames();

    /// ������� ���������� ������ JSON �� ����� ������
    std::vector<std::string> getListGameJson();

    /// ������� �������� ���������� �� ���� �� ��������
    void parsingJSON(std::string _nameGame);


    /// ������� ���������� �������� �� ��������
    std::string getDescription(std::string _nameGame);

    /// ������� ���������� ������ �� ��������
    int getEstimation(std::string _nameGame);

    /// ������� ���������� ���� �� ��������
    std::vector <std::string> getGenre(std::string _nameGame);

    /// ������� ���������� ������������ �� ��������
    std::vector <std::string> getDeveloper(std::string _nameGame);

    /// ������� ���������� �������� �� ��������
    std::vector <std::string> getPublisher(std::string _nameGame);

    /// ������� ���������� ���� ���� �� ��������
    int getPrice(std::string nameGame);

    /// ������� ���������� ���������� �� ���� �� ��������
    std::string getInformation(std::string _nameGame);

};