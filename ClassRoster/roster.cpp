#include <iostream>, <string> 
#include "roster.h"
using namespace std;

//constructor 
Roster::Roster() {}

//destructor 
Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete classRosterArray[i]; //delete each of the student object
	}
}

//add function
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	lastIndex++; //incrementing lastIndex
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

//remove function
void Roster::remove(string studentID) {
    bool found = false; // Flag to track if the student is found
    
    // Loop through each student in the roster
    for (int i = 0; i <= lastIndex; i++) {
        // Check if the current student's ID matches the given ID
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i]; // Delete the student object
            // Shift remaining students down
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            lastIndex--; // Decrement lastIndex
            found = true; // Set found flag to true
            cout << "Student with ID " << studentID << " removed." << endl;
            break; // Exit the loop
        }
    }
    // Print error message if student not found
    if (!found) {
        cout << "ERROR: Student with ID " << studentID << " not found." << endl;
    }
}


// Function to print all students in the roster
void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		classRosterArray[i]->Print();
	}
}

// Function to parse a student data string and add the student to the roster
void Roster::parse(string row) {
    string studentInfo[9]; // Array to hold the parsed student information
    size_t start = 0; // Starting position for parsing
    size_t end = 0; // Ending position for parsing

    // Split the row by commas and store each part in the studentInfo array
    for (int i = 0; i < 9; i++) {
        end = row.find(',', start);
        if (end == string::npos) {
            studentInfo[i] = row.substr(start);
        }
        else {
            studentInfo[i] = row.substr(start, end - start);
            start = end + 1;
        }
    }

    // Convert the degree program string to the enum value
    DegreeProgram degreeProgram;
    if (studentInfo[8] == "SECURITY") degreeProgram = SECURITY;
    else if (studentInfo[8] == "NETWORK") degreeProgram = NETWORK;
    else if (studentInfo[8] == "SOFTWARE") degreeProgram = SOFTWARE;

    // Add the student to the roster using the parsed information
    add(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], stoi(studentInfo[4]), stoi(studentInfo[5]), stoi(studentInfo[6]), stoi(studentInfo[7]), degreeProgram);
}

// Function to print the average days in course for a student
void Roster::printAverageDaysInCourse(string studentID) {
    // Loop through each student in the roster
    for (int i = 0; i <= lastIndex; i++) {
        // Check if the current student's ID matches the given ID
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse(); // Get the days in course array
            cout << "Student ID: " << studentID << ", Average days in course: " << (days[0] + days[1] + days[2]) / 3 << endl; // Calculate and print the average days
            return; // Exit the function
        }
    }
    cout << "ERROR: Student with ID " << studentID << " not found." << endl; // Print error message if student not found
}

// Function to print invalid email addresses
void Roster::printInvalidEmails() {
    // Loop through each student in the roster
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmail(); // Get the email address
        // Check if the email address is invalid
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid email: " << email << endl; // Print the invalid email
        }
    }
}

// Function to print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    // Loop through each student in the roster
    for (int i = 0; i <= lastIndex; i++) {
        // Check if the current student's degree program matches the given degree program
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print(); // Print the student's details
        }
    }
}

// Accessor to get a student at a specific index
Student* Roster::getStudentAt(int index) {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    }
    return nullptr;
}

