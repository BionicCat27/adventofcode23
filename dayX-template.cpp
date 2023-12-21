#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int part1(string filename);
void print_result(string msg, int actual, int expected);

int main()
{
    int result;
    result = part1("dayX-test-data");
    print_result("P1 test:   ", result, 0);
    result = part1("dayX-data");
    print_result("P1 actual: ", result, 2);
}

int part1(string filename)
{
    ifstream data(filename);
    int result = 0;
    string line;
    while (getline(data, line))
    {
    }
    return result;
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