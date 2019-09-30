#include <iostream>
#include "stack_using_linked_list.cpp"

using namespace std;


int main()
{
        int continue_input = 1, choice, element;
        Stack_Linked_List stack;

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
                                stack.push(element);
                                cout << "Element " << element << " is pushed to stack" << endl;
                                break;

                        case 2: // pop
                                if( stack.is_empty() )
                                        cout << "Stack is empty! \n" << endl;
                                else
                                        cout << "Element popped: " << stack.pop() << endl;
                                break;

                        case 3: // display
                                if( stack.is_empty() )
                                        cout << "Stack is empty!" << endl;
                                else {
                                        int count = stack.show();
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