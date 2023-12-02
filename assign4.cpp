// Varad Charholikar
// PA01

// Assignment 4 : To study dynamic memory allocation and static member using employee class.

#include <iostream>
#include <string>
using namespace std;

class employee
{
public:
    string name;
    int employeeNumber;
    string qualification;
    string address;
    long long int contactNumber;
    int salary;

    employee()
    {
        cout << "Enter the Employee Name: ";
        cin >> name;

        cout << "Enter the Employee Number: ";
        cin >> employeeNumber;

        cout << "Enter the Employee Qualification: ";
        cin >> qualification;

        cout << "Enter the Employee Address: ";
        cin >> address;

        cout << "Enter the Employee Contact Number: ";
        cin >> contactNumber;

        cout << "Enter the Employee Salary: ";
        cin >> salary;
        cout << endl;
    }

    void display()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Employee Qualification: " << qualification << endl;
        cout << "Employee Address: " << address << endl;
        cout << "Employee Contact Number: " << contactNumber << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of Employees: " << endl;
    cin >> n;

    employee *arr = new employee[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].display();
        cout << endl;
    }

    delete[] arr;
}