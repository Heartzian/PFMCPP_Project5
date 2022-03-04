#include<iostream>
#include"Market.h"

Market::Market()
{
    std::cout << "Market being constructed!\n" << std::endl;
}

Market::~Market()
{
    std::cout << "Market being destructed!\n" << std::endl;
}

Market::Customer::Customer()
{
    std::cout << "Customer Market being constructed!\n" << std::endl;
}

Market::Customer::~Customer()
{
    std::cout << "Customer Market being destructed!\n" << std::endl;
}

void Market::Customer::calculateOrderPrice(int breakfastProds = 4, int morningBreakProds = 2, int lunchProds = 5, int coffeeBreakProds = 2, int dinnerProds = 3)
{
    double bfProdsPrice = 0.75;
    double mbProdsPrice = 1.25;
    double lProdsPrice = 0.85;
    double cbProdsPrice = 1.25;
    double dProdsPrice = 0.9;
    double memberDiscount = 0.9;

    productsToOrder = breakfastProds + morningBreakProds + lunchProds +coffeeBreakProds + dinnerProds;
    
    productsPrice = (breakfastProds * bfProdsPrice) + (morningBreakProds * mbProdsPrice) + (lunchProds * lProdsPrice) + (coffeeBreakProds * cbProdsPrice) + (dinnerProds * dProdsPrice);

    if(member == true)
    {
        productsPrice = productsPrice * memberDiscount;
    }
}

void Market::Customer::orderProducts(bool requiredDelivery)
{
    double deliveryCharge = 0;
    double tax = 1.19;
    if (requiredDelivery == true)
    {
        deliveryRequired = true;
        if (productsPrice > 20)
        {
            deliveryCharge = 0;
        }
        else
        {
            deliveryCharge = 5;
        }
    }
    totalToPay = (productsPrice * tax) + deliveryCharge;
}

int Market::Customer::countNumberCustomers(int numberDays)
{
    srand(1);
    int x = rand();
    dailyCustomers = x;
    if (dailyCustomers < 0)
    {
        dailyCustomers *= -1;
    }
    return dailyCustomers * numberDays;
}

Market::Customer Market::countNoInventoryProducts(int maxAllowed)
{
    Customer custName;
    for (int i = 0; i < maxAllowed; ++i)
    {
        if (custName.noInventoryProducts < maxAllowed)
        {
            ++custName.noInventoryProducts;
            std::cout << "noInventoryProducts:" << custName.noInventoryProducts << std::endl;
            if (custName.noInventoryProducts >= maxAllowed)
            {
                std::cout << "Max. Limit NO inventory product was reached" << std::endl;
                return custName;
            }
        }
    } 
    return Customer {};
}

void Market::sellProducts(Customer& customerNick) //carl in main()
{ 
    ++customerNick.visitsThisWeek;
    if (customerNick.deliveryRequired == true)
    {
        --numLogisticVehicles;
        --numPeopleWorkingAtStore;
    }
    dailyIncome += customerNick.totalToPay;
    dailyProfit = dailyIncome * 0.65;

    std::cout << "Dear " << customerNick.customerName << ", you ordered " <<  customerNick.productsToOrder << " products, with a total cost of $" << customerNick.totalToPay << ", which will be Delivered by Tom." << " this week, you have come to our store " << customerNick.visitsThisWeek << " times, Thanks for buying with us!\n" << std::endl;
}

double Market::adjustInventary(const Customer& customerName)
{
    numProdLocalInv -= customerName.productsToOrder;
    return numProdLocalInv;
}

//Free Functions for 'this' practice

void Market::callMarketVarFunct()
{
    std::cout << "Market variable call numPeopleWorkingAtStore = " << this->numPeopleWorkingAtStore << std::endl;

    //std::cout << "Market function call adjustInventary() = " << this->adjustInventary(carl.customerPtr) << std::endl;
}

void Market::Customer::callMarketCustomerVarFunct()
{
    std::cout << "Market::Customer variable call productsToOrder = " << this->productsToOrder << std::endl;
    
    std::cout << "Market::Customer function call countNumberCustomers() = " << this->countNumberCustomers(3) << std::endl;
}
