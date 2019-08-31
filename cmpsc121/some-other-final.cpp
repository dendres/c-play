
// http://www-cs.ccny.cuny.edu/~wes/CSC103/docs/practiceproblems.pdf


/*






 */






#include <iostream>
using namespace std;

int main()
{
        int l = 21;
        char m[l];
        cout << "enter\n";
        
        int i = 0;
        do
        {
                // cin >> m[i];
                cin.get(m[i]);
                cout << "message = " << m << "| and current character = " << m[i] << endl;
                ++i;
        } while (i < l -1 && m[i] != '\n');

        m[i] = '\0';
        cout << m << endl;

        return 0;
}




