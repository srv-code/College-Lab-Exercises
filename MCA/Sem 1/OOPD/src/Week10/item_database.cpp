// Author name: Sourav Dey
// Date of creation: 22-OCT-2018
// Week number: 10
// Program name: Items database

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib> // for personal sys compatibility
#include <cstdio> // for debugging

using namespace std;


class Item
{
    private:
        static int code_counter;
        int code, quantity;
        char name[20];
        float price;
        int fill_data(const int c);

    public:
        int accept_data();
        void update_data(const int code);
        void display();
        bool operator==(const int c);
};

class Item_Database
{
    private:
        char db_fname[10];

    public:
        Item_Database(const char* fname);
        void insert(const Item i);
        bool update(const int code);
        bool del(const int code);
        void display_all();
};


Item_Database::Item_Database(const char* fname)
{
    strcpy(db_fname, fname);
}

void Item_Database::insert(const Item i)
{
    ofstream fout(db_fname, ios::app);
    fout.write((char*) &i, sizeof(Item));
    fout.close();
}

bool Item_Database::update(const int code)
{
    fstream file(db_fname, ios::in | ios::out);
    file.seekg(0, ios::beg);

    bool found = false;
    Item i;
    while(file && !found) {
        file.read((char*) &i, sizeof(Item));
        found = (i == code);
    }

    if(found) {
        i.update_data(code);

        file.seekp((long)file.tellg()-sizeof(Item), ios::beg);
        file.write((char*) &i, sizeof(Item));
    }

    file.close();

    return found;
}

bool Item_Database::del(const int code)
{
    char *fname_tmp = "~tmp.dat";
    ifstream file_org(db_fname, ios::ate);
    ofstream file_tmp(fname_tmp);

    long rec_count = file_org.tellg()/sizeof(Item);
    file_org.seekg(0, ios::beg);
    int is_found = 0, was_found = 0;
    Item item;

    for(long i=0; file_org && i<rec_count; i++) {
        file_org.read((char*) &item, sizeof(Item));
        is_found = (item == code);
        was_found |= is_found;
        if(is_found)
            continue; // skip writing to file_tmp, hence deleting
        file_tmp.write((char*) &item, sizeof(Item));
    }

    file_org.close();
    file_tmp.close();

    remove(db_fname);
    rename(fname_tmp, db_fname);

    return was_found;
}

void Item_Database::display_all()
{
    ifstream fin(db_fname, ios::ate);
    long total_entry_count = fin.tellg()/sizeof(Item);
    fin.seekg(0, ios::beg);
    Item item;
    cout << "Total item entries:  " << total_entry_count << endl;
    for(long i=0; fin && i<total_entry_count; i++) {
        fin.read((char*) &item, sizeof(Item));
        item.display();
        cout << endl;
    }
    fin.close();
}


int Item::code_counter;

bool Item::operator==(const int c)
{
    return code == c;
}

int Item::fill_data(const int c = -1)
{
    if(c == -1)
        cout << "Input item details:" << endl;
    else
        cout << "Update item details (code=" << code << "):" << endl;
    cin.ignore();
    cout << "  Name:  "; cin.getline(name, sizeof(name));
    cout << "  Unit price:  "; cin >> price;
    cout << "  Quantity in hand:  "; cin >> quantity;

    if(c == -1)
        code = ++code_counter;

    return code;
}

void Item::update_data(const int code)
{
    fill_data(code);
}

int Item::accept_data()
{
    return fill_data();
}

void Item::display()
{
    cout    << "Item details:"
            << "\n  Code:  " << code
            << "\n  Name:  " << name
            << "\n  Price:  " << price
            << "\n  Quantity in hand:  " << quantity
            << endl;
}



int main()
{
    system("clear");

    Item i;
    Item_Database db("items.db");

    int choice, code;
    do {
        cout    << "\n\n:: Menu ::"
                << "\n  1  Add item"
                << "\n  2  Update item"
                << "\n  3  Delete item"
                << "\n  4  Display all items"
                << "\n  5  Exit"
                << "\nChoice:  ";
        cin >> choice;
        switch(choice) {
            case 1: // add
                code = i.accept_data();
                cout << "  Item code:  " << code << endl;
                db.insert(i);
                cout << "Item successfully added!" << endl;
                break;

            case 2: // update
                cout << "Enter item code:  "; cin >> code;
                if(db.update(code))
                    cout << "Item successfully updated!" << endl;
                else
                    cout << "Error: Item not found!" << endl;
                break;

            case 3: // delete
                cout << "Enter item code:  "; cin >> code;
                if(db.del(code))
                    cout << "Item successfully deleted!" << endl;
                else
                    cout << "Error: Item not found!" << endl;
                break;

            case 4: // display all
                cout << "\nItems in database:" << endl;
                db.display_all();
                break;

            case 5: // exit
                break;

            default:
                cout << "Error: Enter a valid response!" << endl;
        }
    } while(choice != 5);


    return 0;
}