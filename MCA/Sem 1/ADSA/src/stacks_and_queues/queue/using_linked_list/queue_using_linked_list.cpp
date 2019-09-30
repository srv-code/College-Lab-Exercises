#include <iostream>

using namespace std;

class Queue_Linked_List
{
                struct Node
                {
                        int data;
                        Node *link;
                } *front, *rear;

        public:
                Queue_Linked_List()
                {
                        front = rear = NULL;
                }

                int is_empty()
                {
                        return front == NULL;
                }

                void push(const int data)
                {
                        Node *new_node = new Node;
                        new_node->data = data;
                        new_node->link = NULL;

                        if(rear == NULL) {
                                // first node of list
                                front = new_node;
                        } else {
                                rear->link = new_node;
                        }
                        rear = new_node;
                }

                int pop()
                {
                        int data = front->data;
                        Node *node = front;

                        front = front->link;
                        if(front == NULL)
                                rear = NULL;

                        delete node;
                        return data;
                }

                int show()
                {
                        printf("   Curr       Data       Next    \n");
                        printf("----------    ----    ---------- \n");

                        int count = 0;
                        for(Node *curr = front; curr != NULL; count++) {
                                printf("0x%-8x    %4d    0x%-8x \n", curr, curr->data, curr->link);
                                curr = curr->link;
                        }

                        return count;
                }

};