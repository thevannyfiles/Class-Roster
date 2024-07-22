#include <iostream>
#include <string>
#include "student.h"
using namespace std; 

//constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	//this->daysInCourse = daysInCourse;
	daysInCourse[0] = daysInCourse[0];
	daysInCourse[1] = daysInCourse[1];
	daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

// getters - accessors
string Student::getStudentID() {return studentID; }
string Student::getFirstName() {return firstName; }
string Student::getLastName() {return lastName;}
string Student::getEmail() {return email; }
int Student::getAge() {return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() {return degreeProgram; }

//setters - mutators
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) {this->age = age; }
void Student::setDaysInCourse(int daysInCourse[3]) {
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// print function 
void Student::print() {
	cout << studentID << "\t"
		<< firstName << "\t"
		<< lastName << "\t"
		<< "\t" << age << "\t"
		<< "\t" << "{" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}" << "\t";
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