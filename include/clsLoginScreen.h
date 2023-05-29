#ifndef CLSLOGINSCREEN_H
#define CLSLOGINSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUsers.h"
#include "UGlobal.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsLoginScreen : protected clsScreen
{
    private:

        static bool _Login()
        {
            bool LoginFaild = false;
            string Username, Password;
            unsigned counter = 3;
            Current_user = clsUsers::Find("","");
            do
            {
                if(LoginFaild)
                {
                    cout << "\n\tInvalid Username / Password !\n";  --counter;
                    cout << "\n\tLeft " << counter << " trail" << endl;
                    if(counter == 0 )
                    {   cout << "\n\tNo more trails for you!" << endl; return false;    }
                }
                cout << "\n\tEnter Username ? ";
                Username = clsInputValidate::UpperString(clsInputValidate::ReadString());;
                cout << "\n\tEnter Password ? "; cin>>Password;
                Current_user = clsUsers::Find(Username,Password);
                LoginFaild = Current_user.IsEmpty();
            } while (LoginFaild);
            Current_user.RegisterLogin();
            clsMainScreen::ShowMainMenue();
            return true;
        }

    public:
        clsLoginScreen();
        virtual ~clsLoginScreen();

        static bool ShowLoginScreen()
        {
            system("clear");
            _DrawScreenHeader("\t      Login Screen! ");
            _Login();
            return false;
        }
};

#endif // CLSLOGINSCREEN_H
