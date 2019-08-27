//----------------------------------------------------------
// Name: Donald Endres
// E-mail Address: dee5123@psu.edu
// Class: CMPSC 121 Section 001
// Project #: 7-2
// Due Date: 
// Brief Project Description: ary
//----------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
        int numbers[10];

        numbers[5] = 77;

        // verifying that c++ arrays are not zero initialized
        // they are, in fact, not initialized
        for(int i = 0; i<10; i++)
        {
                cout << numbers[i] << endl;
        }


        // but if you use the initialization syntax, you get zeros for the unspecified values!
        int nums[10] = {1,2,3};
        for(int i = 0; i<10; i++)
        {
                cout << nums[i] << endl;
        }


        // XXX No error! program runs and writes something somewhere !?!?!
        nums[99] = 5;
        
        
        return(0);
}
