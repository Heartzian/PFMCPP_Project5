/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */





// copied UDT 1:
#include<iostream>

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
    ~Market() {std::cout << "Market Destructor\n";}

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
        ~Customer() {std::cout << "Customer Destructor\n";}

        void calculateOrderPrice(int breakfastProds, int morningBreakProds, int lunchProds, int coffeeBreakProds, int dinnerProds); 
        void orderProducts(bool deliveryRequired = true);
        int countNumberCustomers(int numberDays);
        //void changeProdAndNumCust();
        void callMarketCustomerVarFunct();
    };

    Customer phillip;

    void sellProducts(Customer customerName);
    double adjustInventary(Customer customerName);
    Customer countNoInventoryProducts(int maxAllowed); 
    //void changeStaffAndinventory();
    void callMarketVarFunct();
};

Market::Market()
{
    std::cout << "\nMarket being constructed!" << std::endl;
}

Market::Customer::Customer()
{
    std::cout << "Customer Market being constructed!\n" << std::endl;
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

void Market::sellProducts(Customer customerNick) //carl in main()
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

double Market::adjustInventary(Customer customerName)
{
    numProdLocalInv -= customerName.productsToOrder;
    return numProdLocalInv;
}

/*void Market::changeStaffAndinventory()
{
    this->numPeopleWorkingAtStore -= 1;
    this->adjustInventary(phillip);
}

void Market::Customer::changeProdAndNumCust()
{
    this->productsToOrder = 20;
    this->countNumberCustomers(3);
}*/


//copied UDT 2:
struct University
{
    int numClassrooms = 80;
    int numLabs = 36;
    int numProfessors = 65;
    float semIncome = 0;
    int classesPerSemester = 0;
    std::string universityName {"Programming Technology University"};
    University();
    ~University() {std::cout << "University Destructor\n";}

    struct Professor
    {
        int age = 30;
        std::string profession = "Engineer";
        std::string postgraduateStudies = "MsC";
        std::string teachingRank = "Band 4";
        std::string professorName {"Joseph Abraham Stern"};
        int yearsExperience = 15;
        int teachedClasses;
        int subscribedStudents;
        Professor();
        ~Professor() {std::cout << "Professor Destructor\n";}

        int checkSubscribedStudents();
        float computeMonthlyExpenses(float rent = 1800,
                                     float food = 550,
                                     float fun = 120, 
                                     float other = 150);
        //void changeNameAndSubscribedSt();
        void callUniversityProfessorVarFunct();
    };

    struct Student
    {
        int age = 18; 
        std::string department = "Engineer"; 
        std::string career = "AgroIndustrial Engineer";
        std::string courseName = "Managing a Field of Corn";
        std::string studentName {"Frank Kaf"};
        float courseID = 001;
        std::string hobby = "Play Bass";
        int semestralCredits = 9;
        int weeklyPresentialStudyHours = 0;
        int weeklyResearchStudyHours = 0;
        double semestralStudyTime = 0;
        double semestralAllowedAbsences = 0;
        int numberPresentations = 0;
        Student();
        ~Student() {std::cout << "Student Destructor\n";}

        double computeWeekStudyTime();
        void computeSemestralAbsences();
        void displayStudentInfo(Student studentName);
        void subscribeCourse(Student studentName, Professor professorName);
        //void changeHoursAndStudyTime();
        void callUniversityStudentVarFunct();
    }; 

    float teachStudents();  
    void doResearch(std::string organization = "UCLA",
                    std::string department = "Chemistry",
                    std::string projectName = "influence of fertilizer on plant cultivation"); 
    void doCulturalActivities(Student name,
                              std::string category = "Arts",
                              std::string activity = "Music Museum Visit"); 
    Student calculatePresentations(Student studentNick);
    //void changeIncomeAndTeachSt();
    void callUniversityVarFunct();
};

University::University()
{
    std::cout << "University being constructed!" << std::endl;
}

University::Professor::Professor()
{
    std::cout << "University Professor being constructed!" << std::endl;
}

University::Student::Student()
{
    std::cout << "University Student being constructed!\n" << std::endl;
}

int University::Professor::checkSubscribedStudents()
{
    int max = 1000;
    srand(1);
    int x = rand();
    subscribedStudents = x % max;
    return subscribedStudents;
}

float University::Professor::computeMonthlyExpenses(float rent,
                                                    float food,
                                                    float fun, 
                                                    float other)
{
    return rent + food + fun + other;
}

/*void University::Professor::changeNameAndSubscribedSt()
{
    this->professorName = "Joseph A. Stern";
    this->checkSubscribedStudents();
}*/

double University::Student::computeWeekStudyTime()
{
    weeklyPresentialStudyHours = semestralCredits * 3;
    weeklyResearchStudyHours = weeklyPresentialStudyHours * 2;
    semestralStudyTime = (weeklyPresentialStudyHours + weeklyResearchStudyHours) * 16;
    return semestralStudyTime;
}

void University::Student::computeSemestralAbsences()
{
    semestralAllowedAbsences = ((weeklyPresentialStudyHours * 16) * 0.1) / 3;
}

void University::Student::displayStudentInfo(Student studentNick)
{
    std::cout << "Dear " << studentNick.studentName << ". Welcome to study " << studentNick.career << ". This semester you chose " << studentNick.semestralCredits << " credits. You'll have " << studentNick.weeklyPresentialStudyHours << " weekly presential study hours. Please remember you can only have 10% of class absence, which in your case means " << studentNick.semestralAllowedAbsences << " hours per class. Enjoy your time!\n" << std::endl;
}

void University::Student::subscribeCourse(Student studentNick, Professor professorNick)
{
    std::cout << "Dear " << studentNick.studentName << " you've successfully subscribed the assignature " << studentNick.courseName << ". Which will have Professor " << professorNick.professorName << " as Main Professor for this class.\n" << std::endl;
}

/*void University::Student::changeHoursAndStudyTime()
{
    this->weeklyPresentialStudyHours += 10;
    this->computeWeekStudyTime();
}*/

float University::teachStudents() 
{
    int calculus = 8;
    int programming = 12;
    int cad = 6;
    return calculus + programming + cad;
}

void University::doResearch(std::string organization, 
                            std::string department,
                            std::string projectName)
{
    std::cout << "This semester the University do Collaborative Research with: " << organization << " from department " << department << " in the project named: " << projectName << std::endl;
}

void University::doCulturalActivities(Student studentNick,
                                           std::string category,
                                           std::string activity)
{
    std::cout << "This semester the University performed a Cultural Activity with " << studentNick.studentName << " from " << studentNick.career << " which likes to " << studentNick.hobby << " in the category: " << category << " doing the activity " << activity << ".\n" << std::endl;
}

University::Student University::calculatePresentations(Student studentNick)
{
    //Student phil;
    int totalPresentations = studentNick.semestralCredits * 2;
    while (studentNick.numberPresentations < totalPresentations)
    {
        studentNick.numberPresentations += 3;
        std::cout << studentNick.studentName << " this semester your should present " << studentNick.numberPresentations << " presentations."<< std::endl;
        if (studentNick.numberPresentations >= totalPresentations)
        {
            return studentNick;
        }
    }
    return Student {};
}

/*void University::changeIncomeAndTeachSt()
{
    this->semIncome += 25;
    this->teachStudents();
}*/

//copied UDT 3:
struct Computer
{
    float energyConsumption = 35.5f;
    float requiredRAM = 6.9f;
    float diskSpace = 89.5f;
    int execErrors = 48;
    int execTask = 25;
    bool programmingSoftwareInstalled = false;
    bool canSaveInfo;
    std::string computerName {"Republic of Gamers Strix Scar"};
    Computer();
    ~Computer() {std::cout << "Computer Destructor\n";}

    struct Hardware
    { 
        double RAM = 16.0; 
        double disk = 1024.0; 
        double CPU = 4.5;
        double GPU = 16.0;
        double screen = 24.0;
        bool canPlayGames;
        bool canTrainAI;
        bool canUseAtOffice;
        int gamesAtRAM = 0;
        Hardware();
        ~Hardware() {std::cout << "Hardware Destructor\n";}
        
        std::string playGames(); 
        void trainAI(); 
        void workAtOffice(); 
        //void changeScreenAndPlayGames();
        void callComputerHardwareVarFunct();
    };

    bool executePrograms(Hardware specs, std::string installedSoft);  
    std::string saveInfo(bool diskAvailable = true); 
    void connectToPCs(bool LANavailable = true);
    Hardware addGamesToRAM(Hardware pcType, bool abilityToPlay);
    //void changeTaskAndSaveInfo();
    void callComputerVarFunct();
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

Computer::Hardware::Hardware()
{
    std::cout << "Computer Hardware being constructed!\n" << std::endl;
}

std::string Computer::Hardware::playGames()
{
    if (RAM >= 4 && disk >=256 && CPU >= 3.0 && GPU >= 2)
    {
        canPlayGames = true;
    }
    return "You can use this computer to play games!"; 
}

void Computer::Hardware::trainAI()
{
    if (canPlayGames == true && GPU > 4)
    {
        //std::cout << "You can use this computer to train AI using" << softwareReq;

        canTrainAI = true;
    }
    
}

void Computer::Hardware::workAtOffice()
{
    if (canPlayGames == true)
    {
        //std::cout << "You can use this computer to do " << mostlyUsedTask;

        canUseAtOffice = true;
    }
    
} 

/*void Computer::Hardware::changeScreenAndPlayGames()
{
    this->screen = 27;
    this->playGames();
}*/

bool Computer::executePrograms(Hardware specs, std::string installedSoft)
{
    if (installedSoft == "GTA")
    {
        if (specs.canPlayGames == true)
        {
            std::cout << "According to the given specs, this computer can be used to play Grand Theft Auto\n" << std::endl;
        }
        else
        {
            std::cout << "Sorry!! This computer can NOT be used to play Grand Theft Auto becasuse of the specs" << std::endl;
        }
    }
    return specs.canPlayGames;
}

std::string Computer::saveInfo(bool diskAvailable)
{
    if (diskAvailable == true)
    {
        canSaveInfo = true;
    }
    return "The file was saved";
    
}

void Computer::connectToPCs(bool LANavailable)
{
    if (LANavailable == true)
    {
        std::cout << "The computer is available to connect to LAN";
    }
}

Computer::Hardware Computer::addGamesToRAM(Hardware pcType, bool abilityToPlay)
{
    if (abilityToPlay == true)
    {
        int maxAllowedGames = 5;
        while(pcType.gamesAtRAM < maxAllowedGames)
        {
            ++pcType.gamesAtRAM;
            std::cout << "Games loaded at RAM: " << pcType.gamesAtRAM << std::endl;
            if (pcType.gamesAtRAM >= maxAllowedGames)
            {
                std::cout << "Max. Games Loaded at RAM!\n";
                return pcType;
            }
        }
    }
    else
    {
        std::cout << "Your computer is not able to play Games, check your Hardware Specs" << std::endl;
    }
    return Hardware {};
}

/*void Computer::changeTaskAndSaveInfo()
{
    this->execTask = 22;
    this->saveInfo();
}*/

//new UDT 4:
struct Marketing
{
    Market asiaLocations;
    Market::Customer numCustomers;
    Marketing();
    ~Marketing() {std::cout << "Marketing Destructor\n";}

    void calculateExpensesRate(Market marketName, int planningDays);
    void calculateRentability(Market marketName, int promotionDays, int numberCustomers);
};

Marketing::Marketing(){}

void Marketing::calculateExpensesRate(Market marketName, int planningDays)
{
    double dailyIndirectExpenses = marketName.dailyBasicUtilitiesFee; 
    double dailyDirectExpenses = marketName.numPeopleWorkingAtStore * 5;
    double directExpenses = dailyDirectExpenses * planningDays;
    double indirectExpenses = dailyIndirectExpenses * planningDays;
    double generalExpensesRate = (directExpenses / indirectExpenses) * 100;
    std::cout << "Your New Product Marketing General Expenses Rate is " << generalExpensesRate << "%\n" << std::endl;
}

void Marketing::calculateRentability(Market marketName, int promotionDays, int numberCustomers = 0)
{
    double totalProfit = marketName.dailyProfit * numberCustomers * promotionDays;
    double totalIncome = marketName.dailyIncome * (numberCustomers * 2.75) * promotionDays;
    double rentability = ((totalProfit * promotionDays) / (totalIncome * promotionDays)) * 100;
    std::cout << "Your New Product Marketing Rentability is " << rentability << "%\n" << std::endl;;
}

//new UDT 5:
struct Projects
{
    University numberPresentedProjects;
    University::Professor numberOpenResearch;
    University::Student numberPapers;
    Projects();
    ~Projects() {std::cout << "Projects Destructor\n";}

    void calculateUniversityRanking(University universityName, University::Professor professorName, University::Student studentName);
    void calculateResearchInvestment(University univName, University::Professor professorName);
};

Projects::Projects() {}

void Projects::calculateUniversityRanking(University univName, University::Professor professorName, University::Student studentName)
{
    int x = professorName.checkSubscribedStudents();
    auto y = univName.calculatePresentations(studentName);
    std::cout << "The University ranking points are " << y.numberPresentations * x << "\n" << std::endl;
}

void Projects::calculateResearchInvestment(University univName, University::Professor professorName)
{
    int x = professorName.checkSubscribedStudents();
    univName.semIncome = x * 30'000;
    float investment = univName.semIncome - (univName.numProfessors * 15'000 * 6);
    
    std::cout << "This semester were invested on Research $ " << investment << std::endl;
}

//Free Functions used for 'This' practice

void Market::callMarketVarFunct()
{
    std::cout << "Market variable call numPeopleWorkingAtStore = " << this->numPeopleWorkingAtStore << std::endl;

    std::cout << "Market function call adjustInventary() = " << this->adjustInventary(phillip) << std::endl;
}

void Market::Customer::callMarketCustomerVarFunct()
{
    std::cout << "Market::Customer variable call productsToOrder = " << this->productsToOrder << std::endl;
    
    std::cout << "Market::Customer function call countNumberCustomers() = " << this->countNumberCustomers(3) << std::endl;
}

void University::callUniversityVarFunct()
{
    std::cout << "University variable call semIncome = " << this->numClassrooms << std::endl;

    std::cout << "University function call teachStudents() = " << this->teachStudents() << std::endl;
}

void University::Professor::callUniversityProfessorVarFunct()
{
    std::cout << "University::Professor variable call professorName  = " << this->professorName << std::endl;

    std::cout << "University::Professor function call checkSubscribedStudents()  = " << this->checkSubscribedStudents() << std::endl;
}

void University::Student::callUniversityStudentVarFunct()
{
    std::cout << "University::Student variable call weeklyResearchStudyHours  = " << this->weeklyResearchStudyHours << std::endl;

    std::cout << "University::Student function call computeWeekStudyTime()  = " << this->computeWeekStudyTime() << std::endl;
}

void Computer::callComputerVarFunct()
{
    std::cout << "Computer variable call execTask  = " << this->execTask << std::endl;

    std::cout << "Computer function call saveInfo()  = " << this->saveInfo() << std::endl;
}

void Computer::Hardware::callComputerHardwareVarFunct()
{
    std::cout << "Computer::Hardware variable call screen = " << this->screen << std::endl;
    
    std::cout << "Computer::Hardware function call playGames() = " << this->playGames() << std::endl;
}

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
    Market superStarMarket; //Line 77
    Market::Customer carl;
    carl.calculateOrderPrice(); //Have options to select
    carl.orderProducts(true);
    auto customers = carl.countNumberCustomers(45); //
    superStarMarket.sellProducts(carl);
    superStarMarket.adjustInventary(carl);
    auto custName = superStarMarket.countNoInventoryProducts(5);

    University programmingSchoolUniversity; //Line 196
    University::Professor joseph;
    University::Student frank; 
    frank.computeWeekStudyTime();
    frank.computeSemestralAbsences();
    frank.displayStudentInfo(frank);
    frank.subscribeCourse(frank, joseph);
    auto studentName = programmingSchoolUniversity.calculatePresentations(frank);

    Computer gamingPC; //Line 343
    Computer::Hardware highSpecs;
    highSpecs.playGames();
    auto canPlay = gamingPC.executePrograms(highSpecs, "GTA");
    gamingPC.addGamesToRAM(highSpecs, canPlay);

    Marketing newProductLaunch; //Line 487
    newProductLaunch.calculateExpensesRate(superStarMarket, 18);
    newProductLaunch.calculateRentability(superStarMarket, 45, customers);
    
    Projects engineeringResearch; //Line 530
    engineeringResearch.calculateUniversityRanking(programmingSchoolUniversity, joseph, frank);
    engineeringResearch.calculateResearchInvestment(programmingSchoolUniversity, joseph);

    // 'This' practice 
    
    Market m;
    
    std::cout << "Market variable call numPeopleWorkingAtStore = " << m.numPeopleWorkingAtStore << std::endl;

    std::cout << "Market function call adjustInventary() = " << m.adjustInventary(carl) << std::endl;
    
    m.callMarketVarFunct();

    
    Market::Customer c;

    std::cout << "Market::Customer variable call productsToOrder = " << c.productsToOrder << std::endl;
    
    std::cout << "Market::Customer function call countNumberCustomers() = " << c.countNumberCustomers(3) << std::endl;
    
    c.callMarketCustomerVarFunct();

    
    University u;

    std::cout << "University variable call semIncome = " << u.numClassrooms << std::endl;

    std::cout << "University function call teachStudents() = " << u.teachStudents() << std::endl;
    
    u.callUniversityVarFunct();

    
    University::Professor p;

    std::cout << "University::Professor variable call professorName  = " << p.professorName << std::endl;

    std::cout << "University::Professor function call checkSubscribedStudents()  = " << p.checkSubscribedStudents() << std::endl;
    
    p.callUniversityProfessorVarFunct();

    
    University::Student s;

    std::cout << "University::Student variable call weeklyResearchStudyHours  = " << s.weeklyResearchStudyHours << std::endl;

    std::cout << "University::Student function call computeWeekStudyTime()  = " << s.computeWeekStudyTime() << std::endl;
    
    s.callUniversityStudentVarFunct();

    
    Computer pc;

    std::cout << "Computer variable call execTask  = " << pc.execTask << std::endl;

    std::cout << "Computer function call saveInfo()  = " << pc.saveInfo() << std::endl;
    
    pc.callComputerVarFunct();
    

    Computer::Hardware hw;

    std::cout << "Computer::Hardware variable call screen = " << hw.screen << std::endl;
    
    std::cout << "Computer::Hardware function call playGames() = " << hw.playGames() << std::endl;
    
    hw.callComputerHardwareVarFunct();    
    
    std::cout << "good to go!" << std::endl;
}
