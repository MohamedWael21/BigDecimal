#include "bigdecimalint.h"
#include <iostream>
#include <string>
using namespace std;

//making a function to reverse string
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}


