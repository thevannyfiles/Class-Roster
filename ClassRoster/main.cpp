#include <iostream>, <string> 
#include "roster.h"
using namespace std;

int main()
{
	//array of strings of student data 
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Vanessa,Okosun,vookosun@wgu.edu,29,20,30,35,SOFTWARE"

	};

	// course details 
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 011956424" << endl; 
	cout << "Name: Vanessa Okosun" << endl; 

	//instance of roster class 
	Roster classRoster;

	//parsing and adding each student's data 
	for (int i = 0; i < 5; ++i) {
		classRoster.parse(studentData[i]); //parse and add each student to roster
	}

	// pseudo-code 

	classRoster.printAll(); //print all students 

	classRoster.printInvalidEmails(); //print invalid emails 
	
	//print average days in course for each student
	for (int i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	classRoster.printByDegreeProgram(SOFTWARE); // Print students by degree program

	classRoster.remove("A3"); // Remove a student and print the roster again
	classRoster.printAll();

	// Attempt to remove the same student again
	classRoster.remove("A3");
	
	return 0; 
}