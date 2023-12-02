// Varad Charholikar
// PA01

// Assignment 5 : Implementation of inheritance using C++.

#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string Emp_name, Emp_id, Address, Mail_id, Mobile_no;
    double DA, HRA, PF, Clu_fund, gross_pay, net_pay, basic_pay;

    Employee(string name, string id, string addr, string mail, string mobile)
    {
        this->Emp_name = name;
        this->Emp_id = id;
        this->Address = addr;
        this->Mail_id = mail;
        this->Mobile_no = mobile;
    }
    virtual void getSalary(double basic_pay) = 0;
    void generateSlip()
    {
        cout << "Employee Name: " << Emp_name << endl;
        cout << "Employee ID: " << Emp_id << endl;
        cout << "Address: " << Address << endl;
        cout << "Mail ID: " << Mail_id << endl;
        cout << "Mobile No: " << Mobile_no << endl;
        cout << "Basic Pay: " << basic_pay << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "PF: " << PF << endl;
        cout << "Club Fund: " << Clu_fund << endl;
        cout << "Gross Pay: " << gross_pay << endl;
        cout << "Net Pay: " << net_pay << endl; 
    }
};

class Programmer : public Employee
{
public:
    Programmer(string name, string id, string addr, string mail, string mobile) : Employee(name, id, addr, mail, mobile) {}
    void getSalary(double basic)
    {
        basic_pay = basic;
        DA = 0.97 * basic_pay;
        HRA = 0.10 * basic_pay;
        PF = 0.12 * basic_pay;
        Clu_fund = 0.001 * basic_pay;

        gross_pay = basic_pay + DA + HRA;
        net_pay = gross_pay - PF - Clu_fund;
    }
};

class TeamLead : public Employee
{
public:
    TeamLead(string name, string id, string addr, string mail, string mobile) : Employee(name, id, addr, mail, mobile) {}
    void getSalary(double basic)
    {
        basic_pay = basic;
        DA = 0.97 * basic_pay;
        HRA = 0.10 * basic_pay;
        PF = 0.12 * basic_pay;
        Clu_fund = 0.001 * basic_pay;

        gross_pay = basic_pay + DA + HRA;
        net_pay = gross_pay - PF - Clu_fund;
    }
};

class AssistantProjectManager : public Employee
{
public:
    AssistantProjectManager(string name, string id, string addr, string mail, string mobile) : Employee(name, id, addr, mail, mobile) {}
    void getSalary(double basic)
    {
        basic_pay = basic;
        DA = 0.97 * basic_pay;
        HRA = 0.10 * basic_pay;
        PF = 0.12 * basic_pay;
        Clu_fund = 0.001 * basic_pay;

        gross_pay = basic_pay + DA + HRA;
        net_pay = gross_pay - PF - Clu_fund;
    }
};

class ProjectManager : public Employee
{
public:
    ProjectManager(string name, string id, string addr, string mail, string mobile) : Employee(name, id, addr, mail, mobile) {}
    void getSalary(double basic)
    {
        basic_pay = basic;
        DA = 0.97 * basic_pay;
        HRA = 0.10 * basic_pay;
        PF = 0.12 * basic_pay;
        Clu_fund = 0.001 * basic_pay;

        gross_pay = basic_pay + DA + HRA;
        net_pay = gross_pay - PF - Clu_fund;
    }
};

int main()
{
    Programmer emp1("Isha Katkar", "1", "123 St", "isha@gmail.com", "1234567890");
    emp1.getSalary(10000);
    emp1.generateSlip();
    cout << endl; 

    TeamLead emp2("Vishwa Patil", "2", "456 St", "vishwa@gmail.com", "2345678901");
    emp2.getSalary(12000);
    emp2.generateSlip();
    cout << endl;

    AssistantProjectManager emp3("Manas Jain", "3", "234 St", "manas@gmail.com", "1357984620");
    emp3.getSalary(15000);
    emp3.generateSlip();
    cout << endl;

    ProjectManager emp4("Varad Charholikar", "4", "789 St", "varad@gmail.com", "1478523690");
    emp4.getSalary(20000);
    emp4.generateSlip();
    cout << endl;

    return 0;
}