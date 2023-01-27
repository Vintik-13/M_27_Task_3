#pragma once

#define _DEBUGGING_

#include <iostream>
#include <string>
#include <vector>

//Функция получает команду в менеджера тип int возвращает команду рабочему тип string
std::string ComandEmp(const int com); 

//Класс Human предок классов Employ, Manager, Boss
//-------------------------------------------------------------------------------------------
class Human {

protected:
    std::string name;

    Human() : name("") {}
};

//Класс Employ
//-------------------------------------------------------------------------------------------
class Employee : public Human {
    std::string task;

public:
    Employee() : Human(), task("") {}

    void SetName(std::string name);

    //Метод  инициализации поля метода task
    void SetComand(const std::string task); 

    //Статический метод устанвки имени работника
    static Employee SetEmployee(const int depNum); 

    //Статический временный метод (debug) устанвки имени работника
    static Employee SetEmployDebug(std::string ttt); 

    std::string GetTask(); 
};

//Класс Manager
//-------------------------------------------------------------------------------------------
class Manager : public Human {

    int countFreeEmployee;

    int firstFreeEmployee;

    bool limit;

    std::string task;

    std::vector<Employee> employee;

public:
    Manager() : Human(), countFreeEmployee(0), firstFreeEmployee(0), limit(false), task("") {}

    void SetName(std::string name); 

    

#ifndef _DEBUGGING_

    //Статический метод компановки отдела менеджер -> работники
    static Manager SetManager(const int depNum);

#endif // !_DEBUGGING_


#ifdef _DEBUGGING_

    //Статический ременный метод (debug) компановки отдела менеджер -> работники
    static Manager SetManager(std::vector<std::string>& ttt, int numDep);

#endif // _DEBUGGING_    

    //Метод получает команду от руководителя и транслирует ее работникам
    bool SetComand(const int com, const int numDep); 
};

//Класс Boss
//-------------------------------------------------------------------------------------------
class Boss : public Human {

    int full;

    std::vector<Manager> manager;

public:
    Boss() : Human(), full(manager.size()) {}

    void SetName(std::string name); 

#ifndef _DEBUGGING_

    //Метод создает пустое предприятие
    void CreateTeam();

#endif // !_DEBUGGING_     

#ifdef _DEBUGGING_

    //Временный метод (debug) создает пустое предприятие
    void CreateTeam(std::vector<std::vector<std::string>>& ttt);

#endif // _DEBUGGING_    

    //Метод передает команду руководителя менеджерам по инстанции
    bool SetComand(const int com); 
};

