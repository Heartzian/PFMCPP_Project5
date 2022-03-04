#include <iostream>
#include"University.h"

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

void University::Student::displayStudentInfo(Student& studentNick)
{
    std::cout << "Dear " << studentNick.studentName << ". Welcome to study " << studentNick.career << ". This semester you chose " << studentNick.semestralCredits << " credits. You'll have " << studentNick.weeklyPresentialStudyHours << " weekly presential study hours. Please remember you can only have 10% of class absence, which in your case means " << studentNick.semestralAllowedAbsences << " hours per class. Enjoy your time!\n" << std::endl;
}

void University::Student::subscribeCourse(Student& studentNick, Professor& professorNick)
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

void University::doCulturalActivities(Student& studentNick,
                                           std::string category,
                                           std::string activity)
{
    std::cout << "This semester the University performed a Cultural Activity with " << studentNick.studentName << " from " << studentNick.career << " which likes to " << studentNick.hobby << " in the category: " << category << " doing the activity " << activity << ".\n" << std::endl;
}

University::Student University::calculatePresentations(Student& studentNick)
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

//Free Functions for 'this' practice

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
