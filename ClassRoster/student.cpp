#include <iostream>
#include <string>
#include "student.h"
using namespace std; 

//constructor
Student::Student(string ID, string fName, string lName, string emailAddress, int yearsOfAge, array<int, 3> days, DegreeProgram nameOfDegree) {
	studentID = ID;
	firstName = fName;
	lastName = lName;
	email = emailAddress;
	yearsOfAge = yearsOfAge;
	daysInCourse = days;
	degreeProgram = nameOfDegree;
}

// getters - accessors
string Student::getStudentID() {return studentID; }
string Student::getFirstName() {return firstName; }
string Student::getLastName() {return lastName;}
string Student::getEmail() {return email; }
int Student::getAge() {return age; }
array<int, 3> Student::getDaysInCourse() {return daysInCourse; }
DegreeProgram Student::getDegreeProgram() {return degreeProgram; }

//setters - mutators
void Student::setStudentID(string ID) { studentID = ID; }
void Student::setFirstName(string fName) { firstName = fName; }
void Student::setLastName(string lName) { lastName = lName; }
void Student::setEmail(string emailAddress) { email = emailAddress; }
void Student::setAge(int yearsOfAge) {age = yearsOfAge; }
void Student::setDaysInCourse(array<int, 3> days) {daysInCourse = days;}
void Student::setDegreeProgram(DegreeProgram nameOfDegree) { degreeProgram = nameOfDegree; }

// print function 
void Student::print() {
	cout << studentID << "\t"
		<< firstName << "\t"
		<< lastName << "\t"
		<< age << "\t"
		<< "{" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}";
	switch (degreeProgram) {
	    case SECURITY:
			cout << "SECURITY";
			break;
		case NETWORK:
			cout << "NETWORK";
			break;
	    case SOFTWARE:
			cout << "SOFTWARE";
			break;
	}
	cout << endl;
	}