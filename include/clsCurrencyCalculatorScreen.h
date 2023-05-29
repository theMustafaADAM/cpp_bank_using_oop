
#ifndef CLSCURRENCYCALCULATORSCREEN_H
#define CLSCURRENCYCALCULATORSCREEN_H

#include "clsCurrency.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
    public:
        clsCurrencyCalculatorScreen();
        virtual ~clsCurrencyCalculatorScreen();

        static void ShowCurrencyCalculator()
        {
            char contnue = 'y';
            while(contnue == 'y' || contnue == 'Y' )
            {
                system("clear");
                _DrawScreenHeader("\t     Currency Calculator!");
                clsCurrency frstcurrency = _GetCurrency("\n\n\tKindly enter the first Currency Code : ");
                clsCurrency scndcurrency = _GetCurrency("\n\n\tKindly enter the second Currency Code : ");
                float amount = _ReadAmount();
                _PrintCalculationResults(amount, frstcurrency, scndcurrency);
                cout << "\n\n\tDo you want to calculate new currency ? [ y / n ] ? "; cin>>contnue;
            }
        }

    private:

        static float _ReadAmount()
        {
            cout << "\n\n\tKindly enter the amount to calculate : ";
            float amount = clsInputValidate::ReadFloatNumber();
            return amount;
        }

        static clsCurrency _GetCurrency(string message)
        {
            string currencycode;
            cout << message;
            currencycode = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(!clsCurrency::IsCurrencyExist(currencycode))
            {
                cout << "\n\tCurrency Code is not found, Kindly rewrite another one : ";
                currencycode = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            clsCurrency currency = clsCurrency::FindByCode(currencycode);
            return currency;
        }

        static void _PrintCalculationResults(float amount, clsCurrency frst, clsCurrency scnd)
        {
            _PrintCurrency(frst, "First Currency");
            float amountINusd = frst.ConvertToUSDCurrency(amount);
            cout <<"\t"<<amount<<" "<<frst.Get_CurrencyCode()<<" = "<<amountINusd<<" USD "<<endl;
            if(scnd.Get_CurrencyCode()=="USD")
            {  return; }
            cout << "\n\n\tConvert from USD To : "<< endl;
            _PrintCurrency(scnd,"Second Currency");
            float amountINscndcurrency = frst.ConvertToNONUSDCurrency(amount, scnd);
            cout <<"\t"<<amount<<" "<<frst.Get_CurrencyCode()<<" = "<<amountINscndcurrency<<" "<<scnd.Get_CurrencyCode()<<endl;
        }

        static void _PrintCurrency(clsCurrency currency, string title)
        {
            cout << "\n\t  "<< title;
            cout << "\n\t----------------------------------";
            cout << "\n\n\t  Country    :  " << currency.Get_Country();
            cout << "\n\t  Code       :  "   << currency.Get_CurrencyCode();
            cout << "\n\n\t  Name       :  " << currency.Get_CurrencyName();
            cout << "\n\t  Rate(1$)   =  "   << currency.Get_Rate();
            cout << "\n\n\t----------------------------------" << endl;
        }
};

#endif // CLSCURRENCYCALCULATORSCREEN_H
