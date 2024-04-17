#include<iostream>
using namespace std;
class Person{
	string name;
public:
	Person(string n):name(n){
	}
	string getName(){ return name;
	}
	virtual int getSalary(){
	}
};
class Teacher:public Person{
int salary;
public:
	Teacher(string n, int sal):Person(n), salary(sal){
	}
	int getSalary(){
		return salary+salary*0.1;
	}
};
class Driver:public Person{
	string name; int daily;
public:
	Driver(string n, int da):Person(n), daily(da){
	}
	int getSalary(){ 
	return daily*30;
	}
};
class Banker:public Person{
	string name; int salary;
public:
	Banker(string n, int sa):Person(n), salary(sa){
	}
	int getSalary(){ 
	return salary+salary*0.2;
	}
};
void display(Person *ptr){
	cout<<ptr->getName()<<"  *****  "<<ptr->getSalary()<<endl;
}

int main (){ 
Teacher tchr("Mujahid", 100000);
Driver dr("Ali", 2500);
Banker bnkr("Ahmad", 90000);
display(&tchr);
display(&bnkr);
display(&dr);
	return 0;
}
