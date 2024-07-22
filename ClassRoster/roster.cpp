#include "roster.h"
#include <iostream>

using namespace std;

Roster::Roster() {
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr; //initialize the array with nullptr 
	}
}Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}

//adds a student to the class roster array 
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
			break;
		}
	}
}

//removes student from array by student ID 
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            for (int j = i; j < 4; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
                classRosterArray[j + 1] = nullptr;
            }
            break;
        }
    }
    if (!found) {
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }
}

//prints all student data 
void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

//prints the invalid emails (valid emails include '@' and '.'. does not include ' ')
void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmail();
            if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
                cout << email << " - is invalid." << endl;
            }
        }
    }
}

//print student by degree program 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// print the average day in course for students 
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            cout << "Student ID: " << studentID << ", average days in course: " << (days[0] + days[1] + days[2]) / 3 << endl;
        }
    }
}

// Helper function to convert string to int
int stringToInt(const string& str) {
    int num = 0;
    for (char c : str) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
    }
    return num;
}

// Function to split a string by a delimiter
string getNextToken(string& str, char delimiter) {
    size_t pos = str.find(delimiter);
    string token = str.substr(0, pos);
    str.erase(0, pos + 1);
    return token;
}

// Function to parse a data row and add a student to the classRosterArray
void Roster::parse(string row) {
    string studentID = getNextToken(row, ',');
    string firstName = getNextToken(row, ',');
    string lastName = getNextToken(row, ',');
    string emailAddress = getNextToken(row, ',');
    int age = stringToInt(getNextToken(row, ','));
    int daysInCourse1 = stringToInt(getNextToken(row, ','));
    int daysInCourse2 = stringToInt(getNextToken(row, ','));
    int daysInCourse3 = stringToInt(getNextToken(row, ','));
    string degreeStr = getNextToken(row, ',');

    DegreeProgram degreeProgram;
    if (degreeStr == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (degreeStr == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (degreeStr == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }

    // Add the student to the roster
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}