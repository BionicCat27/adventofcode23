#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int part1(ifstream &data);
void print_result(string msg, int actual, int expected);

int main()
{
    ifstream Testdata("dayX-test-data");
    ifstream Data("dayX-data");
    int calibration;
    calibration = part1(Testdata);
    print_result("P1 test:   ", calibration, 0);
    calibration = part1(Data);
    print_result("P1 actual: ", calibration, 2);
}

int part1(ifstream &data)
{
    return -1;
}

void print_result(string msg, int actual, int expected)
{
    cout << msg << "Actual " << actual << " Expected " << expected;
    int diff = actual - expected;
    if (expected < 0 && diff != 0)
    {
        cout << " Diff " << diff;
    }
    cout << endl;
}