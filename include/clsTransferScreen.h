#ifndef CLSTRANSFERSCREEN_H
#define CLSTRANSFERSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsDepositsScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsTransferScreen : protected clsScreen
{
    public:
        clsTransferScreen();
        virtual ~clsTransferScreen();

            static void ShowTransfer()
            {
                system("clear");
                _DrawScreenHeader("\t      Transfer Screen");
                string sAccountNumber = "";  double amount = 0;
                cout << "\n\n\tKindly enter source client account number : ";
                sAccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
                while(!clsBankClient::IsClientExist(sAccountNumber))
                {
                    cout << "\n\tAccount number is not found, Kindly rewrite another one : ";
                    sAccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
                }
                clsBankClient sclient = clsBankClient::Find(sAccountNumber);
                _PrintClient(sclient);
                string dAccountNumber = "";
                cout << "\n\n\tKindly enter destination client account number : ";
                dAccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
                while(!clsBankClient::IsClientExist(dAccountNumber))
                {
                    cout << "\n\tAccount number is not found, Kindly rewrite another one : ";
                    dAccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
                }
                clsBankClient dclient = clsBankClient::Find(dAccountNumber);
                _PrintClient(dclient);
                cout << "\n\n\tKindly enter an amount to transfer : ";
                amount = clsInputValidate::ReadDblNumber();
                while(amount > sclient.Get_AccountBalance())
                {
                    cout << "\n\tBalance NOT enough!! Kindly reenter an amount to transfer : ";
                    amount = clsInputValidate::ReadDblNumber();
                }
                cout << "\n\n\tAre you sure want continue this transfer ? y/n ? ";
                char answer ='n'; cin>>answer;
                if(clsInputValidate::AnswerYesNo(answer))
                {
                    sclient.Transfer(amount, dclient);
                    cout << "\n\tTransfer Operation was done successfully :-) \n";
                } else {
                    cout << "\n\tTransfer Operation was canceled ! \n";
                }
                _PrintClient(sclient);
                cout << endl << endl;
                _PrintClient(dclient);
            }

    protected:

    private:

        static void _PrintClient(clsBankClient client)
        {
            cout << "\n\n\tClient Card: ";
            cout << "\n\t----------------------------------";
            cout << "\n\n\tAcc. Number  : " << client.Get_AccountNumber();
            cout << "\n\tFull  Name   : "   << client.FullName();
            cout << "\n\tAcc. Balance : "   << client.Get_AccountBalance();
            cout << "\n\n\t----------------------------------";
        }
};

#endif // CLSTRANSFERSCREEN_H
