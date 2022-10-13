#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt
{
string num;
     string num;
    int sum, carry;
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
    
    friend ostream& operator << (ostream&, BigDecimalInt ); 
     friend bool checkvalid(BigDecimalInt &b);
    friend bool checksign(BigDecimalInt &b);
    friend bool checkbigger(string a, string b);

};

#endif // BIGDECIMALINT_H
