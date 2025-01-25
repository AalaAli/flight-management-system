#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const int Size = 10;
const int numCities = 50;

struct CityTime {
    std::string city;
    int timeOffset; // Time offset from UTC in hours
};

extern CityTime cities[numCities];
extern int diffTimeOffset;

#endif // CONSTANTS_H