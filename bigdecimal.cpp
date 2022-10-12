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
//making the constructors of the class

BigDecimalInt::BigDecimalInt()
{
    num="";
}


BigDecimalInt::BigDecimalInt(string decstr)
{
    num=decstr;
}

BigDecimalInt :: BigDecimalInt (int decint)
{
    if (decint < 0)
    {
        decint*=-1;

        while ( decint!=0)
    {

        num+=(decint%10)+'0';
        decint-= decint%10;
        decint/=10;

    }
    num+='-';
    }



 else   if (decint == 0)
    {
        //cout<<"i'm here\n";
        num="0";
    }


else if (decint >0 ){
    while ( decint!=0)
    {

        num+=(decint%10)+'0';
        decint-= decint%10;
        decint/=10;

    }
}
    reverseStr(num);

}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt b)
{

   if (  num[0]=='-'   &&  (b.num[0]=='+'||(b.num[0]<='9'&&b.num[0]>='0'))  )


    {
        checksign(*this);
        return b - *this;
    }

    if ((num[0]=='+'||(num[0]<='9'&&num[0]>='0'))       &&      b.num[0]=='-')
    {
        checksign(b);
        return *this - b;
    }




