#include "roster.h"
//#include "student.h"
#include <sstream>
#include <iostream>


//FIXME it only seems to be parsing and adding "degree type" and nothing else.

int main() {
	std::cout << "C867 Scritping and Programming Applications\n";
	std::cout << "C++\n";
	std::cout << "Student ID: 009611933\n";
	std::cout << "Travis Handley\n";
	std::cout << "\n";

	Roster classRoster; //creates roster
	DegreeType degree; //new degree

	//Add each student
	for (int i = 0; i < Students; ++i) {
		string studDataInput = studentData[i];
		std::istringstream ss(studDataInput);
		string studDataOutput;
		string tempInfo[9];

		int x = 0;
		while (getline(ss, studDataOutput, ',')) {  //input instead of output?
			tempInfo[x] = studDataOutput;           //input instead of output?
			x += 1;
		}

		if (tempInfo[8] == "NETWORK") {
			degree = NETWORK;
		}
		if (tempInfo[8] == "SECURITY") {
			degree = SECURITY;
		}
		if (tempInfo[8] == "SOFTWARE") {
			degree = SOFTWARE;
		}

		classRoster.add(tempInfo[0], tempInfo[1], tempInfo[2], tempInfo[3], stoi(tempInfo[4]), stoi(tempInfo[5]), stoi(tempInfo[6]), stoi(tempInfo[7]), degree);

	}

	classRoster.printAll();
	std::cout << "\n";

	classRoster.printInvalidEmails();
	std::cout << "\n";

	for (int i = 0; i < Students; ++i) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getID());
	}
	std::cout << "\n";

	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << "\n";


	std::cout << "Removing Student A3\n";
	classRoster.remove("A3");
	std::cout << "Removing Student A3\n";
	classRoster.remove("A3");


	return 0;
}

Roster::Roster() {
//	maxSize = 5;
//	lastIndex = -1;
//	this->classRosterArray = nullptr;
}

/*
Roster::Roster(int maxSize) {
	this->maxSize = maxSize;
	lastIndex = -1;
	this->classRosterArray = new Student*[maxSize];

}
*/

void Roster::add(
	string studID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeType degreeProgram) 
{
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	
	Student* newStudent = nullptr;

	for (int i = 0; i < Students; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = newStudent;
			break;
		}
	}

	for (int i = 0; i < Students; ++i) {
		if (classRosterArray[i] == nullptr) {
			if (degreeProgram == NETWORK) {
				classRosterArray[i] = new NetworkStudent(studID, firstName, lastName, email, age, courseDays, degreeProgram);
			}
			else if (degreeProgram == SECURITY) {
				classRosterArray[i] = new SecurityStudent(studID, firstName, lastName, email, age, courseDays, degreeProgram);
			}
			else if (degreeProgram == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(studID, firstName, lastName, email, age, courseDays, degreeProgram);
			}
			else {
				std::cout << "INVALID DEGREE TYPE! EXITING NOW\n";
				break;
			}
			break;
		}

	}

}


void Roster::printAll() {
	for (int i = 0; i < Students; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::remove(string studID) {
	bool found = false;
	for (int i = 0; i < Students; ++i) {

		if (classRosterArray[i] == nullptr) {
			continue;
		}
		if (classRosterArray[i]->getID() == studID) {
			delete(classRosterArray[i]);
			classRosterArray[i] = nullptr;
			found = true;

			std::cout << "Student " << studID << " removed\n";
		}
	}
	if (!found) {
		std::cout << "STUDENT " << studID << " NOT FOUND!\n";
	}
}

void Roster::printDaysInCourse(string studID) {
	float avg = 0;
	int max = 3;
	for (int i = 0; i < Students; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studID) {
			int *daysInCourse = classRosterArray[i]->getCourseDays();
			for (int x = 0; x < max; ++x) {
				avg += daysInCourse[x];
			}
			std::cout << "Student " << classRosterArray[i]->getID() << "'s average number of days in the three courses is " << (avg / max) << "\n";
			break;
		}
	}
}


void Roster::printInvalidEmails() {
	std::cout << "Displaying Invalid Emails:\n";
	for (int i = 0; i < Students; ++i) {
		bool space = false;
		bool at = false;
		bool dot = false;
		//string tempStr = classRosterArray[i]->getEmail();
		string emailAddress = classRosterArray[i]->getEmail();
		if (emailAddress.rfind('.') == emailAddress.length() - 4) {
			dot = true;
		}
		if (emailAddress.find('@') != string::npos) {
			at = true;
		}
		for (int i = 0; i < emailAddress.length(); i++) {
			if (emailAddress[i] == ' ') {
				space = true;
				std::cout << emailAddress << " is invalid.\n";
				break;
			}
		}
		if (!at || !dot) {
			std::cout << emailAddress << " is invalid.\n";
		}
	}
}


void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < Students; ++i) {
		if (this->classRosterArray[i]->getDegreeType() == degreeProgram)
		{
			this->classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {

}
