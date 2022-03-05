#pragma once
#include "Market.h"
#include "University.h"
#include "Computer.h"

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
