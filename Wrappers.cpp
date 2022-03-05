#include"Wrappers.h"
#include"Market.h"
#include"University.h"
#include"Computer.h"
#include"Marketing.h"
#include"Projects.h"

MarketWrapper::MarketWrapper( Market* newMarketPtr) : marketPtr(newMarketPtr) { }
MarketWrapper::~MarketWrapper() { delete marketPtr; }

CustomerWrapper::CustomerWrapper( Market::Customer* newCustomerPtr) : customerPtr(newCustomerPtr) { }
CustomerWrapper::~CustomerWrapper() { delete customerPtr; }

UniversityWrapper::UniversityWrapper( University* newUniversityPtr) : universityPtr(newUniversityPtr) { }
UniversityWrapper::~UniversityWrapper() { delete universityPtr; }

ProfessorWrapper::ProfessorWrapper(University::Professor* newProfessorPtr) : professorPtr(newProfessorPtr) { }
ProfessorWrapper::~ProfessorWrapper() { delete professorPtr; }

StudentWrapper::StudentWrapper(University::Student* newStudentPtr) : studentPtr(newStudentPtr) { }
StudentWrapper::~StudentWrapper() { delete studentPtr; }

ComputerWrapper::ComputerWrapper(Computer* newComputerPtr) : computerPtr(newComputerPtr) { }
ComputerWrapper::~ComputerWrapper() { delete computerPtr; }

HardwareWrapper::HardwareWrapper(Computer::Hardware* newHardwarePtr) : hardwarePtr(newHardwarePtr) { }
HardwareWrapper::~HardwareWrapper() { delete hardwarePtr; }

MarketingWrapper::MarketingWrapper( Marketing* newMarketingPtr) : marketingPtr(newMarketingPtr) { }
MarketingWrapper::~MarketingWrapper() { delete marketingPtr; }

ProjectsWrapper::ProjectsWrapper( Projects* newProjectsPtr) : projectsPtr(newProjectsPtr) { }
ProjectsWrapper::~ProjectsWrapper() { delete projectsPtr; }
