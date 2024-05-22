#include <iostream>
#include <fstream>

using namespace std;

int main() {
    float array[5];

    ifstream file("float_array.bin", ios::binary);

    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(array), sizeof(array));
        file.close();

        cout << "Array read from binary file:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}


