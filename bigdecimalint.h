#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <string>
using namespace std;

class BigDecimalInt
{
string num;
public:

    BigDecimalInt(string );
    BigDecimalInt(int );
    

    BigDecimalInt operator+(BigDecimalInt);
    BigDecimalInt operator-(BigDecimalInt);


    bool operator< (BigDecimalInt); 
    bool operator> (BigDecimalInt);
    bool operator==(BigDecimalInt);

    BigDecimalInt operator= (BigDecimalInt);

    int size(); 
    int sign();
    
    friend ostream& operator << (ostream&, BigDecimalInt ); 

};

#endif // BIGDECIMALINT_H