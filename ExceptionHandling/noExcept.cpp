#include <iostream>
#include <stdexcept>

// Function that might throw an exception
void mightThrow() noexcept(false) {
 //	throw 1;
    throw std::runtime_error("An error occurred in mightThrow!");
}

int main() {
    try {
        mightThrow();
    } 
	catch (const std::runtime_error &e) {
        std::cerr << "Caught runtime error: " << e.what() << std::endl;
    } catch (int i) {
        std::cerr << "Caught an int type exception" << std::endl;
    } 
	catch (...) {
        std::cerr << "Caught an unknown exception" << std::endl;
    }

 std::cout<<"normal program termination ...";
    return 0;
}

