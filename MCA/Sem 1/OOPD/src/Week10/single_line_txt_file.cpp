// Author name: Sourav Dey
// Date of creation: 22-OCT-2018
// Week number: 10
// Program name: Create and modify a single line text file

#include <iostream>
#include <fstream>

using namespace std;


int count_char(const char*, const char);
void invert_case(char*);

int main()
{
    system("clear");

    const int line_len = 1024;
    char fname[10], line[line_len];

    cout << "Enter a file name:  "; cin >> fname;
    cin.ignore();
    fstream file(fname, ios::in | ios::out | ios::trunc);

    cout << "\nEnter a single line to write into file:  ";
    cin.getline(line, line_len);
    file << line << endl;
    cout << "Line written to file successfully." << endl;

    file.seekg(0, ios::beg);
    file.getline(line, line_len);
    cout << "\nFile contents:  " << line << endl;

    cout << "\nInverting character cases in file..." << endl;
    invert_case(line);

    file.seekp(0, ios::beg);
    file << line << endl;
    cout << "File updated with case-inverted line successfully." << endl;

    file.seekg(0, ios::beg);
    file.getline(line, line_len);
    cout << "\nNew file contents: " << line << endl;

    file.seekg(0, ios::beg);
    file.getline(line, line_len);
    cout << "\nCount of 'a' in file:  " << count_char(line, 'a') << endl;

    file.close();


    return 0;
}

void invert_case(char *line)
{
    for(int i=0, c=line[i]; c != 0; i++, c=line[i]) {
        if(c >= 'a' && c <= 'z') {
            line[i] = 'A'+(c-'a');
        } else if(c >= 'A' && c <= 'Z') {
            line[i] = 'a'+(c-'A');
        }
    }
}

int count_char(const char *line, const char c)
{
    long cnt = 0; int i;
    for(i=0; line[i] != 0; i++) {
        if(line[i] == c)
            cnt++;
    }

    return cnt;
}