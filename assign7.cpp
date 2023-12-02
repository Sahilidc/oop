#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Marksheet
{
public:
    int PRN;
    string studentName;
    int Maths, Physics, Chemistry;
    float Total;
    char Grade;

    Marksheet(){};
    Marksheet(int PRN, string studentName)
    {
        this->PRN = PRN;
        this->studentName = studentName;
    }

    void inputMarks()
    {
        cout << "Enter Marks for Maths: ";
        cin >> Maths;
        cout << "Enter Marks for Physics: ";
        cin >> Physics;
        cout << "Enter Marks for Chemistry: ";
        cin >> Chemistry;

        if (Maths < 0 || Physics < 0 || Chemistry < 0)
        {
            cout << "Marks cannot be negative!" << endl;
            exit(0);
        }

        Total = (Maths + Physics + Chemistry) / 3.0;
        if (Total >= 90)
            Grade = 'A';
        else if (Total >= 80)
            Grade = 'B';
        else if (Total >= 70)
            Grade = 'C';
        else if (Total >= 60)
            Grade = 'D';
        else
            Grade = 'F';
    }

    void displayRecord()
    {
        cout << "\nPRN: " << PRN;
        cout << "\nStudent Name: " << studentName;
        cout << "\nMaths: " << Maths;
        cout << "\nPhysics: " << Physics;
        cout << "\nChemistry: " << Chemistry;
        cout << "\nTotal %: " << Total;
        cout << "\nGrade: " << Grade << endl;
    }
};

class Teacher : public Marksheet
{
public:
    void addRecord(Marksheet &s)
    {
        ofstream fout("marks.txt", ios::app);
        if (!fout)
        {
            cout << "File could not be created!";
            exit(0);
        }
        fout << s.PRN << " ";
        fout << s.studentName << " ";
        fout << s.Maths << " ";
        fout << s.Physics << " ";
        fout << s.Chemistry << " ";
        fout << s.Total << " ";
        fout << s.Grade << endl;
    }

    void searchRecord(int PRN)
    {
        ifstream fin("marks.txt");
        if (!fin)
        {
            cout << "File could not be opened!";
            exit(0);
        }
        Marksheet s;
        while (fin >> s.PRN)
        {
            fin >> s.studentName;
            fin >> s.Maths;
            fin >> s.Physics;
            fin >> s.Chemistry;
            fin >> s.Total;
            fin >> s.Grade;

            if (s.PRN == PRN)
            {
                s.displayRecord();
                return;
            }
        }
        cout << "No student with PRN " << PRN << " was found!" << endl;
    }
};

class Administrator
{
public:
    void deleteRecord(int PRN)
    {
        ifstream fin("marks.txt");
        ofstream fout("temp.txt");
        if (!fin || !fout)
        {
            cout << "File could not be opened!";
            exit(0);
        }
        Marksheet s;
        bool found = false;
        while (fin >> s.PRN)
        {
            fin >> s.studentName;
            fin >> s.Maths;
            fin >> s.Physics;
            fin >> s.Chemistry;
            fin >> s.Total;
            fin >> s.Grade;

            if (s.PRN != PRN)
            {
                fout << s.PRN << " ";
                fout << s.studentName << " ";
                fout << s.Maths << " ";
                fout << s.Physics << " ";
                fout << s.Chemistry << " ";
                fout << s.Total << " ";
                fout << s.Grade << endl;
            }
            else
                found = true;
        }
        if (!found)
            cout << "No student with PRN " << PRN << " was found!" << endl;
        else
        {
            fin.close();
            fout.close();
            remove("marks.txt");
            rename("temp.txt", "marks.txt");
        }
    }
};

int main()
{
    Administrator admin;
    Teacher teacher;
    Marksheet s(1, "Alice");
    s.inputMarks();
    teacher.addRecord(s);
    teacher.searchRecord(1);
    admin.deleteRecord(1);
    return 0;
}