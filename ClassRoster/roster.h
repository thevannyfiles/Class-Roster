#pragma once
#include "student.h" 
using namespace std;


//creation of the roster class including an array of pointers to hold student data table 
class Roster {
private: 
	Student* classRosterArray[5]; 
	int lastIndex; //index to track last student added 

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