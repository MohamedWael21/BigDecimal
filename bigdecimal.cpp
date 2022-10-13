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


    if (b.num.length()>num.length())
    {

        bool checker = (checksign(b)&&checksign(*this)); /// if both - add - at the end

        int diff=b.num.length()-num.length();

        BigDecimalInt c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i+diff]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }

            c.num+=c.sum+'0';
        }
        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }
        reverseStr(c.num) ;
        return c;

    }


    else if (num.length()>b.num.length())
    {

        bool checker=checksign(b)&&checksign(*this);
        int diff=num.length()-b.num.length();
        BigDecimalInt c;
        c.num="";
        c.carry=0;

        for (int i=(b.num.length()-1); i>=0; i--)
        {
            c.sum=0;
            c.sum=num[i+diff]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }
        reverseStr(c.num) ;
        return c;
    }


    else
    {

        bool checker=checksign(b)&&checksign(*this);

        BigDecimalInt c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }


        reverseStr(c.num) ;
        return c;

    }
}





