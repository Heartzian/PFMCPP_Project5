#pragma once
#include "LeakedObjectDetector.h"
#include "University.h"

struct Projects
{
    University numberPresentedProjects;
    University::Professor numberOpenResearch;
    University::Student numberPapers;
    Projects();
    ~Projects();

    void calculateUniversityRanking(University& universityName, University::Professor& professorName, University::Student& studentName);
    void calculateResearchInvestment(University& univName, University::Professor& professorName);
    JUCE_LEAK_DETECTOR(Projects)
};
