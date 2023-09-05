#include "SFMLContent.h"


void Set::GameWindowCreate (sf::Event event)
{
    gamesWindow.create(sf::VideoMode(1600, 900), "Games");
    gamesWindow.setVerticalSyncEnabled(true);
    gamesWindow.setFramerateLimit(60);

    while (gamesWindow.isOpen())
    {
        while (gamesWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gamesWindow.close();
                mainWindow.create(sf::VideoMode(1600, 900), "Launcher");
            }
        }

        gamesWindow.clear(sf::Color(208,208,208));
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
        }

        if (buttonGames.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            textButtonGames.setFillColor(sf::Color::White);
        } else
        {
            textButtonGames.setFillColor(sf::Color(208, 208, 208));
        }

        if (buttonInfo.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            textButtonInfo.setFillColor(sf::Color::White);
        } else
        {
            textButtonInfo.setFillColor(sf::Color(208, 208, 208));
        }

        if (buttonLibrary.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            textButtonLibrary.setFillColor(sf::Color::White);
        } else
        {
            textButtonLibrary.setFillColor(sf::Color(208, 208, 208));
        }

        gameImageTextureBase = imageTexture(linkImages, numRecommendationsGame, 0);
        for (int i = 1; i < gameImageRecommendation.size(); ++i)
        {
            if (gameImageRecommendation[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                gameImageRecommendation[i].setFillColor(sf::Color(255, 255, 255, 255));
                gameImageTextureBase = imageTexture(linkImages, numRecommendationsGame, i);
            }
            else
            {
                gameImageRecommendation[i].setFillColor(sf::Color(255, 255, 255, 120));
            }
        }

        if (buttonPrevious.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
           buttonPrevious.setFillColor(sf::Color(255, 255, 255, 200));
        }
        else if (buttonNext.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            buttonNext.setFillColor(sf::Color(255, 255, 255, 200));
        }
        else
        {
            buttonPrevious.setFillColor(sf::Color(255, 255, 255, 50));
            buttonNext.setFillColor(sf::Color(255, 255, 255, 50));
        }


        if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            if (buttonNext.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                numRecommendationsGame ++;
                if(numRecommendationsGame == linkImages.size())
                {
                    numRecommendationsGame = 0;
                }
                createRecommendationsImage (numRecommendationsGame);
                textNameGame.setString(listRecommendationsGames[numRecommendationsGame]);
            }
            else if (buttonPrevious.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
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

        mainWindow.draw(buttonGames);
        mainWindow.draw(buttonLibrary);
        mainWindow.draw(buttonInfo);

        for (const auto & i : gameImageRecommendation)
        {
            mainWindow.draw(i);
        }


        mainWindow.draw(buttonPrevious);
        mainWindow.draw(buttonNext);

        for (const auto& getRecommendationButtons : recommendationsButtons)
        {
            mainWindow.draw(getRecommendationButtons);
        }

        mainWindow.draw(textButtonGames);
        mainWindow.draw(textButtonInfo);
        mainWindow.draw(textButtonLibrary);
        mainWindow.draw(textNameGame);

        mainWindow.display();
    }
}

void Set::createRecommendationsImage (int numName)
{
    gameImageRecommendation.clear();

    if (!linkImages[numName].empty())
    {
        gameImageTextureBase = imageTexture(linkImages, numName, 0);
        gameImageRecommendation.push_back(image(
                gameImageTextureBase,
                sf::Color(255, 255, 255, 255),
                sf::Vector2f(750.0f, 450.0f),
                sf::Vector2f(200.0f, 400.0f)));
    }

    if (linkImages[numName].size() >= 2)
    {
        gameImageTextureOne = imageTexture(linkImages, numName, 1);
        gameImageRecommendation.push_back(image(
                gameImageTextureOne,
                sf::Color(255, 255, 255, 120),
                sf::Vector2f(210.0f, 100.0f),
                sf::Vector2f(960.0f, 500.0f)));
    }

    if (linkImages[numName].size() >= 3)
    {
        gameImageTextureTwo = imageTexture(linkImages, numName, 2);
        gameImageRecommendation.push_back(image(
                gameImageTextureTwo,
                sf::Color(255, 255, 255, 120),
                sf::Vector2f(210.0f, 100.0f),
                sf::Vector2f(1180.0f, 500.0f)));
    }

    if (linkImages[numName].size() >= 4)
    {
        gameImageTextureThree = imageTexture(linkImages, numName, 3);
        gameImageRecommendation.push_back(image(
                gameImageTextureThree,
                sf::Color(255, 255, 255, 120),
                sf::Vector2f(210.0f, 100.0f),
                sf::Vector2f(960.0f, 610.0f)));
    }
    if (linkImages[numName].size() >= 5)
    {
        gameImageTextureFour = imageTexture(linkImages, numName, 4);
        gameImageRecommendation.push_back(image(
                gameImageTextureFour,
                sf::Color(255, 255, 255, 120),
                sf::Vector2f(210.0f, 100.0f),
                sf::Vector2f(1180.0f, 610.0f)));
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