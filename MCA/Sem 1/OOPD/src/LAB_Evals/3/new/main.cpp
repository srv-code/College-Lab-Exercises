// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Lab evaluation: 3
// Program name: Sort c style string

#include <iostream>
#include <cstdlib> // for personal sys compatibility 
#include "str_utils.cpp" // to import custom str util fns
#include "My_String_1.cpp"
#include "My_String_2.cpp"

using namespace std;


// works with My_String_1 
void version_1(const bool debugging)
{
    char str[My_String_1::MAX_LEN];
    My_String_1::show_debug_info = debugging; // DEBUG

    // if(debugging) {
    //     cpystr(str, "India is my nation");
    //     // cpystr(str, "hgfe dcba");
    
    cout << "Enter string:  "; 
    cin.get(str, My_String_1::MAX_LEN);

    My_String_1 s(str);

    cout << "Original string:  ";
    s.show();
    cout << endl;

    !s;

    cout << "Modified string:  ";
    s.show();
    cout << endl;
}

// works with My_String_2
void version_2(const bool debugging)
{
    char str[My_String_2::MAX_LEN];

    if(debugging) {
        cpystr(str, "India is my nation");
        // cpystr(str, "hgfe dcba");
    } else {
        cout << "Enter string:  "; 
        cin.get(str, My_String_1::MAX_LEN);
    }

    My_String_2 s(str);
    cout << "Original string:  " << s << endl;
    !s;
    cout << "Modified string:  " << s << endl;
}

int main(const int argc, const char** argv)
{
    system("clear");

    bool debugging = (argc > 1 && cmpstr(argv[1], "-d") == 0);

    // version_1(debugging);
    version_2(debugging);
    

    return 0;
}