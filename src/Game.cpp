#include "Game.h"

void ConfigGames::createFile()
{
    int a = getListGameJson().size();

    std::ofstream fileJsonCreate("Game" + std::to_string (a) + ".json");
    nlohmann::json fileJson;

    fileJson["Name"] = nameGame;
    fileJson["Description"] = description;
    fileJson["Estimation"] = estimation;
    fileJson["Genre"] = genre;
    fileJson["Developer"] = developer;
    fileJson["Publisher"] = publisher;
    fileJson["Price"] = price;
    fileJson["Information"] = information;

    fileJsonCreate << fileJson.dump(2);
}

void ConfigGames::createFile(std::string _nameGame,
                            std::string _description,
                            int _estimation,
                            std::vector<std::string> _genre,
                            std::vector<std::string> _developer,
                            std::vector<std::string> _publisher,
                            int _price,
                            std::string _information)
{
    int a = getListGameJson().size();

    std::ofstream fileJsonCreate("Game" + std::to_string (a) + ".json");
    nlohmann::json fileJson;

    fileJson["Name"] = _nameGame;
    fileJson["Description"] = _description;
    fileJson["Estimation"] = _estimation;
    fileJson["Genre"] = _genre;
    fileJson["Developer"] = _developer;
    fileJson["Publisher"] = _publisher;
    fileJson["Price"] = _price;
    fileJson["Information"] = _information;

    fileJsonCreate << fileJson.dump(2);
}


int ConfigGames::getPrice(std::string nameGame)
{
    getlistGames();
    for (int i = 0; i < listGames.size(); i++)
    {
        if (listGames[i] == nameGame)
        {
            std::ifstream fileJsonOpen("Game" + std::to_string (i) + ".json");
            if (fileJsonOpen.is_open())
            {
                nlohmann::json openJson;
                fileJsonOpen >> openJson;
                fileJsonOpen.close();
                return openJson["Price"];
            }
        }
    }
    return 0;
}


std::vector<std::string> ConfigGames::getlistGames()
{
    listGames.clear();
    getListGameJson();
    for(auto&&LGJ : listGameJson)
    {
        std::ifstream fileJsonOpen(LGJ);
        if (fileJsonOpen.is_open())
        {
            nlohmann::json openJson;
            fileJsonOpen >> openJson;
            listGames.push_back(openJson["Name"]);
            fileJsonOpen.close();
        }
    }
    return listGames;
}


std::vector<std::string> ConfigGames::getListGameJson()
{
    listGameJson.clear();
    int i = 0;
    while(true)
    {
        std::ifstream fileJsonOpen("Game" + std::to_string (i) + ".json");
        if (fileJsonOpen.is_open())
        {
            listGameJson.push_back("Game" + std::to_string (i) + ".json");
            i++;
        }
        else break;
    }
    return listGameJson;
}

std::string ConfigGames::getDescription(std::string nameGame)
{
    getlistGames();
    for (int i = 0; i < listGames.size(); i++)
    {
        if (listGames[i] == nameGame)
        {
            std::ifstream fileJsonOpen("Game" + std::to_string (i) + ".json");
            if (fileJsonOpen.is_open())
            {
                nlohmann::json openJson;
                fileJsonOpen >> openJson;
                fileJsonOpen.close();
                return openJson["Description"];
            }
        }
    }

    return std::string("");
}
