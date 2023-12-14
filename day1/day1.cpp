#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string NUMBERS[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int part1(ifstream &data);
int part2(ifstream &data);
string makeNumeric(string line);
int getFirstNumber(string line);
void print_result(string msg, int actual, int expected);

int main()
{
    ifstream Testdata("day1-test-data");
    ifstream Data("day1-data");
    int calibration;
    calibration = part1(Testdata);
    print_result("P1 test:   ", calibration, 142);
    calibration = part1(Data);
    print_result("P1 actual: ", calibration, 53194);

    calibration = part2(Testdata);
    print_result("P2 test:   ", calibration, 142);
    calibration = part2(Data);
    print_result("P2 actual: ", calibration, 54249);
}
int part1(ifstream &data)
{
    data.clear();
    data.seekg(0);
    string line;
    int dataSum = 0;
    while (getline(data, line))
    {
        int lineValue = 10 * getFirstNumber(line);
        reverse(line.begin(), line.end());
        lineValue += getFirstNumber(line);
        dataSum += lineValue;
    }
    return dataSum;
}

int part2(ifstream &data)
{
    data.clear();
    data.seekg(0);
    string line;
    int dataSum = 0;
    while (getline(data, line))
    {
        line = makeNumeric(line);
        int lineValue = 10 * getFirstNumber(line);
        reverse(line.begin(), line.end());
        lineValue += getFirstNumber(line);
        dataSum += lineValue;
    }
    return dataSum;
}

string makeNumeric(string line)
{
    string output = "";
    for (int i = 0; i < line.length(); i++)
    {
        int characterValue = (int)line[i] - 48;
        if (characterValue >= 0 && characterValue <= 9)
        {
            output += to_string(characterValue);
        }
        for (int j = 0; j < sizeof(NUMBERS) / sizeof(NUMBERS[0]); j++)
        {
            string number = NUMBERS[j];
            string number_substr = line.substr(i, number.length());

            if (number_substr.compare(number) == 0)
            {
                output += to_string(j);
            }
        }
    }
    return output;
}

int getFirstNumber(string line)
{
    for (string::iterator iter = line.begin(); iter != line.end(); ++iter)
    {
        int characterValue = (int)*iter - 48;
        if (characterValue >= 0 && characterValue <= 9)
        {
            return characterValue;
        }
    }
    return -1;
}

void print_result(string msg, int actual, int expected)
{
    cout << msg << "Actual " << actual << " Expected " << expected;
    int diff = actual - expected;
    if (diff != 0)
    {
        cout << " Diff " << diff;
    }
    cout << endl;
}