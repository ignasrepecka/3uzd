#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "calculateStatistics.h" // Include this

using namespace std;

void ivestiStudentus(int a) {
    int n;
    cout << "Kiek studentu: ";
    cin >> n;

    vector<Studentas> studentai(n);

    for(int i = 0; i < n; ++i) {
        cout << "Irasyti studento duomenis (vardas, pavarde, balai, egz): " << endl;
        Studentas temp;
        cin >> temp;
        cout << endl;

        temp.calculateStatistics();

        Studentas newStudent(temp);

        studentai[i] = newStudent;
    }

    for(const auto& studentas : studentai) {
        cout << studentas << endl; // Use the overloaded output operator
    }
}
