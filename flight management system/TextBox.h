#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
private:
    sf::RectangleShape box;
    sf::Text txt;
    sf::Text Placeholder;
    sf::Font font;
    bool isActive;
    int inputLimit;

public:
    TextBox(float x, float y, float width, float height, int limit, std::string placeholder);
    void draw(sf::RenderWindow& window) const;
    void setActive(bool active);
    bool contains(float x, float y) const;
    void handleInput(sf::Event& evnt);
    std::string getInput() const;
    bool getActive() const;
    void clearInput();
};

#endif // TEXTBOX_H