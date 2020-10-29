/*
Print the Board
Now that you have a board stored in your program, 
you'll need a way to print it out so you can display the results of your project. 
In this exercise, you will add a PrintBoard function to print the board one row at a time. 
When you are done, the printed output should look like:

010000
010000
010000
010000
000010

This Exercise:

        1.Write a void PrintBoard function. The function should accept the board as an argument. 
        The function should print each row of the board with a newline "\n".
        2.When you have written your PrintBoard function, 
        call it from within main() to print the board.

*/
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

// TODO: Add PrintBoard function here.
int PrintBoard(const vector <vector <int> > &sboard){
  for (const auto &i : sboard){
    for (const auto &j : i ){
     cout << j ;
    }
   cout << "\n";
  }
}

int main() {
  vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0}};
  // TODO: Call PrintBoard function here.
  PrintBoard(board);
}