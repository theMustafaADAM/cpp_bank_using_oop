#ifndef CLSDELETECLIENTSCREEN_H
#define CLSDELETECLIENTSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
    public:
        clsDeleteClientScreen();
        virtual ~clsDeleteClientScreen();

        static void ShowDeleteClient()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pDeleteClient))
            {
                return; /// exit and not continue
            }
            _DrawScreenHeader("\t Delete Client Screen");
            string AccountNumber = "";
            cout << "\n\n\tKindly enter client account number : ";
            AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\n\tAccount number is not found, Kindly rewrite another one : ";
                AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            clsBankClient client = clsBankClient::Find(AccountNumber);
            _PrintClient(client);
            cout << "\n\n\tAre you sure delete this Account ? 'y' / any ? ";
            char answer ='n'; cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                if(client.Delete())
                {
                    cout << "\n\tClient deleted successfully :-) \n";
                    _PrintClient(client);
                }
                else
                {
                    cout << "\n\tError : Client was not deleted !\n";
                }
            } else {
                cout << "\n\n\tError : Deleting an account of [ " + AccountNumber + " ] was canceled !\n\n";
            }
        }

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
            cout << "\n\n\t----------------------------------";
        }
};

#endif // CLSDELETECLIENTSCREEN_H
