#include "SFMLContent.h"


void Set::createRecommendationsImage (int numName)
{
    gameImageRecommendation.clear();
    imageTextureInRecommendation.clear();

    for (int i = 0; i < linkImages[numName].size(); ++i)
    {
        imageTextureInRecommendation.emplace_back(imageTexture(linkImages, numName, i));
    }

    for (int i = 0; i < linkImages[numName].size(); ++i)
    {
        switch (i)
        {
            case 0:
                gameImageRecommendation.emplace_back(image(
                        imageTextureInRecommendation[i],
                        sf::Color(255, 255, 255, 255),
                        sf::Vector2f(750.0f, 450.0f),
                        sf::Vector2f(200.0f, 400.0f)));
                break;
            case 1:
                gameImageRecommendation.emplace_back(image(
                        imageTextureInRecommendation[i],
                        sf::Color(255, 255, 255, 120),
                        sf::Vector2f(210.0f, 100.0f),
                        sf::Vector2f(960.0f, 500.0f)));
                break;
            case 2:
                gameImageRecommendation.emplace_back(image(
                        imageTextureInRecommendation[i],
                        sf::Color(255, 255, 255, 120),
                        sf::Vector2f(210.0f, 100.0f),
                        sf::Vector2f(1180.0f, 500.0f)));
                break;
            case 3:
                gameImageRecommendation.emplace_back(image(
                        imageTextureInRecommendation[i],
                        sf::Color(255, 255, 255, 120),
                        sf::Vector2f(210.0f, 100.0f),
                        sf::Vector2f(960.0f, 610.0f)));
                break;
            case 4:
                gameImageRecommendation.emplace_back(image(
                        imageTextureInRecommendation[i],
                        sf::Color(255, 255, 255, 120),
                        sf::Vector2f(210.0f, 100.0f),
                        sf::Vector2f(1180.0f, 610.0f)));
                break;
            default:
                return;
        }
    }
}

void Set::createRecommendationsName(int numName)
{
    if(!listRecommendationsGames.empty())
    {
        textNameGame = text(
                fontCalibriBold,
                listRecommendationsGames[numName],
                35,
                sf::Color(208,208,208),
                sf::Vector2f (1000.0f, 425.0f));
    }
}

std::vector<sf::RectangleShape> Set::createRecommendationsButton()
{
    std::vector<sf::RectangleShape> listButtonRecommendation;
    auto deltaSize = 0.0f;
    auto step = 17.5f * (float)(listRecommendationsGames.size() - 1);

    for (auto i = 0; i < listRecommendationsGames.size(); i++)
    {
        if (i == 0)
        {
            listButtonRecommendation.push_back(image(
                    textureRecommendationButton,
                    sf::Color(255, 255, 255, 50),
                    sf::Vector2f (30.0f, 20.0f),
                    sf::Vector2f (785.0f - step, 860.0f)));
        }
        else
        {
            deltaSize += 35.0f;
            listButtonRecommendation.push_back(image(
                    textureRecommendationButton,
                    sf::Color(255, 255, 255, 50),
                    sf::Vector2f (30.0f, 20.0f),
                    sf::Vector2f (785.0f + deltaSize - step, 860.0f)));
        }
    }
    return listButtonRecommendation;
}

std::vector<sf::RectangleShape> Set::gameListGenerator()
{
    std::vector<sf::RectangleShape> gameListRectangle;

    float posY = 100.0f;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        gameListRectangle.emplace_back(
                line(
                customGrey,
                sf::Vector2f(1200.0f, 450.0f),
                sf::Vector2f(200.0f, posY)));

        posY += 500.0f;
    }

    return gameListRectangle;
}

std::vector<sf::RectangleShape> Set::createGameListImage()
{
    std::vector<sf::RectangleShape> gameImageList;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        imageTextureInGames.emplace_back(imageTexture(linkMainImgAllGames, i));
    }

    float posY = 100.0f;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        gameImageList.emplace_back(image(
                imageTextureInGames[i],
                sf::Color(255, 255, 255, 255),
                sf::Vector2f(750.0f, 450.0f),
                sf::Vector2f(200.0f, posY)));

        posY += 500.0f;
    }

    return gameImageList;
}

std::vector<std::vector<sf::RectangleShape>> Set::createStarsEstimation()
{
    std::vector<sf::RectangleShape> starsEstimation;
    std::vector<std::vector<sf::RectangleShape>> listStarsEstimation;

    float posX = 1050.0f;
    float posY = 470.0f;

    for (int k = 0; k < configGames.getlistGames().size(); ++k)
    {
        for (int i = 0; i < 5; ++i)
        {
            if(configGames.getEstimation(configGames.getlistGames()[k]) > i)
            {
                starsEstimation.emplace_back(image(
                        starsTexture[1],
                        sf::Color(255, 255, 255, 255),
                        sf::Vector2f(50.0f, 50.0f),
                        sf::Vector2f(posX, posY)));
            } else
            {
                starsEstimation.emplace_back(image(
                        starsTexture[0],
                        sf::Color(255, 255, 255, 255),
                        sf::Vector2f(50.0f, 50.0f),
                        sf::Vector2f(posX, posY)));
            }

            posX += 50.0f;
        }

        listStarsEstimation.emplace_back(starsEstimation);
        starsEstimation.clear();
        posY += 500.0f;
        posX = 1050.0f;
    }

    return listStarsEstimation;
}

std::vector<sf::Text> Set::createListDescription()
{
    std::vector<sf::Text> listDescription;
    float posY = 200.0f;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        listDescription.emplace_back(text(
                fontCalibriRegular,
                configGames.getDescription(configGames.getlistGames()[i]),
                15,
                sf::Color(208,208,208),
                sf::Vector2f (1000.0f, posY)));

        posY += 500.0f;
    }

    return listDescription;
}
std::vector<sf::Text> Set::createListPrice()
{
    std::vector<sf::Text> listPrice;
    float posY = 440.0f;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        listPrice.emplace_back(text(
                fontCalibriBold,
                listPriceWithRub[i],
                25,
                sf::Color(208,208,208),
                sf::Vector2f (1120.0f, posY)));

        posY += 500.0f;
    }

    return listPrice;
}
std::vector<sf::Text> Set::createListName()
{
    std::vector<sf::Text> listName;
    float posY = 130.0f;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        listName.emplace_back(text(
                fontCalibriBold,
                configGames.getlistGames()[i],
                35,
                sf::Color(208,208,208),
                sf::Vector2f (1000.0f, posY)));

        posY += 500.0f;
    }

    return listName;
}


std::vector<sf::Text> Set::createListDeveloper()
{
    std::vector<sf::Text> listDvlpr;
    float posY = 380.0f;

    for (int i = 0; i < configGames.getlistGames().size(); ++i)
    {
        listDvlpr.emplace_back(text(
                fontCalibriRegular,
                configGames.getListDeveloper()[i],
                15,
                sf::Color(208,208,208),
                sf::Vector2f (1000.0f, posY)));

        posY += 500.0f;
    }

    return listDvlpr;
}


void Set::gameWindowCreate (sf::Event event)
{
    sf::View view(sf::FloatRect(0.0f, 0.0f, 1600.f, 900.f));

    gamesWindow.create(sf::VideoMode(1600, 900), "Games");
    gamesWindow.setVerticalSyncEnabled(true);
    gamesWindow.setFramerateLimit(60);

    auto gameListRectangles = gameListGenerator();
    auto gameListImages = createGameListImage();
    auto gameListNames = createListName();
    auto starsEstimation = createStarsEstimation();
    auto gameDescription = createListDescription();
    auto gamePrice = createListPrice();
    auto gameDeveloper = createListDeveloper();

    while (gamesWindow.isOpen())
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(gamesWindow);
        while (gamesWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gamesWindow.close();
                mainWindow.create(sf::VideoMode(1600, 900), "Launcher");
            }

            if (event.mouseWheelScroll.delta == 1 && view.getCenter().y != 450)
            {
                view.move(0.0f, -50.0f);
            }
            else if (event.mouseWheelScroll.delta == -1 && view.getCenter().y <= (gameListRectangles[gameListRectangles.size() - 1].getPosition().y + 100))
            {
                view.move(0.0f, 50.0f);
            }
        }

        gamesWindow.clear(sf::Color(208,208,208));

        gamesWindow.setView(view);

        gamesWindow.draw(upLine);

        for (auto gameListRectangle : gameListRectangles)
        {
            gamesWindow.draw(gameListRectangle);
        }

        for (auto gameListImage : gameListImages)
        {
            gamesWindow.draw(gameListImage);
        }

        for (auto gameListName : gameListNames)
        {
            gamesWindow.draw(gameListName);
        }

        for (int i = 0; i < configGames.getlistGames().size(); ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                gamesWindow.draw(starsEstimation[i][j]);
            }
        }

        for (auto gameDesc : gameDescription)
        {
            gamesWindow.draw(gameDesc);
        }

        for (auto gamePrc : gamePrice)
        {
            gamesWindow.draw(gamePrc);
        }

        for (auto gameDvlpr : gameDeveloper)
        {
            gamesWindow.draw(gameDvlpr);
        }

        gamesWindow.display();
    }
}

void Set::mainWindowCreate()
{

    mainWindow.create(sf::VideoMode(1600, 900), "Launcher");
    mainWindow.setVerticalSyncEnabled(true);
    mainWindow.setFramerateLimit(60);

    int numRecommendationsGame = 0;

    createRecommendationsImage(numRecommendationsGame);
    createRecommendationsName(numRecommendationsGame);
    auto recommendationsButtons = createRecommendationsButton();
    textNameGame.setString(listRecommendationsGames[numRecommendationsGame]);

    while (mainWindow.isOpen())
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(mainWindow);
        sf::Event event{};

        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }

            if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                if (buttonGamesInfoLibrary[0].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    mainWindow.close();
                    gameWindowCreate(event);
                }
            }

            if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                if (buttonPreviousAndNext[1].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    numRecommendationsGame ++;
                    if(numRecommendationsGame == linkImages.size())
                    {
                        numRecommendationsGame = 0;
                    }
                    createRecommendationsImage (numRecommendationsGame);
                    textNameGame.setString(listRecommendationsGames[numRecommendationsGame]);
                }
                else if (buttonPreviousAndNext[0].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    numRecommendationsGame --;
                    if(numRecommendationsGame < 0)
                    {
                        numRecommendationsGame = linkImages.size() - 1;
                    }
                    createRecommendationsImage (numRecommendationsGame);
                    textNameGame.setString(listRecommendationsGames[numRecommendationsGame]);
                }

                for (int i = 0; i < recommendationsButtons.size(); ++i)
                {
                    if (recommendationsButtons[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                    {
                        numRecommendationsGame = i;
                        createRecommendationsImage (numRecommendationsGame);
                        textNameGame.setString(listRecommendationsGames[numRecommendationsGame]);
                    }
                }
            }

        }



        for (int i = 0; i < buttonGamesInfoLibrary.size(); ++i)
        {
            if (buttonGamesInfoLibrary[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                textGamesInfoLibrary[i].setFillColor(sf::Color::White);
            } else if (textGamesInfoLibrary[i].getFillColor() != sf::Color(208, 208, 208))
            {
                textGamesInfoLibrary[i].setFillColor(sf::Color(208, 208, 208));
            }
        }

        imageTextureInRecommendation[0] = imageTexture(linkImages, numRecommendationsGame, 0);
        for (int i = 1; i < gameImageRecommendation.size(); ++i)
        {
            if (gameImageRecommendation[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                gameImageRecommendation[i].setFillColor(sf::Color(255, 255, 255, 255));
                imageTextureInRecommendation[0] = imageTexture(linkImages, numRecommendationsGame, i);
            }
            else if (gameImageRecommendation[i].getFillColor() != sf::Color(255, 255, 255, 120))
            {
                gameImageRecommendation[i].setFillColor(sf::Color(255, 255, 255, 120));
            }
        }

        for (auto & getButtonPreviousAndNext : buttonPreviousAndNext)
        {
            if (getButtonPreviousAndNext.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                getButtonPreviousAndNext.setFillColor(sf::Color(255, 255, 255, 200));
            }
            else if (getButtonPreviousAndNext.getFillColor() != sf::Color(255, 255, 255, 50))
            {
                getButtonPreviousAndNext.setFillColor(sf::Color(255, 255, 255, 50));
            }
        }

        recommendationsButtons[numRecommendationsGame].setFillColor(sf::Color(255, 255, 255, 200));

        for (int i = 0; i < recommendationsButtons.size(); ++i)
        {
            if (recommendationsButtons[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                recommendationsButtons[i].setFillColor(sf::Color(255, 255, 255, 200));
            }
            else if (i != numRecommendationsGame)
            {
                recommendationsButtons[i].setFillColor(sf::Color(255, 255, 255, 50));
            }
        }


        mainWindow.clear(sf::Color(208, 208, 208));

        mainWindow.draw(upLine);
        mainWindow.draw(recommendationRectangle);

        mainWindow.draw(banner);

        for (const auto & i : buttonGamesInfoLibrary)
        {
            mainWindow.draw(i);
        }

        for (const auto & i : gameImageRecommendation)
        {
            mainWindow.draw(i);
        }

        for (auto & getButtonPreviousAndNext : buttonPreviousAndNext)
        {
            mainWindow.draw(getButtonPreviousAndNext);
        }

        for (const auto& getRecommendationButtons : recommendationsButtons)
        {
            mainWindow.draw(getRecommendationButtons);
        }

        for (const auto & i : textGamesInfoLibrary)
        {
            mainWindow.draw(i);
        }

        mainWindow.draw(textNameGame);

        mainWindow.display();
    }
}