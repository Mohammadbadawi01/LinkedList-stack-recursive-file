#include "Univ.h"
#include <iostream>
using namespace std;
#include<fstream>
#include<cmath>
#include <Stack>

/*
class Stack {
public:
	STUDENT* head;
	Stack() {
		head = NULL;
	}
	void insert(STUDENT* n) {
		STUDENT* ss = new STUDENT;
		ss->id = n->id;
		ss->gpa = n->gpa;
		strcpy(ss->address, n->address);
		strcpy(ss->name, n->name);
		n = ss;
		n->next_student = NULL;
		if (head == NULL) {
			head = n;
		}
		else {
			n->next_student = head;
			head = n;
		}
	}
	void insertUni(STUDENT* n) {
		STUDENT* p = n;
		while (p != NULL) {
			insert(p);
			p = p->next_student;
		}
	}
	void print() {
		STUDENT* p = head;
		while (p != NULL) {
			cout << p->id << " " << p->name<<" " <<p->address << " " << p->gpa << endl;
			p = p->next_student;
		}
	}
};
*/
STUDENT* UNIVERSITY::getStart()
{
	return start;
}

void UNIVERSITY::add(STUDENT* s)
{
	STUDENT* ss = new STUDENT;
	ss->id = s->id;
	ss->gpa = s->gpa;
	strcpy(ss->address, s->address);
	strcpy(ss->name, s->name);
	s = ss;
	s->next_student = NULL;
	if (start == NULL) {
		start = s;
		count++;
		s->next_student = start->next_student = NULL;
		return;
	}
	else if ((s->id < start->id) ) {
		s->next_student = start;
		start = s;
		count++;
		 
		return;
	}
	STUDENT* p = start;
	STUDENT* pre = start;

	while (p != NULL) {
		if (p->id > s->id) {
			s->next_student = p;
			pre->next_student = s;
			count++;
			 
			return;
		}
		pre = p;
		p = p->next_student;
	}
	pre->next_student = ss;
	count++;
}

void UNIVERSITY::setName(char* name)
{
	this->university_name = name;
}

double UNIVERSITY::Rec_AVG()
{
	double a = 0.0;
	return getAvg(start,a) / getCount();
}

void UNIVERSITY::print()
{
	STUDENT* p = start;
	while (p != NULL) {
		cout << p->id << " " << p->name <<" " << p->address << " " << p->gpa << endl;
		p = p->next_student;
	}
}

double UNIVERSITY::getAvg(STUDENT* s, double &d)
{
	if (s == NULL) {
		return d;
	}
	d += s->gpa;
	return getAvg(s->next_student, d);
}

char* UNIVERSITY::getName()
{
	return university_name;
}

int UNIVERSITY::getCount()
{
	return count;
}

UNIVERSITY::UNIVERSITY()
{
	university_name = (char*)malloc(sizeof(char) * 200);
	count = 0;
	start = NULL;
}

UNIVERSITY UNIVERSITY::operator=(const UNIVERSITY& obj)
{
	UNIVERSITY t;
	this->count = obj.count;
	this->start = obj.start;
	this->university_name = obj.university_name;
	return t;
}

UNIVERSITY operator+(UNIVERSITY& uni, STUDENT& obj)
{
	uni.add(&obj);
	return uni;
}

ostream& operator<<(ostream& out, UNIVERSITY& obj)
{
	stack <STUDENT> arr;
	stack <STUDENT> d;
	
	out << obj.getName() << "\n";
	
	STUDENT* p = obj.start;
	

	while (p != NULL) {
		STUDENT o;
		o.id = p->id;
		o.gpa = p->gpa;
		strcpy(o.address, p->address);
		strcpy(o.name, p->name);
		arr.push(o);
		p = p->next_student;
	}
	for (; !arr.empty();) {
		d.push(arr.top());
		arr.pop();
	}
	for (; !d.empty();) {
		cout << d.top().id << " " << d.top().name << " " << d.top().address << " " << d.top().gpa << endl;
		d.pop();
	}
	out << "\n";

	return out;
}

istream& operator >>(istream& in, UNIVERSITY& obj)
{
	//char first[30];
	//char last[30];
	char* uName = (char*)malloc(sizeof(char) * 200);
	in >> uName;
	obj.setName(uName);
	STUDENT* stu = new STUDENT;
	while (in >> stu->id >> stu->name >> stu->address >> stu->gpa) {
		//strcpy(stu->name, first);
		//strcat(stu->name, " ");
		//strcat(stu->name, last);
		obj.add(stu);
	}
	return in;
}
