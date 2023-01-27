#pragma once

#define _DEBUGGING_

#include <iostream>
#include <string>
#include <vector>

//������� �������� ������� � ��������� ��� int ���������� ������� �������� ��� string
std::string ComandEmp(const int com); 

//����� Human ������ ������� Employ, Manager, Boss
//-------------------------------------------------------------------------------------------
class Human {

protected:
    std::string name;

    Human() : name("") {}
};

//����� Employ
//-------------------------------------------------------------------------------------------
class Employee : public Human {
    std::string task;

public:
    Employee() : Human(), task("") {}

    void SetName(std::string name);

    //�����  ������������� ���� ������ task
    void SetComand(const std::string task); 

    //����������� ����� �������� ����� ���������
    static Employee SetEmployee(const int depNum); 

    //����������� ��������� ����� (debug) �������� ����� ���������
    static Employee SetEmployDebug(std::string ttt); 

    std::string GetTask(); 
};

//����� Manager
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

    //����������� ����� ���������� ������ �������� -> ���������
    static Manager SetManager(const int depNum);

#endif // !_DEBUGGING_


#ifdef _DEBUGGING_

    //����������� �������� ����� (debug) ���������� ������ �������� -> ���������
    static Manager SetManager(std::vector<std::string>& ttt, int numDep);

#endif // _DEBUGGING_    

    //����� �������� ������� �� ������������ � ����������� �� ����������
    bool SetComand(const int com, const int numDep); 
};

//����� Boss
//-------------------------------------------------------------------------------------------
class Boss : public Human {

    int full;

    std::vector<Manager> manager;

public:
    Boss() : Human(), full(manager.size()) {}

    void SetName(std::string name); 

#ifndef _DEBUGGING_

    //����� ������� ������ �����������
    void CreateTeam();

#endif // !_DEBUGGING_     

#ifdef _DEBUGGING_

    //��������� ����� (debug) ������� ������ �����������
    void CreateTeam(std::vector<std::vector<std::string>>& ttt);

#endif // _DEBUGGING_    

    //����� �������� ������� ������������ ���������� �� ���������
    bool SetComand(const int com); 
};

