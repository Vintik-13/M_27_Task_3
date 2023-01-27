#include "Company.h"

std::string ComandEmp(const int com) {
    srand(time(0));

    char tmp = 65 + (rand() % 3);

    std::string tmpS;

    tmpS = tmp;

    tmpS += ("-" + std::to_string(com));

    return tmpS;
}

void Employee::SetName(std::string name) {

	this->name = name;
}

void Employee::SetComand(const std::string task) {

	this->task = task;

	std::cout << "Employee " << this->name << " got a task \"" << task << "\"" << std::endl;
}

Employee Employee::SetEmployee(const int depNum) {

    Employee tmp;

    std::string name;

    std::cout << "Enter the name of the employee of department " << depNum << ": ";

    std::getline(std::cin, name);

    tmp.SetName(name);

    return tmp;
}

Employee Employee::SetEmployDebug(std::string ttt) {

    Employee tmp;

    tmp.name = ttt;

    return tmp;
}

std::string Employee::GetTask() {

    return this->task;
}

void Manager::SetName(std::string name) {
    this->name = name;
}

#ifndef _DEBUGGING_

Manager Manager::SetManager(const int depNum) {

    Manager tmp;

    std::string countW, name;

    int iCountW{ 0 };

    std::cout << "Enter the name of the manager of department " << depNum << ": ";

    std::getline(std::cin, name);

    tmp.SetName(name);

    std::cout << "Set the number of workers " << depNum << " department: ";

    std::getline(std::cin, countW);

    try {
        tmp.countFreeEmployee = std::stoi(countW);
    }
    catch (const std::invalid_argument inv) {
        std::cout << inv.what();
    }

    for (int i = 0; i < tmp.countFreeEmployee; i++) {
        tmp.employee.push_back(Employee::SetEmployee(depNum));
    }

    return tmp;
}

#endif // !_DEBUGGING_

#ifdef _DEBUGGING_

Manager Manager::SetManager(std::vector<std::string>& ttt, int numDep) {

    Manager tmp;

    tmp.name = ttt[0];

    tmp.countFreeEmployee = ttt.size() - 1;

    for (int i = 1; i < ttt.size(); i++) {
        tmp.employee.push_back(Employee::SetEmployDebug(ttt[i]));
    }

    return tmp;
}

#endif // _DEBUGGING_ 



bool Manager::SetComand(const int com, const int numDep) {

    if (countFreeEmployee <= 0) {
        limit = true;
        std::cout << std::endl << "There are no available workers" << std::endl;
        return true;
    }

    int tmpCom = com + numDep;

    this->task = std::to_string(com);

    std::cout << std::endl << "The manager of the " << numDep + 1 << "nd department "
        << this->name << " received task \"" << this->task << "\"" << std::endl;

    srand(tmpCom);

    int startId;

    if ((countFreeEmployee - 1) > 0)
        startId = 1 + rand() % (countFreeEmployee - 1);
    else
        startId = 1;

    std::cout << startId << std::endl;

    for (int i = firstFreeEmployee; i < firstFreeEmployee + startId; i++) 
        employee[i].SetComand(::ComandEmp(tmpCom));    

    firstFreeEmployee += startId;
    countFreeEmployee -= startId;

    return false;
}

void Boss::SetName(std::string name) {

    this->name = name;
}

#ifndef _DEBUGGING_

void Boss::CreateTeam() {

    std::string countM, name;

    int iCountM{ 0 }; int iCountW{ 0 };

    std::cout << "Enter the name of the head of the company: ";

    std::getline(std::cin, name);

    this->SetName(name);

    std::cout << "Set the number of managers: ";

    std::getline(std::cin, countM);
    try {
        iCountM = std::stoi(countM);
    }
    catch (const std::invalid_argument inv) {
        std::cout << inv.what();
    }

    for (int i = 0; i < iCountM; i++)
        this->manager.push_back(Manager::SetManager(i + 1));

    this->full = this->manager.size();
}

#endif // !_DEBUGGING_



#ifdef _DEBUGGING_ 

void Boss::CreateTeam(std::vector<std::vector<std::string>>& ttt) {

    this->name = "Vinogradov";

    std::vector<std::vector<std::string>>::iterator itVec = ttt.begin();

    Manager tmp;

    for (int i{ 1 }; itVec != ttt.end(); itVec++, i++)
        this->manager.push_back(Manager::SetManager(*itVec, i));

    this->full = this->manager.size();
}

#endif // _DEBUGGING_ 

bool Boss::SetComand(const int com) {

    for (int i = 0; i < manager.size(); i++) {
        if (this->full == 0) {
            return true;
        }
        if (manager[i].SetComand(com, i))
            this->full--;
    }

    return false;
}
