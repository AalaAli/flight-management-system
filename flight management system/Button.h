#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape btn;
    sf::Text txt;
    sf::Font font;
    bool isActive;

public:
    Button(float x, float y, float width, float height, std::string str);
    void setActive(bool f);
    bool getActive() const;
    bool contains(float x, float y) const;
    void draw(sf::RenderWindow& window) const;
};

#endif // BUTTON_H