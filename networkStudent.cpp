#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent() {
	setDegreeType(NETWORK);
}

NetworkStudent::NetworkStudent(
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

DegreeType NetworkStudent::getDegreeType() {
	return NETWORK;
}

void NetworkStudent::setDegreeType(DegreeType d) {
	this->degreeProgram = d;
}

void NetworkStudent::print() {
	this->Student::print();
	std::cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
	delete this;
}