#ifndef CLSWITHDRAWSSCREEN_H
#define CLSWITHDRAWSSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsDepositsScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsWithdrawsScreen : protected clsScreen
{
    public:
        clsWithdrawsScreen();
        virtual ~clsWithdrawsScreen();

        static void ShowWithdrawsScreen()
        {
            _DrawScreenHeader("\t    Withdrawals Screen");
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
            cout << "\n\n\tKindly enter an amount to withdrawal : ";
            amount = clsInputValidate::ReadDblNumber();
            while(amount > client.Get_AccountBalance())
            {
                cout << "\n\tBalance NOT enough!! Kindly reenter an amount to withdrawal : ";
                amount = clsInputValidate::ReadDblNumber();
            }
            cout << "\n\n\tAre you sure want continue this withdrawal ? y/n ? ";
            char answer ='n'; cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                client.Withdraw(amount);
                cout << "\n\tWithdrawal Operation was done successfully :-) \n";
                cout << "\n\tYour new balance = " << client.Get_AccountBalance() << endl << endl;
            } else {
                cout << "\n\tWithdrawal Operation was canceled ! \n";
                cout << "\n\tYour balance = " << client.Get_AccountBalance() << endl << endl;
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

#endif // CLSWITHDRAWSSCREEN_H
