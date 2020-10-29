#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main(){
    vector <int> v = {1, 2, 3};

    for(auto i = 0; i < v.size(); ++i){ //.size() is total length of vector
        cout << v[i];
    }
    cout << "\n";

    // addind data to vector
    v.push_back (4); //back mean back side of the vector

    for (auto i = 0; i < v.size(); ++i){
        cout << v[i];
    }
    cout << "\n";

    
}