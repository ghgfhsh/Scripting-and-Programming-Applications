#include "student.h"
#include "degree.h"
#include "pch.h"
#include <string>
#include <sstream>
#include <cstring>

using namespace std;


//constructors
Student::Student() {

	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	studentAge = 0;
	numDaystoComplete[0] = 0;
	numDaystoComplete[1] = 0;
	numDaystoComplete[2] = 0;
	

}

Student::Student(string IDpar, string firstNamepar, string lastNamepar, string emailpar,
	int agepar, int coursedaysleft[3]) {

	studentID = IDpar;
	firstName = firstNamepar;
	lastName = lastNamepar;
	emailAddress = emailpar;
	studentAge = agepar;
	numDaystoComplete[0] = coursedaysleft[0];
	numDaystoComplete[1] = coursedaysleft[1];
	numDaystoComplete[2] = coursedaysleft[2];
}

Student::~Student()
{

}

//getters
string Student::GetstudentID()
{
	return studentID;
}

string Student::GetfirstName()
{
	return firstName;
}

string Student::GetlastName()
{
	return lastName;
}

string Student::GetemailAddress()
{
	return emailAddress;
}

int Student::Getage()
{
	return studentAge;
}

int* Student::GetnumDaystoComplete()
{
	return numDaystoComplete;
}

//Mutators

void Student::SetstudentID(string ID)
{
	studentID = ID;
	return;
}

void Student::SetfirstName(string Name)
{
	firstName = Name;
	return;
}

void Student::SetlastName(string Name)
{
	lastName = Name;
	return;
}

void Student::SetemailAddress(string email)
{
	emailAddress = email;
	return;
}

void Student::Setage(int age)
{
	studentAge = age;
	return;
}

void Student::SetnumDaystoComplete(int courseNum, int days)
{
	numDaystoComplete[courseNum] = days;
	return;
}

void Student::print()
{

}

string Student::printDegreeType(Student * studentobj)
{
	string output;

	switch (studentobj->GetDegreeProgram()) {
	case security:
		output = "security";
		break;
	case software:
		output = "software";
		break;
	case network:
		output = "network";
		break;
	}


	return output;
}

Degreetype Student::GetDegreeProgram()
{
	return Degreetype();
}

string Student::daystoCompletetoString()
{
	ostringstream daysString;
	string outputString;

	daysString << "{" << numDaystoComplete[0] << ", " << numDaystoComplete[1] << ", " << numDaystoComplete[2] << "}";
	outputString = daysString.str();

	return outputString;
}

bool Student::isEmailValid(string email)
{
	//var declarations
	int atSymbolPosition;
	bool ismissingat = true;
	bool ismissingdot = true;



	// checks for @ symbol and sets location. returns invalid email if it can't find it. 
	for (int i = 0; i < email.length(); i++) {
		if (email.at(i) == '@') {
			atSymbolPosition = i;
			ismissingat = false;

		}
		
	}
	if (ismissingat) {
		return false;
	}

	//checks for space and returns invalid if found
	for (int i = 0; i < email.length(); i++) {
		if (email.at(i) == ' ') {
			return false;
		}
	}

	//checks for '.'. returns invalid email if it can't find it.
	for (int i = atSymbolPosition + 1; i < email.length(); i++) {
		if (email.at(i) == '.'){
			ismissingdot = false;
		}
	}
	if (ismissingdot) {
		return false;
	}

	return true;
}
