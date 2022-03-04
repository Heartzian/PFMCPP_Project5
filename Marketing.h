#pragma once
#include "LeakedObjectDetector.h"
#include "Market.h"

struct Marketing
{
    Market asiaLocations; 
    Market::Customer numCustomers;
    Marketing();
    ~Marketing();

    void calculateExpensesRate(Market& marketName, int planningDays);
    void calculateRentability(Market& marketName, int promotionDays, int numberCustomers);
    JUCE_LEAK_DETECTOR(Marketing)
};
