#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
using namespace std;

class networkStudent : public Student {
public:
	networkStudent(string IDpar, string firstNamepar, string lastNamepar, string emailpar, int agepar, int coursedaysleft[3]);
	void print(); // prints all data members with " \t " between them;
	Degreetype GetDegreeProgram(); // overrides get degree program
private:
	Degreetype degree;

};



#endif