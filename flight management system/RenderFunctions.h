#ifndef RENDERFUNCTIONS_H
#define RENDERFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Flight.h"
#include "TextBox.h"

void renderInput(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, departure dpt, arrival arv, int& j, bool f);
void renderTable(sf::RenderWindow& window, departure dpt[], arrival arv[], int arvn, int dptn, bool isDeparture, TextBox searchBar);
void displaySearch(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, std::vector<departure>fillteredDpt, std::vector<arrival> fillteredArv, bool f);
void handleSearch(TextBox& textBox, departure dpt[], int dptn, arrival arv[], int arvn, std::vector<departure>& fillteredDpt, std::vector<arrival>& fillteredArv, bool f);
void getNotification(sf::RenderWindow& window, std::string flightNo, std::string msg, bool isNotification);
void updateFlightStatus(departure dpt[], arrival arv[], int dptn, int arvn, bool isDeparture);

#endif // RENDERFUNCTIONS_H