#ifndef CLSCURRENCY_H
#define CLSCURRENCY_H

#include <iostream>
#include <string>
#include "UGlobal.h"
#include "../../../Cpp_OOP_L1/OOP_Project_String_Class/include/clsString.h"
#include <fstream>
#include <vector>

using namespace std;

class clsCurrency
{
    private:

        string _Country;        float _Rate;
        string _CurrencyCode;   string _CurrencyName;
        enum enMode { EmptyMode = 0, UpdatMode = 1 };
        enMode _Mode;

        static clsCurrency _ConvertLineToCurrencyObject(string line, string seperator = "#//#")
        {
            vector <string> vCurrencyData;
            vCurrencyData = clsString::Split(line, seperator);
            return clsCurrency(enMode::UpdatMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
        }

        static string _ConvertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
        {
            string currencyrecord = "";
            currencyrecord += currency.Get_Country() + seperator;
            currencyrecord += currency.Get_CurrencyCode() + seperator;
            currencyrecord += currency.Get_CurrencyName() + seperator;
            currencyrecord += to_string(currency.Get_Rate());
            return currencyrecord;
        }

        static vector<clsCurrency> _LoadCurrenciesDataFromFile()
        {
            vector<clsCurrency> vCurrency; fstream myfile;
            myfile.open(currencyfile, ios::in);
            if(myfile.is_open())
            {
                string line;
                while(getline(myfile,line))
                {
                    clsCurrency currency = _ConvertLineToCurrencyObject(line);
                    vCurrency.push_back(currency);
                } myfile.close();
            } return vCurrency;
        }

        static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency)
        {
            fstream myfile;
            myfile.open(currencyfile, ios::out);
            string dataLine;
            if(myfile.is_open())
            {
                for(clsCurrency c : vCurrency)
                {
                    dataLine = _ConvertCurrencyObjectToLine(c);
                    myfile << dataLine << endl;
                } myfile.close();
            }
        }

        void _Update()
        {
            vector <clsCurrency> _vCurrency;
            _vCurrency = _LoadCurrenciesDataFromFile();
            for(clsCurrency c : _vCurrency)
            {
                if(c.Get_CurrencyCode() == Get_CurrencyCode())
                {
                    c = *this; break;
                }
            } _SaveCurrencyDataToFile(_vCurrency);
        }

        static clsCurrency _GetEmptyCurrencyObject()
        {
            return clsCurrency(enMode::EmptyMode, "","", "", 0);
        }

    public:
        clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
        {
            _Mode = Mode;
            _Country = Country;
            _CurrencyCode = CurrencyCode;
            _CurrencyName = CurrencyName;
            _Rate = Rate;
        }
        virtual ~clsCurrency();

        string Get_Country()        { return _Country; }
        string Get_CurrencyCode()   { return _CurrencyCode; }
        string Get_CurrencyName()   { return _CurrencyName; }
        float Get_Rate()            { return _Rate; }
        void UpdateRate(float newRate)
        {
            _Rate = newRate;
            _Update();
        }

        static vector <clsCurrency> GetAllUSDRates()
        {
            return _LoadCurrenciesDataFromFile();
        }

        bool IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }

        static clsCurrency FindByCode(string CurrencyCode)
        {
            CurrencyCode = clsString::UpperAllStrings(CurrencyCode);
            fstream myfile;
            myfile.open(currencyfile, ios::in);
            string dataLine;
            if(myfile.is_open())
            {
                 string line;
                 while(getline(myfile,line))
                 {
                     clsCurrency curr = _ConvertLineToCurrencyObject(line);
                     if(curr.Get_CurrencyCode()== CurrencyCode)
                     {
                         myfile.close(); return curr;
                     }
                 } myfile.close();
            } return _GetEmptyCurrencyObject();
        }

        static clsCurrency FindByCountry(string Country)
        {
            Country = clsString::UpperAllStrings(Country);
            fstream myfile;
            myfile.open(currencyfile, ios::in);
            string dataLine;
            if(myfile.is_open())
            {
                 string line;
                 while(getline(myfile,line))
                 {
                     clsCurrency curr = _ConvertLineToCurrencyObject(line);
                     if(clsString::UpperAllStrings(curr.Get_Country())== Country)
                     {
                         myfile.close(); return curr;
                     }
                 } myfile.close();
            } return _GetEmptyCurrencyObject();
        }

        static bool IsCurrencyExist(string CurrencyCode)
        {
            clsCurrency crr = clsCurrency::FindByCode(CurrencyCode);
            return (!crr.IsEmpty());
        }

        static bool IsCountryExist(string Country)
        {
            clsCurrency crr = clsCurrency::FindByCountry(Country);
            return (!crr.IsEmpty());
        }

        static vector<clsCurrency> GetCurrenciesList()
        {
            return _LoadCurrenciesDataFromFile();
        }

        float ConvertToUSDCurrency(float amount)
        {
            return (float)(amount / Get_Rate());
        }

        float ConvertToNONUSDCurrency(float amount, clsCurrency dstcurrency)
        {
            float AmountInUsd = ConvertToUSDCurrency(amount);
            if(dstcurrency.Get_CurrencyCode() == "USD")
            {
                return AmountInUsd;
            }
            return (float)(AmountInUsd * dstcurrency.Get_Rate());
        }
};

#endif // CLSCURRENCY_H
