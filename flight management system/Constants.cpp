#include "Constants.h"
#include "HelperFunctions.h"
int diffTimeOffset = difference_UTC_systemTime();

CityTime cities[numCities] = {
    {"New York", -5 + diffTimeOffset},      // UTC-5
    {"Los Angeles", -8 + diffTimeOffset},   // UTC-8
    {"London", 0 + diffTimeOffset},         // UTC+0
    {"Paris", 1 + diffTimeOffset},          // UTC+1
    {"Berlin", 1 + diffTimeOffset},         // UTC+1
    {"Rome", 1 + diffTimeOffset},           // UTC+1
    {"Madrid", 1 + diffTimeOffset},         // UTC+1
    {"Moscow", 3 + diffTimeOffset},         // UTC+3
    {"Cairo", 2 + diffTimeOffset},          // UTC+2
    {"Athens", 2 + diffTimeOffset},         // UTC+2
    {"Dubai", 4 + diffTimeOffset},          // UTC+4
    {"Tokyo", 9 + diffTimeOffset},          // UTC+9
    {"Seoul", 9 + diffTimeOffset},          // UTC+9
    {"Sydney", 11 + diffTimeOffset},        // UTC+11
    {"Wellington", 12 + diffTimeOffset},    // UTC+12
    {"Mexico City", -6 + diffTimeOffset},   // UTC-6
    {"Rio de Janeiro", -3 + diffTimeOffset},// UTC-3
    {"Buenos Aires", -3 + diffTimeOffset},  // UTC-3
    {"Lima", -5 + diffTimeOffset},          // UTC-5
    {"Toronto", -5 + diffTimeOffset},       // UTC-5
    {"Vancouver", -8 + diffTimeOffset},     // UTC-8
    {"San Francisco", -8 + diffTimeOffset}, // UTC-8
    {"Chicago", -6 + diffTimeOffset},       // UTC-6
    {"Houston", -6 + diffTimeOffset},       // UTC-6
    {"Dallas", -6 + diffTimeOffset},        // UTC-6
    {"Bogota", -5 + diffTimeOffset},        // UTC-5
    {"Caracas", -4 + diffTimeOffset},       // UTC-4
    {"Berlin", 1 + diffTimeOffset},         // UTC+1
    {"Amsterdam", 1 + diffTimeOffset},      // UTC+1
    {"Brussels", 1 + diffTimeOffset},       // UTC+1
    {"Vienna", 1 + diffTimeOffset},         // UTC+1
    {"Zurich", 1 + diffTimeOffset},         // UTC+1
    {"Prague", 1 + diffTimeOffset},         // UTC+1
    {"Stockholm", 1 + diffTimeOffset},      // UTC+1
    {"Oslo", 1 + diffTimeOffset},           // UTC+1
    {"Helsinki", 2 + diffTimeOffset},       // UTC+2
    {"Istanbul", 3 + diffTimeOffset},       // UTC+3
    {"Abu Dhabi", 4 + diffTimeOffset},      // UTC+4
    {"Riyadh", 3 + diffTimeOffset},         // UTC+3
    {"Jeddah", 3 + diffTimeOffset},         // UTC+3
    {"Singapore", 8 + diffTimeOffset},      // UTC+8
    {"Hong Kong", 8 + diffTimeOffset},      // UTC+8
    {"Kuala Lumpur", 8 + diffTimeOffset},   // UTC+8
    {"Manila", 8 + diffTimeOffset},         // UTC+8
    {"Bangkok", 7 + diffTimeOffset},        // UTC+7
    {"Jakarta", 7 + diffTimeOffset},        // UTC+7
    {"Mumbai", 5 + diffTimeOffset},         // UTC+5
    {"New Delhi", 5 + diffTimeOffset},      // UTC+5
    {"Dhaka", 6 + diffTimeOffset},          // UTC+6
    {"Kathmandu", 5 + diffTimeOffset},      // UTC+5
};