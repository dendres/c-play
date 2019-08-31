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


class Thing
{
public:
        int size;
        string description;
        Thing();
        Thing(int);
};

Thing::Thing()
{
        cout << "constructor called\n";
}

Thing::Thing(int a = 999)
{
        size = a;
}

int main()
{

        Thing t;
        Thing s(99);

        cout << "fin\n";
        cout << "s.size = " << s.size << endl;
        return 0;


}



/*
TEST_CASE( "Factorials are computed", "[factorial]" ) {
        REQUIRE( 1 == 1 );
}
*/
