#include <iostream>
#include <cstdio> // DEBUG
#include <cstdlib> // for compatibility

using namespace std;

const bool DEBUG_ENABLED = 0; // DEBUG

const int MAX_SIZE = 10;


class Graph
{
    private:
        int vcount; // count of vertices
        int matrix[MAX_SIZE][MAX_SIZE];

    public:
        void read_inputs()
        {
            cout << "Enter vertices count:  ";
            cin >> vcount;

            for(int i=0; i<vcount; i++)
                for(int j=0; j<vcount; j++)
                        matrix[i][j] = 0;

            cout << "Enter source and destination vertices for each edge (-1 -1 for terminating): " << endl;
            for(int src, dst, i=0;; i++) {
                cout << "  Edge " << (i+1) << ":  ";
                cin >> src >> dst;
                if(src == -1 && dst == -1) // termination signal
                    break;
                matrix[src][dst] = 1;

                if(DEBUG_ENABLED)
                    printf("  [src=%d, dst=%d: %d] \n", src, dst, matrix[src][dst]);
            }
        }

        void show_adj_matrix()
        {
            cout << endl;
            for(int v1=0; v1<vcount; v1++) {
                cout << "Vertex " << v1 << ":  ";
                for(int v2=0; v2<vcount; v2++) {
                    cout << matrix[v1][v2] << "  ";
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
    g.show_adj_matrix();


    return 0;
}