#ifndef CLSUPDATECLIENTSCREAN_H
#define CLSUPDATECLIENTSCREAN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsUpdateClientScrean : protected clsScreen
{
    public:
         clsUpdateClientScrean();
        virtual ~ clsUpdateClientScrean();

        static void ShowUpdateClient()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pUpdateClient))
            {
                return; /// exit and not continue
            }
            _DrawScreenHeader("\t   Update Client Screen");
            string AccountNumber = "";
            cout << "\n\n\tKindly enter client account number : ";
            AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\n\tAccount number is not found, Kindly rewrite another one : ";
                AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            cout << "\n\tYour entered [ " + AccountNumber + " ] is existing account number! Would you like to continue ? y/n ? ";
            char answer ='n'; cin>>answer;
            if(!clsInputValidate::AnswerYesNo(answer))
            {
                cout << "\n\n\tError : Updating an account of [ " + AccountNumber + " ] was canceled !\n\n"; return;
            }
            else {
                clsBankClient client = clsBankClient::Find(AccountNumber);
                _PrintClient(client);
                cout << "\n\n\tUpdate Client Info for account number [ " + AccountNumber + " ] ";
                cout << "\n\t--------------------------------------------------------------------";
                //-------------------------------------------------------------------
                /// Can Update Only One element by next line
                ///client.Set_PinCode(clsInputValidate::ReadString()); client.Save();
                //-------------------------------------------------------------------
                _ReadClientInfo(client);
                clsBankClient::enSaveResults SaveResult;
                SaveResult = client.Save();
                switch(SaveResult)
                {
                    case clsBankClient::enSaveResults::svSucceded:
                    {
                        cout << "\n\tAccount Updated Successfully :-)\n";
                        _PrintClient(client); break;
                    }
                    case clsBankClient::enSaveResults::svFailAccNumberExist:
                    {
                        cout << "\n\tError : Account was not saved : Acc. is exist!\n";
                        _PrintClient(client); break;
                    }
                    case clsBankClient::enSaveResults::svFailEmptyObject:
                    {
                        cout << "\n\tError : Account was not saved : it's empty!";
                        _PrintClient(client); break;
                    }
                }
            }
        }

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
};

#endif // CLSUPDATECLIENTSCREAN_H
