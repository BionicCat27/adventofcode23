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

int main()
{
    ifstream Testdata("test-data");
    ifstream Data("data");
    int calibration;
    calibration = part1(Testdata);
    cout << "Test calibration was: " << calibration << ". Expected: " << 142 << endl;
    calibration = part1(Data);
    cout << "Calibration was: " << calibration << ". Expected: " << 53194 << endl;

    calibration = part2(Testdata);
    cout << "P2 Test calibration was: " << calibration << endl;
    calibration = part2(Data);
    cout << "P2 Calibration was: " << calibration << endl;
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