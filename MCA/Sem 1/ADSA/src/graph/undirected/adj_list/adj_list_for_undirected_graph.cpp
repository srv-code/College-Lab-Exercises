#include <iostream>
#include <cstdlib> // DEBUG

using namespace std;

const bool DEBUG_ENABLED = 0; // debug

const int MAX_SIZE = 10;


class Graph
{
    private:
        struct Node
        {
            int data;
            Node *link;
        } *list[MAX_SIZE];

        int vcount; // count of vertices

        void insert(int parent, int child)
        {
            Node* node = new Node;
            node->data = child;
            node->link = list[parent];
            list[parent] = node;
        }

    public:
        void read_inputs()
        {
            cout << "Enter vertices count:  ";
            cin >> vcount;

            for(int i=0; i<vcount; i++)
                list[i] = NULL;

            cout << "Enter source and destination vertices for each edge (-1 -1 for terminating): " << endl;
            for(int src, dst, i=0;; i++) {
                cout << "  Edge " << (i+1) << ":  ";
                cin >> src >> dst;

                if(src == -1 && dst == -1) // termination signal
                    break;

                insert(src, dst);
                insert(dst, src); // set in both directions
            }
        }

        void show_adj_list()
        {
            cout << endl;
            for(int i=0; i<vcount; i++) {
                cout << "Vertex " << i << ":  ";
                Node* curr = list[i];
                while(curr != NULL) {
                    cout << curr->data << "  ";
                    curr=curr->link;
                }
                cout << endl;
            }
        }
};


int main()
{
    system("clear");

    Graph g;
    g.read_inputs();
    g.show_adj_list();


    return 0;
}