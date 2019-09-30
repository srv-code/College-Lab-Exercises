#include <iostream>

using namespace std;

class Stack_Linked_List
{
                struct Node
                {
                        int data;
                        Node *link;
                } *top;

        public:
                Stack_Linked_List()
                {
                        top = NULL;
                }

                int is_empty()
                {
                        return top == NULL;
                }

                void push(const int data)
                {
                        Node *new_node = new Node;
                        new_node->data = data;
                        new_node->link = top;
                        top = new_node;
                }

                int pop()
                {
                        int data = top->data;
                        Node *node = top;
                        top = top->link;
                        delete node;
                        return data;
                }

                int show()
                {
                        printf("   Curr       Data       Next    \n");
                        printf("----------    ----    ---------- \n");

                        int count = 0;
                        for(Node *curr = top; curr != NULL; count++) {
                                printf("0x%-8x    %4d    0x%-8x \n", curr, curr->data, curr->link);
                                curr = curr->link;
                        }

                        return count;
                }

};