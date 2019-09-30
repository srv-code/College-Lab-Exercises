// Author name: Sourav Dey
// Date of creation: 29-OCT-2018
// Week number: 10
// Program name: Create a multiline text file and show summary

#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    system("clear");

    char fname[10];

    cout << "Enter file name:  "; cin >> fname;

    fstream file(fname, ios::in | ios::out | ios::trunc);
    char ch;
    long char_cnt=0, alpha_cnt=0, digit_cnt=0, line_cnt=0, space_cnt=0;

    cout << "\nEnter lines of texts. Press Ctrl-D to stop." << endl;
    file.seekp(0, ios::beg);
    cin.ignore();
    // while((ch=cin.get()) != stop_char) {
    while((ch=cin.get()) != EOF) {
        file.put(ch);

        if(line_cnt==0)
            line_cnt=1;
        if(ch=='\n')
            line_cnt++;
        char_cnt++;
        if(isalpha(ch))
            alpha_cnt++;
        if(isdigit(ch))
            digit_cnt++;
        if(isspace(ch))
            space_cnt++;
    }

    cout << "\n\nFile contents: " << endl;
    file.seekg(0, ios::beg);
    while(file) {
        cout << (char)file.get();
    }

    file.close();

    cout    << "\n\nSummary:"
            << "\n\tTotal chars:  " << char_cnt
            << "\n\tTotal alphabets:  " << alpha_cnt
            << "\n\tTotal digits:  " << digit_cnt
            << "\n\tTotal digits:  " << digit_cnt
            << "\n\tTotal lines:  " << line_cnt
            << "\n\tTotal spaces:  " << space_cnt
            << endl;



    return 0;
}