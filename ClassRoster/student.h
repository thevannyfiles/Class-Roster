#pragma once
#include <string> 
#include <array>
#include "degree.h"
using namespace std;

//creation of the student class with all attributes
class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	//constructor : not default 
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[3], DegreeProgram degreeProgram);

	//accessors (getters)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	// mutators (setters)
	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[3]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print(); //print student details

};