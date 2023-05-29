#ifndef CLSDEPOSITSSCREEN_H
#define CLSDEPOSITSSCREEN_H

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDepositsScreen.h"
#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsDepositsScreen : protected clsScreen
{
    public:
        clsDepositsScreen();
        virtual ~clsDepositsScreen();

        static void ShowDepositsScreen()
        {
            _DrawScreenHeader("\t      Deposits Screen");
            string AccountNumber = "";  double amount = 0;
            cout << "\n\n\tKindly enter client account number : ";
            AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\n\tAccount number is not found, Kindly rewrite another one : ";
                AccountNumber = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            clsBankClient client = clsBankClient::Find(AccountNumber);
            _PrintClient(client);
            cout << "\n\n\tKindly enter a deposit amount : ";
            amount = clsInputValidate::ReadDblNumber();
            cout << "\n\n\tAre you sure want continue this performing ? y/n ? ";
            char answer ='n'; cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                client.Deposit(amount);
                cout << "\n\tAmount deposited successfully :-) \n";
                cout << "\n\tYour new balance = " << client.Get_AccountBalance() << endl << endl;
            } else {
                cout << "\n\tDeposited Operation was canceled ! \n";
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
            cout << "\n\n\t----------------------------------";
        }
};

#endif // CLSDEPOSITSSCREEN_H
