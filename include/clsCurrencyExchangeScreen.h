#ifndef CLSCURRENCYEXCHANGESCREEN_H
#define CLSCURRENCYEXCHANGESCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsCurrencyCalculatorScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
    public:
        clsCurrencyExchangeScreen();
        virtual ~clsCurrencyExchangeScreen();

        static void ShowCurrencyExchangeMenue()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pCurrencyExchange))
            {
                return; /// exit and not continue
            }
            system("clear");
            _DrawScreenHeader("\t  Currency Exchange Screen");
            cout << endl << endl;
            cout << setw(37) << left << "" << "\t    Currency Exchange Menu :" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n\n" << endl;
            cout << setw(37) << left << "" << "\t[1]  Currencies List. " << endl;
            cout << setw(37) << left << "" << "\t[2]  Find Currency. " << endl;
            cout << setw(37) << left << "" << "\t[3]  Update Rate. " << endl;
            cout << setw(37) << left << "" << "\t[4]  Currency Calculator. " << endl;
            cout << setw(37) << left << "" << "\t[5]  Main Menu. \n" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n" << endl;
            _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenueOption());
        }

    protected:

    private:

        enum enCurrencyExchangeMenuOptions{ eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCalculator = 4, eMainMenue = 5 };

        static short _ReadCurrencyExchangeMenueOption()
        {
            cout << setw(37) << left << "" << "\tChoose what you want to do ? [ 1 to 5 ] ? ";
            short  choice = clsInputValidate::ReadIntNumberBetween(1,5, "\n\t\t\t\t\tKindly Enter ONLY Between      1 to 5 !   ");
            return choice;
        }

        static void _GoBackToCurrencyExchangeMenue()
        {
            cout << setw(37) << left << "" << "\n\t\t\t\t\t\tPress any key to go back to Manage User Menu ... \n" << endl;
            cin.ignore(); cin.get();
            ShowCurrencyExchangeMenue();
        }

        static void _ShowAllCurrencyScreen()
        {
            clsCurrenciesListScreen::ShowCurrenciesList();
        }

        static void _ShowUpdateRateScreen()
        {
            clsUpdateRateScreen::ShowUpdateRate();
        }

        static void _ShowFindCurrencyScreen()
        {
            clsFindCurrencyScreen::ShowFindCurrency();
        }

        static void _ShowCurrencyCalculatorScreen()
        {
            clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
        }

        static void _BackMainScreen()
        {
            cout << "\n\n\n\t\t\t\t\t\tBack Currency Exchange Menu Screen Will be here ... \n" << endl;
        }

        static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenueOption)
        {
            switch (CurrencyExchangeMenueOption)
            {
                case enCurrencyExchangeMenuOptions::eListCurrencies:
                {
                    system("clear"); _ShowAllCurrencyScreen(); _GoBackToCurrencyExchangeMenue();
                     break;
                }
                case enCurrencyExchangeMenuOptions::eFindCurrency:
                {
                    system("clear"); _ShowFindCurrencyScreen(); _GoBackToCurrencyExchangeMenue();
                    break;
                }
                case enCurrencyExchangeMenuOptions::eUpdateRate:
                {
                    system("clear"); _ShowUpdateRateScreen(); _GoBackToCurrencyExchangeMenue();
                    break;
                }
                case enCurrencyExchangeMenuOptions::eCalculator:
                {
                    system("clear"); _ShowCurrencyCalculatorScreen(); _GoBackToCurrencyExchangeMenue();
                    break;
                }
                case enCurrencyExchangeMenuOptions::eMainMenue:
                {
                    break;
                }
            }
        }
};

#endif // CLSCURRENCYEXCHANGESCREEN_H
