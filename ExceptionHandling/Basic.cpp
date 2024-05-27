#include <iostream>
#include <stdexcept>
using namespace std;
void anotherfunction()
{
    throw 5;
}
int divide(int a, int b)
{
    //	anotherfunction();
    if (b == 0)
        throw invalid_argument("div by zero");
    if (a < 0)
        throw invalid_argument("numertator is -ve");
    if (b < 0)
        throw logic_error("denominator is -ve");
    return a / b; // graceful
}

int main()
{
try{

    try
    {
        cout << "Testing divide function..." << endl;
        int result = divide(10, -2);
        cout << "Result of division: " << result << endl;
    }
    catch (const invalid_argument &e)
    {

        cerr << "Caught exception: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << " something wrong  " << e.what() << endl;
        throw;
    }
    catch (...)
    {
        cerr << " something wrong " << endl;
    }
} // outer try catch 
catch (const exception &ex){
	cerr<<"outer try catch .. "<<ex.what()<<endl;
}
    cout << "\n end of Program";
    return 0;
}
