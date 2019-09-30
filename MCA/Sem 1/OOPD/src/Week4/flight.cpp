// Author name: Sourav Dey
// Date of creation: 27-AUG-2018
// Week number: 4
// Program name: Populate and display flight Information from and to user

#include <iostream>

#include <cstdlib> // remove 

using namespace std;

class Flight
{
        private:
                int no;
                char dest[20];
                float dist, fuel;

                int calculate_fuel()
                {
                        if(dist <= 1000.0)
                                return 500;
                        else if(dist <= 2000)
                                return 1100;
                        else
                                return 2200;
                }

        public:
                Flight() : fuel(13.2)
                {}

                Flight(const float f) : fuel(f)
                {}

                void information_entry()
                {
                        cout << "Enter flight information: \n";
                        cout << "  Flight Number:  "; cin >> no;
                        cout << "  Destination:  "; cin >> dest;
                        cout << "  Distance:  "; cin >> dist;
                        fuel = calculate_fuel();
                        cout << endl;
                }

                void display_info()
                {
                        cout << "Flight Information: \n";
                        cout << "  Flight number:  " << no << "\n";
                        cout << "  Destination:  " << dest << "\n";
                        cout << "  Distance:  " << dist << " km \n";
                        cout << "  Fuel required:  " << fuel << " litres \n";
                        cout << endl;
                }
};

int main()
{
        Flight flight;

        system("clear");

        flight.information_entry();
        flight.display_info();


        return 0;
}