#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string indexNumber;
    string name;

public:
    Student();
    Student(string idx, string nm);

    void inputStudent();
    void displayStudent() const;

    string getIndex() const;
    string getName() const;

    void saveToFile() const;
    static vector<Student> loadFromFile();
};

#endif
