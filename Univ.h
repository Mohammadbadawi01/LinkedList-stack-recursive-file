#pragma once
#include <iostream>
using namespace std;
#include<fstream>
#include<cmath>




struct STUDENT {
	char name[64];
	char address[64];
	int id;
	double gpa;
	STUDENT* next_student;
};

class UNIVERSITY {
private:
	STUDENT* start;
	char* university_name;
	int count;
public:
	char* getName();
	int getCount();
	UNIVERSITY();
	//~UNIVERSITY();
	UNIVERSITY operator=(const UNIVERSITY& obj);
	friend UNIVERSITY operator+(UNIVERSITY& uni,STUDENT& obj);
	friend ostream& operator<<(ostream& out, UNIVERSITY& obj);
	friend istream& operator>>(istream& in, UNIVERSITY& obj);
	STUDENT* getStart();
	void add(STUDENT* s);
	double getAvg(STUDENT* s, double &d);
	void setName(char* name);
	double Rec_AVG();
	void print();
	
};
