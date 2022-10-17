#include "bigdecimalint.h"
#include <iostream>
#include <string>
using namespace std;


BigDecimalInt::BigDecimalInt(){
    number = "";
    isNegative = false;
}


BigDecimalInt::BigDecimalInt(string decstr){
    isNegative = (!decstr.empty() && decstr[0] == '-');
    int start = isNegative ? 1 : 0;
    number = decstr.substr(start);
}

BigDecimalInt :: BigDecimalInt (int decint){
    number = to_string(decint);
    isNegative = (!number.empty() && number[0] == '-');
    int start = isNegative ? 1 : 0;
    number = number.substr(start);
}


int BigDecimalInt::size(){
    return number.size();
}


BigDecimalInt BigDecimalInt::operator= (BigDecimalInt rightOperand){
    number = rightOperand.number;
    isNegative = rightOperand.isNegative;
    return (*this);
}

bool BigDecimalInt::operator<( BigDecimalInt rightOperand){
    if(isNegative && !rightOperand.isNegative){
        return true;
    }
    if(!isNegative && rightOperand.isNegative){
        return false;
    }
    bool isLessThan;
    if(size() == rightOperand.size()){
        isLessThan = number < rightOperand.number;
    }else{
        isLessThan = size() < rightOperand.size();
    }

    return (isNegative ? !isLessThan : isLessThan);
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt rightOperand){
    if(rightOperand.isNegative){
        rightOperand.isNegative = false;
        return (*this) + rightOperand;
    }
    if(isNegative && !rightOperand.isNegative){
        rightOperand.isNegative = true;
        return (*this) + rightOperand;
    }

    BigDecimalInt result;
    result.isNegative = (*this) < rightOperand;
    if(result.isNegative){
        return rightOperand - (*this);
    }
    string up = number;
    int i = up.size()-1;
    int j = rightOperand.size();
    while(i>=0 && j>=0){
        int currentDigit = up[i] - '0';
        if(up[i] < rightOperand.number[j]){
            int k = i-1;
            while(k>=0 && up[k] == '0'){
                up[k] = '9';
                k--;
            }
            up[k] = ((up[k] - '0') - 1) + '0';
            currentDigit += 10;
        }
        result.number.push_back((currentDigit - (rightOperand.number[j] - '0')) + '0');
    }
    while(i>=0){
        result.number.push_back(up[i]);
        i--;
    }
    reverse(result.number.begin(), result.number.end());
    return result;
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt rightOperand){
    if(isNegative && !rightOperand.isNegative){
        return rightOperand - (*this);
    }
    if(!isNegative && rightOperand.isNegative){
        return (*this) - rightOperand;
    }
    int carry = 0;
    int i = size()-1;
    int j = rightOperand.size()-1;
    string sum;
    while(i >=0 && j>=0){
        int currentDigitSum = (number[i]-'0') + (rightOperand.number[j]-'0') + carry;
        sum.push_back((currentDigitSum%10)+'0');
        carry = currentDigitSum / 10;
        i--;
        j--;
    }
    while(j>=0){
        int currentDigitSum = (rightOperand.number[j]-'0') + carry;
        sum.push_back((currentDigitSum%10)+'0');
        carry = currentDigitSum / 10;
        j--;
    }
    while(i>=0){
        int currentDigitSum = (number[i]-'0') + carry;
        sum.push_back((currentDigitSum%10)+'0');
        carry = currentDigitSum / 10;
        i--;
    }
    if(carry){
        sum.push_back(carry + '0');
    }
    reverse(sum.begin(), sum.end());
    BigDecimalInt result;
    result.number = sum;
    result.isNegative = (isNegative && rightOperand.isNegative);
    return result;
}

bool BigDecimalInt::operator>(BigDecimalInt b){
    return b < (*this);
}

bool BigDecimalInt::operator==(BigDecimalInt rightOperand){
    return (number == rightOperand.number && isNegative == rightOperand.isNegative);
}

int BigDecimalInt::sign(){
    return (isNegative ? -1 : 1);
}    

ostream& operator<<(ostream&out, BigDecimalInt rightOperand){
    if(rightOperand.isNegative){
        out << '-';
    }
    for(char digit : rightOperand.number){
        out << digit;
    }
    out << '\n';
    return out;
}