#pragma once
#include "LeakedObjectDetector.h"

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
    ~Computer();

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
        ~Hardware();
        
        std::string playGames(); 
        void trainAI(); 
        void workAtOffice(); 
        //void changeScreenAndPlayGames();
        void callComputerHardwareVarFunct();
        JUCE_LEAK_DETECTOR(Hardware)
    };

    bool executePrograms(Hardware* specs, std::string installedSoft);  
    std::string saveInfo(bool diskAvailable = true); 
    void connectToPCs(bool LANavailable = true);
    Hardware addGamesToRAM(Hardware* pcType, bool abilityToPlay);
    //void changeTaskAndSaveInfo();
    void callComputerVarFunct();
    JUCE_LEAK_DETECTOR(Computer)
};
