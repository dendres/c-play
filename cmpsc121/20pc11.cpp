//----------------------------------------------------------
// Name: Donald Endres
// E-mail Address: dee5123@psu.edu
// Class: CMPSC 121 Section 001
// Project #:
// Due Date: 
// Brief Project Description:
//----------------------------------------------------------

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include <iostream>
#include <string>
using namespace std;

/*
try stripping the first and last characters
return null string if length < 3
 */
string strip(string x)
{
        int length = x.length();
        if (length < 3)
                return "";
        return x.substr(1, length - 2);
}


// compare first and last characters
// null string and single character string match ???
bool ends_match(string x)
{
        int length = x.length();

        if (length < 2)
                return true;

        char first = tolower(x[0]);
        char last  = tolower(x[length - 1]);
        cout << "first = " << first << ", last = " << last << endl;

        if (first == last)
                return true;

        return false;
}

// like s/[^W]*//g
string words_only(string x)
{
        int length = x.length();
        for(int i=0; i<(length); i++)
        {
                cout << "erasing out non-alpha characters from: " << x << "|" << endl;
                
                if(! isalpha(x[i]))
                {
                        x.erase(i,1);
                        length--;
                        i--;
                }
        }
        return x;               
}



bool is_palindrome(string x)
{
        // strip all non-characters... without regex???
        x = words_only(x);
        
        cout << "checking " << x << endl;
        
        int length = x.length();
        bool matched = ends_match(x);
        
        if(length > 1 && matched)
                matched = is_palindrome(strip(x));

        if (matched)
                cout << "last round was a palindrome" << endl;
        else
                cout << "last round was not a palindrome" << endl;
        return matched;
}
/*
int main()
{

        string stripped = strip("ay");
        cout << "stripped ay = " << stripped << endl;

        
        if (ends_match("kayak"))
                cout << "ends match" << endl;
        
        
        if (is_palindrome("kayak"))
                cout << "kayak is a palindrome" << endl;
        else
                cout << "kayak is NOT a palindrome" << endl;
        
        return 0;
}
*/


TEST_CASE( "Factorials are computed", "[factorial]" ) {
        REQUIRE( words_only("Des       serts, I stressed") == "DessertsIstressed");
        REQUIRE( is_palindrome("Kayak") == true );
        REQUIRE( is_palindrome("Desserts, I stressed") == true );
        REQUIRE( is_palindrome("A man, a plan, a canal, Panama") == true );
        REQUIRE( is_palindrome("Able was I, ere I saw Elba") == true );

/*
Able was I, ere I saw Elba

A man, a plan, a canal, Panama

Desserts, I stressed

Kayak
*/
}

