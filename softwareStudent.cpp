#include <iostream>
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent() {
	setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(
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

DegreeType SoftwareStudent::getDegreeType() {
	return SOFTWARE;
}

void SoftwareStudent::setDegreeType(DegreeType d) {
	this->degreeProgram = d;
}

void SoftwareStudent::print() {
	this->Student::print();
	std::cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
	delete this;
}