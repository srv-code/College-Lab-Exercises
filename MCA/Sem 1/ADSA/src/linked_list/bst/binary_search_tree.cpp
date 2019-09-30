#include <iostream>
#include <cstdlib> // DEBUG

using namespace std;


const int DEBUG_ENABLED = 0;


class Binary_Search_Tree
{
    private:
        struct Node
        {
            int val;
            Node *llink, *rlink;
        } *root;

        void show_preorder_traversal(const Node *n)
        {
            if(n == NULL) return;

            // Seq: NLR
            cout << n->val << "  ";
            show_preorder_traversal(n->llink);
            show_preorder_traversal(n->rlink);
        }

        void show_postorder_traversal(const Node *n)
        {
            if(n == NULL) return;

            // Seq: LRN
            show_postorder_traversal(n->llink);
            show_postorder_traversal(n->rlink);
            cout << n->val << "  ";
        }

        void show_inorder_traversal(const Node *n)
        {
            if(n == NULL) return;

            // Seq: LNR
            show_inorder_traversal(n->llink);
            cout << n->val << "  ";
            show_inorder_traversal(n->rlink);
        }

    public:
        Binary_Search_Tree()
        {
            root = NULL;
        }

        void insert(const int e)
        {
            Node *node = new Node;
            node->val = e;
            node->llink = NULL;
            node->rlink = NULL;

            if(DEBUG_ENABLED)
                printf("  [new node {add=0x%x, val=%d}] \n", node, node->val);

            if(root == NULL) {
                root = node;

                if(DEBUG_ENABLED)
                    printf("  [inserted as root (0x%x)] \n");
            } else {
                Node *curr = root, *prev = NULL;
                bool insert_at_left;
                while(curr != NULL) {
                    prev = curr;
                    if(insert_at_left = (e < curr->val)) {
                        // move to left node
                        curr = curr->llink;
                    } else {
                        // move to right node
                        curr = curr->rlink;
                    }
                }

                if(insert_at_left)
                    prev->llink = node;
                else
                    prev->rlink = node;

                if(DEBUG_ENABLED)
                    printf("  [inserted as %s leaf node] \n", insert_at_left ? "left" : "right");
            }
        }

        void show_preorder_traversal()
        {
            show_preorder_traversal(root);
        }

        void show_postorder_traversal()
        {
            show_postorder_traversal(root);
        }

        void show_inorder_traversal()
        {
            show_inorder_traversal(root);
        }
};