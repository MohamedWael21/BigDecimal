#include "bigdecimalint.h"
#include <iostream>
#include <string>
using namespace std;

//making a function to reverse string
void reverseStr(string& str)
{
    reverse(str.begin(), str.end());
}
//making the constructors of the class

BigDecimalInt::BigDecimalInt()
{
    Number = "";
}


BigDecimalInt::BigDecimalInt(string decstr)
{
    Number = decstr;
}

BigDecimalInt :: BigDecimalInt (int decint)
{
    Number = to_string(decint);
}

//function to check sign of class
int CheckSign(string &a, BigDecimalInt &b)
{
    if((a.front() == '+' || isdigit(a.front())) && (b.Number.front() == '+' || isdigit(b.Number.front()))) // The two numbers are +ve
        return 1;
    if(a.front() == '-' && b.Number.front() == '-') // The two numbers are -ve
        return -1;
    return 0;

}

int BigDecimalInt::size(){
    return Number.size();
}

int BigDecimalInt::length(){

    for(int i = 0; i < Number.size(); i++)
        if(isdigit(Number[i]) && Number[i] != '0')
            return Number.size()-i;

}

BigDecimalInt BigDecimalInt::operator= (BigDecimalInt b){
    Number = b.Number;

}

bool BigDecimalInt::operator<( BigDecimalInt b){


    if(b.Number[0] == '-' && (Number[0] == '+' || isdigit(Number[0])))
        return false;
    if((b.Number[0] == '+' || isdigit(b.Number[0])) && Number[0] == '-')
        return true;

    if((b.Number[0] == '+' || isdigit(b.Number[0])) && (Number[0] == '+' || isdigit(Number[0]))){
        if((*this).length() > b.length())
            return false;
        else if((*this).length() < b.length())
            return true;

        for(int i = 0; i < b.length(); i++){
            if(Number[i] > b.Number[i])
                return false;
            else if(Number[i] < b.Number[i])
                return true;
        }
    }
    else{

        if((*this).length() > b.length())
            return true;
        else if((*this).length() < b.length())
            return false;

        for(int i = 0; i < b.length(); i++){
            if(Number[i] > b.Number[i])
                return true;
            else if(Number[i] < b.Number[i])
                return false;
        }
    }
    return false;

}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt b){

    BigDecimalInt result;
    if((*this) < b){
        result = b - (*this);
        result.Number = '-' + result.Number;
        return result;
    }

    for(int i = 0; i < max(b.Number.size(), Number.size()); i++)
        result.Number[i] = '0';

    while (b.length() < (*this).length())
        b.Number = '0' + b.Number;
    for(int i = 0; i < (*this).length(); i++){
        result.Number[i] = Number[i] - b.Number[i];
    }

    for(int i = 0; i < result.length(); i++){
        while(result.Number[i] < 0){
            result.Number[i] += 10;
            result.Number[i+1]--;
        }
    }

    return result;


}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt b)
{
    int status = CheckSign(Number, b);
    BigDecimalInt result;

    if(status != 0){ // The two numbers are +ve || -ve
        if(status == -1){
            Number.erase(Number.begin());
            b.Number.erase(Number.begin());
        }

        while(Number.size() > b.Number.size())
            b.Number = '0' + b.Number;

        while(b.Number.size() > Number.size())
            Number = '0' + Number;

        int carry = 0;

        for(int i = Number.size()-1; i > -1; i--){
            carry = (Number[i] - '0') + (b.Number[i] - '0') + carry;
            result = char((carry%10) + '0') + result.Number;
            carry /= 10;
        }

        if(status == -1){
            Number = '-' + Number;
            b.Number = '-' + b.Number;
        }

        if(carry == 1)
            result.Number = '1' + result.Number;

        if(status == -1)
            result.Number = '-' + result.Number;

        return result;

    }

    else{
        if(Number.front() == '-'){
            result = b - (*this);
            return result;
        }
        else{
            result = (*this) - b;
            return result;
        }
    }

}





