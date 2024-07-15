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

    // Parse each entry and add to the roster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }

    // Demonstrate the functionality
    cout << "Displaying all students:" << endl;
    classRoster.printAll();

    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();

    cout << "Displaying average days in course:" << endl;
    for (int i = 0; i <= 4; i++) { // 5 students
        classRoster.printAverageDaysInCourse(classRoster.getStude(i));
    }

    cout << "Displaying students in the SOFTWARE degree program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << "\nRemoving A3:" << endl;
    classRoster.remove("A3");
    classRoster.printAll();

    cout << "\nRemoving A3 again:" << endl;
    classRoster.remove("A3");

    // Call the destructor explicitly (optional, for clarity)
    classRoster.~Roster();

    return 0;
}

	return 0;
}