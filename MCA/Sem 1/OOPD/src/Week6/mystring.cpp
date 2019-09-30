// Author name: Sourav Dey
// Date of creation: 24-SEPT-2018
// Week number: 6
// Program name: Compare two MyString objects using overloaded <= operator

#include <iostream>
#include <cstring>

#define MAX_SIZE 10

using namespace std;


class MyString
{
        private:
                char data[MAX_SIZE];
                int len;

        public:
                MyString(const char d[MAX_SIZE])
                {
                        strcpy(data, d);
                        len = strlen(data);
                }

                int operator<=(const MyString x)
                {
                        if(len > x.len) // reverse of actual condition
                                return 0;
                        for(int i=0; i<len; i++) {
                                if(data[i] > x.data[i]) // reverse of actual condition
                                        return 0;
                        }
                        return 1;
                }

                void show()
                {
                        cout << data;
                }
};

int main()
{
        system("clear");

        char str1[MAX_SIZE], str2[MAX_SIZE];

        cout << "Enter string 1:  "; cin >> str1;
        cout << "Enter string 2:  "; cin >> str2;

        MyString s1(str1), s2(str2);

        cout << "Result:  ";
        s1.show();
        if(s1 <= s2)
                cout << " is lesser than or equals to ";
        else
                cout << " is not lesser than or equals to ";
        s2.show();
        cout << endl;


        return 0;
}