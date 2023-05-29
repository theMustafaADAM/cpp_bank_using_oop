#ifndef CLSFINDCLIENTSCREEN_H
#define CLSFINDCLIENTSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsFindClientScreen : protected clsScreen
{
    public:
        clsFindClientScreen();
        virtual ~clsFindClientScreen();

        static void ShowFindClientScreen()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pFindClient))
            {
                return; /// exit and not continue
            }
            _DrawScreenHeader("\t     Find Client Data!");
            string AccountNumber = "";
            cout << "\n\n\tKindly enter client account number : ";
            AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\n\tAccount number is not found, Kindly rewrite another one : ";
                AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            clsBankClient client = clsBankClient::Find(AccountNumber);
            if(!client.IsEmpty())
            {
                cout << "\n\tClient's Data Found successfully :-) \n";
                    _PrintClient(client); return;
            } else
            {
                cout << "\n\tError : Client's Data was not Found !\n";
            }
        }

    protected:

    private:
        static void _PrintClient(clsBankClient client)
        {
            cout << "\n\n\tClient Card: ";
            cout << "\n\t----------------------------------";
            cout << "\n\n\tAcc. Number  : " << client.Get_AccountNumber();
            cout << "\n\n\tFirst Name   : " << client.Get_FrstName();
            cout << "\n\tLast  Name   : "   << client.Get_LastName();
            cout << "\n\tFull  Name   : "   << client.FullName();
            cout << "\n\n\tEmail        : " << client.Get_Email();
            cout << "\n\tPhone        : "   << client.Get_Phone();
            cout << "\n\n\tPassword     : " << client.Get_PinCode();
            cout << "\n\tAcc. Balance : "   << client.Get_AccountBalance();
            cout << "\n\n\t----------------------------------" << endl << endl;
        }
};

#endif // CLSFINDCLIENTSCREEN_H
