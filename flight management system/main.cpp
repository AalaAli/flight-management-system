#include "Flight.h"
#include "TextBox.h"
#include "Button.h"
#include "HelperFunctions.h"
#include "RenderFunctions.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include<iostream>
int Count = 0;
using namespace std;
int main() {
    const string fileName1 = "C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\Flights data\\departure data";
    const string fileName2 = "C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\Flights data\\arrival data";

    sf::RenderWindow window(sf::VideoMode(1500, 980), "Flight Management System", sf::Style::Close | sf::Style::Titlebar);
    departure dpt[10]; arrival arv[10];
    vector<departure>fillteredDpt;
    vector<arrival>fillteredArv;
    int dptn = loadFromFile(dpt, arv, Size, fileName1, 1), arvn = loadFromFile(dpt, arv, Size, fileName2, 0);

    sf::Text txt;
    string flightNo, msg;
    int homePage = 1, departurePage = 2, arrivalPage = 3;
    bool searchBtnisActive = false, isNotification = false;
    sf::Clock updateClock, notifiClock;

    TextBox textBoxes[5] = {
        TextBox(20, 80, 90, 40, 5, "time"),
        TextBox(140, 80, 90, 40, 4, "flightNo"),
        TextBox(260, 80, 250, 40, 13, "destination"),
        TextBox(540, 80, 250, 40, 13, "remark..."),
        TextBox(20, 140, 350, 40, 18, "search by time or remark or fNo")
    };

    Button button[3]{
        Button(800, 80, 90, 40, "ADD"),
        Button(900, 80, 90, 40, "DELETE"),
        Button(1000, 80, 90, 40, "UPDATE"),
    };

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\fonts\\Cambridge Round Bold.otf")) {
        return -1; // Handle font loading error
    }

    sf::Texture txtHome, txtDeparture, txtArrival, txtSearch;
    txtHome.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\images\\home.jpeg");
    sf::Sprite homeBtn, departureBtn, arrivalBtn, searchBtn;
    homeBtn.setTexture(txtHome);
    homeBtn.setScale(0.1f, 0.1f);

    txtDeparture.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\images\\departure.png");
    departureBtn.setTexture(txtDeparture);
    txtArrival.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\images\\arrival.png");
    arrivalBtn.setTexture(txtArrival);
    txtSearch.loadFromFile("C:\\Users\\Pc\\OneDrive\\computer graphics\\flight management system\\images\\search.png");
    searchBtn.setTexture(txtSearch);
    searchBtn.setPosition(375, 142);
    searchBtn.setScale(0.4f, 0.4f);
    sf::RectangleShape searchBack(sf::Vector2f(40, 40));
    searchBack.setFillColor(sf::Color(45, 45, 45));
    searchBack.setPosition(372, 140);

    int currentPage = homePage;

    sf::Text notification;
    notification.setPosition(100, 920);
    notification.setFont(font);
    notification.setFillColor(sf::Color::White);

    sf::Text text("", font, 24);
    text.setPosition(60, 160); // Offset a bit inside the input box
    text.setFillColor(sf::Color::White);

    // String to store user input
    std::string userInput;

    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                window.close();
            }

            if (evnt.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(evnt.mouseButton.x, evnt.mouseButton.y);
                for (int i = 0; i < 5; i++) {
                    textBoxes[i].setActive(textBoxes[i].contains(mousePos.x, mousePos.y));
                }
            }
            for (int i = 0; i < 5; i++) {
                textBoxes[i].handleInput(evnt);
            }
        }

        sf::Vector2f mousePos(evnt.mouseButton.x, evnt.mouseButton.y);

        if (evnt.type == sf::Event::MouseButtonPressed) {
            if (evnt.mouseButton.button == sf::Mouse::Left) {
                if (currentPage == homePage && departureBtn.getGlobalBounds().contains(mousePos)) {
                    currentPage = departurePage;
                }
                else if (currentPage == homePage && arrivalBtn.getGlobalBounds().contains(mousePos)) {
                    currentPage = arrivalPage;
                }
                else if (currentPage == departurePage && homeBtn.getGlobalBounds().contains(mousePos)) {
                    currentPage = homePage;
                }
                else if (currentPage == departurePage && arrivalBtn.getGlobalBounds().contains(mousePos)) {
                    currentPage = arrivalPage;
                }
                else if (currentPage == arrivalPage && homeBtn.getGlobalBounds().contains(mousePos)) {
                    currentPage = homePage;
                }
                else if (currentPage == arrivalPage && departureBtn.getGlobalBounds().contains(mousePos)) {
                    currentPage = departurePage;
                }

                if (button[0].contains(mousePos.x, mousePos.y)) {
                    button[0].setActive(true);
                }
                else if (button[1].contains(mousePos.x, mousePos.y)) {
                    button[1].setActive(true);
                }
                else if (button[2].contains(mousePos.x, mousePos.y)) {
                    button[2].setActive(true);
                }
                if (searchBtn.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    searchBtnisActive = true;
                }
            }
        }

        if (evnt.type == sf::Event::MouseButtonReleased && evnt.mouseButton.button == sf::Mouse::Left) {
            if (button[0].getActive() && button[0].contains(mousePos.x, mousePos.y)) {
                msg = "ADDED";

                if (currentPage == departurePage) {
                    dpt[dptn].addFlight(textBoxes[0].getInput(), textBoxes[1].getInput(), textBoxes[2].getInput(), textBoxes[3].getInput(), dpt, dptn);
                }
                else if (currentPage == arrivalPage) {
                    arv[arvn].addFlight(textBoxes[0].getInput(), textBoxes[1].getInput(), textBoxes[2].getInput(), textBoxes[3].getInput(), arv, arvn);
                }
                isNotification = true;
                flightNo = textBoxes[1].getInput();
                button[0].setActive(false);
                for (int i = 0; i < 4; i++)
                    textBoxes[i].clearInput();
            }
            else if (button[1].getActive() && button[1].contains(mousePos.x, mousePos.y)) {
                msg = "DELETED";

                if (currentPage == departurePage) {
                    deleteFlightDpt(dpt, dptn, textBoxes[1].getInput());
                }
                else if (currentPage == arrivalPage) {
                    deleteFlightArv(arv, arvn, textBoxes[1].getInput());
                }
                isNotification = true;
                flightNo = textBoxes[1].getInput();
                button[1].setActive(false);
                for (int i = 0; i < 4; i++)
                    textBoxes[i].clearInput();
            }
            else if (button[2].getActive() && button[2].contains(mousePos.x, mousePos.y)) {
                msg = "UPDATED";
                if (currentPage == departurePage) {
                    dpt[searchdpt(dpt, dptn, textBoxes[1].getInput())].updateFlight(textBoxes[0].getInput(), textBoxes[1].getInput(), textBoxes[2].getInput(), textBoxes[3].getInput());
                    flightNo = textBoxes[1].getInput();
                }
                else if (currentPage == arrivalPage) {
                    arv[searcharv(arv, arvn, textBoxes[1].getInput())].updateFlight(textBoxes[0].getInput(), textBoxes[1].getInput(), textBoxes[2].getInput(), textBoxes[3].getInput());
                    flightNo = textBoxes[1].getInput();
                }
                isNotification = true;
                button[2].setActive(false);
                for (int i = 0; i < 4; i++)
                    textBoxes[i].clearInput();
            }
            if (searchBtnisActive == true && searchBtn.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                if (currentPage == departurePage) {
                    handleSearch(textBoxes[4], dpt, dptn, arv, arvn, fillteredDpt, fillteredArv, 1);
                }
                else {
                    handleSearch(textBoxes[4], dpt, dptn, arv, arvn, fillteredDpt, fillteredArv, 0);
                }
                searchBtnisActive = false;
            }
        }

        if (currentPage == homePage) {
            sf::Text txt;
            txt.setFont(font);
            window.clear(sf::Color::Black);

            // Create the title text
            sf::Text title;
            title.setFont(font);             // Set the font
            title.setString("Flight Management System");   // Set the title string
            title.setCharacterSize(60);      // Set the title size
            title.setFillColor(sf::Color::Yellow); // Set the title color
            title.setPosition(350, 350); // Position at the top center 
            window.draw(title);
            departureBtn.setPosition(450, 450);
            arrivalBtn.setPosition(790, 450);
            departureBtn.setScale(0.2f, 0.2f);
            arrivalBtn.setScale(0.1f, 0.1f);
            txt.setString("DEPARTURES");
            txt.setPosition(450, 700);
            txt.setFillColor(sf::Color::White);
            txt.setCharacterSize(40);
            window.draw(txt);
            txt.setString("ARRIVALS");
            txt.setPosition(790, 700);
            window.draw(txt);
            window.draw(departureBtn);
            window.draw(arrivalBtn);
        }
        else if (currentPage == departurePage) {
            window.clear(sf::Color::Black);
            renderTable(window, dpt, arv, arvn, dptn, 1, textBoxes[4]);
            homeBtn.setPosition(20, 20);
            window.draw(homeBtn);
            arrivalBtn.setScale(0.025f, 0.025f);
            arrivalBtn.setPosition(100, 20);
            window.draw(arrivalBtn);
            for (int i = 0; i < 5; i++) {
                textBoxes[i].draw(window);
            }
            for (int i = 0; i < 3; i++) {
                button[i].draw(window);
            }
            window.draw(searchBack);
            window.draw(searchBtn);

            if (!textBoxes[4].getInput().empty())
                displaySearch(txt, font, window, fillteredDpt, fillteredArv, 1);

            getNotification(window, flightNo, msg, isNotification);

            if (updateClock.getElapsedTime().asSeconds() > 5.0f) {
                updateFlightStatus(dpt, arv, dptn, arvn, 1,Count);
                updateClock.restart();
                if (Count > 3)
                    Count = 0;
            }
            if (notifiClock.getElapsedTime().asSeconds() > 10.0f) {
                isNotification = false;
                notifiClock.restart();
            }
        }
        else if (currentPage == arrivalPage) {
            window.clear(sf::Color::Black);
            renderTable(window, dpt, arv, arvn, dptn, 0, textBoxes[4]);
            homeBtn.setPosition(20, 20);
            window.draw(homeBtn);
            departureBtn.setScale(0.05f, 0.05f);
            departureBtn.setPosition(110, 20);
            window.draw(departureBtn);
            for (int i = 0; i < 5; i++) {
                textBoxes[i].draw(window);
            }
            for (int i = 0; i < 3; i++) {
                button[i].draw(window);
            }
            window.draw(searchBack);
            window.draw(searchBtn);

            if (!textBoxes[4].getInput().empty())
                displaySearch(txt, font, window, fillteredDpt, fillteredArv, 0);

            getNotification(window, flightNo, msg, isNotification);

            if (updateClock.getElapsedTime().asSeconds() > 5.0f) {
                updateFlightStatus(dpt, arv, dptn, arvn, 0,Count);
                updateClock.restart(); if (Count > 3)
                    Count = 0;
            }
            if (notifiClock.getElapsedTime().asSeconds() > 10.0f) {
                isNotification = false;
                notifiClock.restart();
            }
        }

        // Display the rendered frame
        window.display();
    }

    saveToFile(dpt, arv, dptn, arvn, fileName1, 1);
    saveToFile(dpt, arv, dptn, arvn, fileName2, 0);

    return 0;
}