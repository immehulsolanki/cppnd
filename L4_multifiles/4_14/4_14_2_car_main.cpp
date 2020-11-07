/*
Scaling Up
In this concept and the previous one, you took code without classes 
and converted it into an object-oriented format.

In case you aren't convinced that organizing the code using OOP 
saved you some trouble, the next cell redefines main.cpp 
to generate 100 cars with different colors, move each, and print data about each. 
This would have been extremely difficult to do if you had to 
manually create new variables for each car!

There is a lot going on in the code to unpack, including the new keyword 
and the -> operator. The arrow operator -> is used to simultaneously

dereference a pointer to an object and
access an attribute or method.
For example, in the code below, cp is a pointer to a Car object, 
and the following two are equivalent:

// Simultaneously dereference the pointer and 
// access IncrementDistance().
cp->IncrementDistance();

// Dereference the pointer using *, then 
// access IncrementDistance() with traditional 
// dot notation.
(*cp).IncrementDistance();
The new operator allocates memory on the "heap" for a new Car. In general, 
this memory must be manually managed (deallocated) to avoid memory leaks in your program. 
Memory management is the primary focus of one of the later courses in this Nanodegree program, 
so we won't go into greater depth about the difference between stack and heap in this lesson.

Click on the explanation button for a discussion of the code.

Note: This main.cpp uses the class files defined above, so be sure 
you have run the previous example before running this one.
*/

#include <iostream>
#include <string>
#include <vector>
#include "car.h"
using std::string;
using std::cout;
using std::vector;

int main() {
    // Create an empty vector of pointers to Cars 
    // and a null pointer to a car.
    vector<Car*> car_vect;
    Car* cp = nullptr;
    
    // The vector of colors for the cars:
    vector<string> colors {"red", "blue", "green"};

    // Create 100 cars with different colors and 
    // push pointers to each of those cars into the vector.
    for (int i=0; i < 100; i++) {;
        cp = new Car(colors[i%3], i+1);
        car_vect.push_back(cp);
    }

    // Move each car forward by 1.
    for (Car* cp: car_vect) {
        cp->IncrementDistance();
    }

    // Print data about each car.
    for (Car* cp: car_vect) {
        cp->PrintCarData();
    }
}