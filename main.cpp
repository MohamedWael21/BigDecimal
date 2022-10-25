#include "bigdecimalint.h"

int main(){
    BigDecimalInt a("1233939028390390283098093802803982938093492804938098090");
    BigDecimalInt b("-2338023093289083094809393080980948039800803804982080382");
    
    cout << a+b << '\n';
    
    cout << a-b << '\n';

    cout << (a>b?"Yes":"No") << '\n';

    cout << (a<b?"Yes":"No") << '\n';

    cout << (a==b?"Yes":"No") << '\n';

    cout << a.sign() << '\n';
    
    cout << b.sign() << '\n';

    cout << a.size() << '\n';
    cout << b.size() << '\n';

    a = b;

    cout << a << '\n';

}