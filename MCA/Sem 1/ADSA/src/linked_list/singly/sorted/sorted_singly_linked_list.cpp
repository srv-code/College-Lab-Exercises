#include <iostream>
#include <cstdio> // Remove

using namespace std;

const int DEBUG_ENABLED = 1;


class Linked_List
{
        private:
                struct Node
                {
                        int data;
                        Node* link;
                } *head, *tail;


                int search(Node **curr, Node **prev, const int d)
                {
                        int pos = -1;
                        *prev = NULL;
                        *curr = head;

                        if(DEBUG_ENABLED)
                                printf("    [Inside search(Node**, Node**, const int): search starting with: pos=%d, prev=0x%x, curr=0x%x] \n", pos, *prev, *curr);

                        while( (*curr != NULL) && ((*curr)->data < d) ) {
                                pos++;
                                *prev = *curr;
                                *curr = (*curr)->link;
                        }

                        if(DEBUG_ENABLED)
                                printf("    [Inside search(Node**, Node**, const int): search ended with:    pos=% d, prev=0x%x, curr=0x%x] \n", pos, *prev, *curr);

                        return pos;
                }


        public:
                Linked_List()
                {
                        head = NULL;
                        tail = NULL;
                }

                int insert(const int e)
                {
                        Node *prev, *curr;
                        int pos = search(&curr, &prev, e);

                        if(DEBUG_ENABLED) {
                                printf("  [search returned: pos=%d, curr=0x%x, prev=0x%x] \n", pos, curr, prev);
                                printf("  [head=0x%x, tail=0x%x] \n", head, tail);
                        }

                        Node* node = new Node;
                        node->data = e;

                        if(curr == head) { // insert as head
                                node->link = head;
                                head = node;
                                if(head->link == NULL)
                                        tail = head;

                                if(DEBUG_ENABLED)
                                        printf("  [Node inserted at head. node: address=0x%x, data=%d, link=0x%x, new head=0x%x] \n", node, node->data, node->link, head);
                        } else if(prev == tail) { // insert as tail
                                node->link = NULL;
                                prev->link = node;
                                tail = node;

                                if(DEBUG_ENABLED)
                                        printf("  [Node inserted at tail. node: address=0x%x, data=%d, link=0x%x, new tail=0x%x] \n", node, node->data, node->link, tail);
                        } else { // insert in between
                                prev->link = node;
                                node->link = curr;

                                if(DEBUG_ENABLED)
                                        printf("  [Node inserted in between. node: address=0x%x, data=%d, link=0x%x, prev=0x%x] \n", node, node->data, node->link, prev);
                        }

                        return pos;
                }

                int remove(const int e)
                {
                        Node *prev, *curr;
                        int pos = search(&curr, &prev, e);

                        if(DEBUG_ENABLED)
                                printf("  [search returned: pos=%d] \n", pos);

                        if(curr == NULL || curr->data != e) // not found
                                return -1;

                        if(DEBUG_ENABLED)
                                printf("  [Node to be removed: data=%d, address=0x%x] \n", curr->data, curr);

                        if(curr == head) { // remove from head
                                if(DEBUG_ENABLED)
                                        printf("  [Node is at head] \n");

                                head = head->link;
                                if(head == NULL)
                                        tail = NULL;
                        } else if(curr == tail) { // remove from tail
                                if(DEBUG_ENABLED)
                                        printf("  [Node is at tail] \n");

                                tail = prev;
                                tail->link = NULL;
                        } else { // remove from between
                                if(DEBUG_ENABLED)
                                        printf("  [Node is in between] \n");

                                prev->link = curr->link;
                        }
                        delete curr;

                        return pos + 1; // Position of removed node
                }

                int display()
                {
                        Node *prev, *curr;
                        cout    << "Pos        Prev        Data      Address          Next    \n"
                                << "---     ----------     ----     ----------     ---------- \n";

                        int pos = 0;
                        prev = NULL, curr = head;
                        while(curr != NULL) {
                                printf("%3d     0x%-8x     %4d     0x%-8x     0x%-8x \n", ++pos, prev, curr->data, curr, curr->link);
                                prev = curr;
                                curr = curr->link;
                        }
                        cout << endl;

                        return pos; // # of elements displayed
                }

                int is_empty()
                {
                        return head == NULL;
                }
};