#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student {
private: DegreeType d;
public:
	NetworkStudent();
	NetworkStudent(
		string StudID,
		string FirstName,
		string LastName,
		string Email,
		int Age,
		int CourseDays[],
		//DegreeType degreeProgram);
		DegreeType d);

	DegreeType getDegreeType();
	//void setDegreeType(DegreeType degreeProgram);
	void setDegreeType(DegreeType d);
	void print();

	~NetworkStudent();
};