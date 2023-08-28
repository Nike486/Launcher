#include "Game.h"


void ConfigGames::parsingJSON(std::string _nameGame)
{
    getlistGames();
    for (int i = 0; i < listGames.size(); i++)
    {
        if (listGames[i] == _nameGame)
        {
            std::ifstream fileJsonOpen("Game" + std::to_string (i) + ".json");
            if (fileJsonOpen.is_open())
            {
                nlohmann::json openJson;
                fileJsonOpen >> openJson;
                fileJsonOpen.close();

                nameGame = openJson["Name"];
                description = openJson["Description"];
                estimation = openJson["Estimation"];
                genre = openJson["Genre"];
                developer = openJson["Developer"];
                publisher = openJson["Publisher"];
                price = openJson["Price"];
                information = openJson["Information"];
            }
        }
    }
}



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

std::string ConfigGames::getDescription(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return description;
}

int ConfigGames::getEstimation(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return estimation;
}

std::vector<std::string> ConfigGames::getGenre(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return genre;
}

std::vector<std::string> ConfigGames::getDeveloper(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return developer;
}

std::vector<std::string> ConfigGames::getPublisher(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return publisher;
}

int ConfigGames::getPrice(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return price;
}

std::string ConfigGames::getInformation(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return information;
}
