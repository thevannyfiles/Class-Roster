#pragma once
#include <string> <array>
#include "degree.h"

//creation of the student class 
class Student {
public: 
	// mutators 
	void SetStudentID(string ID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string emailAddress);
	void SetAge(int age);
	void setDaysInCourse(int daysInCourse[]); 
	void SetDegreeProgram(DegreeProgram degreeProgram); 
	void Print(); //print 

	//accessors 
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram(); 

	//constructor : not default 
	Student(string studentId, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int yearsOfAge;
	int courseDays[3];
	DegreeProgram degreeProgram; 
};

