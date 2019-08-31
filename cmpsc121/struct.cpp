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

struct Box
{
        int length;
        int width;
};



int main()
{

        Box b;
        b.length = 5;

        Box c = {33, 44};
        
        cout << "box length = " << b.length << endl;

        cout << "c.length = " << c.length << endl;
        
        return 0;
}



/*
TEST_CASE( "Factorials are computed", "[factorial]" ) {
        REQUIRE( 1 == 1 );
}
*/
