#pragma once

#include <utility>
#include "SFMLClass.h"
#include "Game.h"


class Set : protected SFML
{
private:

    ConfigGames configGames;

    sf::RenderWindow gamesWindow;
    sf::RenderWindow mainWindow;

    std::vector<std::string> listRecommendationsGames;

    std::vector<std::vector<std::string>> linkImages = configGames.getRecommendations(listRecommendationsGames);
    std::vector<std::string> linkArrow = {".\\images\\Left.png", ".\\images\\Right.png"};
    std::string linkRecommendationButton = ".\\images\\recBut.png";

    //// Текстуры

    sf::Texture gameImageTextureBase;
    sf::Texture gameImageTextureOne;
    sf::Texture gameImageTextureTwo;
    sf::Texture gameImageTextureThree;
    sf::Texture gameImageTextureFour;

    sf::Texture textureLiftArrow = imageTexture (linkArrow, 0);
    sf::Texture textureRightArrow = imageTexture (linkArrow, 1);

    sf::Texture textureRecommendationButton = imageTexture (linkRecommendationButton);

    //// Картинки рекомендаций
    sf::RectangleShape gameImageRecommendationBase;
    sf::RectangleShape gameImageRecommendationOne;
    sf::RectangleShape gameImageRecommendationTwo;
    sf::RectangleShape gameImageRecommendationThree;
    sf::RectangleShape gameImageRecommendationFour;


    //// Шрифты
    sf::Font fontCalibriBold = SFML::fontCalibriBold();
    sf::Font fontCalibriRegular = SFML::fontCalibriRegular();


    //// Цвета
    sf::Color customGrey = SFML::customGrey();


    //// Линии
    sf::RectangleShape upLine = line(
            sf::Color(customGrey),
            sf::Vector2f (1600.0f, 50.0f),
            sf::Vector2f(0.0f, 0.0f));

    sf::RectangleShape recommendationRectangle = line(
            customGrey,
            sf::Vector2f(1200.0f, 450.0f),
            sf::Vector2f(200.0f, 400.0f));

    sf::RectangleShape centre = line(
            sf::Color(255, 255, 255),
            sf::Vector2f(5.0f, 900.0f),
            sf::Vector2f(797.5f, 0.0f));


    //// Кнопки
    sf::RectangleShape buttonGames   =  button(
            sf::Color(customGrey),
            sf::Vector2f (100.0f, 50.0f),
            sf::Vector2f(650.0f, 0.0f));

    sf::RectangleShape buttonInfo    =  button(
            sf::Color(customGrey),
            sf::Vector2f (100.0f, 50.0f),
            sf::Vector2f(750.0f, 0.0f));

    sf::RectangleShape buttonLibrary =  button(
            sf::Color(customGrey),
            sf::Vector2f (100.0f, 50.0f),
            sf::Vector2f(850.0f, 0.0f));

    sf::RectangleShape buttonPrevious = image(
            textureLiftArrow,
            sf::Color(255, 255, 255, 50),
            sf::Vector2f (50.0f, 50.0f),
            sf::Vector2f (140.0f, 600.0f));

    sf::RectangleShape buttonNext = image(
            textureRightArrow,
            sf::Color(255, 255, 255, 50),
            sf::Vector2f (50.0f, 50.0f),
            sf::Vector2f (1410.0f, 600.0f));

    sf::RectangleShape buttonRecommendation = image(
            textureRecommendationButton,
            sf::Color(255, 255, 255, 255),
            sf::Vector2f (30.0f, 20.0f),
            sf::Vector2f (785.0f, 860.0f));


    //// Тексты
    sf::Text textButtonGames = text(
            fontCalibriBold,
            "Games",
            20,
            sf::Color(208,208,208),
            sf::Vector2f (buttonGames.getPosition().x + 20, buttonGames.getPosition().y + 11));

    sf::Text textButtonInfo = text(
            fontCalibriBold,
            "Info",
            20,
            sf::Color(208,208,208),
            sf::Vector2f (buttonInfo.getPosition().x + 33, buttonInfo.getPosition().y + 11));

    sf::Text textButtonLibrary = text(
            fontCalibriBold,
            "Library",
            20,
            sf::Color(208,208,208),
            sf::Vector2f (buttonLibrary.getPosition().x + 21, buttonLibrary.getPosition().y + 11));

    sf::Text textNameGame;


public:

    Set(std::vector<std::string> _listRecommendationsGames) : listRecommendationsGames(std::move(_listRecommendationsGames)){};


    void createRecommendationsImage (int numName);
    void createRecommendationsName (int numName);
    std::vector<sf::RectangleShape> createRecommendationsButton();

    //// Окна
    void GameWindowCreate(sf::Event event);
    void mainWindowCreate();
};