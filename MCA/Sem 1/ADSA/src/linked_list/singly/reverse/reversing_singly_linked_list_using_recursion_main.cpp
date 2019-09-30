#include <iostream>
#include "linked_list.cpp"

using namespace std;


int main()
{
        system("clear");

        int len, item;
        Linked_List ls;


        // Taking inputs
        cout << "Input list:" << endl;
        cout << "  Length:  "; cin >> len;

        for(int i=1; i<=len; i++) {
                cout << "    Item " << i <<  ":  ";
                cin >> item;
                ls.add(item);
        }

        cout << endl;

        cout << "Inputed list:" << endl;
        ls.show();
        cout << endl;

        cout << "Reversing list..." << endl;
        ls.reverse();
        cout << endl;

        cout << "Reversed list:" << endl;
        ls.show();
        cout << endl;


        return 0;
}