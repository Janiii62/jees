#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int selection =0;
    vector<student>studentList;
    vector<student>::iterator it = studentList.begin();
    string nimi;
    int ika;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            //cout << "DEBUG: case 0, lisätään opiskelija" << endl;
            // kysytään oppilaalta nimi ja ikä

            cout << "Student name ?" << endl;
            cin>>nimi;

            cout << "Student age ?" << endl;
            cin>>ika;

            // Lisätään uusi student StudentList vektoriin.
            studentList.emplace_back(nimi,ika);

            break;

        case 1:
            // tulostetaan StudentListiin opiskelijoiden nimet
            // cout << "DEBUG: case 1, tulostetaan lista." << endl;

            for(auto &s: studentList){
                s.printStudentInfo();   // changed to match teacher output
            }
            break;

        case 2:
            //cout << "DEBUG: case 2" << endl;
            // sortilla järjestetään StudenListin oliot nimien perusteel

            sort(studentList.begin(), studentList.end(), [](student &a, student &b){
                return a.getName() < b.getName();
            });

            // tulostetaan järjestellyt opiskelijat '' s.printStudentInfo();'' avul
            for(auto &s: studentList){
                s.printStudentInfo();
            }
            break;

        case 3:
            //cout << "DEBUG: case 3, tulosta järjestetyt opiskelijat" << endl;
            // laitellaan student oliot iän mukaiseen järjestyksee

            sort(studentList.begin(), studentList.end(), [](student &a, student &b){
                return a.getAge() < b.getAge();
            });

            // tulostetaan taas ne opiskelijat
            for (auto &s: studentList){
                s.printStudentInfo();
            }
            break;

        case 4:
            // kysytään opiskelijan nimeä

            cout << "Student to be found name = ?" << endl;
            cin >> nimi;

            // etitään löytyykö nimeä
            it = find_if(studentList.begin(), studentList.end(), [nimi](student &a){
                return a.getName() == nimi;
            });

            if(it != studentList.end()){
                cout << "Student found:" << endl;
                it->printStudentInfo();
            }
            else{
                cout << "Name not found" << endl;
            }

            break;

        default:
            cout << "Chose wrong, stopping."<<endl;
            break;
        }

    }while(selection < 5);

    return 0;
}
