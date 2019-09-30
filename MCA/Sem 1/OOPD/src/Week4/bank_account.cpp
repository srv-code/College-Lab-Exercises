// Author name: Sourav Dey
// Date of creation: 27-AUG-2018
// Week number: 4
// Program name: Create and display bank account information from and to user

#include <iostream>

#include <cstdlib> // remove

using namespace std;

class Bank_Account
{
        public:
                const static int NAME_LEN = 20;
                enum account_type { SAVINGS, FIXED, CURRENT };

        private:
                static long acc_count;
                char cust_name[NAME_LEN];
                long acc_no;
                float bal;
                enum account_type acc_type;

        public:
                Bank_Account()
                {
                        Bank_Account("no-name", 100.0, CURRENT);
                }

                Bank_Account(   const char n[],
                                const float b, 
                                const enum account_type t) : bal(b), acc_type(t)
                {
                        acc_no = ++acc_count;
                        // initialize cust_name from n
                        int i, len;
                        for(i=0, len=NAME_LEN-1; i<len && n[i]!=0; i++)
                            cust_name[i] = n[i];
                        cust_name[i] = 0;
                }

                int deposit_amount(const float a)
                {
                        if(a <= 0.0)
                            return -1;

                        bal += a;
                        return 0;
                }

                friend int withdraw_amount(Bank_Account*, const float);

                void display()
                {
                        cout << "Account Information: \n";
                        cout << "  Name:  " << cust_name << "\n";
                        cout << "  Balance:  " << bal << "\n";
                        cout << endl;
                }
};

long Bank_Account::acc_count = 0;


int withdraw_amount(Bank_Account* acc, const float a)
{
        if(a <= 0.0 || a > acc->bal)
                return -1;

        acc->bal -= a;
        return 0;
}


int main()
{
        system("clear");

        Bank_Account account;
        int continue_input = 1, choice, acc_opened = 0;
        char name[Bank_Account::NAME_LEN];
        int acc_type;
        float amt;

        while(continue_input)
        {
                cout << "\n\nBanking options: \n";
                cout << "    1  Open an account \n";
                cout << "    2  Deposit amount \n";
                cout << "    3  Withdraw amount \n";
                cout << "    4  Display information \n";
                cout << "    5  Exit \n";
                cout << "Enter choice:  ";
                cin >> choice;

                switch(choice)
                {
                        case 1: // Open an account
                                if(acc_opened)
                                {
                                        cout << "Account already opened! \n";
                                        break;
                                }

                                cout << "Enter account holder information: \n";
                                cout << "  Name:  "; cin >> name;
                                cout << "  Balance:  "; cin >> amt;
                                cout << "  Account type: \n";

                                while(continue_input)
                                {
                                        cout << "    1  Savings \n";
                                        cout << "    2  Fixed \n";
                                        cout << "    3  Current \n";
                                        cout << "  Enter choice:  "; cin >> choice;

                                        if(continue_input = (choice < 1 || choice > 3) )
                                                cout << "Error: Invalid choice entered! Try again. \n";
                                }

                                account = Bank_Account(name, amt, (choice == 1) ? 
                                            Bank_Account::SAVINGS : ( (choice == 2) ? 
                                                Bank_Account::FIXED : Bank_Account::CURRENT ) );
                                cout << "Account created successfully! \n";
                                acc_opened = 1;
                                continue_input = 1; // reset for main loop

                                break;

                        case 2: // Deposit amount
                                if(!acc_opened)
                                {
                                        cout << "Error: Kindly open an account first! \n";
                                        break;
                                }

                                cout << "Enter amount:  "; cin >> amt;
                                if(account.deposit_amount(amt))
                                    cout << "Error: Invalid amount entered! \n";
                                else 
                                    cout << "Amount deposited successfully. \n";

                                break;

                        case 3: // Withdraw amount
                                if(!acc_opened)
                                {
                                        cout << "Error: Kindly open an account first! \n";
                                        break;
                                }

                                cout << "Enter amount:  "; cin >> amt;
                                if(withdraw_amount(&account, amt))
                                    cout << "Error: Invalid amount entered! \n";
                                else    
                                    cout << "Amount withdrawn successfully. \n";

                                break;

                        case 4: // Display information
                                if(!acc_opened)
                                {
                                        cout << "Error: Kindly open an account first! \n";
                                        break;
                                }

                                account.display(); 
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