#include"Marketing.h"


Marketing::Marketing()
{
    std::cout << "Marketing being constructed!\n" << std::endl;
}
Marketing::~Marketing()
{
    std::cout << "Marketing being destructed!\n" << std::endl;
}

void Marketing::calculateExpensesRate(Market& marketName, int planningDays)
{
    double dailyIndirectExpenses = marketName.dailyBasicUtilitiesFee; 
    double dailyDirectExpenses = marketName.numPeopleWorkingAtStore * 5;
    double directExpenses = dailyDirectExpenses * planningDays;
    double indirectExpenses = dailyIndirectExpenses * planningDays;
    double generalExpensesRate = (directExpenses / indirectExpenses) * 100;
    std::cout << "Your New Product Marketing General Expenses Rate is " << generalExpensesRate << "%\n" << std::endl;
}

void Marketing::calculateRentability(Market& marketName, int promotionDays, int numberCustomers = 0)
{
    double totalProfit = marketName.dailyProfit * numberCustomers * promotionDays;
    double totalIncome = marketName.dailyIncome * (numberCustomers * 2.75) * promotionDays;
    double rentability = ((totalProfit * promotionDays) / (totalIncome * promotionDays)) * 100;
    std::cout << "Your New Product Marketing Rentability is " << rentability << "%\n" << std::endl;;
}
