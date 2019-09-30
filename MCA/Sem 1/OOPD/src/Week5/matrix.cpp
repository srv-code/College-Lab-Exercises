// Author name: Sourav Dey
// Date of creation: 17-SEPT-2018
// Week number: 5
// Program name: Create, check, add and subtract two matrices by overloading appropriate operators


#include <iostream>

using namespace std;

class Matrix
{
        public:
                static const int MAX_LEN = 10;

        private:
                int data[MAX_LEN][MAX_LEN];
                int col_sz, row_sz;

                Matrix(int d[MAX_LEN][MAX_LEN], int r, int c)
                {
                        row_sz = (r > MAX_LEN ? MAX_LEN : r);
                        col_sz = (c > MAX_LEN ? MAX_LEN : c);

                        for(int i=0; i<row_sz; i++)
                                for(int j=0; j<col_sz; j++)
                                        data[i][j] = d[i][j];
                }

        public:
                Matrix()
                {
                        row_sz = col_sz = 0;
                }

                int read_data()
                {
                        cout << "  Column size:  "; cin >> col_sz;
                        if(col_sz > MAX_LEN) {
                                cerr << "Error: Please enter a value between 1 and " << MAX_LEN << endl;
                                return -1;
                        }

                        cout << "  Row size:     "; cin >> row_sz;
                        if(row_sz > MAX_LEN) {
                                cerr << "Error: Please enter a value between 1 and " << MAX_LEN << endl;
                                return -1;
                        }

                        for(int i=0; i<row_sz; i++) {
                                cout << "    For row " << (i+1) << "\n";\
                                for(int j=0; j<col_sz; j++) {
                                        cout << "      Col " << (j+1) << ":  ";
                                        cin >> data[i][j];
                                }
                        }


                        return 0;
                }

                int operator==(Matrix x) const // to check compatibility
                {
                        return (row_sz == x.row_sz && col_sz == x.col_sz);
                }

                Matrix operator+(Matrix x)
                {
                        int d[MAX_LEN][MAX_LEN];

                        for(int i=0; i<row_sz; i++)
                                for(int j=0; j<col_sz; j++)
                                        d[i][j] = data[i][j] + x.data[i][j];

                        return Matrix(d, row_sz, col_sz);
                }

                Matrix operator-(Matrix x)
                {
                        int d[MAX_LEN][MAX_LEN];

                        for(int i=0; i<row_sz; i++)
                                for(int j=0; j<col_sz; j++)
                                        d[i][j] = data[i][j] - x.data[i][j];

                        return Matrix(d, row_sz, col_sz);
                }

                void show()
                {
                        cout << "[Order: " << row_sz << "x" << col_sz << "] \n";
                        for(int i=0; i<row_sz; i++) {
                                for(int j=0; j<col_sz; j++)
                                        cout << "  " << data[i][j];
                                cout << "\n";
                        }

                        cout << endl;
                }
};

int main()
{
        system("clear");

        Matrix m1, m2, sum, diff;
        int x;

        cout << "Input matrix 1: " << endl;
        if(m1.read_data())
                exit(-1);

        cout << "Input matrix 2: " << endl;
        if(m2.read_data())
                exit(-1);

        cout << "Matrix 1:" << endl;
        m1.show();

        cout << "Matrix 2:" << endl;
        m2.show();

        cout << "Are matrices compatible for addition or subtraction?  " << ((x=(m1==m2)) ? "Yes" : "No") << endl;

        if(x) {
                cout << "Adding two matrices... \n";
                sum = m1 + m2;
                cout << "Result: \n";
                sum.show();

                cout << "Subtracting two matrices... \n";
                diff = m1 - m2;
                cout << "Result: \n";
                diff.show();
        }


        return 0;
}