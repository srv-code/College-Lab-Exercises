#include <iostream>
#include <cstdlib> // remove 
#include "sorted_doubly_linked_list.cpp"

using namespace std;


int main()
{
        int continue_input = 1, choice, element;
        Sorted_Doubly_Linked_List ls;

        system("clear");

        while(continue_input)
        {
                cout << "\n\nEnter choice:" << endl;
                cout << "  1  Add element" << endl;
                cout << "  2  Remove element" << endl;
                cout << "  3  Display in forward direction" << endl;
                cout << "  4  Display in reverse direction" << endl;
                cout << "  5  Exit" << endl;
                cout << "Choice?  ";
                cin >> choice;

                switch(choice)
                {
                        case 1 : // add
                                cout << "Element?  ";
                                cin >> element;
                                ls.add(element);
                                cout << "Element " << element << " is added" << endl;
                                break;

                        case 2: // remove
                                if( ls.is_empty() )
                                        cout << "List is empty! \n" << endl;
                                else {
                                        cout << "Element?  ";
                                        cin >> element;
                                        if(ls.remove(element) == -1)
                                                cout << "Element " << element << " not found" << endl;
                                        else
                                                cout << "Element " << element << " removed" << endl;
                                }
                                break;

                        case 3: // display in forward direction
                                if( ls.is_empty() )
                                        cout << "List is empty!" << endl;
                                else {
                                        cout << "Total " << ls.show_fwd() << " item(s) found" << endl;
                                }

                                break;

                        case 4: // display in reverse direction
                                if( ls.is_empty() )
                                        cout << "List is empty!" << endl;
                                else {
                                        cout << "Total " << ls.show_bwd() << " item(s) found" << endl;
                                }

                                break;

                        case 5: // exit
                                continue_input = 0;
                                break;

                        default:
                                cout << "Invalid choice! Try again." << endl;
                }
        }

        return 0;
}