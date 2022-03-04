#pragma once
#include "Market.h"
#include "University.h"
#include "Computer.h"
// struct Market; //that means you don't need to forward declare this type
// struct Market::Customer; //you must include the header file where this is declared
// struct University; //that means you don't need to forward declare this type
// struct University::Professor; //you must include the header file where this is declared
// struct University::Student; //you must include the header file where this is declared
// struct Computer; //that means you don't need to forward declare this type
// struct Computer::Hardware; //you must include the header file where this is declared
struct Marketing; 
struct Projects;

struct MarketWrapper
{
    MarketWrapper( Market* newMarketPtr);
    ~MarketWrapper();

    Market* marketPtr = nullptr;
};

struct CustomerWrapper
{
    CustomerWrapper( Market::Customer* newCustomerPtr);
    ~CustomerWrapper();

    Market::Customer* customerPtr = nullptr;
};

struct UniversityWrapper
{
    UniversityWrapper( University* newUniversityPtr);
    ~UniversityWrapper();

    University* universityPtr = nullptr;
};

struct ProfessorWrapper
{
    ProfessorWrapper(University::Professor* newProfessorPtr);
    ~ProfessorWrapper();

    University::Professor* professorPtr = nullptr;
};

struct StudentWrapper
{
    StudentWrapper(University::Student* newStudentPtr);
    ~StudentWrapper();

    University::Student* studentPtr = nullptr;
};

struct ComputerWrapper
{
    ComputerWrapper(Computer* newComputerPtr);
    ~ComputerWrapper();

    Computer* computerPtr = nullptr;
};

struct HardwareWrapper
{
    HardwareWrapper(Computer::Hardware* newHardwarePtr);
    ~HardwareWrapper();

    Computer::Hardware* hardwarePtr = nullptr;
};

struct MarketingWrapper
{
    MarketingWrapper( Marketing* newMarketingPtr);
    ~MarketingWrapper();

    Marketing* marketingPtr = nullptr;
};

struct ProjectsWrapper
{
    ProjectsWrapper( Projects* newProjectsPtr);
    ~ProjectsWrapper();

    Projects* projectsPtr = nullptr;
};
