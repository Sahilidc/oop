// Varad Charholikar
// PA01

// Assignment 3 : To demonstrate the use of objects, classes, constructors and destructors using C++.

#include <iostream>
using namespace std;

class Complex
{
public:
    int real, imaginary;

    // Default Constructor
    Complex()
    {
        cout << "Default Constructor was called!" << endl;
    }

    // Parameterized Constructor
    Complex(int r, int i)
    {
        this->real = r;
        this->imaginary = i;
        cout << "Parameterized Constructor was called!" << endl;
    }

    // Copy Constructor
    Complex(Complex &obj)
    {
        this->real = obj.real;
        this->imaginary = obj.imaginary;
        cout << "Copy Constructor was called!" << endl;
    }

    // Member function
    void addComplexNumber(Complex obj1, Complex obj2, Complex &ans)
    {
        ans.real = obj1.real + obj2.real;
        ans.imaginary = obj1.imaginary + obj2.imaginary;
        cout << "The addition of real number is " << ans.real << ", the addition of imaginary number is " << ans.imaginary << endl;
    }

    // Destructor
    ~Complex()
    {
        cout << "Destructor was called!" << endl;
    }
};

int main()
{
    // Complex obj1, obj2, ans;

    Complex* obj1();

    Complex obj2(4,5);

    Complex c1(obj2);
    
    Complex c2(2,8);

    Complex ans(0,0);

    ans.addComplexNumber(c1, c2, ans);

    return 0;
}