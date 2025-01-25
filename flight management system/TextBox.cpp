#include "TextBox.h"
#include<iostream>
using namespace std;
TextBox::TextBox(float x, float y, float width, float height, int limit, std::string placeholder) : isActive(false), inputLimit(limit) {
    if (!font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\Cambridge Round Bold.otf")) {
        cout << "Error loading font!";
    }
    box.setPosition(sf::Vector2f(x, y));
    box.setSize(sf::Vector2f(width, height));
    box.setFillColor(sf::Color::Color(45, 45, 45));
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::Black);

    txt.setFillColor(sf::Color::White);
    txt.setPosition(x + 5, y + 5);
    txt.setFont(font);
    Placeholder.setPosition(x + 5, y + 10);
    Placeholder.setFont(font);
    Placeholder.setFillColor(sf::Color(220, 220, 220));
    Placeholder.setString(placeholder);
    Placeholder.setCharacterSize(18);
}

void TextBox::draw(sf::RenderWindow& window) const {
    window.draw(box);
    window.draw(txt);
    if (getInput().empty()) {
        window.draw(Placeholder);
    }
}

void TextBox::setActive(bool active) {
    isActive = active;
    box.setOutlineColor(isActive ? sf::Color::White : sf::Color::Black);
}

bool TextBox::contains(float x, float y) const {
    return box.getGlobalBounds().contains(x, y);
}

void TextBox::handleInput(sf::Event& evnt) {
    std::string input = "";
    if (!isActive)
        return;

    if (evnt.type == sf::Event::TextEntered) {
        if (evnt.text.unicode == '\b') {            // Backspace key
            if (!txt.getString().isEmpty()) {
                input = txt.getString();
                input.pop_back();
                txt.setString(input);
            }
        }
        else if (evnt.text.unicode < 128 && txt.getString().getSize() < inputLimit) { // ASCII characters
            txt.setString(txt.getString() + static_cast<char>(evnt.text.unicode));
        }
    }
}

std::string TextBox::getInput() const {
    return txt.getString();
}

bool TextBox::getActive() const {
    return isActive;
}

void TextBox::clearInput() {
    txt.setString("");
}