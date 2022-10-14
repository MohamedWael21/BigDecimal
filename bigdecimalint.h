#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt
{
private:
    string Number = "";
    int length();
public:

    BigDecimalInt(string decstr );
    BigDecimalInt(int decint );
    BigDecimalInt();

    BigDecimalInt operator+(BigDecimalInt b);
    BigDecimalInt operator-(BigDecimalInt);

    bool operator< (BigDecimalInt);
    bool operator> (BigDecimalInt);
    bool operator==(BigDecimalInt);
    BigDecimalInt operator= (BigDecimalInt);

    int size(); 
    int sign();



    friend ostream& operator<<(ostream&, BigDecimalInt); 
    friend int CheckSign(string&, BigDecimalInt&);

};

#endif // BIGDECIMALINT_H
