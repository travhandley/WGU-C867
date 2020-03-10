#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent() {
	setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(
	string StudID,
	string FirstName,
	string LastName,
	string Email,
	int Age,
	int CourseDays[],
	//DegreeType degreeProgram);
	DegreeType d) : Student(
		StudID,
		FirstName,
		LastName,
		Email,
		Age,
		CourseDays, degreeProgram)
{
	setDegreeType(d);
}

DegreeType SecurityStudent::getDegreeType() {
	return SECURITY;
}

void SecurityStudent::setDegreeType(DegreeType d) {
	this->degreeProgram = d;
}

void SecurityStudent::print() {
	this->Student::print();
	std::cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
	delete this;
}