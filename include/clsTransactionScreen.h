#ifndef CLSTRANSACTIONSCREEN_H
#define CLSTRANSACTIONSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsTransferRecordsScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsWithdrawsScreen.h"
#include "clsDepositsScreen.h"
#include "clsTransferScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsTransactionScreen : protected clsScreen
{
    private:

        enum enTransactionMenuOptions{ eDeposits = 1, eWithdraws = 2, eShowTotalBalances = 3, eTransfer = 4, eTransferRecords = 5 , eShowMainMenue = 6 };
        static short _ReadTransactionMenueOption()
        {
            cout << setw(37) << left << "" << "\tChoose what you want to do ? [ 1 to 6 ] ? ";
            short  choice = clsInputValidate::ReadIntNumberBetween(1,6, "\n\t\t\t\t\tKindly Enter ONLY Between      1 to 6 !   ");
            return choice;
        }

        static void _GoBackToTransactionMenue()
        {
            cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Transaction Menu ... \n" << endl;
            cin.ignore(); cin.get();
            ShowTransactionMenue();
        }

        static void _ShowDepositsScreen()
        {
            clsDepositsScreen::ShowDepositsScreen();
        }

        static void _ShowWithdrawsScreen()
        {
            clsWithdrawsScreen::ShowWithdrawsScreen();
        }

        static void _ShowTotalBalancesScreen()
        {
            clsTotalBalancesScreen::ShowTotalBalances();
        }

        static void _ShowTransferScreen()
        {
            clsTransferScreen::ShowTransfer();
        }

        static void _ShowTransferRecordsScreen()
        {
            clsTransferRecordsScreen::ShowTransferRecords();
        }

        static void _ShowMainMenueScreen()
        {
            cout << "\n\t\t\t\t\tBack to Main Screen Now ... \n" << endl;
        }

        static void _PerformTransactionMenueOption(enTransactionMenuOptions TransMenueOption)
        {
            switch (TransMenueOption)
            {
                case enTransactionMenuOptions::eDeposits:
                {
                    system("clear"); _ShowDepositsScreen(); _GoBackToTransactionMenue();
                     break;
                }
                case enTransactionMenuOptions::eWithdraws:
                {
                    system("clear"); _ShowWithdrawsScreen(); _GoBackToTransactionMenue();
                    break;
                }
                case enTransactionMenuOptions::eShowTotalBalances:
                {
                    system("clear"); _ShowTotalBalancesScreen(); _GoBackToTransactionMenue();
                    break;
                }
                case enTransactionMenuOptions::eTransfer:
                {
                    system("clear"); _ShowTransferScreen(); _GoBackToTransactionMenue();
                    break;
                }
                case enTransactionMenuOptions::eTransferRecords:
                {
                    system("clear"); _ShowTransferRecordsScreen(); _GoBackToTransactionMenue();
                    break;
                }
                case enTransactionMenuOptions::eShowMainMenue:
                {
                    break;
                }
            }
        }

    public:

        clsTransactionScreen();
        virtual ~clsTransactionScreen();

        static void ShowTransactionMenue()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pTransactions))
            {
                return; /// exit and not continue
            }
            system("clear");
            _DrawScreenHeader("\t Transaction Menu Screen");
            cout << endl << endl;
            cout << setw(37) << left << "" << "\t    Transaction Menu :" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n\n" << endl;
            cout << setw(37) << left << "" << "\t[1]  Deposits. " << endl;
            cout << setw(37) << left << "" << "\t[2]  Withdrawals. " << endl;
            cout << setw(37) << left << "" << "\t[3]  Total Balances. " << endl;
            cout << setw(37) << left << "" << "\t[4]  Transfers. " << endl;
            cout << setw(37) << left << "" << "\t[5]  Transfers Records. " << endl;
            cout << setw(37) << left << "" << "\t[6]  Main Menu. \n" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n" << endl;
            _PerformTransactionMenueOption((enTransactionMenuOptions)_ReadTransactionMenueOption());
        }

};

#endif // CLSTRANSACTIONSCREEN_H
