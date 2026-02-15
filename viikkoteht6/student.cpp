#include "student.h"
#include <iostream>

student::student()
{
    //cout << "DEBUG: Default konstruktori" << endl;
}

student::student(string a, int b)
{
    //cout << "DEBUG: Konstruktori käyttää parametrejä: " << a << " ja " << b << endl;
    name = a;
    age = b;
}

void student::setAge(int a)
{
    //cout << "DEBUG: setAge()" << endl;
    age = a;
}

void student::setName(string n)
{
    //cout << "DEBUG: setName()" << endl;
    name = n;
}

string student::getName() const
{
    //cout << "DEBUG: getName()" << endl;
    return name;
}

int student::getAge() const
{
    //cout << "DEBUG: getAge()" << endl;
    return age;
}

void student::printStudentInfo() const
{
    //cout << "DEBUG: printStudentInfo()" << endl;
    cout << "Student " << name << " Age " << age << endl;
}
