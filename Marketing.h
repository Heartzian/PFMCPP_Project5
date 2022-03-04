#pragma once
#include "LeakedObjectDetector.h"
#include "Market.h"

struct Marketing
{
    Market asiaLocations; 
    Market::Customer numCustomers;
    Marketing();
    ~Marketing();

    void calculateExpensesRate(const Market& marketName, int planningDays);
    void calculateRentability(const Market& marketName, int promotionDays, int numberCustomers);
    JUCE_LEAK_DETECTOR(Marketing)
};
