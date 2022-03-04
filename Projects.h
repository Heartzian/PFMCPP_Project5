#pragma once

#include"Wrappers.h"

struct Projects
{
    University numberPresentedProjects;
    University::Professor numberOpenResearch;
    University::Student numberPapers;
    Projects();
    ~Projects() {std::cout << "Projects Destructor\n";}

    void calculateUniversityRanking(University& universityName, University::Professor& professorName, University::Student& studentName);
    void calculateResearchInvestment(University& univName, University::Professor& professorName);
    JUCE_LEAK_DETECTOR(Projects)
};
