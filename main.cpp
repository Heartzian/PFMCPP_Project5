/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
         
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

#include<iostream>
#include"LeakedObjectDetector.h"
#include"Wrappers.h"
#include"Market.h"
#include"University.h"
#include"Computer.h"
#include"Marketing.h"
#include"Projects.h"


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    MarketWrapper superStarMarket(new Market()); 
    CustomerWrapper carl(new Market::Customer());
    carl.customerPtr->calculateOrderPrice(2,3,4,2,3);
    carl.customerPtr->orderProducts(true);
    auto customers = carl.customerPtr->countNumberCustomers(45); 
    superStarMarket.marketPtr->sellProducts(*carl.customerPtr);
    superStarMarket.marketPtr->adjustInventary(*carl.customerPtr);
    auto custName = superStarMarket.marketPtr->countNoInventoryProducts(5);

    UniversityWrapper programmingSchoolUniversity(new University()); 
    ProfessorWrapper joseph(new University::Professor());
    StudentWrapper frank(new University::Student()); 
    frank.studentPtr->computeWeekStudyTime();
    frank.studentPtr->computeSemestralAbsences();
    frank.studentPtr->displayStudentInfo(*frank.studentPtr);
    frank.studentPtr->subscribeCourse(*frank.studentPtr, *joseph.professorPtr);
    auto studentName = programmingSchoolUniversity.universityPtr->calculatePresentations(*frank.studentPtr);

    ComputerWrapper gamingPC(new Computer()); 
    HardwareWrapper highSpecs(new Computer::Hardware());
    highSpecs.hardwarePtr->playGames();
    auto canPlay = gamingPC.computerPtr->executePrograms(*highSpecs.hardwarePtr, "GTA");
    gamingPC.computerPtr->addGamesToRAM(*highSpecs.hardwarePtr, canPlay);

    MarketingWrapper newProductLaunch(new Marketing());
    newProductLaunch.marketingPtr->calculateExpensesRate(*superStarMarket.marketPtr, 18);
    newProductLaunch.marketingPtr->calculateRentability(*superStarMarket.marketPtr, 45, customers);
    
    ProjectsWrapper engineeringResearch(new Projects());
    engineeringResearch.projectsPtr->calculateUniversityRanking(*programmingSchoolUniversity.universityPtr, *joseph.professorPtr, *frank.studentPtr);
    engineeringResearch.projectsPtr->calculateResearchInvestment(*programmingSchoolUniversity.universityPtr, *joseph.professorPtr);

    // 'This' practice 
    
    MarketWrapper m(new Market());
    
    std::cout << "Market variable call numPeopleWorkingAtStore = " << m.marketPtr->numPeopleWorkingAtStore << std::endl;

    std::cout << "Market function call adjustInventary() = " << m.marketPtr->adjustInventary(*carl.customerPtr) << std::endl;
    
    m.marketPtr->callMarketVarFunct();

    
    CustomerWrapper c(new Market::Customer()) ;

    std::cout << "Market::Customer variable call productsToOrder = " << c.customerPtr->productsToOrder << std::endl;
    
    std::cout << "Market::Customer function call countNumberCustomers() = " << c.customerPtr->countNumberCustomers(3) << std::endl;
    
    c.customerPtr->callMarketCustomerVarFunct();

    
    UniversityWrapper u(new University());

    std::cout << "University variable call semIncome = " << u.universityPtr->numClassrooms << std::endl;

    std::cout << "University function call teachStudents() = " << u.universityPtr->teachStudents() << std::endl;
    
    u.universityPtr->callUniversityVarFunct();

    
    ProfessorWrapper p(new University::Professor());

    std::cout << "University::Professor variable call professorName  = " << p.professorPtr->professorName << std::endl;

    std::cout << "University::Professor function call checkSubscribedStudents()  = " << p.professorPtr->checkSubscribedStudents() << std::endl;
    
    p.professorPtr->callUniversityProfessorVarFunct();

    
    StudentWrapper s(new University::Student());

    std::cout << "University::Student variable call weeklyResearchStudyHours  = " << s.studentPtr->weeklyResearchStudyHours << std::endl;

    std::cout << "University::Student function call computeWeekStudyTime()  = " << s.studentPtr->computeWeekStudyTime() << std::endl;
    
    s.studentPtr->callUniversityStudentVarFunct();

    
    ComputerWrapper pc(new Computer());

    std::cout << "Computer variable call execTask  = " << pc.computerPtr->execTask << std::endl;

    std::cout << "Computer function call saveInfo()  = " << pc.computerPtr->saveInfo() << std::endl;
    
    pc.computerPtr->callComputerVarFunct();
    

    HardwareWrapper hw(new Computer::Hardware());

    std::cout << "Computer::Hardware variable call screen = " << hw.hardwarePtr->screen << std::endl;
    
    std::cout << "Computer::Hardware function call playGames() = " << hw.hardwarePtr->playGames() << std::endl;
    
    hw.hardwarePtr->callComputerHardwareVarFunct();    
    
    std::cout << "good to go!" << std::endl;
}
