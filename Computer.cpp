#include<iostream>
#include"Computer.h"

Computer::Computer()
{
    std::cout << "Computer being constructed!\n" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer being destructed!\n" << std::endl;
}

Computer::Hardware::Hardware()
{
    std::cout << "Computer Hardware being constructed!\n" << std::endl;
}

Computer::Hardware::~Hardware()
{
    std::cout << "Computer Hardware being destructed!\n" << std::endl;
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

bool Computer::executePrograms(Hardware& specs, std::string installedSoft)
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

Computer::Hardware Computer::addGamesToRAM(Hardware& pcType, bool abilityToPlay)
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

//Free Functions for 'this' practice

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
