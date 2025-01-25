#include "RenderFunctions.h"
#include "Flight.h"
#include "HelperFunctions.h"
#include <iostream>
#include<SFML/Graphics.hpp>
#include <vector>
#include "TextBox.h"
void renderInput(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, departure dpt, arrival arv, int& j, bool f) {
    if (f) {
        txt.setFont(font);
        txt.setString(dpt.departureTime);
        txt.setFillColor(sf::Color(255, 244, 24));
        txt.setCharacterSize(40);
        txt.setPosition(35, 405 + j);
        txt.setLetterSpacing(2);
        window.draw(txt);
        txt.setString(dpt.destination);
        txt.setPosition(245, 405 + j);
        window.draw(txt);
        txt.setString(dpt.flightNo);
        txt.setPosition(725, 405 + j);
        window.draw(txt);
        txt.setString(dpt.status);
        txt.setPosition(1085, 405 + j);
        dpt.updateStatusColor(txt);
        window.draw(txt);
        j += 60;
    }
    else {
        txt.setFont(font);
        txt.setString(arv.arrivalTime);
        txt.setFillColor(sf::Color(255, 244, 24));
        txt.setCharacterSize(40);
        txt.setPosition(35, 405 + j);
        txt.setLetterSpacing(2);
        window.draw(txt);
        txt.setString(arv.from);
        txt.setPosition(245, 405 + j);
        window.draw(txt);
        txt.setString(arv.flightNo);
        txt.setPosition(725, 405 + j);
        window.draw(txt);
        txt.setString(arv.status);
        txt.setPosition(1085, 405 + j);
        dpt.updateStatusColor(txt);
        window.draw(txt);
        j += 60;
    }
}

void renderTable(sf::RenderWindow& window, departure dpt[], arrival arv[], int arvn, int dptn, bool isDeparture, TextBox searchBar) {
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\Cambridge Round Bold.otf")) {
        return;
    }

    sf::Text txt;
    txt.setFont(font);

    sf::RectangleShape titleTable(sf::Vector2f(1500, 120));
    titleTable.setPosition(0, 260);
    titleTable.setFillColor(sf::Color(36, 36, 36));
    window.draw(titleTable);
    sf::RectangleShape subTitleTable(sf::Vector2f(1500, 30));
    subTitleTable.setFillColor(sf::Color(17, 17, 17));
    subTitleTable.setPosition(0, 230);
    window.draw(subTitleTable);
    subTitleTable.setPosition(0, 380);
    window.draw(subTitleTable);
    txt.setString("TIME");
    txt.setPosition(60, 380);
    txt.setFillColor(sf::Color::White);
    txt.setCharacterSize(25);
    window.draw(txt);
    if (isDeparture)
        txt.setString("DESTINATION");
    else
        txt.setString("FROM");
    txt.setPosition(250, 380);
    window.draw(txt);
    txt.setString("FLIGHT NO.");
    txt.setPosition(725, 380);
    window.draw(txt);
    txt.setString("REMARK");
    txt.setPosition(1100, 380);
    window.draw(txt);
    if (isDeparture)
        txt.setString("DEPARTURES");
    else
        txt.setString("ARRIVALS");

    txt.setLetterSpacing(5);
    txt.setFillColor(sf::Color(255, 244, 24));
    txt.setPosition(490, 290);
    txt.setCharacterSize(50);
    window.draw(txt);

    sf::RectangleShape notificationBar(sf::Vector2f(1500, 80));
    notificationBar.setPosition(0, 900);
    notificationBar.setFillColor(sf::Color(18, 18, 18));
    window.draw(notificationBar);

    sf::RectangleShape row1(sf::Vector2f(1440, 40));
    row1.setFillColor(sf::Color(45, 45, 45));
    sf::RectangleShape row2(sf::Vector2f(1500, 10));
    row2.setFillColor(sf::Color(18, 18, 18));
    sf::RectangleShape col(sf::Vector2f(5, 40));
    col.setFillColor(sf::Color::Black);

    for (int i = 0; i < 450; i += 60) {
        row1.setPosition(30, 415 + i);
        window.draw(row1);

        row2.setPosition(0, 460 + i);
        window.draw(row2);
        for (int j = 0; j < 1500; j += 30) {
            col.setPosition(60 + j, 415 + i);
            window.draw(col);
        }
    }

    sf::Font tableFont;
    if (!font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\bitblox-monospaced.otf")) {
        return;
    }
    if (searchBar.getInput().empty()) {
        if (isDeparture) {
            int j = 0;
            for (int i = 0; i < dptn; i++)
                renderInput(txt, font, window, dpt[i], arv[i], j, isDeparture);
        }
        else {
            int j = 0;
            for (int i = 0; i < arvn; i++)
                renderInput(txt, font, window, dpt[i], arv[i], j, isDeparture);
        }
    }
}

void displaySearch(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, std::vector<departure>fillteredDpt, std::vector<arrival> fillteredArv, bool f) {
    font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\bitblox-monospaced.otf");
    if (f) {
        int j = 0;
        for (int i = 0; i < fillteredDpt.size(); i++) {
            txt.setFont(font);
            txt.setString(fillteredDpt[i].departureTime);
            txt.setFillColor(sf::Color(255, 244, 24));
            txt.setCharacterSize(40);
            txt.setPosition(35, 405 + j);
            txt.setLetterSpacing(2);
            window.draw(txt);
            txt.setString(fillteredDpt[i].destination);
            txt.setPosition(245, 405 + j);
            window.draw(txt);
            txt.setString(fillteredDpt[i].flightNo);
            txt.setPosition(725, 405 + j);
            window.draw(txt);
            txt.setString(fillteredDpt[i].status);
            txt.setPosition(1085, 405 + j);
            fillteredDpt[i].updateStatusColor(txt);
            window.draw(txt);
            j += 60;
        }
    }
    else {
        int j = 0;
        for (int i = 0; i < fillteredArv.size(); i++) {
            txt.setFont(font);
            txt.setString(fillteredArv[i].arrivalTime);
            txt.setFillColor(sf::Color(255, 244, 24));
            txt.setCharacterSize(40);
            txt.setPosition(35, 405 + j);
            txt.setLetterSpacing(2);
            window.draw(txt);
            txt.setString(fillteredArv[i].from);
            txt.setPosition(245, 405 + j);
            window.draw(txt);
            txt.setString(fillteredArv[i].flightNo);
            txt.setPosition(725, 405 + j);
            window.draw(txt);
            txt.setString(fillteredArv[i].status);
            txt.setPosition(1085, 405 + j);
            fillteredArv[i].updateStatusColor(txt);
            window.draw(txt);
            j += 60;
        }
    }
}

void handleSearch(TextBox& textBox, departure dpt[], int dptn, arrival arv[], int arvn, std::vector<departure>& fillteredDpt, std::vector<arrival>& fillteredArv, bool f) {
    if (textBox.getInput().empty()) {
        return;
    }
    if (f) {
        fillteredDpt.clear();
        for (int i = 0; i < dptn; ++i) {
            if (to_lower(dpt[i].status).find(to_lower(textBox.getInput())) != std::string::npos
                || dpt[i].departureTime.find(textBox.getInput()) != std::string::npos || to_lower(dpt[i].flightNo).find(to_lower(textBox.getInput())) != std::string::npos || to_lower(dpt[i].destination).find(to_lower(textBox.getInput())) != std::string::npos) {
                fillteredDpt.push_back(dpt[i]);
            }
        }
    }
    else {
        fillteredArv.clear();
        for (int i = 0; i < arvn; i++) {
            if (to_lower(arv[i].status).find(to_lower(textBox.getInput())) != std::string::npos
                || arv[i].arrivalTime.find(textBox.getInput()) != std::string::npos || to_lower(arv[i].flightNo).find(to_lower(textBox.getInput())) != std::string::npos || to_lower(arv[i].from).find(to_lower(textBox.getInput())) != std::string::npos) {
                fillteredArv.push_back(arv[i]);
            }
        }
    }
}

void getNotification(sf::RenderWindow& window, std::string flightNo, std::string msg, bool isNotification) {
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\bitblox-monospaced.otf")) {
        return;
    }

    sf::Text notification;
    notification.setPosition(50, 920);
    notification.setFont(font);
    notification.setFillColor(sf::Color::Color(255, 255, 24));
    notification.setString("FLIGHT NO." + flightNo + " WAS " + msg);
    if (isNotification)
        window.draw(notification);
}

void updateFlightStatus(departure dpt[], arrival arv[], int dptn, int arvn, bool isDeparture,int Count) {
    if (isDeparture) {
        for (int i = 0; i < dptn; i++) {
            if (Count == 0) {
                dpt[i].status = "DELAYED";
            }
            else if (Count == 1) {
                dpt[i].status = "ONTIME";
            }
            else if (Count == 2) {
                dpt[i].status = "CANCELLED";
            }
            else {
                dpt[i].status = "BOARDING";
            }
        }
        Count++;
    }
    else {
        for (int i = 0; i < arvn; i++) {
            if (Count == 0) {
                arv[i].status = "DELAYED";
            }
            else if (Count == 1) {
                arv[i].status = "ONTIME";
            }
            else if (Count == 2) {
                arv[i].status = "CANCELLED";
            }
            else {
                arv[i].status = "BOARDING";
            }
            Count++;
        }
    }
}