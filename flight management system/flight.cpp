#include "Flight.h"
#include "HelperFunctions.h"
#include "RenderFunctions.h"
#include <iostream>
#include<SFML/Graphics.hpp>
void flight::updateStatusColor(sf::Text& txt) {
    if (txt.getString() == "CANCELLED")
        txt.setFillColor(sf::Color::Red);
    else if (txt.getString() == "BOARDING")
        txt.setFillColor(sf::Color::Green);
    else if (txt.getString() == "DELAYED")
        txt.setFillColor(sf::Color::Red);
    else
        txt.setFillColor(sf::Color::Yellow);
}

void departure::addFlight(std::string time, std::string fNo, std::string dest, std::string st, departure dpt[], int& n) {
    if (n < Size && searchdpt(dpt, n, fNo) == -1) {
        flightNo = fNo;
        status = st;
        destination = dest;
        departureTime = addHoursToTime(time, searchCity(cities, destination).timeOffset);
        n++;
    }
}

void departure::display() {
    std::cout << "\nTIME\t\tDESTINATION\t\tFLIFGHT\t\tREMARKS\n";
    std::cout << departureTime << "\t\t" << destination << "\t\t" << flightNo << "\t\t" << status << "\n";
}

void departure::updateFlight(std::string time, std::string fNo, std::string dest, std::string st) {
    if (flightNo == fNo) {
        flightNo = fNo;
        status = st;
        destination = dest;
        departureTime = time;
    }
}

void departure::save(std::ofstream& outFile) const {
    outFile << departureTime << ' ' << flightNo << ' ' << destination << ' ' << status << '\n';
}

void departure::load(std::ifstream& inFile) {
    inFile >> departureTime >> flightNo >> destination >> status;
}

void arrival::addFlight(std::string time, std::string fNo, std::string frm, std::string st, arrival arv[], int& n) {
    if (n < Size && searcharv(arv, n, fNo) == -1) {
        flightNo = fNo;
        status = st;
        from = frm;
        arrivalTime = time;
        n++;
    }
}

void arrival::display() {
    std::cout << "\nTIME\t\tFROM\t\tFLIFGHT\t\tREMARKS\n";
    std::cout << arrivalTime << "\t\t" << from << "\t\t" << flightNo << "\t\t" << status << "\n";
}

void arrival::updateFlight(std::string time, std::string fNo, std::string dest, std::string st) {
    if (flightNo == fNo) {
        flightNo = fNo;
        status = st;
        from = dest;
        arrivalTime = time;
    }
}

void arrival::save(std::ofstream& outFile) const {
    outFile << arrivalTime << ' ' << flightNo << ' ' << from << ' ' << status << '\n';
}

void arrival::load(std::ifstream& inFile) {
    inFile >> arrivalTime >> flightNo >> from >> status;
}