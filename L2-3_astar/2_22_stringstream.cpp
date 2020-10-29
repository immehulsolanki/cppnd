#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main(){

    // string stream parse one charachter at a time frome line.
    string aa = "1 2 3"; //ordinary stream
    istringstream my_string (aa);//init string stream

    int n; //iterator
    while(my_string){ // bool: check if input string stream available

        my_string >> n; // update iterator
        if (my_string){ // bool: check if new char available 
            cout << n << "\n";
        }
        else{
            cout << "Error\n";
        }
    }

    //short way
    aa = "1 2 3"; //ordinary stream
    istringstream my_string1 (aa);//init string stream
    n = 0;
    while (my_string1 >> n){ // bool:(my_string >> n) as true false condition.
        cout << n << "\n";
    }
    cout << "Error \n";

    //mix data type
    string b = ("1,2,3,4"); // this is predefine (n+c) mix type formate see o/p
    char c; //charachter iterator //4 wont print.
    n = 0; //no. iterator

    istringstream my_stream2 (b); // initialize stream 
    while (my_stream2 >> n >> c){ //put whie loop end as bool
        cout << n << " " << c << "\n"; 
    }
    cout << "stream finished\n";    
}