#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int part1(string filename);
void print_result(string msg, int actual, int expected);

int main()
{
    int result;
    result = part1("day3-test-data");
    print_result("P1 test:   ", result, 4361);
    // result = part1("day3-data");
    // print_result("P1 actual: ", result, 2);
}

int part1(string filename)
{
    ifstream data(filename);
    int result = 0;
    string line;
    getline(data, line);
    string fullLine = line;
    int linelength = line.length();
    cout << "Line length is " << linelength << endl;
    cout << "Received line: " << line << endl;
    while (getline(data, line))
    {
        cout << "Received line: " << line << endl;
        fullLine.append(line);
    }
    string::iterator currentLine = fullLine.begin();

    string partnum = "";

    while (currentLine != fullLine.end())
    {
        if (*currentLine == '.')
        {
            if (partnum.length() > 0)
            {
                bool partfound = false;
                cout << "Part number: " << partnum << endl;
                string::iterator lookbehind = currentLine - partnum.length();
                if (distance(fullLine.begin(), lookbehind) > 0)
                {
                    lookbehind -= 1;
                    if (!isdigit(*lookbehind) && *lookbehind != '.')
                    {
                        cout << "Found valid part (left) " << partnum << endl;
                        result += stoi(partnum);
                        partfound = true;
                    }
                }
                int index = distance(fullLine.begin(), currentLine);
                int quotient = index / linelength;
                int difference = index % linelength;
                if (quotient > 0 && !partfound)
                {
                    lookbehind -= linelength;
                    for (int i = 0; i < partnum.length() + 2; i++)
                    {
                        if (!isdigit(*lookbehind) && *lookbehind != '.')
                        {
                            cout << "Found valid part (line above)" << endl;
                            result += stoi(partnum);
                            partfound = true;
                            break;
                        }
                        lookbehind++;
                    }
                }
                string::iterator lookahead = currentLine;
                if (distance(lookahead, fullLine.end()) > 0)
                {
                    lookahead += 1;
                    if (!isdigit(*lookahead) && *lookahead != '.')
                    {
                        cout << "Found valid part! " << partnum << endl;
                        result += stoi(partnum);
                        partfound = true;
                    }
                }
                index = distance(currentLine, fullLine.end());
                quotient = index / linelength;
                difference = index % linelength;
                if (quotient > 0 && !partfound)
                {
                    lookahead += linelength - partnum.length() - 2;
                    for (int i = 0; i < partnum.length() + 2; i++)
                    {
                        if (!isdigit(*lookahead) && *lookahead != '.')
                        {
                            cout << "Found valid part (line below)" << endl;
                            result += stoi(partnum);
                            partfound = true;
                            break;
                        }
                        lookahead++;
                    }
                }
                partnum = "";
            }
        }
        else if (isdigit(*currentLine))
        {
            partnum += *currentLine;
        }
        else
        {
            if (partnum.length() > 0)
            {
                cout << "Found valid part (right): " << partnum << endl;
                result += stoi(partnum);
                partnum = "";
            }
        }
        currentLine++;
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