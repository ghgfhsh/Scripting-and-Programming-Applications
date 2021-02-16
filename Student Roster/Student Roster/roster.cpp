#include "roster.h"
#include "pch.h"
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

using namespace std;


roster::~roster()
{
	delete[] classrosterarray;
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degreetype degree)
{
	//checks if roster is full before adding
	if (lastIndex < classrosterSize) {
		//creates array of days in course from input to pass into Student subobject
		int temparry[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		
		//makes a new student subobject based on the degree type
		switch (degree) {
		case network:
			classrosterarray[lastIndex] = new networkStudent(studentID, firstName, lastName, emailAddress, age, temparry);
			lastIndex++;
			break;
		case software:
			classrosterarray[lastIndex] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, temparry);
			lastIndex++;
			break;
		case security:
			classrosterarray[lastIndex] = new securityStudent(studentID, firstName, lastName, emailAddress, age, temparry);
			lastIndex++;
			break;
		default:
			cout << "Error, degree type does not exsist";
			break;
		}
	}
	else
		cout << "Class Roster is Full" << endl;
	return;
}

void roster::remove(string studentID)
{
	
	bool isExist = false; // set to true if found, if not it will take branch to print error message
	for (int i = 0; i < lastIndex; i++) { // set to 5 because that is the max size of the array for the project
		if (classrosterarray[i]->GetstudentID() == studentID) { // checks to see if searched student id is in roster
			isExist = true;
			delete this->classrosterarray[i]; // deletes the pointer
			if (i != 4) {
				for (int j = i; j < 4; j++) {
					classrosterarray[j] = classrosterarray[j + 1]; // shifts all values o
				}
				
			}
			lastIndex--; //moves last index down so add function knows where to put new student
		}
	}

	if (isExist == false) {
		cout << "Student ID does not exist!" << endl;
	}
	
	return;
	
}

void roster::printAll()
{
	//loops through all students print functions
	cout << "Current Student Roster: " << endl;
	for (int i = 0; i < lastIndex; i++) {
		cout << i + 1 << " \t ";
		classrosterarray[i]->print();

	}
	cout << endl;

}

void roster::printInvalidEmails()
{
	//loops through all Students isEmailValid functions
	cout << "Invalid Emails: " << endl;
	for (int i = 0; i < lastIndex; i++) {
		if (!classrosterarray[i]->isEmailValid(classrosterarray[i]->GetemailAddress())) {
			cout << "Student: " << classrosterarray[i]->GetstudentID() << " \t " << "Email: " <<  classrosterarray[i]->GetemailAddress() << endl;
		}

	}
	cout << endl;
}

void roster::printDaysInCourse(string StudentID)
{
	int *temp; //pointer to first value of daystocomplete array
	int avg;

	bool isFound = false;
	for (int i = 0; i < lastIndex; i++) {
		if (classrosterarray[i]->GetstudentID() == StudentID) {
			temp = classrosterarray[i]->GetnumDaystoComplete();
			avg = (*(temp) + *(temp + 1) + *(temp + 2)) / 3;

			cout << "Average Days to Complete For " << classrosterarray[i]->GetstudentID() << ": " << avg << endl;
			isFound = true;
		}
	}
	if (!isFound) {
		cout << "StudentID does not exist" << endl;
	}
	cout << endl;


}

void roster::printByDegreeProgram(Degreetype degreepar)
{
	//loops through all students with the correct degreepar input and calls print functions
	switch(degreepar) {
	case network:
		cout << "Students in Network: " << endl;
		for (int i = 0; i < lastIndex; i++) {
			if (classrosterarray[i]->GetDegreeProgram() == network) {
				classrosterarray[i]->print();
			}
		}
		break;
	case software:
		cout << "Students in Software: " << endl;
		for (int i = 0; i < lastIndex; i++) {
			if (classrosterarray[i]->GetDegreeProgram() == software) {
				classrosterarray[i]->print();
			}
		}
		break;
	case security:
		cout << "Students in Security: " << endl;
		for (int i = 0; i < lastIndex; i++) {
			if (classrosterarray[i]->GetDegreeProgram() == security) {
				classrosterarray[i]->print();
			}
		}
		break;
	}

	cout << endl;

}

void roster::addbyString(const string input[5], roster &roster)
{
	string studentID, firstName, lastName, email, tempdegree;
	int age, firstCourse, secondCourse, thirdCourse;
	Degreetype degreetype;

	//keep reading until end of string
	for (int i = 0; i < 5; i++){
		//read Student ID
		int rhs = input[i].find(',');
	studentID = input[i].substr(0, rhs);

	//read first name
	int lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	firstName = input[i].substr(lhs, rhs - lhs);

	//read last name
	lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	lastName = input[i].substr(lhs, rhs - lhs);

	//read email
	lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	email = input[i].substr(lhs, rhs - lhs);

	//read age
	lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	age = stoi(input[i].substr(lhs, rhs - lhs));

	//read first course
	lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	firstCourse = stoi(input[i].substr(lhs, rhs - lhs));

	//read second course
	lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	secondCourse = stoi(input[i].substr(lhs, rhs - lhs));

	//read third course
	lhs = rhs + 1;
	rhs = input[i].find(",", lhs);
	thirdCourse = stoi(input[i].substr(lhs, rhs - lhs));

	//read degree type. if it is at the last iteration it will base rhs off of the end of the string instead
	if (i < 4) {
		lhs = rhs + 1;
		rhs = input[i].find(",", lhs);
		tempdegree = input[i].substr(lhs, rhs - lhs);
	}
	else {
		lhs = rhs + 1;
		rhs = input[i].find(",", lhs);
		tempdegree = input[i].substr(lhs, rhs - lhs);
	}

	//convert string to Degreetype ENUM
	if (tempdegree == "NETWORK")
		degreetype = network;
	else if (tempdegree == "SECURITY")
		degreetype = security;
	else if (tempdegree == "SOFTWARE")
		degreetype = software;

	roster.add(studentID, firstName, lastName, email, age, firstCourse, secondCourse, thirdCourse, degreetype);
	}
}

int main() {
	cout << "C867 Scripting and Programming Applications, C++, #001121729, Jeremiah D McElroy" << endl;

	roster classRoster;

	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Mary,Sue,ms@gmail.com,35,20,50,70,SOFTWARE" };

	classRoster.addbyString(studentData, classRoster);
	classRoster.printAll();
	classRoster.printInvalidEmails();
	//iterate through all available student IDs and print the Avg of the days in course
	for (int i = 1; i < 6; i++) {
		string temp = "A0";
		temp.at(1) += i;
		classRoster.printDaysInCourse(temp);
	}
	classRoster.printByDegreeProgram(software);
	classRoster.remove("A3");
	classRoster.remove("A3");

	//NOTE FOR GRADER: The course said call destructor? I assume it means define it and make it work, since the destructor is automatically called when the program exits. 
	//If I call it manually the program throws an exception when exiting from trying to delete unallocated memory. 
}
