#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream TestData("data");
    int expectedCalibrationValue = 142;
    string line;
    int dataSum = 0;
    while (getline(TestData, line))
    {
        cout << line << endl;
        int lineValue = 0;
        for (string::iterator iter = line.begin(); iter != line.end(); ++iter)
        {
            int characterValue = (int)*iter - 48;
            if (characterValue >= 0 && characterValue <= 9)
            {
                lineValue += (characterValue * 10);
                break;
            }
        }
        for (string::iterator iter = line.end(); iter != line.begin(); --iter)
        {
            int characterValue = (int)*iter - 48;
            if (characterValue >= 0 && characterValue <= 9)
            {
                lineValue += characterValue;
                break;
            }
        }
        cout << "Found number: " << lineValue << endl;
        dataSum += lineValue;
    }
    cout << "Count was " << dataSum << endl;
    return 0;
}