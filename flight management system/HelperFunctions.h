#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H
#include<iostream>

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Flight.h"
#include "Constants.h"
std::string to_lower(const std::string& str);
std::string addHoursToTime(std::string& time, int hoursToAdd);
int difference_UTC_systemTime();
CityTime searchCity(CityTime cities[], std::string city);
void deleteFlightDpt(departure dpt[], int& dptn, std::string fNo);
void deleteFlightArv(arrival arv[], int& arvn, std::string fNo);
int searchdpt(departure dpt[], int n, std::string fNo);
int searcharv(arrival arv[], int n, std::string fNo);
void saveToFile(departure dpt[], arrival arv[], int& dptn, int& arvn, const std::string& filename, bool isDeparture);
int loadFromFile(departure dpt[], arrival arv[], int maxSize, const std::string& filename, bool isDeparture);

#endif // HELPERFUNCTIONS_H