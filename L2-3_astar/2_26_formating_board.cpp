#include <iostream>

using std::cout;

int main(){
    enum class color { red, blue, green, orange};

    // declare var. with class init. get value from enum class.
    color my_color = color::blue;

    // sample comparison 
    cout << "====enum if test=====" << "\n";
    if ( my_color == color::green){
        cout << "its blue!" <<"\n";
    }else{
        cout << "no its not" << "\n";
    }

    // new enum 
    enum class direction { up, down, left, right};
    direction my_direction = direction::down;
    // one var to test
    cout << "=====enum switch test=====" << "\n";
    switch (my_direction){
        case direction::down : cout << "down" << "\n";
        break;

        case direction::up : cout << "up" << "\n";
        break;

        case direction::left : cout << "left" << "\n";
        break;

        case direction::right : cout << "right" << "\n";
        break;
    }
    


}