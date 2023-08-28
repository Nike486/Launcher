#pragma once

#include "SFMLClass.h"

class Set : protected SFML
{
private:

    sf::RenderWindow gamesWindow;
    sf::RenderWindow mainWindow;

    int numCentre = 1;
    int numLeft = 0;
    int numRight = 2;

    std::vector<std::string> linkImages = {".\\images\\GTA.jpg", ".\\images\\Witcher.jpeg", ".\\images\\NFS.jpeg", ".\\images\\RGR2.jpeg"};
    std::vector<std::string> linkArrow = {".\\images\\Left.png", ".\\images\\Right.png"};

    //// Текстуры
    sf::Texture gameImageTextureCentre = imageTexture (linkImages, numCentre);
    sf::Texture gameImageTextureLeft = imageTexture (linkImages, numLeft);
    sf::Texture gameImageTextureRight = imageTexture (linkImages, numRight);

    sf::Texture textureLiftArrow = imageTexture (linkArrow, 0);
    sf::Texture textureRightArrow = imageTexture (linkArrow, 1);

    //// Картинки рекомендаций
    sf::RectangleShape gameImageCentre = image(
            gameImageTextureCentre,
            sf::Color(255, 255, 255, 255),
            sf::Vector2f (720.0f, 430.0f),
            sf::Vector2f (450.0f, 400.0f));

    sf::RectangleShape gameImageLeft  = image(
            gameImageTextureLeft,
            sf::Color(255, 255, 255, 50),
            sf::Vector2f (650.0f, 390.0f),
            sf::Vector2f (-280.0f, 420.0f));

    sf::RectangleShape gameImageRight= image(
            gameImageTextureRight,
            sf::Color(255, 255, 255, 50),
            sf::Vector2f (650.0f, 390.0f),
            sf::Vector2f (1250.0f, 420.0f));


    //// Шрифты
    sf::Font fontCalibri = SFML::fontCalibri();


    //// Цвета
    sf::Color customGrey = SFML::customGrey();


    //// Линии
    sf::RectangleShape upLine = line(
            sf::Color(41,49,51),
            sf::Vector2f (1600.0f, 50.0f),
            sf::Vector2f(0.0f, 0.0f));


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
            textureRightArrow,
            sf::Color(255, 255, 255, 50),
            sf::Vector2f (50.0f, 50.0f),
            sf::Vector2f (1185.0f, 600.0f));

    sf::RectangleShape buttonNext = image(
            textureLiftArrow,
            sf::Color(255, 255, 255, 50),
            sf::Vector2f (50.0f, 50.0f),
            sf::Vector2f (385.0f, 600.0f));


    //// Тексты
    sf::Text textButtonGames = text(
            fontCalibri,
            "Games",
            20,
            sf::Color(208,208,208),
            sf::Vector2f (buttonGames.getPosition().x + 20, buttonGames.getPosition().y + 11));

    sf::Text textButtonInfo = text(
            fontCalibri,
            "Info",
            20,
            sf::Color(208,208,208),
            sf::Vector2f (buttonInfo.getPosition().x + 33, buttonInfo.getPosition().y + 11));

    sf::Text textButtonLibrary = text(
            fontCalibri,
            "Library",
            20,
            sf::Color(208,208,208),
            sf::Vector2f (buttonLibrary.getPosition().x + 21, buttonLibrary.getPosition().y + 11));


public:

    //// Окна
    void GameWindowCreate (sf::Event event);

    void mainWindowCreate ();
};