#include<iostream>
using namespace std;
class Teacher{
int salary;string name;
public:
	Teacher(string n, int sal):name(n), salary(sal){
	}
	int getMonthlySalary(){
		return salary+salary*0.1;
	}
	string getName(){ return name;
	}
};
class Driver{
	string name; int daily;
public:
	Driver(string n, int da):name(n), daily(da){
	}
	string getName(){ return name;
	}
	int getMonthlyWages(){ 
	return daily*30;
	}
};
class Banker{
	string name; int salary;
public:
	Banker(string n, int sa):name(n), salary(sa){
	}
	string getName(){ return name;
	}
	int getMonthlyRemuneration(){ 
	return salary+salary*0.2;
	}
};
void display(Teacher t){
	cout<<t.getName()<<"  *****  "<<t.getMonthlySalary()<<endl;
}
void display(Banker b){
	cout<<b.getName()<<"  *****  "<<b.getMonthlyRemuneration()<<endl;
}
void display(Driver d){
	cout<<d.getName()<<"  *****  "<<d.getMonthlyWages()<<endl;
}
int main (){ 
Teacher tchr("Mujahid", 100000);
Driver dr("Ali", 2500);
Banker bnkr("Ahmad", 90000);
display(tchr);
display(bnkr);
display(dr);
	return 0;
}
