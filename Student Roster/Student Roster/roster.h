#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "degree.h"
#include <vector>
using namespace std;

class roster {
public:

	~roster();
	//adds a student subclass to classrosterarray
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degreetype degree);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails();
	void printDaysInCourse(string StudentID);
	void printByDegreeProgram(Degreetype degreepar);// overrides get degree program
	void addbyString(const string input[5], roster &roster); // parses string into individual variables to pass into add()
private:
	int classrosterSize = 5; // change me to allow more students
	Student **classrosterarray = new Student*[classrosterSize];
	int lastIndex = 0;
};



#endif 