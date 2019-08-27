//----------------------------------------------------------
// Name: Donald Endres
// E-mail Address: dee5123@psu.edu
// Class: CMPSC 121 Section 001
// Project #: 20 programming challenges 4
// Due Date: 
// Brief Project Description: recursive sum of array
//----------------------------------------------------------

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()

#include "catch.hpp"
#include <iostream>
#include <string>

using namespace std;


/*
sum takes an array and the array size
and returns the sum of all array elements
 */
int sum(int ary[], int n)
{
        int total = 0;
        
        for(int i=0; i<n; i++)
        {
                total += ary[i];
        }
        return total;
}

/*
now do it recursively!!
walk the array from last to first element
XXX couldn't design this. had to use trial and error
*/
int sumr(int ary[], int index)
{
        // cout << "index = " << index << endl;
        
        if ( index < 1)
                return 0;

        int next = index - 1;
        int a = ary[next];
        int b = sumr(ary, next);

        // cout << "adding " << a << " + " << b << endl;
        
        return a + b;
}


TEST_CASE( "sum and recursive sum should return the same values" ) {

        // setup
        int x[] = {7,6,5,4,3,2};
        int len = 6;

        cout << "array is: ";
        for(int i=0; i<len; i++)
        {
                cout << x[i] << " ";
        }
        cout << endl;

        int y = sum(x,len);
        int z = sumr(x,len);

        // test
        REQUIRE( y == z );
}  


