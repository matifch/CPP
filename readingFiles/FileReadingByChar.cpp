#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // Open the file for reading
    ifstream fin("d:/temp/abc.txt");
     if (!fin) {
        cerr << "Failed to open file for reading!" <<endl;
        return 1; // abnormal termination
    }
   // Read the contents of the file
   string str;
   while(!fin.eof())
   {
   cout<<(char)fin.get();
   //cout <<str<<" ";
  }
   // Close the file
    fin.close();
    return 0;
}

