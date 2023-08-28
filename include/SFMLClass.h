#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class SFML
{
protected:

    //// Фунуция для создания кнопки
    sf::RectangleShape button (sf::Color color,
                               sf::Vector2f size,
                               sf::Vector2f position);

    //// Фунуция для создания текста
    sf::Text text (const sf::Font& font,
                   const sf::String& setText,
                   unsigned int characterSize,
                   sf::Color color,
                   sf::Vector2f position);

    //// Фунуция для создания картинки
    sf::RectangleShape image (const sf::Texture& gameImageTexture,
                              sf::Color fillColor,
                              sf::Vector2f size,
                              sf::Vector2f position);

    //// Фунуция для создания прямоугольника
    sf::RectangleShape line (sf::Color color,
                             sf::Vector2f size,
                             sf::Vector2f position);

    //// Фунуция для создания текстуры
    sf::Texture imageTexture (std::vector<std::string> linkImages,
                              int num);

    //// Фунуция для создания шрифта Calibri
    sf::Font fontCalibri();

    //// Фунуция для создания цвета (серый)
    sf::Color customGrey();

};