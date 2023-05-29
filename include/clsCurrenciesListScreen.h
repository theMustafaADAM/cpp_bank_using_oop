#ifndef CLSCURRENCIESLISTSCREEN_H
#define CLSCURRENCIESLISTSCREEN_H

#include "clsScreen.h"
#include "clsCurrency.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
    public:
        clsCurrenciesListScreen();
        virtual ~clsCurrenciesListScreen();

        static void ShowCurrenciesList()
        {
            vector<clsCurrency> vcurrency = clsCurrency::GetCurrenciesList();
            string Title = "\t   Currencies List Screen ";
            string subTitle = "\t     (" + to_string(vcurrency.size()) + ") Currencies.\n";
            _DrawScreenHeader(Title, subTitle);
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            cout << setw(8) << left << "" << "\t| " << left << setw(35)  << "Country";
            cout << "| " << left << setw(12) << "Code";
            cout << "| " << left << setw(45) << "Currency Name";
            cout << "| " << left << setw(12) << "Rate";
            cout << endl << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            if(vcurrency.size() == 0 )
            { cout << "\n\t\t\tNo Users Available In the System!"; }
            else
            {
                for(clsCurrency c : vcurrency)
                {
                    _PrintCurrenciesList(c); cout << endl;
                }
            }
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
        }

    protected:

    private:

        static void _PrintCurrenciesList(clsCurrency curncy)
        {
            cout << setw(8) << left << "" << "\t| " << left << setw(35)  << curncy.Get_Country();
            cout << "| " << left << setw(12) << curncy.Get_CurrencyCode();
            cout << "| " << left << setw(45) << curncy.Get_CurrencyName();
            cout << "| " << left << setw(12) << curncy.Get_Rate();
        }
};

#endif // CLSCURRENCIESLISTSCREEN_H
