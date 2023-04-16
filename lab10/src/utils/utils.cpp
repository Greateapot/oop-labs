#include "utils.hpp"

#include <iostream>
#include <random>

#include "../pair/pair.hpp"

using namespace std;

Pair get_rand_pair()
{
    int a = rand() % 1000;
    return Pair(a / 100, a % 100);
}

unsigned short int input_option_number()
{
    char c;
    cin.sync();
    cin >> c;
    return c - '0';
}

int input_int_number(string message)
{
    int v;
    bool f = 1;
    do
    {
        cout << message;
        bool stop = 0;
        string s, r("");
        cin.sync();
        getline(cin, s);

        for (int i = 0; i < s.length() && !stop; i++)
            if ((s[i] == '-' && i == 0) || (isdigit(s[i])))
                r += s[i];
            else
                stop = 1;

        if (!stop)
        {
            v = stoi(r);
            f = 0;
        }
    } while (f);
    return v;
}

double input_double_number(string message)
{
    double v;
    bool f = 1;
    do
    {
        cout << message;
        bool dot = 0, stop = 0;
        string s, r("");
        cin.sync();
        getline(cin, s);

        for (int i = 0; i < s.length() && !stop; i++)
            if ((s[i] == '-' && i == 0) || (s[i] == '.' && !dot) || (isdigit(s[i])))
            {
                r += s[i];
                if (s[i] == '.')
                    dot = 1;
            }
            else
                stop = 1;

        if (!stop)
        {
            v = stod(r);
            f = 0;
        }
    } while (f);
    return v;
}
