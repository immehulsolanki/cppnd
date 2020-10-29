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

int* AddOne1(int& j) 
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    return &j;
}

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

    cout << "===== demo pointer to function =====" << "\n";
    //Passing pointer to fuction
    /*
    When using pointers with functions, some care should be taken. 
    If a pointer is passed to a function and then assigned to a variable in the function that 
    goes out of scope after the function finishes executing, then the pointer will have undefined 
    behavior at that point - the memory it is pointing to might be overwritten by other parts of the program.
    */
     int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";

    cout << "===== demo return pointer from function =====" << "\n";
    //return ponter and reference
    /*
    You can also return a pointer from a function. As mentioned just above, 
    if you do this, you must be careful that the object being pointed to doesn't go out of scope 
    when the function finishes executing. If the object goes out of scope, the memory address being 
    pointed to might then be used for something else.
    In the example below, a reference is passed into a function and a pointer is returned. 
    This is safe since the pointer being returned points to a reference - a variable that exists outside of 
    the function and will not go out of scope in the function.
    */
    int j = 1;
    cout << "The value of i is: " << j << "\n";
    
    // Declare a pointer and initialize to the value
    // returned by AddOne:
    int* my_pointer = AddOne1(j);
    cout << "The value of i is now: " << j << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
}