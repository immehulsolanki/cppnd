// normal program to store anything's mulltiple properties such as color, speed etc...

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

/*
We want to keep track of three different cars properties, such as color and its speed.
So in convencional method we will create and initialize no.of vars. same as no. of
the cars we want to track.
*/

int main(){

    // create car var. and store color as its property
    string car1 = "red";
    string car2 = "blue";
    string car3 = "yellow";

    // create car speed vars. and init with 0
    int car1_speed = 0;
    int car2_speed = 0;
    int car3_speed = 0;

    car1_speed++;
    car2_speed++;
    car3_speed++;

    cout << "car 1 speed is: " << car1_speed << endl;
    cout << "car 2 speed is: " << car2_speed << endl;
    cout << "car 3 speed is: " << car3_speed << endl;

    return  0;
}