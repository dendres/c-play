//----------------------------------------------------------
// Name: Donald Endres
// E-mail Address: dee5123@psu.edu
// Class: CMPSC 121 Section 001
// Project #: 5-15
// Due Date: 
// Brief Project Description: file io
//----------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
        ofstream o;
        ifstream i;
        string content;
        int content_int;
        
        o.open("o.txt");
        o << "stuf 3 to write to file\n";
        o.close();
        
        i.open("o.txt");
        i >> content;
        cout << content << endl;
        i >> content_int;
        cout << content_int << endl;

        // >> returns false if nothing could be read
        while (i >> content)
        {
                cout << content << endl;
        }

        i.close();


        // test if file exists
        ifstream j;
        j.open("fake_file.txt");

        // ifstream object returns false if there is nothin to read?????
        if (j)
        {
                cout << "opened the file\n";
        } else {
                cout << "not able to open the file\n";
        }
        j.close();

        
        return 0;
}
