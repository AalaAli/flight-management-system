#include "HelperFunctions.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>

std::string to_lower(const std::string& str) {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

std::string addHoursToTime(std::string& time, int hoursToAdd) {
    int h, m;
    sscanf_s(time.c_str(), "%d:%d", &h, &m);
    int totalHours = h + hoursToAdd;
    totalHours %= 24;
    std::ostringstream result;
    result << std::setw(2) << std::setfill('0') << totalHours << ":"
        << std::setw(2) << std::setfill('0') << m;
    return result.str();
}

int difference_UTC_systemTime() {
    auto now = std::chrono::system_clock::now();
    time_t systemTime = std::chrono::system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &systemTime);
    tm utcTime;
    gmtime_s(&utcTime, &systemTime);
    auto localTimeSeconds = mktime(&localTime);
    auto utcTimeSeconds = mktime(&utcTime);
    auto difference = difftime(localTimeSeconds, utcTimeSeconds);
    return difference;
}

CityTime searchCity(CityTime cities[], std::string city) {
    for (int i = 0; i < numCities; i++)
        if (to_lower(cities[i].city) == to_lower(city))
            return cities[i];
    return cities[-1];
}

void deleteFlightDpt(departure dpt[], int& dptn, std::string fNo) {
    for (int i = 0; i < dptn; i++) {
        if (dpt[i].flightNo == fNo) {
            for (int j = i; j < dptn; j++)
                dpt[j] = dpt[j + 1];
            dptn--;
        }
    }
}

void deleteFlightArv(arrival arv[], int& arvn, std::string fNo) {
    for (int i = 0; i < arvn; i++) {
        if (arv[i].flightNo == fNo) {
            for (int j = i; j < arvn; j++)
                arv[j] = arv[j + 1];
            arvn--;
        }
    }
}

int searchdpt(departure dpt[], int n, std::string fNo) {
    for (int i = 0; i < n; i++) {
        if (dpt[i].flightNo == fNo)
            return i;
    }
    return -1;
}

int searcharv(arrival arv[], int n, std::string fNo) {
    for (int i = 0; i < n; i++) {
        if (arv[i].flightNo == fNo)
            return i;
    }
    return -1;
}

void saveToFile(departure dpt[], arrival arv[], int& dptn, int& arvn, const std::string& filename, bool isDeparture) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    if (isDeparture) {
        for (int i = 0; i < dptn; i++) {
            dpt[i].save(outFile);
        }
    }
    else {
        for (int i = 0; i < arvn; i++)
            arv[i].save(outFile);
    }
    outFile.close();
}

int loadFromFile(departure dpt[], arrival arv[], int maxSize, const std::string& filename, bool isDeparture) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return 0;
    }

    int count = 0;
    if (isDeparture) {
        while (!inFile.eof() && count < maxSize) {
            dpt[count].load(inFile);
            if (inFile) {
                ++count;
            }
        }
    }
    else {
        while (!inFile.eof() && count < maxSize) {
            arv[count].load(inFile);
            if (inFile) {
                ++count;
            }
        }
    }
    inFile.close();
    std::cout << "Objects loaded from " << filename << std::endl;
    return count;
}