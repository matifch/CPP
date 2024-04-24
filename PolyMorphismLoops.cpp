#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
public:
    Person(const string& name) : name(name) {}
    string getName() const {
        return name;
    }
    virtual double getSalary() const = 0; // Pure virtual function
};
// Teacher subclass
class Teacher : public Person {
    double basic_salary;
public:
    Teacher(const string& name, double basic_salary)
        : Person(name), basic_salary(basic_salary) {}

    double getSalary() const override {
        return basic_salary + 0.1 * basic_salary; // Basic salary + 10%
    }
};
// Driver subclass
class Driver : public Person {
    int days_worked;

public:
    Driver(const string& name, int days_worked)
        : Person(name), days_worked(days_worked) {}

    double getSalary() const override {
        return days_worked * 2500; // 2500 per day worked
    }
};

// Banker subclass
class Banker : public Person {
    double basic_salary;

public:
    Banker(const string& name, double basic_salary)
        : Person(name), basic_salary(basic_salary) {}

    double getSalary() const override {
        return basic_salary + 0.2 * basic_salary; // Basic salary + 20%
    }
};

int main() {
    const int TOTAL_PEOPLE = 60; // Total number of people
    Person* people[TOTAL_PEOPLE]; // Array of pointers to Person

    // Assign 15 pointers to Teacher, 25 to Driver, and 20 to Banker using one loop with conditions
    for (int i = 0; i < TOTAL_PEOPLE; i++) {
        if (i < 15) { // First 15 are Teachers
            people[i] = new Teacher("Teacher_" + i, 50000);
        } else if (i < 40) { // Next 25 are Drivers
            people[i] = new Driver("Driver_" + (i - 15), 20); // 20 days worked
        } else { // Remaining 20 are Bankers
            people[i] = new Banker("Banker_" + (i - 40), 70000);
        }
    }

    // Calculate the total salary and average salary
    double total_salary = 0;
    int total_count = TOTAL_PEOPLE;

    for (int i = 0; i < total_count; i++) {
        total_salary += people[i]->getSalary();
    }

    double average_salary = total_salary / total_count;

    cout << "Average salary of all persons: " << average_salary << endl;

    // Clean up memory
    for (int i = 0; i < total_count; i++) {
        delete people[i]; // Release memory for each object
    }

    return 0;
}

