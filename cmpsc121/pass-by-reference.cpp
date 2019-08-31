//----------------------------------------------------------
// Name: Donald Endres
// E-mail Address: dee5123@psu.edu
// Class: CMPSC 121 Section 001
// Project #:
// Due Date: 
// Brief Project Description:
//----------------------------------------------------------

// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
// #include "catch.hpp"
#include <iostream>
using namespace std;

void modifies_reference(int &x)
{
        x = 5; // when passed by reference &x is the address and x is the variable. // *x is not needed
        cout << "inside function, x = " << x << endl;
}

int main()
{

        int y = 7;
        cout << "y = " << y << endl;
        modifies_reference(y);
        cout << "y = " << y << endl;


        int a[5] = {10,11,12,13,14};
        if (a[3] == *(a + 3))
                cout << "they are equal\n";

        int *b = a;
        if (b[2] == a[2])
                cout << "equal again\n";
        
}




/*
TEST_CASE( "Factorials are computed", "[factorial]" ) {
        REQUIRE( 1 == 1 );
}
*/
