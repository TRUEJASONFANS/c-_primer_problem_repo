//
// Created by zhxie on 5/17/2022.
//

#include "isSubClass.h"
#include <iostream>

// An extendable class
class Mammal {};

// A subclass of Mammal
class Human: public Mammal {};

// Not a subclass of Mammal
class Guitar {};


/****************************************************************/
/*																*/
/*						  Main function							*/
/*																*/
/****************************************************************/


// Main function
int main() {

    // Print booleans as strings
    std::cout << std::boolalpha;

    // Check to see if a human is a mammal
    std::cout << "It is " << is_subclass(Human, Mammal)
              << " that a human is a mammal" << std::endl;

    // Check to see if a guitar is a mammal
    std::cout << "It is " << is_subclass(Guitar, Mammal)
              << " that a guitar is a mammal" << std::endl;

    // Success
    return EXIT_SUCCESS;
}