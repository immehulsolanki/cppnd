/*
Pointers to Other Object Types

Although the type of object being pointed to must be included in a pointer declaration, 
pointers hold the same kind of value for every type of object: just a memory address to where 
the object is stored. In the following code, a vector is declared. Write your own code 
to create a pointer to the address of that vector. Then, dereference your pointer and 
print the value of the first item in the vector.

*/
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;
}

int main() {
    // Vector v is declared and initialized to {1, 2, 3}
    vector<int> v {1, 2, 3};
    
    // Declare and initialize a pointer to the address of v here:
    vector<int>* pointer_v = &v;

    // The following loops over each int a in the vector v and prints.
    // Note that this uses a "range-based" for loop:
    // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-for-range
    for (int a: v) {
        cout << a << "\n";
    }
    
    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    cout << "first elelment of vector v: " << (*pointer_v)[0] << "\n";
    // If you've created a pointer to v, say pv, you can retrieve v with (*pv).

    //Passing Pointers to a Function
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";
}