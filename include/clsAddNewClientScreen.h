#ifndef CLSADDNEWCLIENTSCREEN_H
#define CLSADDNEWCLIENTSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
    private:
        static void _ReadClientInfo(clsBankClient& client)
        {
            cout << "\n\n\tEnter First Name       : " ; client.Set_FrstName(clsInputValidate::ReadString());
            cout << "\n\tEnter Last  Name       : " ; client.Set_LastName(clsInputValidate::ReadString());
            cout << "\n\tEnter the Email        : " ; client.Set_Email(clsInputValidate::ReadString());
            cout << "\n\tEnter the Phone        : " ; client.Set_Phone(clsInputValidate::ReadString());
            cout << "\n\tEnter the Password     : " ; client.Set_PinCode(clsInputValidate::ReadString());
            cout << "\n\tEnter the initiate Balance : " ; client.Set_AccountBalance(clsInputValidate::ReadDblNumber());
            cout << "\n\t----------------------------------";
        }

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

    public:
        clsAddNewClientScreen();
        virtual ~clsAddNewClientScreen();

        static void ShowAddNewClientScreen()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pAddNewClient))
            {
                return; /// exit and not continue
            }
            _DrawScreenHeader("\t  Add New Client Screen");
            string AccountNumber = "";
            cout << "\n\n\tFirst, Let's check if chosen account number existing! ";
            cout << "\n\n\tKindly enter new client account number : ";
            AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\n\tThe entered account number is already exist, Kindly write a new one : ";
                AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            cout << "\n\n\tYour entered [ " + AccountNumber + " ] is new account number! Would you like to continue ? y/n : ";
            char answer ='n'; cin>>answer;
            if(!clsInputValidate::AnswerYesNo(answer))
            {
                cout << "\n\n\tError : Adding a new account was canceled !\n\n"; return;
            }
            else {
                clsBankClient newClient = clsBankClient::GetAddNewClientObject(AccountNumber);
                cout << "\n\n\tAdd New Client Info under account no. [ " + AccountNumber + " ] : ";
                cout << "\n\n\t----------------------------------";
                _ReadClientInfo(newClient);
                clsBankClient::enSaveResults SaveResult;
                SaveResult = newClient.Save();
                switch(SaveResult)
                {
                    case clsBankClient::enSaveResults::svSucceded:
                    {
                        cout << "\n\n\tAccount Added Successfully :-)\n";
                        _PrintClient(newClient); break;
                    }
                    case clsBankClient::enSaveResults::svFailAccNumberExist:
                    {
                        cout << "\n\n\tError : Account was not saved : Acc. is exist!\n"; break;
                    }
                    case clsBankClient::enSaveResults::svFailEmptyObject:
                    {
                        cout << "\n\n\tError : Account was not saved : it's empty!"; break;
                    }
                }
            }
        }
};

#endif // CLSADDNEWCLIENTSCREEN_H
