#include <iostream>
#include "queue_using_linked_list.cpp"

using namespace std;


int main()
{
        int continue_input = 1, choice, element;
        Queue_Linked_List queue;

        system("clear");

        while(continue_input)
        {
                cout << "\n\nEnter choice:" << endl;
                cout << "  1  Push" << endl;
                cout << "  2  Pop" << endl;
                cout << "  3  Display" << endl;
                cout << "  4  Exit" << endl;
                cout << "Choice?  ";
                cin >> choice;

                switch(choice)
                {
                        case 1 : // push
                                cout << "Element?  ";
                                cin >> element;
                                queue.push(element);
                                cout << "Element " << element << " is pushed to queue" << endl;
                                break;

                        case 2: // pop
                                if( queue.is_empty() )
                                        cout << "Queue is empty! \n" << endl;
                                else
                                        cout << "Element popped: " << queue.pop() << endl;
                                break;

                        case 3: // display
                                if( queue.is_empty() )
                                        cout << "Queue is empty!" << endl;
                                else {
                                        int count = queue.show();
                                        cout << "Total " << count << " item(s) found" << endl;
                                }

                                break;

                        case 4: // exit
                                continue_input = 0;
                                break;

                        default:
                                cout << "Invalid choice! Try again." << endl;
                }
        }

        return 0;
}