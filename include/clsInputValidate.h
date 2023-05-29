#pragma once

#include <iostream>
#include "../../../Cpp_OOP_L1/OOP_Projects_Date/include/clsDate.h"
#include <string>
#include "../../../Cpp_OOP_L1/OOP_Project_String_Class/include/clsString.h"
#include <limits>
#include <utility>

using namespace std;

class clsInputValidate
{
    public:
        clsInputValidate();
        virtual ~clsInputValidate();

        template <typename T>T IsNumberBetween(T Nmbr, T From, T To)
        {
            return (Nmbr >= From && Nmbr <= To);
        }

        static string IsNumberBetween_stringResult(int Nmbr, int From, int To)
        {
            return (Nmbr >= From && Nmbr <= To) ? "true" : "false";
        }
        static bool IsNumberBetween(int Nmbr, int From, int To)
        {
            return (Nmbr >= From && Nmbr <= To);
        }
        static bool IsNumberBetween(short Nmbr, short From, short To)
        {
            return (Nmbr >= From && Nmbr <= To);
        }
        static bool IsNumberBetween(float Nmbr, float From, float To)
        {
            return (Nmbr >= From && Nmbr <= To);
        }
        static bool IsNumberBetween(double Nmbr, double From, double To)
        {
            return (Nmbr >= From && Nmbr <= To);
        }
        static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
        {
            /// Date >= From && Date <= To
            if((    clsDate::IsDate1AfterDate2(Date, From)|| clsDate::IsDate1EqualDate2(Date, From)) &&
               (    clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
               {
                   return true;
               }
            /// Date >= To && Date <= From
            if((    clsDate::IsDate1AfterDate2(Date, To)   || clsDate::IsDate1EqualDate2(Date, To)) &&
               (    clsDate::IsDate1BeforeDate2(Date, From)|| clsDate::IsDate1EqualDate2(Date, From)))
               {
                   return true;
               }
               return false;
        }

        static int ReadIntNumber(string errorMessages = "\n\t\t\t\t\tInvalid Input! Kindly reenter again :  ")
        {
            int Nmbr;
            while(!(cin >> Nmbr))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << errorMessages ;
            }return Nmbr;
        }

        template <typename T> T ReadNumber(string errorMessages = "\n\t\t\t\t\tInvalid Input! Kindly reenter again :  ")
        {
            T Nmbr;
            while(!(cin >> Nmbr))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << errorMessages ;
            }return Nmbr;
        }

        static float ReadFloatNumber(string errorMessages = "\n\t\t\t\t\tInvalid Input! Kindly reenter again :  ")
        {
            float Nmbr;
            while(!(cin >> Nmbr))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << errorMessages ;
            }return Nmbr;
        }

        static double ReadDblNumber(string errorMessages = "\n\t\t\t\t\tInvalid Input! Kindly reenter again :  ")
        {
            double Nmbr;
            while(!(cin >> Nmbr))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << errorMessages ;
            }return Nmbr;
        }

        static string ReadString()
        {
            string the_string = "";
            getline(cin>> ws,the_string);
            return the_string;
        }

        static string UpperString(string strng)
        {
            for(size_t i = 0; i < strng.length(); ++i)
            { strng[i] = toupper(strng[i]); }
            return strng;
        }

        static string LowerString(string strng)
        {
            for(size_t i = 0; i < strng.length(); ++i)
            { strng[i] = tolower(strng[i]); }
            return strng;
        }


        static bool AnswerYesNo(char answer)
        {
            return (answer=='y' || answer=='Y'? true : answer=='n' || answer=='N' ? false : false );
        }

        /*template <typename T> T ReadNumberBetween(T From, T To, string errorMessages = "Number is not within range! enter again :\n")
        {
            T Nmbr = ReadNumber();
            while(!IsNumberBetween(Nmbr,From,To))
            {
                cout << errorMessages;
                Nmbr = ReadNumber();
            }return Nmbr;
        }*/

        static int ReadIntNumberBetween(int From, int To, string errorMessages = "\n\t\t\t\t\tNumber is not within range! enter again :  ")
        {
            int Nmbr = ReadIntNumber();
            while(!IsNumberBetween(Nmbr,From,To))
            {
                cout << errorMessages;
                Nmbr = ReadIntNumber();
            }return Nmbr;
        }

        static float ReadFloatNumberBetween(float From, float To, string errorMessages = "\n\t\t\t\t\tNumber is not within range! enter again :  ")
        {
            float Nmbr = ReadFloatNumber();
            while(!IsNumberBetween(Nmbr,From,To))
            {
                cout << errorMessages;
                Nmbr = ReadDblNumber();
            }return Nmbr;
        }

        static double ReadDblNumberBetween(double From, double To, string errorMessages = "\n\t\t\t\t\tNumber is not within range! enter again :  ")
        {
            double Nmbr = ReadDblNumber();
            while(!IsNumberBetween(Nmbr,From,To))
            {
                cout << errorMessages;
                Nmbr = ReadDblNumber();
            }return Nmbr;
        }

        static bool IsValidDate(clsDate Date)
        {
            return clsDate::IsValidDate(Date);
        }
};

