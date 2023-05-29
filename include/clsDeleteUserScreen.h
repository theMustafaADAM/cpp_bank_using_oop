#ifndef CLSDELETEUSERSCREEN_H
#define CLSDELETEUSERSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsers.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
    public:
        clsDeleteUserScreen();
        virtual ~clsDeleteUserScreen();

        static void ShowDeleteUser()
        {
            _DrawScreenHeader("\t Delete User Screen");
            string Username = "";
            cout << "\n\n\tKindly enter Username : ";
            Username = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsUsers::IsUserExist(Username))
            {
                cout << "\n\tUsername is not found, Kindly rewrite another one : ";
                Username = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            clsUsers user = clsUsers::Find(Username);
            _PrintUser(user);
            cout << "\n\n\tAre you sure delete this User ? 'y' / any ? ";
            char answer ='n'; cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                if(user.Delete())
                {
                    cout << "\n\tUser deleted successfully :-) \n";
                    _PrintUser(user);
                }
                else
                {
                    cout << "\n\tError : User was not deleted !\n";
                }
            } else {
                cout << "\n\n\tError : Deleting User of [ " + Username + " ] was canceled !\n\n";
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

#endif // CLSDELETEUSERSCREEN_H
