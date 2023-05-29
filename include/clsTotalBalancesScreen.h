#ifndef CLSTOTALBALANCESSCREEN_H
#define CLSTOTALBALANCESSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsDepositsScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
    public:
        clsTotalBalancesScreen();
        virtual ~clsTotalBalancesScreen();

        static void ShowTotalBalances()
        {
            vector<clsBankClient> vClients = clsBankClient::GetClientsList();
            string Title = "\t   Total Balances Screen ";
            string subTitle = "\t     (" + to_string(vClients.size()) + ") Client(s)\n";
            _DrawScreenHeader(Title, subTitle);
            cout << endl << setw(8) << left << ""
                 << "----------------------------------------------------";
            cout << "----------------------------------------------------\n"<< endl;
            cout << setw(8) << left << "" << "\t| " << left << setw(11)  << "Acc. ID";
            cout << "\t    | " << left << setw(28) << "Client Name  ";
            cout << "\t    | " << left << setw(11) << "Balance";
            cout << endl << endl << setw(8) << left << ""
                 << "----------------------------------------------------";
            cout << "----------------------------------------------------\n"<< endl;
            if(vClients.size() == 0 )
            { cout << "\n\t\t\tNo Clients Available In the System!"; }
            else
            {
                for(clsBankClient client : vClients)
                {
                    _PrintBalanceRecordLine(client); cout << endl;
                }
            }
            cout << endl << setw(8) << left << ""
                 << "----------------------------------------------------";
            cout << "----------------------------------------------------\n"<< endl;
            double TotalBalances = clsBankClient::GetTotalBalances();
            cout << endl << setw(8) << left << ""
                 << "The Total of Balances =  " << TotalBalances << "  SAR. " << endl;

            cout << endl << setw(8) << left << ""
            << "Only ( " << clsUtil::NumberToText(TotalBalances) << " ) Saudi Riyals. " << endl;
        }

    protected:

    private:

        static void _PrintBalanceRecordLine(clsBankClient client)
        {
            cout << "\t\t| " << left << setw(18)  << client.Get_AccountNumber();
            cout << "| " << left << setw(38) << client.FullName();
            cout << "| " << left << setw(22) << client.Get_AccountBalance();
        }
};

#endif // CLSTOTALBALANCESSCREEN_H
