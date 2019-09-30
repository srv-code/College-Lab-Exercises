// Author name: Sourav Dey
// Date of creation: 17-SEPT-2018
// Week number: 5
// Proram name: Create and implement increment operator in a Date class

#include <iostream>

using namespace std;

class Date
{
        private:
                int day, mon, yr;

                int is_leap_year()
                {
                        int res = 0;
                        if(yr <= 0)
                                return -1;
                        if(yr % 4 == 0) {
                                res = 1;
                                if(yr % 100 == 0)
                                        if(yr % 400 > 0)
                                                res = 0;
                        }
                        return res;
                }

        public:
                Date(const int d, const int m, const int y)
                {
                        day = d;
                        mon = m;
                        yr = y;
                }

                Date operator++()
                {
                        if(mon == 1 || mon == 3 || mon == 5 || mon == 7 ||
                                mon == 8 || mon == 10 || mon == 12) { // months with 31 days
                                if(day == 31) {
                                        day = 1;
                                        if(mon == 12) {
                                                mon = 1;
                                                yr++;
                                        } else
                                                mon++;
                                } else
                                        day++;
                        } else if(mon == 4 || mon == 6 ||
                                        mon == 9 || mon == 11) { // months with 30 days
                                if(day == 30) {
                                        day = 1;
                                        mon++;
                                }

                        } else { // feb found
                                if(day == 28) {
                                        if(is_leap_year())
                                                day = 29;
                                        else {
                                                day = 1;
                                                mon = 3;
                                        }
                                } else if(day == 29) {
                                        day = 1;
                                        mon = 3;
                                } else
                                        day++;
                        }

                        return *this;
                }

                void show()
                {
                        printf("%02d-%02d-%04d \n", day, mon, yr);
                }
};

int main()
{
        system("clear");

        int d, m, y;

        cout << "Enter date: " << endl;
        cout << "  Day:    "; cin >> d;
        cout << "  Month:  "; cin >> m;
        cout << "  Year:   "; cin >> y;

        Date date(d, m, y);

        cout << "Old date:  ";
        date.show();

        cout << "Incrementing date by 1..." << endl;

        ++date;

        cout << "New date:  ";
        date.show();

        return 0;
}