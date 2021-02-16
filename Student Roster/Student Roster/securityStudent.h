#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
using namespace std;

class securityStudent : public Student {
public:
	securityStudent(string IDpar, string firstNamepar, string lastNamepar, string emailpar, int agepar, int coursedaysleft[3]);
	Degreetype GetDegreeProgram();//overrides degree program as degree is a private data member
	void print(); // prints all data members with " \t " between them;
private:
	Degreetype degree;
};



#endif 