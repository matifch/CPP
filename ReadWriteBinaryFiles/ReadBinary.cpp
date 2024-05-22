#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // Open the binary file for reading
    ifstream inFile("myData.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
		int i;
        double d;
    while (inFile) {
        // Read an int value
        inFile.read(reinterpret_cast<char*>(&i), sizeof(i));
        cout << "int value: " << i << endl;
        // Read a double value
        inFile.read(reinterpret_cast<char*>(&d), sizeof(d));
        cout << "double value: " << d << endl;
    }

    return 0;
}

