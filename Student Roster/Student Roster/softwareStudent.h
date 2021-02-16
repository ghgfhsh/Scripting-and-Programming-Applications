#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
using namespace std;

class softwareStudent : public Student {
public:
	softwareStudent(string IDpar, string firstNamepar, string lastNamepar, string emailpar, int agepar, int coursedaysleft[3]);
	Degreetype GetDegreeProgram();// overrides get degree program
	void print(); // prints all data members with " \t " between them;
private:
	Degreetype degree;
};



#endif 