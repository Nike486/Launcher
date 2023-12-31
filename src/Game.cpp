#include "Game.h"

#include <utility>


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
                images = openJson["Images"];
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
    fileJson["Images"] = images;

    fileJsonCreate << fileJson.dump(2);
}

void ConfigGames::createFile(std::string _nameGame,
                            std::string _description,
                            int _estimation,
                            std::vector<std::string> _genre,
                            std::vector<std::string> _developer,
                            std::vector<std::string> _publisher,
                            int _price,
                            std::string _information,
                             std::vector<std::string> _images)
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
    fileJson["Images"] = _images;

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

std::vector<std::string> ConfigGames::getImages(std::string _nameGame)
{
    parsingJSON(std::move(_nameGame));
    return images;
}

std::vector<std::vector<std::string>> ConfigGames::getRecommendations(std::vector<std::string> _nameGame)
{
    std::vector<std::vector<std::string>> listRecommendations;

    for (int i = 0; i < _nameGame.size(); ++i)
    {
        listRecommendations.push_back(getImages(_nameGame[i]));
    }

    return listRecommendations;
}

std::vector<std::string> ConfigGames::getMainImagesAllGames()
{
    std::vector<std::string> listImg;

    for (int i = 0; i < listGames.size(); ++i)
    {
        listImg.emplace_back(getImages(listGames[i])[0]);
    }

    return listImg;
}

std::vector<std::string> ConfigGames::getListPriceRub()
{
    std::vector<std::string> listPriceRub;

    for (int i = 0; i < listGames.size(); ++i)
    {
        listPriceRub.emplace_back( std::to_string(getPrice(listGames[i])) + " RUB.");
    }

    return listPriceRub;
}

std::vector<std::string> ConfigGames::getListDeveloper()
{
    std::vector<std::string> listDeveloper;

    for (int i = 0; i < listGames.size(); ++i)
    {
        if (getDeveloper(listGames[i]).size() > 1)
        {
            std::string strDev;
            for (auto dev : getDeveloper(listGames[i]))
            {
                strDev += dev + "\n";
            }
            listDeveloper.emplace_back(strDev);
        }
        else listDeveloper.emplace_back(getDeveloper(listGames[i])[0]);
    }

    return listDeveloper;
}
