// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Lab evaluation: 3
// Program name: Sort c style string

#include <iostream>

using namespace std;

const int MAX_SIZE = 80;


class My_String
{
    char data[MAX_SIZE];
    char splits[MAX_SIZE][MAX_SIZE];
    int len, split_sz;

    void sort(int);

    public:
        My_String(const char str[])
        {
            int i, j, k, eos=0;
            for(i=0, j=0, k=0; i<MAX_SIZE && eos==0; i++) {
                data[i] = str[i];
                if(str[i] == ' ' || str[i] == 0) {
                    j++;
                    k=0;
                    if(str[i] == 0)
                        eos = 1;
                } else
                    splits[j][k++] = str[i];
            }
            len = i;
            split_sz = j;
        }

        void show()
        {
            cout << data;
        }

        friend void operator!(My_String &s);
};

void My_String::sort(int idx)
{
    // cout << idx  << ": " << splits[idx] << endl;
                    for(int a=1, b, key; splits[idx][a] != 0; a++) {
                        key = splits[idx][a];
                        for(b=a-1; b>=0; b--) {
                            if(splits[idx][b] > key) {
                                // shift right
                                splits[idx][b+1] = splits[idx][b];
                            } else break;
                        }
                        splits[idx][b+1] = key;
                    }

    // cout << idx  << ": " << splits[idx] << endl;
}


void operator!(My_String &s)
{
    int k=0;

    for(int i=0, x=0; i<s.split_sz; x++) {
        if(s.splits[i][x] == 0) {
            x=0;
            s.sort(i);

            for(int a=0; s.splits[i][a] != 0; a++)
                s.data[k++] = s.splits[i][a];
            i++;
            s.data[k++] = ' ';
        }
    }
    s.data[k] = 0;

}

/* **** ABANDONED ****
void operator*(My_String &s)
{
    for(int i=0, start=-1, end, sz=s.len+1; i<sz; i++) {
        if(s.data[i] == ' ' || s.data[i] == 0) {
            if(start != -1) {
                if(i-start > 1) {
                    // sort
                    for(int a=1, b, key, n=i-start; a<n; a++) {
                        key = s.data[a];
                        for(b=a-1; b>=0; b--) {
                            if(s.data[b] > key) {
                                // shift right
                                s.data[b+1] = s.data[b];
                            } else break;
                        }
                        s.data[b] = key;
                    }
                }
            } else {
                if(start == -1)
                    start = i;
            }
        }
    }
}
*/

int main()
{
    system("clear");
    My_String s1("India is my nation");
    // My_String s1("hgfe dcba");

    cout << "Original string:  ";
    s1.show();
    cout << endl;

    !s1;

    cout << "Modified string:  ";
    s1.show();
    cout << endl;


    return 0;
}