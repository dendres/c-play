//----------------------------------------------------------
// Name: Donald Endres
// E-mail Address: don@endres.us
// Class: CMPSC 121 Section
// Project # 2-7
// Due Date:
// Brief Project Description: copy from book
//----------------------------------------------------------

/*
see if stdio still works
*/

#include <iostream>
#include <cstdio>


int another()
{
        printf("something else\n");
}

int main()
{
        // call a function
        another();

        int number;
        number = 5;
        printf("the value in number is %d\n", number);
        return 0;
}


