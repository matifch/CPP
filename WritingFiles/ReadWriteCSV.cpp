#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    // Open the file for reading
    ifstream fin("d:/temp/data.csv");
    // Open the file for writing
    ofstream fout("d:/temp/target.csv");

    if (!fin || !fout)
    {
        cerr << "Failed to open/create files!" << endl;
        return 1; // abnormal termination
    }
    // Read the contents of the file
    string str;
    getline(fin, str); // read the first line
    cout << str << endl;
    int i = 1, sum = 0;
    string name;
    while (!fin.eof())
    {
        if (i % 6 == 0) // read the last value in a row (without ',')
            getline(fin, str);
        else
            getline(fin, str, ','); // read values 1 by 1 except the last value in a row
        if (i % 6 == 1)             // if the first value
        {
            name = str;
            sum = 0;
        }
        else
            sum += stoi(str); // C++11 or higher

        if (i > 1 && i % 6 == 0)
        {
            cout << name << " " << sum << endl;
            fout << name << ',' << sum << endl;
        }

        i++;
    }
    // Close the file
    fin.close();
    fout.close();
    return 0;
}
