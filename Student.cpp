#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

Student::Student() {}

Student::Student(string idx, string nm) {
    indexNumber = idx;
    name = nm;
}

void Student::inputStudent() {
    cout << "Enter Index Number: ";
    cin >> indexNumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
}

void Student::displayStudent() const {
    cout << "Index: " << indexNumber << " | Name: " << name << endl;
}

string Student::getIndex() const {
    return indexNumber;
}

string Student::getName() const {
    return name;
}

void Student::saveToFile() const {
    ofstream out("students.txt", ios::app);
    if (out.is_open()) {
        out << indexNumber << "," << name << endl;
        out.close();
    }
}

vector<Student> Student::loadFromFile() {
    vector<Student> students;
    ifstream in("students.txt");

    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            size_t comma = line.find(',');
            if (comma != string::npos) {
                string idx = line.substr(0, comma);
                string nm = line.substr(comma + 1);
                students.push_back(Student(idx, nm));
            }
        }
        in.close();
    }

    return students;
}
