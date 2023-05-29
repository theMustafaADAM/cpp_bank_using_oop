#ifndef CLSMAINSCREEN_H
#define CLSMAINSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScrean.h"
#include "clsTransactionScreen.h"
#include "clsManageUserScreen.h"
#include "clsFindClientScreen.h"
#include "clsClientListScreen.h"
#include "clsListUserScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsScreen.h"
#include "UGlobal.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsMainScreen : protected clsScreen
{
    private:
        enum enMainMenuOptions{ eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
                                eFindClient = 5, eTransactionsMenue = 6, eManageUser = 7, eLoginRegister = 8, eCurrecny = 9, eExit = 0 };
        static short _ReadMainMenueOption()
        {
            cout << setw(37) << left << "" << "\tChoose what you want to do ? [ 0 to 9 ] ? ";
            short  choice = clsInputValidate::ReadIntNumberBetween(0,9, "\n\t\t\t\t\tKindly Enter ONLY Between      0 to 9 !   ");
            return choice;
        }

        static void _GoBackToMainMenue()
        {
            cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Main Menu ... \n" << endl;
            cin.ignore(); cin.get();
            ShowMainMenue();
        }

        static void _ShowAllClientsScreen()
        {
            clsClientListScreen::ShowClientsList();
        }

        static void _ShowAddNewClientsScreen()
        {
            clsAddNewClientScreen::ShowAddNewClientScreen();
        }

        static void _ShowDeleteClientsScreen()
        {
            clsDeleteClientScreen::ShowDeleteClient();
        }

        static void _ShowUpdateClientsScreen()
        {
            clsUpdateClientScrean::ShowUpdateClient();
        }

        static void _ShowFindClientsScreen()
        {
            clsFindClientScreen::ShowFindClientScreen();
        }

        static void _ShowTransactionMenueScreen()
        {
            clsTransactionScreen::ShowTransactionMenue();
        }

        static void _ShowManageUsersScreen()
        {
            clsManageUserScreen::ShowManageUserMenue();
        }

        static void _ShowLgoinRegisterScreen()
        {
            clsLoginRegisterScreen::ShowLoginRegister();
        }

        static void _ShowCurrencyExchangeScreen()
        {
            clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
        }

        static void _Logout()
        {
            Current_user = clsUsers::Find("","");
        }

        static void _PerformMainMenueOption(enMainMenuOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
                case enMainMenuOptions::eListClients:
                {
                    system("clear"); _ShowAllClientsScreen(); _GoBackToMainMenue();
                     break;
                }
                case enMainMenuOptions::eAddNewClient:
                {
                    system("clear"); _ShowAddNewClientsScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eDeleteClient:
                {
                    system("clear"); _ShowDeleteClientsScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eUpdateClient:
                {
                    system("clear"); _ShowUpdateClientsScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eFindClient:
                {
                    system("clear"); _ShowFindClientsScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eTransactionsMenue:
                {
                    system("clear"); _ShowTransactionMenueScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eManageUser:
                {
                    system("clear"); _ShowManageUsersScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eLoginRegister:
                {
                    system("clear"); _ShowLgoinRegisterScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eCurrecny:
                {
                    system("clear"); _ShowCurrencyExchangeScreen(); _GoBackToMainMenue();
                    break;
                }
                case enMainMenuOptions::eExit:
                {
                   _Logout();
                    break;
                }
            }
        }

    public:
        clsMainScreen();
        virtual ~clsMainScreen();
        static void ShowMainMenue()
        {
            system("clear");
            _DrawScreenHeader("\t\tMain Screen");
            cout << endl << endl;
            cout << setw(37) << left << "" << "\t    Main Menu :" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n\n" << endl;
            cout << setw(37) << left << "" << "\t [1]  Show Clients List. " << endl;
            cout << setw(37) << left << "" << "\t [2]  Add New Client. " << endl;
            cout << setw(37) << left << "" << "\t [3]  Delete Client. " << endl;
            cout << setw(37) << left << "" << "\t [4]  Update Client. " << endl;
            cout << setw(37) << left << "" << "\t [5]  Find Client. " << endl;
            cout << setw(37) << left << "" << "\t [6]  Transactions. " << endl;
            cout << setw(37) << left << "" << "\t [7]  Manage Users. " << endl;
            cout << setw(37) << left << "" << "\t [8]  Login Register." << endl;
            cout << setw(37) << left << "" << "\t [9]  Currency Exchange." << endl;
            cout << setw(37) << left << "" << "\t [0]  Logout. \n" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n" << endl;
            _PerformMainMenueOption((enMainMenuOptions)_ReadMainMenueOption());
        }
};

#endif // CLSMAINSCREEN_H
