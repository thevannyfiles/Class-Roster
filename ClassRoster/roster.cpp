#include "roster.h"
#include <iostream>

using namespace std;

// Constructor for the Roster class - initialize to nullptr 
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor for the Roster class, ensures dynamic memory is cleaned up
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

// adds new student to the roster 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    if (lastIndex < 4) {
        classRosterArray[++lastIndex] = newStudent; //increments the index and then add new student to array 
    }
    else {
        cout << endl; 
    }
}

//remove student by ID 
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];  // Deallocate memory
            classRosterArray[i] = classRosterArray[lastIndex];
            classRosterArray[lastIndex] = nullptr;  // Nullify the moved pointer
            lastIndex--;
            found = true;
            cout << "Removing " << studentID << ":" << endl;
            break;
        }
    }
    if (!found) {
        cout << "The student wit the ID: " << studentID << " was not found." << endl;
    }
}

// Print all students
void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

    // Print the average days in course for a specific student
    void Roster::printAverageDaysInCourse(string studentID) {
        for (int i = 0; i <= lastIndex; i++) {
            if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
                array<int,3> days = classRosterArray[i]->getDaysInCourse();
                cout << "Student ID: " << studentID << ", average days in the course is: "
                    << (days[0] + days[1] + days[2]) / 3.0 << endl;
                break;
            }
        }
    }

// Print invalid emails
void Roster::printInvalidEmails() {
    cout << "Displaying invalid emails:" << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]) {
            string email = classRosterArray[i]->getEmail();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << email << " - is invalid." << endl;
            }
        }
    }
}
// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Showing students in degree program: " << degreeProgram << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}