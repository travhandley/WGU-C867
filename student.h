#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student { // main student class

protected: //private was causing errors. making them inaccessible
	const static int courseDaysArray = 3;
	string studID;
	string firstName;
	string lastName;
	string email;
	int age;
	//int* courseDays; //getting errors, maybe double works better?
	int courseDays[courseDaysArray];
	DegreeType degreeProgram;

public:
	//const static int courseDaysArray = 3;
	Student(); // empty
	Student(
		string StudID,
		string FirstName,
		string LastName,
		string Email,
		int Age,
		int CourseDays[],
		DegreeType degreeProgram); //may not need degree type yet

	// Get
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getCourseDays(); // pointer
	virtual DegreeType getDegreeType() = 0;

	// Set

	void setID(string newStudID);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmail(string newEmail);
	void setAge(int newAge);
	void setCourseDays(int newCoursDays[]);
	//virtual void setDegreeProgram(DegreeType d) = 0;
	virtual void print() = 0;

	~Student();
};