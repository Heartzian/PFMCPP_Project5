#pragma once
#include "LeakedObjectDetector.h"

struct Market
{
    double numProdLocalInv = 215;
    int numLogisticVehicles = 5; 
    int numPeopleWorkingAtStore =32; 
    double dailyBasicUtilitiesFee = 320.53;  
    double dailyIncome = 0; 
    double dailyProfit = 0;
    int peopleAtStore = 0; 
    std::string marketName {"Asia SuperMarket"};
    Market();
    ~Market();

    struct Customer
    {
        int age = 38;
        bool member = true;
        int visitsThisWeek = 0;
        std::string gender = "Male";
        std::string customerName {"Frederick Carl Steinhaus"};
        int productsToOrder = 0;
        double productsPrice = 0;
        double totalToPay = 0;
        int noInventoryProducts = 0;
        bool deliveryRequired = false;
        int dailyCustomers = 0;
        Customer();
        ~Customer();

        void calculateOrderPrice(int breakfastProds, int morningBreakProds, int lunchProds, int coffeeBreakProds, int dinnerProds); 
        void orderProducts(bool deliveryRequired = true);
        int countNumberCustomers(int numberDays);
        //void changeProdAndNumCust();
        void callMarketCustomerVarFunct();
        JUCE_LEAK_DETECTOR(Customer)
    };

    //Customer phillip;

    void sellProducts(Customer& customerName);
    double adjustInventary(Customer& customerName);
    Customer countNoInventoryProducts(int maxAllowed); 
    //void changeStaffAndinventory();
    void callMarketVarFunct();
    JUCE_LEAK_DETECTOR(Market)
};



Market::Market()
{
    std::cout << "\nMarket being constructed!" << std::endl;
}


