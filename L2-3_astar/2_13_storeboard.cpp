/*
Store a Grid in Your Program
In order to write the A* search algorithm, 
you will need a grid or "board" to search through. 
We'll be working with this board throughout the remaining exercises, 
and we'll start by storing a hard-coded board in the main function. 
In later exercises, you will write code to read the board from a file.

This Exercise:

        In the main function, declare a variable board as a 
        vector of vectors of ints: vector<vector<int>>.
        Assign this data to the board variable:

        {{0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0}}

Note: you will need to include the vector library, 
just as iostream is included. You will also need to use 
the namespace std::vector if you want to write vector rather than std::vector in your code.
*/
#include <iostream>
#include <vector>

using namespace std;
vector <int> a = {1,2,3,4}; //1d vector

int main(){
    vector < vector <int> > board = 
    {{0,1,0,0,0,0},
     {0,1,0,0,0,0},
     {0,1,0,0,0,0},
     {0,0,0,0,1,0}
    };

    cout << "done!"<<endl;
    cout << board.size() << endl;

    //iteration 1d
    for(int i:a){
        cout << i;
    }
    cout << endl;

    //iteration 2D
    for(auto i:board){
        for(int j : i){
            cout << j;
        }
        cout << endl;
    }
}