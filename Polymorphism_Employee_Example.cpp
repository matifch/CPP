#include <iostream>

// Base class Employee
class Employee {
public:
    virtual double getSalary() const {
        return baseSalary;
    }

protected:
    double baseSalary = 5000; // Base salary constant for all employees
};

// Derived class Faculty
class Faculty : public Employee {};

// Derived class Admin
class Admin : public Employee {};

// Derived class ResearchFaculty from Faculty
class ResearchFaculty : public Faculty {
public:
    double getSalary() const override {
        return 2 * baseSalary; // Double the base salary for ResearchFaculty
    }
};

// Main function
int main() {
    // Total number of employees (10 Admin, 5 Faculty, 3 ResearchFaculty)
    const int totalEmployees = 18;

    // Array of pointers to Employee objects
    Employee* employees[totalEmployees];

    // Loop to create 10 Admin, 5 Faculty, and 3 ResearchFaculty
    for (int i = 0; i < totalEmployees; i++) {
        if (i < 10) {
            employees[i] = new Admin(); // First 10 are Admin
        } else if (i < 15) {
            employees[i] = new Faculty(); // Next 5 are Faculty
        } else {
            employees[i] = new ResearchFaculty(); // Last 3 are ResearchFaculty
        }
    }

    // Compute the sum of all salaries
    double totalSalary = 0;
    for (int i = 0; i < totalEmployees; i++) {
        totalSalary += employees[i]->getSalary();
    }

    // Calculate the average salary
    double averageSalary = totalSalary / totalEmployees;

    // Output the total and average salary
    std::cout << "Total salary: " << totalSalary << "\n";
    std::cout << "Average salary: " << averageSalary << "\n";

    // Clean up allocated memory
    for (int i = 0; i < totalEmployees; i++) {
        delete employees[i]; // Free allocated memory
    }

    return 0;
}

