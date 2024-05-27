#include <iostream>
#include <stdexcept>

class Book {
public:
    void print() {
        std::cout << "Book details." << std::endl;
    }
};

class NullPointerException : public std::runtime_error {
public:
    NullPointerException() : std::runtime_error("Null pointer dereferenced") {}
};

class Teacher {
public:
    Teacher(int id, Book* bookPtr) : id(id), bookPtr(bookPtr) {}
    
    void display() {
        if (bookPtr == nullptr) {
            throw NullPointerException();
        }
        std::cout << "Teacher ID: " << id << std::endl;
        bookPtr->print();
    }

private:
    int id;
    Book* bookPtr;
};

int main() {
    try {
        Book* p = nullptr; // Uninitialized pointer
        Teacher t(12, p);
        t.display(); // This will throw an exception
    } catch (const NullPointerException& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return 0;
}

