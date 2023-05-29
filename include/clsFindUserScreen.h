#ifndef CLSFINDUSERSCREEN_H
#define CLSFINDUSERSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsers.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsFindUserScreen : protected clsScreen
{
    public:
        clsFindUserScreen();
        virtual ~clsFindUserScreen();

        static void ShowFindUserScreen()
        {
            _DrawScreenHeader("\t     Find User Data!");
            string Username = "";
            cout << "\n\n\tKindly enter Username : ";
            Username = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsUsers::IsUserExist(Username))
            {
                cout << "\n\tUsername is not found, Kindly rewrite another one : ";
                Username = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            clsUsers user = clsUsers::Find(Username);
            if(!user.IsEmpty())
            {
                cout << "\n\tUser's Data Found successfully :-) \n";
                    _PrintUser(user); return;
            } else
            {
                cout << "\n\tError : User's Data was not Found !\n";
            }
        }

    protected:

    private:

        static void _PrintUser(clsUsers user)
        {
            cout << "\n\n\tUser Card: ";
            cout << "\n\t----------------------------------";
            cout << "\n\n\tUsername     : " << user.Get_Username();
            cout << "\n\n\tFirst Name   : " << user.Get_FrstName();
            cout << "\n\tLast  Name   : "   << user.Get_LastName();
            cout << "\n\tFull  Name   : "   << user.FullName();
            cout << "\n\n\tEmail        : " << user.Get_Email();
            cout << "\n\tPhone        : "   << user.Get_Phone();
            cout << "\n\n\tPassword     : " << user.Get_Password();
            cout << "\n\tPermissions  : "   << user.Get_Permession();
            cout << "\n\n\t----------------------------------";
        }
};

#endif // CLSFINDUSERSCREEN_H
