#pragma once
#include "LeakedObjectDetector.h"

struct Marketing
{
    Market asiaLocations;
    Market::Customer numCustomers;
    Marketing();
    ~Marketing() {std::cout << "Marketing Destructor\n";}

    void calculateExpensesRate(Market& marketName, int planningDays);
    void calculateRentability(Market& marketName, int promotionDays, int numberCustomers);
    JUCE_LEAK_DETECTOR(Marketing)
};
