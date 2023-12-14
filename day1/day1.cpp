#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int part1(ifstream *data);

int main()
{
    ifstream Testdata("test-data");
    int calibration = part1(&Testdata);
    cout << "Test calibration was: " << calibration << ". Expected: " << 142 << endl;
    ifstream Data("data");
    calibration = part1(&Data);
    cout << "Calibration was: " << calibration << ". Expected: " << 53194 << endl;
}
int part1(ifstream *data)
{
    string line;
    int dataSum = 0;
    while (getline(*data, line))
    {
        int lineValue = 0;
        bool found = false;
        for (string::iterator iter = line.begin(); iter != line.end(); ++iter)
        {
            int characterValue = (int)*iter - 48;
            if (characterValue >= 0 && characterValue <= 9)
            {
                lineValue += (characterValue * 10);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not found start: " << line << endl;
        }
        found = false;
        reverse(line.begin(), line.end());
        for (string::iterator iter = line.begin(); iter != line.end(); ++iter)
        {
            int characterValue = (int)*iter - 48;
            if (characterValue >= 0 && characterValue <= 9)
            {
                lineValue += characterValue;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not found ends: " << line << endl;
        }
        // cout << "Found number: " << lineValue << endl;
        dataSum += lineValue;
    }
    return dataSum;
}