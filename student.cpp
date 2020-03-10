#include <iomanip>
#include <iostream>
#include "student.h"
//using namespace std;

Student::Student() { //empty

	this->studID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = -1;
	//this->courseDays = new int[courseDaysArray];
	for (int i = 0; i < courseDaysArray; ++i) {
		this->courseDays[i] = 0;
	}
}

/*string studID = "";
string firstName = "";
string lastName = "";
string email = "";
int age = -1;
int courseDays = new int[courseDaysArray];
{ for (int i = 0 ; i < courseDaysArray; ++i) { this->courseDays[i] = 0; } }
*/

Student::Student(string StudID, string FirstName, string LastName, string Email, int Age, int CourseDays[], DegreeType degreeProgram) {
	this->studID = StudID;
	this->firstName = FirstName;
	this->lastName = LastName;
	this->email = Email;
	this->age = Age;
	//this->courseDays = new int[courseDaysArray];
	for (int i = 0; i < courseDaysArray; ++i) {
		this->courseDays[i] = CourseDays[i];
	};
}

// Get

string Student::getID() {
	return studID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getCourseDays() {
	return courseDays;
}

// Set

void Student::setID(string newStudID) {
	//this->studID = studID;
	studID = newStudID;
}
void Student::setFirstName(string newFirstName) {
	//this->firstName = firstName;
	firstName = newFirstName;
}
void Student::setLastName(string newLastName) {
	//this->lastName = lastName;
	lastName = newLastName;
}
void Student::setEmail(string newEmail) {
	//this->email = email;
	email = newEmail;
}
void Student::setAge(int newAge) {
	//this->age = age;
	age = newAge;
}
void Student::setCourseDays(int *cd) {
	//this->courseDays = new int[courseDaysArray];
	for (int i = 0; i < sizeof(courseDays)/sizeof(courseDays[0]); ++i) {
		//this->courseDays[i] = courseDays[i];
		courseDays[i] = cd[i];
	}
}

//PRINT

void Student::print() {
	std::cout << "First Name: " << firstName << "\t"
		<< "Last Name: " << lastName << "\t"
		<< "Age: " << age << "\t"
		<< "Days Left: " << courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "\t"
		<< "Degree Program: " << degreeProgram << "\t";
}

Student::~Student() {
	/* if (courseDays != nullptr) {
	delete[] courseDays;
	courseDays = nullptr;
	}*/
}