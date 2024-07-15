#include <iostream>, <string>
#include "student.h"
using namespace std; 

//mutators 
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(string emailAddress) {
	email = emailAddress;
}
void Student::SetAge(int age) {
	yearsOfAge = age;
}
void Student::setDaysInCourse(int dayInCourse[]) {
	for (int i = 0; i < 3; i++) {
		courseDays[i] = dayInCourse[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram; 
}

//accesors 
string Student::getStudentID() {return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() {return lastName;}
string Student::getEmail() { return email; }
int Student::getAge() { return yearsOfAge; }
int* Student::getDaysInCourse() { return courseDays; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

//constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	email = emailAddress;
	yearsOfAge = age;
	for (int i = 0; i < 3; i++) {
		courseDays[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

// print function 
void Student::Print() {
	cout << studentID << "\t"
		<< firstName << "\t"
		<< lastName << "\t"
		<< yearsOfAge << "\t"
		<< "{" << courseDays[0] << "," << courseDays[1] << "," << courseDays[2] << "}";
	switch (degreeProgram) {
	case SECURITY:
		cout << "SECURITY";
	case NETWORK:
		cout << "NETWORK";
	case SOFTWARE:
		cout << "SOFTWARE";
		break;
	}
	cout << endl;
	}