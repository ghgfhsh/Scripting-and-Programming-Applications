#include "securityStudent.h"
#include "student.h"
#include "pch.h"
#include <iostream>

using std::cout;
using std::endl;

securityStudent::securityStudent(string IDpar, string firstNamepar, string lastNamepar, string emailpar,int agepar, int coursedaysleft[3])
{
	studentID = IDpar;
	firstName = firstNamepar;
	lastName = lastNamepar;
	emailAddress = emailpar;
	studentAge = agepar;
	numDaystoComplete[0] = coursedaysleft[0];
	numDaystoComplete[1] = coursedaysleft[1];
	numDaystoComplete[2] = coursedaysleft[2];
	degree = security;
}

Degreetype securityStudent::GetDegreeProgram()
{
	return degree;
}

void securityStudent::print()
{
	cout << "First Name: " << this->GetfirstName() << " \t " << "Last Name: " << this->GetlastName() << " \t " << "Age: " << this->Getage() << " \t "
		<< "daysInCourse: " << this->daystoCompletetoString() << "Degree Program: " << this->printDegreeType(this) << endl;
}
