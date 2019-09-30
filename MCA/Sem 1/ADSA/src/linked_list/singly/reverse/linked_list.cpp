#include <iostream>

using namespace std;

const int DEBUG_ENABLED = 0;


class Linked_List
{
        private:
                struct Node
                {
                        int data;
                        Node *link;
                } *head, *tail;

                int len;

                void reverse(Node *curr, Node *prev)
                {
                        if(curr == NULL) {
                                head = prev;
                                return;
                        }

                        reverse(curr->link, curr);
                        curr->link = prev;
                }

        public:
                Linked_List()
                {
                        head = NULL;
                        tail = NULL;
                }

                void add(const int data)
                {
                        Node *new_node = new Node, *curr = head;
                        new_node->data = data;
                        new_node->link = NULL;

                        if(DEBUG_ENABLED)
                                printf("  [at add(const int): head=0x%x, tail=0x%x] \n", head, tail);

                        if(tail == NULL) { // head is null, insert at head
                                if(DEBUG_ENABLED)
                                        printf("  [node {add=0x%x, data=%d} set at head (add=0x%x)] \n", new_node, new_node->data, head);

                                head = new_node;
                        } else {
                                if(DEBUG_ENABLED)
                                        printf("  [node {add=0x%x, data=%d} set at tail (add=0x%x)] \n", new_node, new_node->data, tail);

                                tail->link = new_node;
                        }

                        tail = new_node;
                }

                void reverse()
                {
                        reverse(head, NULL);
                }

                int show() const
                {
                        if(head == NULL) {
                                cout << "List is empty!" << endl;
                                return 0;
                        }

                        int count = 0;
                        Node *curr = head;

                        printf("   Curr       Data       Next    \n");
                        printf("----------    ----    ---------- \n");

                        for(Node *curr = head; curr != NULL; count++) {
                                printf("0x%-8x    %4d    0x%-8x \n", curr, curr->data, curr->link);
                                curr = curr->link;
                        }

                        return count;
                }
};