#pragma once
#include "student.h" 
#include <vector>
using namespace std;


//creation of the roster class including an array of pointers to hold student data table 
class Roster {
    private: 
		Student* classRosterArray[5];
		int lastIndex; //tracking last index in the array 

    public:
		//constructor
		Roster();

	   //destructor
	   ~Roster();

	//functions 
	   void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	   void remove(string studentID);
	   void printAll();
	   void printAverageDaysInCourse(string studentID);
	   void printInvalidEmails();
	   void printByDegreeProgram(DegreeProgram degreeProgram);
	   void parse(string row); 
};