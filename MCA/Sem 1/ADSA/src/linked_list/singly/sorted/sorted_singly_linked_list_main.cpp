#include <iostream>
#include <cstdlib> // Remove 
#include "sorted_singly_linked_list.cpp"

using namespace std;


int main()
{
        system("clear");

        Linked_List list;
        int continue_loop = 1, e, choice;

        while(continue_loop) {
                cout    << "\n\nMenu: \n"
                        << "  1  Insert \n"
                        << "  2  Remove \n"
                        << "  3  Display \n"
                        << "  4  Exit \n"
                        << "Choice:  ";
                cin >> choice;

                switch(choice) {
                        case 1: // insert
                                cout << "Element:  "; cin >> e;
                                list.insert(e);
                                cout << "Element " << e << " inserted" << endl;

                                break;

                        case 2: // remove
                                if(list.is_empty())
                                        cout << "List is empty!" << endl;
                                else {
                                        cout << "Element:  "; cin >> e;
                                        int pos = list.remove(e);
                                        if(pos == -1)
                                                cout << "Element " << e << " not found!" << endl;
                                        else
                                                cout << "Element " << e << " removed" << endl;
								}

                                break;

                        case 3: // display
                                if(list.is_empty())
                                        cout << "List is empty!" << endl;
                                else {
                                        cout << "\n";
                                        int count = list.display();
                                        cout << count << " element(s) found" << endl;
                                }

                                break;

                        case 4: // exit
                                continue_loop = 0;

                                break;

                        default:
                                cerr << "Error: Invalid choice input! Please try again." << endl;
                }
        }

        return 0;
}