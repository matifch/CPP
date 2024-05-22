#include <iostream>
#include <fstream>
using namespace std;
int main() {
    float array[5] = {1.2, 2.3, 3.4, 4.5, 5.6};

ofstream file("float_array.bin", ios::binary);

if (file.is_open()) {
    file.write(reinterpret_cast<char*>(array), sizeof(array));
    if (file.fail()) {
        cout << "Write failed." << endl;
    } else {
        cout << "Array written to binary file successfully." << endl;
    }
    file.close();
} else {
    cout << "Unable to open file." << endl;
}


    return 0;
}

