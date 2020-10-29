/*
Constants

This example highlights how to use const to promise not to modify a variable, 
even though the variable can only be evaluated at run time.

The example also show how to use constexpr to guarantee 
that a variable can be evaluated at compile time.

In other words:
const can be initialize empty and compiler will allow one time assignment
const a = n * 1;
here n is not know but still it will run

while in constexpr MUST initialized with any value.

*/

#include <iostream>
#include <vector>

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
        sum += i;
    return sum;
}

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."
    
    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."
    
    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";


    /*
    The major difference between `const` and `constexpr`, though, is 
    that `constexpr` must be evaluated at compile time.
    The compiler will catch a `constexpr` variable that cannot be evaluated at compile time.
    */


   /*
   A common usage of const is to guard against accidentally changing a variable, 
   especially when it is passed-by-reference as a function argument.
   */
  std::vector<int> v {0, 1, 2, 3, 4};
  std::cout << sum(v) << "\n";

}