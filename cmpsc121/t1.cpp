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
#include <string>
using namespace std;


int main()
{
        string s = "hello there";
        string t = "hello there";

        if (s == t)
                cout << "they are equal\n";
        else
                cout << "not equal\n";

        string u = s + " again";

        cout << u << endl;
        


        return 0;
}



/*
TEST_CASE( "Factorials are computed", "[factorial]" ) {
        REQUIRE( 1 == 1 );
}
*/
