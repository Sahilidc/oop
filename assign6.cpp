#include <iostream>
using namespace std;

class Box
{
private:
    int length, breadth, height;

public:
    // Default constructor
    Box() : length(0), breadth(0), height(0) {}

    // Parameterized constructor
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}

    // Member function to add the two box objects
    Box operator+(const Box &b)
    {
        return Box(length + b.length, breadth + b.breadth, height + b.height);
    }

    // Overloading << operator to display the box dimensions
    friend ostream &operator<<(ostream &os, const Box &b)
    {
        os << "Box dimensions are length: " << b.length << ", breadth: " << b.breadth << ", and height: " << b.height;
        return os;
    }

    // Overloading >> operator to read the box dimensions
    friend istream &operator>>(istream &is, Box &b)
    {
        cout << "Enter length, breadth, and height of the box: ";
        is >> b.length >> b.breadth >> b.height;
        return is;
    }

    // Friend function to compute the volume of this box
    friend int operator*(const Box &b1, const Box &b2)
    {
        return b1.length * b1.breadth * b1.height * b2.length * b2.breadth * b2.height;
    }
};

int main()
{
    Box b1(5, 6, 7), b2(8, 9, 10);

    cout << b1 << endl;
    cout << b2 << endl;

    cout << "Adding the two boxes: " << endl;
    Box b3 = b1 + b2;
    cout << b3 << endl;

    cout << "Computing the volume of the two boxes: " << endl;
    int volume = b1 * b2;
    cout << "Volume: " << volume << endl;

    return 0;
}