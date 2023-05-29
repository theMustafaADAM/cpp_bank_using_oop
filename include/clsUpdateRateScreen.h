#ifndef CLSUPDATERATESCREEN_H
#define CLSUPDATERATESCREEN_H

#include "clsCurrency.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsUpdateRateScreen : protected clsScreen
{
    public:
        clsUpdateRateScreen();
        virtual ~clsUpdateRateScreen();

        static void ShowUpdateRate()
        {
            _DrawScreenHeader("\t   Update Rate Screen");
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
                cout << "\n\tYour entered [ " + fCurrency + " ] is existing! Would you like to continue ? [ y / n ] ? ";
                char answer ='n'; cin>>answer;
                if(!clsInputValidate::AnswerYesNo(answer))
                {
                    cout << "\n\n\tError : Updating a rate of [ " + fCurrency + " ] was canceled !\n\n"; return;
                } else {
                    _PrintCurrency(currency);
                    float nwrate = 0;
                    cout << "\n\n\tKindly enter the new rate : "; nwrate = clsInputValidate::ReadFloatNumber();
                    currency.UpdateRate(nwrate);
                    _PrintCurrency(currency); return;
                }
            } else {
                cout << "\n\tError : Currency's Data was not Found !\n";
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

#endif // CLSUPDATERATESCREEN_H
