#include <iostream>
#include <cstdio>

using namespace std;

const bool DEBUG_ENABLED = false;


class Sorted_Doubly_Linked_List
{
            struct Node
            {
                    int data;
                    Node *prev, *next;
            } *head, *tail;

            int search(Node **curr, const int data)
            {
                // sets the curr pointer to the next node relative to the data provided
                int pos = 0;
                for(*curr=head; *curr != NULL && (*curr)->data < data; *curr=(*curr)->next, pos++);
                return pos; // # nodes traversed for search op
            }

            int show(const bool need_reverse)
            {
                printf("Pos        Prev        Data      Address          Next    \n");
                printf("---     ----------     ----     ----------     ---------- \n");

                int pos = 0;
                if(need_reverse) { // show list in reverse direction
                    for(Node *curr=tail; curr!=NULL; curr=curr->prev) {
                        show_node(++pos, curr);
                    }
                } else { // show list in forward direction
                    for(Node *curr=head; curr!=NULL; curr=curr->next) {
                        show_node(++pos, curr);
                    }
                }

                return pos;
            }

            void show_node(const int pos, const Node *node) 
            {
                printf("%3d     0x%-8x     %4d     0x%-8x     0x%-8x \n", 
                        pos, node->prev, node->data, node, node->next);
            }

        public:
            Sorted_Doubly_Linked_List()
            {
                head = tail = NULL;
            }

            int add(const int data)
            {
                Node* new_node = new Node;
                new_node->data = data;
                int pos;
				
				if(head == NULL) { 
                    // first node in list
					new_node->next = new_node->prev = NULL;
					head = tail = new_node;
                    pos = 0;
					
					if(DEBUG_ENABLED)
						printf("  [first node in list] \n");
				} else {
                    Node *next;
					pos = search(&next, data);
                    new_node->next = next;
					
					if(next == head) {
						// insert as head
						new_node->prev = NULL;
						head->prev = new_node;
						head = new_node;

                        if(DEBUG_ENABLED)
						    printf("  [node set at head] \n");
					} else if(next == NULL) {
						// insert as tail
						new_node->prev = tail;
						tail->next = new_node;
						tail = new_node;

                        if(DEBUG_ENABLED)
						    printf("  [node set at tail] \n");
					} else {
						// insert in between
						new_node->prev = next->prev;
						next->prev->next = new_node;
                        next->prev = new_node;

                        if(DEBUG_ENABLED)
						    printf("  [node set in between] \n");
					}
				}
				
                if(DEBUG_ENABLED)
				    printf("  [node={pos=%d, curr=0x%x, prev=0x%x, data=%d, next=0x%x}, head=0x%x, tail=0x%x] \n",
								pos, new_node, new_node->prev, new_node->data, new_node->next, head, tail);

               return pos; // position inserted
			}

            bool is_empty()
            {
                return head == NULL;
            }

            int remove(const int data)
            {
                Node *node;
                int pos = search(&node, data);
                
                if(node == NULL || node->data != data)
                    return -1; // not found

                if(DEBUG_ENABLED)
                    printf("  [node={pos=%d, curr=0x%x, prev=0x%x, data=%d, next=0x%x}] \n", 
                                pos, node, node->prev, node->data, node->next);

                if(node == head) {
                    // found at head
                    if(DEBUG_ENABLED)
                        printf("  [Node found at head (0x%x)] \n", head);

                    // resetting head
                    head = head->next;
                    if(head == NULL)
                        tail = NULL;
                    else
                        head->prev = NULL;
                } else if(node == tail) {
                    // found at tail
                    if(DEBUG_ENABLED)
                        printf("  [Node found at tail (0x%x)] \n", tail);

                    // resetting tail
                    tail = tail->prev;
                    if(tail == NULL)
                        head = NULL;
                    else
                        tail->next = NULL;
                } else {
                    // found somewhere in between
                    node->prev->next = node->next;
                    node->next->prev = node->prev;

                    if(DEBUG_ENABLED)
                        printf("  [Node found in between] \n");
                }
                delete node;

                if(DEBUG_ENABLED)
                    printf("  [new head=0x%x, new tail=0x%x] \n", head, tail);

                return pos; // pos removed from
            }

            int show_fwd()
            {
                return show(false);
            }

            int show_bwd()
            {
                return show(true);
            }
};