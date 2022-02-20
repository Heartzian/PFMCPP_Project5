/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

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
        Customer();
        ~Customer() {std::cout << "Customer Destructor\n";}

        void calculateOrderPrice(int breakfastProds, int morningBreakProds, int lunchProds, int coffeeBreakProds, int dinnerProds); 
        void orderProducts(bool deliveryRequired = true);  
        auto countNoInventoryProducts(int maxAllowed); //Moved from Line 110
    };

    void sellProducts(Customer customerName);
    void adjustInventary(Customer customerName);
    /*Customer countNoInventoryProducts(int maxAllowed)
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
    }*/
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

auto Market::Customer::countNoInventoryProducts(int maxAllowed)
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
    {--numLogisticVehicles;
    --numPeopleWorkingAtStore;
    }
    dailyIncome += customerNick.totalToPay;

    std::cout << "Dear " << customerNick.customerName << ", you ordered " <<  customerNick.productsToOrder << " products, with a total cost of $" << customerNick.totalToPay << ", which will be Delivered by Tom." << " this week, you have come to our store " << customerNick.visitsThisWeek << " times, Thanks for buying with us!\n" << std::endl;
}

void Market::adjustInventary(Customer customerName)
{
    numProdLocalInv -= customerName.productsToOrder;
}

//copied UDT 2:
struct University
{
    int numClassrooms = 80;
    int numLabs = 36;
    int numProfessors = 95;
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
        Professor();
        ~Professor() {std::cout << "Professor Destructor\n";}

        void checkSubscribedStudents();
        float computeMonthlyExpenses(float rent = 1800,
                                     float food = 550,
                                     float fun = 120, 
                                     float other = 150);
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

        void computeWeekStudyTime();
        void computeSemestralAbsences();
        void displayStudentInfo(Student studentName);
        void subscribeCourse(Student studentName, Professor professorName);
    }; 

    float teachStudents();  
    void doResearch(std::string organization = "UCLA",
                    std::string department = "Chemistry",
                    std::string projectName = "influence of fertilizer on plant cultivation"); 
    void doCulturalActivities(Student name,
                              std::string category = "Arts",
                              std::string activity = "Music Museum Visit"); 
    Student calculatePresentations(Student studentNick)
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

void University::Professor::checkSubscribedStudents()
{
    return ;
}

float University::Professor::computeMonthlyExpenses(float rent,
                                                    float food,
                                                    float fun, 
                                                    float other)
{
    return rent + food + fun + other;
}

void University::Student::computeWeekStudyTime()
{
    weeklyPresentialStudyHours = semestralCredits * 3;
    weeklyResearchStudyHours = weeklyPresentialStudyHours * 2;
    semestralStudyTime = (weeklyPresentialStudyHours + weeklyResearchStudyHours) * 16;
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
        
        void playGames(); 
        void trainAI(); 
        void workAtOffice(); 
    };

    bool executePrograms(Hardware specs, std::string installedSoft);  
    void saveInfo(bool diskAvailable = true); 
    void connectToPCs(bool LANavailable = true);
    Hardware addGamesToRAM(Hardware pcType, bool abilityToPlay)
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
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

Computer::Hardware::Hardware()
{
    std::cout << "Computer Hardware being constructed!\n" << std::endl;
}

void Computer::Hardware::playGames()
{
    if (RAM >= 4 && disk >=256 && CPU >= 3.0 && GPU >= 2)
    {
        //std::cout << "You can use this computer to play games";  
    
        canPlayGames = true;
    }
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

void Computer::saveInfo(bool diskAvailable)
{
    if (diskAvailable == true)
    {
        std::cout << "The file will be saved";

        canSaveInfo = true;
    }
    
}

void Computer::connectToPCs(bool LANavailable)
{
    if (LANavailable == true)
    {
        std::cout << "The computer is available to connect to LAN";
    }
}

//new UDT 4:
struct Marketing
{
    Market numberLocations;
    Market::Customer numberCustomers;
    Marketing();
    ~Marketing() {std::cout << "Marketing Destructor\n";}

    void calculateExpenses();
    void calculateRentability();
};

//new UDT 5:
struct Projects
{
    University numberPresentedProjects;
    University::Professor numberOpenResearch;
    University::Student numberPapers;
    Projects();
    ~Projects() {std::cout << "Projects Destructor\n";}

    void calculateUniversityRanking();
    void calculateResearchInvestment();
};


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
    superStarMarket.sellProducts(carl);
    superStarMarket.adjustInventary(carl);
    auto custName = carl.countNoInventoryProducts(5);
    //auto custName = superStarMarket.countNoInventoryProducts(5);
    //Line 110

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
    
    std::cout << "good to go!" << std::endl;
}
