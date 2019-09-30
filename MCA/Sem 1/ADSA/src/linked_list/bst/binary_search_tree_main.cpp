#include <iostream>
#include "binary_search_tree.cpp"

using namespace std;


int main()
{
    system("clear");

    Binary_Search_Tree tree;
    int e_count, e, i;

    cout << "Number of elements to insert:  ";
    cin >> e_count;
    for(i=0; i<e_count; i++) {
        cout << "  Element " << (i+1) << ":  ";
        cin >> e;
        tree.insert(e);
    }
    cout << endl;

    cout << "Preorder traversal sequence:   ";
    tree.show_preorder_traversal();
    cout << endl;

    cout << "Postorder traversal sequence:  ";
    tree.show_postorder_traversal();
    cout << endl;

    cout << "Inorder traversal sequence:    ";
    tree.show_inorder_traversal();
    cout << endl;



    return 0;
}