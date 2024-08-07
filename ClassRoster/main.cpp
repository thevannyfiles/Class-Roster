#include <iostream>
#include <string> 
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

    // Parse each entry and add to the roster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }

    cout << endl;

    //print all students 
    cout << "Displaying all students:" << endl;
    classRoster.printAll();

    cout << endl;

    //print invalid emails 
    cout << "Displaying invalid emails:" << endl;
    cout << endl;
    classRoster.printInvalidEmails();

    cout << endl;

    //print average day in course for each students
    for (int i = 0; i < 5; ++i) { // 5 students
        if (classRoster.classRosterArray[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
    }

    cout << endl;

    // print students by degree program (SOFTWARE)
    cout << "Showing students in the degree program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);


    //remove student by ID and print the rest of students 
    cout << "\nRemoving A3:" << endl;
    cout << endl;
    classRoster.remove("A3");
    classRoster.printAll();


    //attempt to remove same student 
    cout << "\nRemoving A3 again:" << endl;
    cout << endl;
    classRoster.remove("A3");

    cout << "DONE.";

    return 0;
}
