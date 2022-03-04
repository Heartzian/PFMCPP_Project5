#pragma once
#include "LeakedObjectDetector.h"
#include"Wrappers.h"

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
        JUCE_LEAK_DETECTOR(Professor)
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
        //~Student() {std::cout << "Student Destructor\n";}

        double computeWeekStudyTime();
        void computeSemestralAbsences();
        void displayStudentInfo(Student& studentName);
        void subscribeCourse(Student& studentName, Professor& professorName);
        //void changeHoursAndStudyTime();
        void callUniversityStudentVarFunct();
        JUCE_LEAK_DETECTOR(Student)
    }; 

    float teachStudents();  
    void doResearch(std::string organization = "UCLA",
                    std::string department = "Chemistry",
                    std::string projectName = "influence of fertilizer on plant cultivation"); 
    void doCulturalActivities(Student& name,
                              std::string category = "Arts",
                              std::string activity = "Music Museum Visit"); 
    Student calculatePresentations(Student& studentNick);
    //void changeIncomeAndTeachSt();
    void callUniversityVarFunct();
    JUCE_LEAK_DETECTOR(University)
};
