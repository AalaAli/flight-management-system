#include "Button.h"
#include<iostream>

Button::Button(float x, float y, float width, float height, std::string str) : isActive(false) {
    if (!font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\Cambridge Round Bold.otf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    btn.setPosition(sf::Vector2f(x, y));
    btn.setSize(sf::Vector2f(width, height));
    btn.setFillColor(sf::Color(255, 244, 24));
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(20);

    sf::FloatRect textBounds = txt.getLocalBounds();
    txt.setPosition(btn.getPosition().x + (btn.getSize().x - textBounds.width) / 2 - textBounds.left,
        btn.getPosition().y + (btn.getSize().y - textBounds.height) / 2 - textBounds.top);
    txt.setFillColor(sf::Color::White);
}

void Button::setActive(bool f) {
    isActive = f;
}

bool Button::getActive() const {
    return isActive;
}

bool Button::contains(float x, float y) const {
    return btn.getGlobalBounds().contains(x, y);
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(btn);
    window.draw(txt);
}