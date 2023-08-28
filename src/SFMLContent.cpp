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

void Set::mainWindowCreate ()
{
    mainWindow.create(sf::VideoMode(1600, 900), "Launcher");
    mainWindow.setVerticalSyncEnabled(true);
    mainWindow.setFramerateLimit(60);

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
        }
        else
        {
            textButtonGames.setFillColor(sf::Color(208,208,208));
        }


        if (buttonInfo.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            textButtonInfo.setFillColor(sf::Color::White);
        }
        else
        {
            textButtonInfo.setFillColor(sf::Color(208,208,208));
        }



        if (buttonLibrary.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            textButtonLibrary.setFillColor(sf::Color::White);
        }
        else
        {
            textButtonLibrary.setFillColor(sf::Color(208,208,208));
        }



        if (buttonNext.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            buttonNext.setFillColor(sf::Color(255, 255, 255, 150));
        }
        else
        {
            buttonNext.setFillColor(sf::Color(255, 255, 255, 50));
        }

        if (buttonPrevious.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            buttonPrevious.setFillColor(sf::Color(255, 255, 255, 150));
        }
        else
        {
            buttonPrevious.setFillColor(sf::Color(255, 255, 255, 50));
        }





        if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {

            if (buttonGames.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {

                mainWindow.close();
                GameWindowCreate(event);
            }

            else if (buttonPrevious.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                numCentre++;
                numLeft++;
                numRight++;


                if (numCentre == linkImages.size())
                {
                    numCentre = 0;
                }
                gameImageTextureCentre.loadFromFile(linkImages[numCentre]);
                gameImageTextureCentre.setSmooth(true);

                gameImageCentre.setTexture(&gameImageTextureCentre);


                if (numLeft == linkImages.size())
                {
                    numLeft = 0;
                }
                gameImageTextureLeft.loadFromFile(linkImages[numLeft]);
                gameImageTextureLeft.setSmooth(true);

                gameImageLeft.setTexture(&gameImageTextureLeft);


                if (numRight == linkImages.size())
                {
                    numRight = 0;
                }
                gameImageTextureRight.loadFromFile(linkImages[numRight]);
                gameImageTextureRight.setSmooth(true);

                gameImageRight.setTexture(&gameImageTextureRight);
            }


            else if (buttonNext.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                numCentre--;
                numLeft--;
                numRight--;


                if (numCentre < 0)
                {
                    numCentre = linkImages.size() - 1;
                }
                gameImageTextureCentre.loadFromFile(linkImages[numCentre]);
                gameImageTextureCentre.setSmooth(true);

                gameImageCentre.setTexture(&gameImageTextureCentre);



                if (numLeft < 0)
                {
                    numLeft = linkImages.size() - 1;
                }
                gameImageTextureLeft.loadFromFile(linkImages[numLeft]);
                gameImageTextureLeft.setSmooth(true);

                gameImageLeft.setTexture(&gameImageTextureLeft);



                if (numRight < 0)
                {
                    numRight = linkImages.size() - 1;
                }
                gameImageTextureRight.loadFromFile(linkImages[numRight]);
                gameImageTextureRight.setSmooth(true);

                gameImageRight.setTexture(&gameImageTextureRight);
            }





        }


        mainWindow.clear(sf::Color(208,208,208));

        mainWindow.draw(upLine);

        mainWindow.draw(buttonGames);
        mainWindow.draw(buttonLibrary);
        mainWindow.draw(buttonInfo);
        mainWindow.draw(buttonNext);
        mainWindow.draw(buttonPrevious);

        mainWindow.draw(textButtonGames);
        mainWindow.draw(textButtonInfo);
        mainWindow.draw(textButtonLibrary);

        mainWindow.draw(gameImageCentre);
        mainWindow.draw(gameImageLeft);
        mainWindow.draw(gameImageRight);




        mainWindow.display();

    }

}


