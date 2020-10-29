#include <iostream>
using std::cout;

// Pass by value (Normally used).
// Original var. data remain uncanged.
int mul(int i){
    i = i * 2;
    return i;
}

// Pass by reference.
// Original var. data will be modified.
int mul1(int &i){
    i = i * 2;
    return i;
}

int main(){

    cout << "==== demo pass by value ====" << "\n";
    int a = 5;
    int b = mul(a); 
    cout << "origional a " << a << "\n";
    cout << "b " << b << "\n";
    cout << "status of a " << a << "\n";

    cout << "==== demo pass by reference ====" << "\n";
    int c = 5;
    int d = mul1(c); 
    cout << "origional c " << c << "\n";
    cout << "d " << d << "\n";
    cout << "status of c " << c << "\n";

}