// Author name: Sourav Dey
// Date of creation: 27-AUG-2018
// Week number: 4
// Program name: Create and display cricketer information from and to user

#include <iostream>

#include <cstdlib> // remove

using namespace std;

const int MAX_SIZE = 10;

class Cricketer
{
        private:
                int code, innings, runs, not_out_count;
                char name[20];

        public:
                Cricketer() {}

                Cricketer(const int c, const char n[], const int r, const int inn, const int noc)
                {
                        code = c;
                        runs = r;
                        innings = inn;
                        not_out_count = noc;

                        // copying name from n
                        int i;
                        for(i=0; n[i]!=0 && i<19; i++)
                                name[i] = n[i];
                        name[i]=0;
                }

                // getters
                int get_code() { return code; }
                char* get_name() { return name; }
                int get_total_innings_played() { return innings; }
                int get_total_runs() { return runs; }
                int get_not_out_count() { return not_out_count; }

                static float get_avg_run(Cricketer c)
                {
                        return (float)c.get_total_runs()/c.get_total_innings_played();
                }

                // Overloaded
                static float get_avg_run(const Cricketer c[], const int len)
                {
                        float avg = 0.0;
                        for(int i=0; i<len; i++)
                                avg += get_avg_run(c[i]);
                        return avg;
                }

                static int search_cricketer(Cricketer c[], const int len, const int ccode)
                {
                        for(int i=0; i<len; i++)
                                if(c[i].get_code() == ccode)
                                        return i;
                        return -1;
                }

                static void display_in_sorted_order(const Cricketer c[], const int len)
                {
                        // sort locally
                        Cricketer sorted_c[len], key;

                        // copy all objects to temp array
                        for(int i=0; i<len; i++)
                                sorted_c[i] = c[i];

                        // implementing insertion sort
                        for(int i=1, j; i<len; i++) {
                                key = sorted_c[i];
                                for(j=i-1; j>=0 && sorted_c[j].get_total_runs() > key.get_total_runs(); j--) {
                                        // shift element to right by one
                                        sorted_c[j+1] = sorted_c[j];
                                }
                                sorted_c[j+1] = key;
                        }

                        // display each player's info
                        for(int i=0; i<len; i++) {
                                cout << "Player " << (i+1) << ": \n";
                                cout << "  Code:  " << sorted_c[i].get_code() << "\n";
                                cout << "  Name:  " << sorted_c[i].get_name() << "\n";
                                cout << "  Total innings played:  " << sorted_c[i].get_total_innings_played() << "\n";
                                cout << "  Total runs:  " << sorted_c[i].get_total_runs() << "\n";
                                cout << "  Total not out count:  " << sorted_c[i].get_not_out_count() << "\n";
                                cout << endl;
                        }
                }
};

int main()
{
        int continue_input = 1, choice, cricketer_count = 0;
        Cricketer cricketers[MAX_SIZE];

        system("clear");

        while(continue_input) {
                cout << "\n\nMenu: \n";
                cout << "    1  Enter details of players \n";
                cout << "    2  Display average runs of a single player \n";
                cout << "    3  Average runs of all players \n";
                cout << "    4  Display the list of players in sorted order as per runs \n";
                cout << "    5  Exit" << endl;
                cout << "Enter choice:  ";
                cin >> choice;

                switch(choice) {
                        case 1:  // Enter details of a player
                                        if(cricketer_count == MAX_SIZE) {
                                                cerr << "Error: Maximum player input limit reached!" << endl;
                                        } else {
                                                int ccode, runs, innings, not_out_count;
                                                char name[20];
                                                cout << "Enter player information: \n";
                                                cout << "  Code:  "; cin >> ccode;
                                                cout << "  Name:  "; cin >> name;
                                                cout << "  Total runs:  "; cin >> runs;
                                                cout << "  Total innings played:  "; cin >> innings;
                                                cout << "  Not out count:  "; cin >> not_out_count;

                                                cricketers[cricketer_count++] = Cricketer(ccode, name, runs, innings, not_out_count);
                                        }

                                        break;

                        case 2:  // Display average runs of a single player
                                        if(cricketer_count == 0) {
                                                cerr << "Error: No player information have been provided yet! \n";
                                                break;
                                        }

                                        int ccode, i;
                                        cout << "Enter player code:  "; cin >> ccode;
                                        i = Cricketer::search_cricketer(cricketers, cricketer_count, ccode);
                                        if(i == -1) {
                                                cerr << "Error: No cricketer found with code " << ccode << "!" << endl;
                                        } else {
                                                cout << "Average run:  " << Cricketer::get_avg_run(cricketers[i]) << endl;
                                        }

                                        break;

                        case 3:  // Average runs of all players
                                        if(cricketer_count == 0) {
                                                cerr << "Error: No player information have been provided yet! \n";
                                                break;
                                        }

                                        cout << "Average run: " << Cricketer::get_avg_run(cricketers, cricketer_count) << endl;

                                        break;

                        case 4:  // Display the list of players in sorted order as per runs
                                        if(cricketer_count == 0) {
                                                cerr << "Error: No player information have been provided yet! \n";
                                                break;
                                        }

                                        Cricketer::display_in_sorted_order(cricketers, cricketer_count);
                                        cout << endl;

                                        break;

                        case 5: // Exit
                                continue_input = 0;
                                break;

                        default:
                                cerr << "Error: Invalid option entered! Try again. \n";
                }
        }

        return 0;
}