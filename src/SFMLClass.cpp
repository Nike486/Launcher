#include "SFMLClass.h"


sf::RectangleShape SFML::button (sf::Color color,
                                 sf::Vector2f size,
                                 sf::Vector2f position)
{
    sf::RectangleShape button;
    button.setFillColor(color);
    button.setSize(size);
    button.setPosition(position);

    return button;
}

sf::Text SFML::text (const sf::Font& font,
                     const sf::String& setText,
                     unsigned int characterSize,
                     sf::Color color,
                     sf::Vector2f position)
{
    sf::Text text;
    text.setFont(font);
    text.setString(setText);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(position);

    return text;
}

sf::RectangleShape SFML::image (const sf::Texture& gameImageTexture,
                                sf::Color fillColor,
                                sf::Vector2f size,
                                sf::Vector2f position)
{
    sf::RectangleShape gameImage;
    gameImage.setTexture(&gameImageTexture);
    gameImage.setFillColor(fillColor);
    gameImage.setSize(size);
    gameImage.setPosition(position);

    return gameImage;
}

sf::RectangleShape SFML::line (sf::Color color,
                               sf::Vector2f size,
                               sf::Vector2f position)
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(color);
    rectangle.setSize(size);
    rectangle.setPosition(position);

    return rectangle;
}


sf::Texture SFML::imageTexture (std::vector<std::vector<std::string>> linkImages,
                                int numName,
                                int numImage)
{
    sf::Texture gameImageTexture;
    gameImageTexture.loadFromFile(linkImages[numName][numImage]);
    gameImageTexture.setSmooth(true);

    return gameImageTexture;
}

sf::Texture SFML::imageTexture(std::vector<std::string> linkImages,
                               int numName)
{
    sf::Texture gameImageTexture;
    gameImageTexture.loadFromFile(linkImages[numName]);
    gameImageTexture.setSmooth(true);

    return gameImageTexture;
}

sf::Font SFML::fontCalibriBold ()
{
    sf::Font font;
    font.loadFromFile(".\\fonts\\calibri-bold.ttf");
    return font;
}

sf::Font SFML::fontCalibriRegular()
{
    sf::Font font;
    font.loadFromFile(".\\fonts\\Geologica.ttf");
    return font;
}

sf::Color SFML::customGrey ()
{
    sf::Color color = sf::Color(41,49,51);
    return color;
}