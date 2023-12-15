#include <iostream>
#include <fstream>

using namespace std;

int part1(string filename);
int part2(string filename);
void print_result(string msg, int actual, int expected);
int get_next_number(string::iterator &schar);
string get_next_word(string::iterator &schar);

int main()
{
    int result;
    result = part1("day2-test-data");
    print_result("P1 test:   ", result, 8);
    result = part1("day2-data");
    print_result("P1 actual: ", result, 2545);

    result = part2("day2-test-data");
    print_result("P2 test:   ", result, 2286);
    result = part2("day2-data");
    print_result("P2 actual: ", result, 78111);
}

int part1(string filename)
{
    ifstream data(filename);

    int result = 0;
    string line;
    while (getline(data, line))
    {
        string::iterator schar = line.begin();
        schar += 5;

        int gameId = get_next_number(schar);
        schar += 2;

        int max_red = 0;
        int max_green = 0;
        int max_blue = 0;

        while (schar != line.end())
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            // Doing colours
            while ((char)*schar != ';' && schar != line.end())
            {
                int color_count = get_next_number(schar);
                if (color_count == -1)
                {
                    cout << "Invalid color returned" << endl;
                    return -1;
                }
                schar += 1;
                string color_name = get_next_word(schar);
                if (color_name.compare("red") == 0)
                    red = color_count;
                if (color_name.compare("green") == 0)
                    green = color_count;
                if (color_name.compare("blue") == 0)
                    blue = color_count;
                if ((char)*schar == ',')
                {
                    schar += 2;
                }
            }
            if (red > 12 ||
                green > 13 ||
                blue > 14)
            {
                break;
            }
            if (schar == line.end())
            {
                result += gameId;
                break;
            }
            schar += 2;
        }
    }

    return result;
}

int part2(string filename)
{
    ifstream data(filename);

    int result = 0;
    string line;
    while (getline(data, line))
    {
        string::iterator schar = line.begin();
        schar += 5;

        int gameId = get_next_number(schar);
        schar += 2;

        int max_red = 0;
        int max_green = 0;
        int max_blue = 0;

        while (schar != line.end())
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            // Doing colours
            while ((char)*schar != ';' && schar != line.end())
            {
                int color_count = get_next_number(schar);
                if (color_count == -1)
                {
                    cout << "Invalid color returned" << endl;
                    return -1;
                }
                schar += 1;
                string color_name = get_next_word(schar);
                if (color_name.compare("red") == 0)
                    red = color_count;
                if (color_name.compare("green") == 0)
                    green = color_count;
                if (color_name.compare("blue") == 0)
                    blue = color_count;
                if ((char)*schar == ',')
                {
                    schar += 2;
                }
            }
            if (max_red < red) max_red = red;
            if (max_green < green) max_green = green;
            if (max_blue < blue) max_blue = blue;
            if (schar == line.end())
            {
                result += max_red * max_green * max_blue;
                break;
            }
            schar += 2;
        }
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

int get_next_number(string::iterator &schar)
{
    string number = "";
    int char_value = *schar - 48;
    while (char_value >= 0 && char_value <= 9)
    {
        number += to_string(char_value);
        *schar++;
        char_value = *schar - 48;
    }
    if (number.length() == 0)
    {
        return -1;
    }
    return stoi(number);
}

string get_next_word(string::iterator &schar)
{
    string word = "";
    char character = *schar;
    while (character >= 97 && character <= 122)
    {
        word += character;
        *schar++;
        character = *schar;
    }
    return word;
}