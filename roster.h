#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using std::string;

const int numStudents = 5;

const string studentData[]= 
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Travis,Handley,thandl3@wgu.edu,28,10,16,22,SOFTWARE" };

const int Students = sizeof(studentData) / sizeof(studentData[0]);
const int dataFields = 9;

class Roster {
protected:
	//Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:
	//int lastIndex;
	//int maxSize;
	Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // array of pointers
	Roster(); // empty
	//Roster(int maxSize);
	void add(
		string studID,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeType degreeProgram); 
	void printAll();
	void remove(string studID);
	void printDaysInCourse(string studID); // average days
	void printInvalidEmails(); // A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void printByDegreeProgram(int degreeProgram); // prints out student information for a degree program specified by an enumerated type.
	
	~Roster();
};
