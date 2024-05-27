#include <iostream>
#include <stdexcept>

// Custom exceptions
class CGPAException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid cgpa provided.";
    }
};
// a function to add 0.1 to cgpa
void addToCGPA(float &cgpa){
	if (cgpa<0 || cgpa>4) throw CGPAException();
	cgpa+=0.1;
}
int main() {
    try {
         float  cgpa=5.4;
          addToCGPA(cgpa);
        std::cout << "UPDATED CGPA is " << cgpa << std::endl;
    }
    catch (const CGPAException& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error occurred: " <<  std::endl;
    }
std::cout<<"Program ended gracefully";
    return 0;
}

