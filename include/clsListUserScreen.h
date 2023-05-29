#ifndef CLSLISTUSERSCREEN_H
#define CLSLISTUSERSCREEN_H

#include "clsScreen.h"
#include "clsUsers.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsListUserScreen : protected clsScreen
{
    public:
        clsListUserScreen();
        virtual ~clsListUserScreen();

        static void ShowUsersList()
        {
            vector<clsUsers> vUsers = clsUsers::GetUsersList();
            string Title = "\t     Users List Screen ";
            string subTitle = "\t       (" + to_string(vUsers.size()) + ") User(s)\n";
            _DrawScreenHeader(Title, subTitle);
            cout << endl << setw(8) << left << ""
                 << "-------------------------------------------------------------------";
            cout << "-------------------------------------------------------------------\n"<< endl;
            cout << setw(8) << left << "" << "\t| " << left << setw(11)  << "User ID";
            cout << "| " << left << setw(30) << "Full Name";
            cout << "| " << left << setw(15) << "Phone";
            cout << "| " << left << setw(30) << "Email";
            cout << "| " << left << setw(15)  << "Password";
            cout << "| " << left << setw(11) << "Permissions";
            cout << endl << endl << setw(8) << left << ""
                 << "-------------------------------------------------------------------";
            cout << "-------------------------------------------------------------------\n"<< endl;
            if(vUsers.size() == 0 )
            { cout << "\n\t\t\tNo Users Available In the System!"; }
            else
            {
                for(clsUsers user : vUsers)
                {
                    PrintUserRecordLine(user); cout << endl;
                }
            }
            cout << endl << setw(8) << left << ""
                 << "-------------------------------------------------------------------";
            cout << "-------------------------------------------------------------------\n"<< endl;
        }

    protected:

    private:

        static void PrintUserRecordLine(clsUsers user)
        {
            cout << setw(8) << left << "" << "\t| " << left << setw(11)  << user.Get_Username();
            cout << "| " << left << setw(30) << user.FullName();
            cout << "| " << left << setw(15) << user.Get_Phone();
            cout << "| " << left << setw(30) << user.Get_Email();
            cout << "| " << left << setw(15)  << user.Get_Password();
            cout << "| " << left << setw(11) << user.Get_Permession();
        }
};

#endif // CLSLISTUSERSCREEN_H
