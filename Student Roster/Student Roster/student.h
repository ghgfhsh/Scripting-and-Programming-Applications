#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student {
public:
	//constructors
	Student();
	Student(string IDpar, string firstNamepar, string lastNamepar, string emailpar, 
		int agepar, int coursedaysleft[3]);
	~Student();

	//Getter Functions
	string GetstudentID();
	string GetfirstName();
	string GetlastName();
	string GetemailAddress();
	int Getage();
	int* GetnumDaystoComplete();

	//Mutator Functions
	void SetstudentID(string ID);
	void SetfirstName(string Name);
	void SetlastName(string Name);
	void SetemailAddress(string email);
	void Setage(int age);
	void SetnumDaystoComplete(int courseNum, int days);

	//prints student data defined in subclasses
	virtual void print();
	string printDegreeType(Student *studentobj); // outputs a string of the degree type, takes obj as input
	virtual Degreetype GetDegreeProgram(); 
	string daystoCompletetoString(); //converts numdaystocomplete to "{val1, val2, val3}" for printing
	bool isEmailValid(string email); // checks if email have no space characters and has a '@' followed by '.'

protected:
	//Student Values
	string studentID, firstName, lastName, emailAddress;
	int studentAge;
	int numDaystoComplete[3];
};
#endif 