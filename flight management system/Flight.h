#ifndef FLIGHT_H
#define FLIGHT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include "TextBox.h"
#include "Button.h"
class flight;
class arrival;
class departure;
class flight {
protected:
    std::string flightNo;
    std::string status;

public:
    virtual void addFlight(std::string time, std::string fNo, std::string dest, std::string st, int& n) {};
    virtual void search() {};
    virtual void display() {};
    virtual void updateFlight(std::string time, std::string fNo, std::string dest, std::string st) {}
    void updateStatusColor(sf::Text& txt);
};

class departure : public flight {
private:
    std::string destination;
    std::string departureTime;

public:
    void addFlight(std::string time, std::string fNo, std::string dest, std::string st, departure dpt[], int& n);
    void display();
    void updateFlight(std::string time, std::string fNo, std::string dest, std::string st);
    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);

    friend void deleteFlightDpt(departure dpt[], int& dptn, std::string fNo);
    friend int searchdpt(departure dpt[], int n, std::string fNo);
    friend void renderInput(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, departure dpt, arrival arv, int& j, bool f);
    friend void handleSearch(TextBox& textBox, departure dpt[], int dptn, arrival arv[], int arvn, std::vector<departure>& fillteredDpt, std::vector<arrival>& fillteredArv, bool f);
    friend void displaySearch(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, std::vector<departure>fillteredDpt, std::vector<arrival> fillteredArv, bool f);
    friend void updateFlightStatus(departure dpt[], arrival arv[], int dptn, int arvn, bool isDeparture,int Count);
};

class arrival : public flight {
private:
    std::string from;
    std::string arrivalTime;

public:
    void addFlight(std::string time, std::string fNo, std::string frm, std::string st, arrival arv[], int& n);
    void display();
    void updateFlight(std::string time, std::string fNo, std::string dest, std::string st);
    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);

    friend int searcharv(arrival arv[], int n, std::string fNo);
    friend void renderInput(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, departure dpt, arrival arv, int& j, bool f);
    friend void deleteFlightArv(arrival arv[], int& arvn, std::string fNo);
    friend void handleSearch(TextBox& textBox, departure dpt[], int dptn, arrival arv[], int arvn, std::vector<departure>& fillteredDpt, std::vector<arrival>& fillteredArv, bool f);
    friend void displaySearch(sf::Text& txt, sf::Font& font, sf::RenderWindow& window, std::vector<departure>fillteredDpt, std::vector<arrival> fillteredArv, bool f);
    friend void updateFlightStatus(departure dpt[], arrival arv[], int dptn, int arvn, bool isDeparture,int Count);
};

#endif // FLIGHT_H