// Varad Charholikar
// PA01

// Assignment 1 : To parameter passing by value vs by reference, passing array as constant pointer

#include <iostream>
using namespace std;

void swapbyV(int n1, int n2)
{
    cout << "Swapping by Value!" << endl
         << endl;
    swap(n1, n2);
    cout << "Inside function!" << endl;
    cout << "Number 1: " << n1 << endl;
    cout << "Number 2: " << n2 << endl;
}

void swapbyR(int &n1, int &n2)
{
    cout << "Swapping by Reference!" << endl
         << endl;
    swap(n1, n2);
    cout << "Inside function!" << endl;
    cout << "Number 1: " << n1 << endl;
    cout << "Number 2: " << n2 << endl;
}

void printarr(int *arr, int n)
{
    cout << "Printing Array!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n1, n2;
    cout << "Enter two numbers to swap: ";
    cin >> n1 >> n2;
    cout << "Number 1: " << n1 << endl;
    cout << "Number 2: " << n2 << endl
         << endl;

    // Passing by value
    swapbyV(n1, n2);
    cout << "Inside main!" << endl;
    cout << "Number 1 after pass by value: " << n1 << endl;
    cout << "Number 2 after pass by value: " << n2 << endl
         << endl;

    // Passing by reference
    swapbyR(n1, n2);
    cout << "Inside main!" << endl;
    cout << "Number 1 after pass by reference: " << n1 << endl;
    cout << "Number 2 after pass by reference: " << n2 << endl
         << endl;

    // Passing array as a pointer
    int arr[10], n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printarr(arr, n);

    return 0;
}