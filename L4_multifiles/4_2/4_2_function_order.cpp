/*
Using a Header

One other way to solve the code problem above (without rearranging the functions) 
would have been to declare each function at the top of the file. 
A function declaration is much like the first line of a function definition - it contains the return type, 
function name, and input variable types. The details of the function definition are not needed for 
the declaration though.

To avoid a single file from becomming cluttered with declarations and definitions for every function, 
it is customary to declare the functions in another file, called the header file. In C++, 
the header file will have filetype .h, and the contents of the header file must be included at the top of the .cpp file. 
See the following example for a refactoring of the code above into a header and a cpp file.

Notice that the code from the first example was fixed without having to rearrange the functions! 
In the code above, you might also have noticed several other things:

    The function declarations in the header file don't need variable names, just variable types. 
    You can put names in the declaration, however, and doing this often makes the code easier to read.
    The #include statement for the header used quotes " " around the file name, and not angle brackets <>. 
    We have stored the header in the same directory as the .cpp file, and the quotes tell the preprocessor 
    to look for the file in the same directory as the current file - not in the usual set of directories 
    where libraries are typically stored.
    Finally, there is a preprocessor directive:

    #ifndef HEADER_EXAMPLE_H
    #define HEADER_EXAMPLE_H

    at the top of the header, along with an #endif at the end. This is called an "include guard". 
    Since the header will be included into another file, and #include just pastes contents into a file, 
    the include guard prevents the same file from being pasted multiple times into another file. 
    This might happen if multiple files include the same header, and then are all included into the same main.cpp, 
    for example. The ifndef checks if HEADER_EXAMPLE_H has not been defined in the file already. 
    If it has not been defined yet, then it is defined with #define HEADER_EXAMPLE_H, and 
    the rest of the header is used. If HEADER_EXAMPLE_H has already been defined, 
    then the preprocessor does not enter the ifndef block. Note: There are other ways to do this. 
    Another common way is to use an #pragma oncepreprocessor directive, but we won't cover that in detail here. 
    See this Wikipedia article for examples.
*/
#include "4_2_header_example.h" // double quate note<> ensure file in same dir.
#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int IncrementAndComputeVectorSum(vector<int> v) 
{
    int total = 0;
    AddOneToEach(v);

    for (auto i: v) {
        total += i;
    }
    return total;
}

void AddOneToEach(vector<int> &v) 
{
    // Note that the function passes a reference to v
    // and the for loop below uses references to 
    // each item in v. This means the actual
    // ints that v holds will be incremented.
    for (auto& i: v) {
        i++;
    }
}

int main() 
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}