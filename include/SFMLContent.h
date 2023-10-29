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
    std::string linkBanner = ".\\images\\COD.jpg";

    std::vector<std::vector<std::string>> linkImages = configGames.getRecommendations(listRecommendationsGames);
    std::vector<std::string> linkMainImgAllGames = configGames.getMainImagesAllGames();
    std::vector<std::string> listPriceWithRub = configGames.getListPriceRub();
    std::vector<std::string> listDeveloper = configGames.getListDeveloper();

    std::vector<std::string> linkArrow = {".\\images\\Left.png", ".\\images\\Right.png"};
    std::string linkRecommendationButton = ".\\images\\recBut.png";
    std::vector<std::string> linkStarsEstimation = {".\\images\\StarVoid.png", ".\\images\\StarFull.png"};

    //// Текстуры

    std::vector<sf::Texture> imageTextureInGames;
    std::vector<sf::Texture> imageTextureInRecommendation;

    std::vector<sf::Texture> starsTexture = {imageTexture (linkStarsEstimation, 0), imageTexture (linkStarsEstimation, 1)};

    sf::Texture bannerTexture = imageTexture (linkBanner);

    sf::Texture textureLiftArrow = imageTexture (linkArrow, 0);
    sf::Texture textureRightArrow = imageTexture (linkArrow, 1);



    sf::Texture textureRecommendationButton = imageTexture (linkRecommendationButton);

    //// Картинки рекомендаций
    std::vector<sf::RectangleShape> gameImageRecommendation;

    sf::RectangleShape banner = image(
            bannerTexture,
            sf::Color(255, 255, 255, 255),
            sf::Vector2f (1600.0f, 300.0f),
            sf::Vector2f (0.0f, 50.0f));


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

    std::vector <sf::RectangleShape> buttonGamesInfoLibrary = {
            button(
                    sf::Color(customGrey),
                    sf::Vector2f (100.0f, 50.0f),
                    sf::Vector2f(650.0f, 0.0f)),
            button(
                    sf::Color(customGrey),
                    sf::Vector2f (100.0f, 50.0f),
                    sf::Vector2f(750.0f, 0.0f)),
            button(
                    sf::Color(customGrey),
                    sf::Vector2f (100.0f, 50.0f),
                    sf::Vector2f(850.0f, 0.0f))};

    std::vector <sf::RectangleShape> buttonPreviousAndNext = {
            image(
                    textureLiftArrow,
                    sf::Color(255, 255, 255, 50),
                    sf::Vector2f (50.0f, 50.0f),
                    sf::Vector2f (140.0f, 600.0f)),
            image(
                    textureRightArrow,
                    sf::Color(255, 255, 255, 50),
                    sf::Vector2f (50.0f, 50.0f),
                    sf::Vector2f (1410.0f, 600.0f))};

    sf::RectangleShape buttonRecommendation = image(
            textureRecommendationButton,
            sf::Color(255, 255, 255, 255),
            sf::Vector2f (30.0f, 20.0f),
            sf::Vector2f (785.0f, 860.0f));


    //// Тексты

    std::vector<sf::Text> textGamesInfoLibrary =
            {
                    text(
                            fontCalibriBold,
                            "Games",
                            20,
                            sf::Color(208,208,208),
                            sf::Vector2f (buttonGamesInfoLibrary[0].getPosition().x + 20, buttonGamesInfoLibrary[0].getPosition().y + 11)),
                    text(
                            fontCalibriBold,
                            "Info",
                            20,
                            sf::Color(208,208,208),
                            sf::Vector2f (buttonGamesInfoLibrary[1].getPosition().x + 33, buttonGamesInfoLibrary[1].getPosition().y + 11)),
                    text(
                            fontCalibriBold,
                            "Library",
                            20,
                            sf::Color(208,208,208),
                            sf::Vector2f (buttonGamesInfoLibrary[2].getPosition().x + 21, buttonGamesInfoLibrary[2].getPosition().y + 11))
            };

    sf::Text textNameGame;


public:

    Set(std::vector<std::string> _listRecommendationsGames) : listRecommendationsGames(std::move(_listRecommendationsGames)){};


    void createRecommendationsImage (int numName);
    void createRecommendationsName (int numName);
    std::vector<sf::RectangleShape> createRecommendationsButton();
    std::vector<sf::RectangleShape> createGameListImage();
    std::vector<sf::Text> createListName();
    std::vector<sf::Text> createListDescription();
    std::vector<sf::Text> createListPrice();
    std::vector<sf::Text> createListDeveloper();

    std::vector<std::vector<sf::RectangleShape>> createStarsEstimation();

    //// Окна
    void gameWindowCreate(sf::Event event);
    void mainWindowCreate();

    //// Генератор списка игр
    std::vector<sf::RectangleShape> gameListGenerator();
};