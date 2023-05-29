#ifndef CLSFINDCURRENCYSCREEN_H
#define CLSFINDCURRENCYSCREEN_H

#include "clsCurrency.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
    public:
        clsFindCurrencyScreen();
        virtual ~clsFindCurrencyScreen();

        static void ShowFindCurrency()
        {
            _DrawScreenHeader("\t     Find Currency!");
            short chose = 0;
            cout << "\n\n\tKindly Chose to find by [1] Country [2] Currency Code : "; cin>>chose;
            if(chose == 1)
            {
                string fCountry = "";
                cout << "\n\n\tKindly enter Country : ";
                fCountry = clsInputValidate::UpperString(clsInputValidate::ReadString());
                while(!clsCurrency::IsCountryExist(fCountry))
                {
                    cout << "\n\tCountry is not found, Kindly rewrite another one : ";
                    fCountry = clsInputValidate::UpperString(clsInputValidate::ReadString());
                }
                clsCurrency tcurrency = clsCurrency::FindByCountry(fCountry);
                if(!tcurrency.IsEmpty())
                {
                    cout << "\n\tCurrency's Data Found successfully :-) \n";
                    _PrintCurrency(tcurrency); return;
                } else
                {
                    cout << "\n\tError : Country's Data was not Found !\n";
                }
            }
            else
                if(chose == 2)
            {
                string fCurrency = "";
                cout << "\n\n\tKindly enter Currency Code : ";
                fCurrency = clsInputValidate::UpperString(clsInputValidate::ReadString());
                while(!clsCurrency::IsCurrencyExist(fCurrency))
                {
                    cout << "\n\tCurrency Code is not found, Kindly rewrite another one : ";
                    fCurrency = clsInputValidate::UpperString(clsInputValidate::ReadString());
                }
                clsCurrency currency = clsCurrency::FindByCode(fCurrency);
                if(!currency.IsEmpty())
                {
                    cout << "\n\tCurrency's Data Found successfully :-) \n";
                        _PrintCurrency(currency); return;
                } else
                {
                    cout << "\n\tError : Currency's Data was not Found !\n";
                }
            }
        }

    protected:

    private:
        static void _PrintCurrency(clsCurrency currency)
        {
            cout << "\n\t  Currency Card: ";
            cout << "\n\t----------------------------------";
            cout << "\n\n\t  Country    :  " << currency.Get_Country();
            cout << "\n\t  Code       :  "   << currency.Get_CurrencyCode();
            cout << "\n\n\t  Name       :  " << currency.Get_CurrencyName();
            cout << "\n\t  Rate(1$)   =  "   << currency.Get_Rate();
            cout << "\n\n\t----------------------------------" << endl;
        }
};

#endif // CLSFINDCURRENCYSCREEN_H
