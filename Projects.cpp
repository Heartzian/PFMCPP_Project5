#include"Projects.h"
#include "University.h"

Projects::Projects()
{
    std::cout << "Projects being constructed!\n" << std::endl;
}
Projects::~Projects()
{
    std::cout << "Projects being destructed!\n" << std::endl;
}

void Projects::calculateUniversityRanking(University& univName, University::Professor& professorName, University::Student& studentName)
{
    int x = professorName.checkSubscribedStudents();
    auto y = univName.calculatePresentations(studentName);
    std::cout << "The University ranking points are " << y.numberPresentations * x << "\n" << std::endl;
}

void Projects::calculateResearchInvestment(University& univName, University::Professor& professorName)
{
    int x = professorName.checkSubscribedStudents();
    univName.semIncome = x * 30'000;
    float investment = univName.semIncome - (univName.numProfessors * 15'000 * 6);
    
    std::cout << "This semester were invested on Research $ " << investment << std::endl;
}
