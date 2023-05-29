#pragma once


#include <iostream>
#include <string>
#include "../../../Cpp_OOP_L1/OOP_Projects_Date/include/clsDate.h"

;using namespace std;

class clsUtil
{
    protected:

    private:

    public:
        clsUtil();
        virtual ~clsUtil();
        enum enCharType
        {
            SmallLetter = 1, CaptlLetter = 2, Digit = 3, MixCahr = 4, SpecialChar = 5
        };

        static void Srand()
        {
            srand((unsigned)time(NULL));
        }

        static int RandomNumber(short From, short To)
        {
            int Nmbr = rand()%(To - From + 1) + From;
            return Nmbr;
        }

        static char GetRandomCharacter(enCharType charType)
        {
            if(charType == MixCahr) {   charType = (enCharType)RandomNumber(1,3);  }
            switch (charType)
            {
                case enCharType::SmallLetter:
                    {   return char(RandomNumber(97,122)); break;    }
                case enCharType::CaptlLetter:
                    {   return char(RandomNumber(65,90)); break;    }
                case enCharType::SpecialChar:
                    {   return char(RandomNumber(33,47)); break;    }
                case enCharType::Digit:
                    {   return char(RandomNumber(48,57)); break;    }
                default:
                    {   return char(RandomNumber(65,90)); break;    }
            }
        }

        static string GenerateWord(enCharType charType, size_t length)
        {
            string word;
            for(size_t i = 1; i <= length; i++)
            {
                word = word + GetRandomCharacter(charType);
            }
            return word;
        }

        static string GenerateKey(enCharType charType = CaptlLetter)
        {
            string key = "";
            key = GenerateWord(charType,4) + "-";
            key = key + GenerateWord(charType,4) + "-";
            key = key + GenerateWord(charType,4) + "-";
            key = key + GenerateWord(charType,4);
            return key;
        }

        static void GenerateMultiKeys(int NumberOfKeys, enCharType charType)
        {
            for (int i = 1; i <= NumberOfKeys; ++i )
            {
                cout << "Key [" << i <<"] : ";
                cout << GenerateKey(charType) << endl;
            }
        }

        static void FillArrayWithRandomWords(string arr[100], short arrLength, enCharType charType, short wordLength)
        {
            for(short i = 0; i < arrLength; ++i)
                arr[i] = GenerateWord(charType, wordLength);
        }

        static void FillArrayWithRandomKeys(string arr[100], short arrLength, enCharType charType)
        {
            for (short i = 0; i < arrLength; ++i)
                arr[i] = GenerateKey(charType);
        }

        static void SwapNumber(int& frstNmbr, int& scndNmbr)
        {
            int tempNmbr = frstNmbr;
            frstNmbr = scndNmbr;
            scndNmbr = tempNmbr;
        }
        static void SwapNumber(double& frstNmbr, double& scndNmbr)
        {
            double tempNmbr = frstNmbr;
            frstNmbr = scndNmbr;
            scndNmbr = tempNmbr;
        }
        static void SwapBool(bool& frstBool, bool& scndBool)
        {
            bool tempBool = frstBool;
            frstBool = scndBool;
            scndBool = tempBool;
        }
        static void SwapChar(char& frstChar, char& scndChar)
        {
            char tempChar = frstChar;
            frstChar = scndChar;
            scndChar = tempChar;
        }
        static void SwapString(string& frststr, string& scndstr)
        {
            string tempstr = frststr;
            frststr = scndstr;
            scndstr = tempstr;
        }
        static void SwapDate(clsDate& frstDate, clsDate& scndDate)
        {
            clsDate::SwapDates(frstDate, scndDate);
        }

        static void shuffleArray(int arr[100], int arrLength)
        {
            for(int i = 0; i < arrLength; ++i)
            {
                SwapNumber(arr[RandomNumber(1,arrLength)], arr[RandomNumber(1,arrLength)]);
            }
        }
        static void shuffleArray(string arr[100], size_t arrLength)
        {
            for(size_t i = 0; i < arrLength; ++i)
            {
                SwapString(arr[RandomNumber(1,arrLength)], arr[RandomNumber(1,arrLength)]);
            }
        }

        static string Tabs(short NumberOfTabs)
        {
            string t = "";
            for(int i = 0; i < NumberOfTabs; ++i)
            {
                t = t + "\t";   cout << t;
            }return t;
        }

        static string EncryptText(string Text, short encryptionKey = 3)
        {
            for(size_t i = 0; i <= Text.length(); ++i)
            { Text[i] = char((int)Text[i] + encryptionKey); }
            return Text;
        }

        static string DecryptText(string Text, short encryptionKey = 3)
        {
            for(size_t i = 0; i <= Text.length(); ++i)
            { Text[i] = char((int)Text[i] - encryptionKey); }
            return Text;
        }

        static string NumberToText(int Number)
        {
            if(Number == 0) { return ""; }
            if(Number >= 1 && Number <= 19)
            {
                string arr[]= { "", "One","Two", "Three", "Four", "Five", "six", "Seven", "Eight", "Nine", "Ten",
                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
                return arr[Number] + " ";
            }
            if(Number >= 20 && Number <= 99)
            {
                string arr[]= { "", "", "Twenty","Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
                return arr[Number/10] + " " + NumberToText(Number%10);
            }
            if(Number >= 100 && Number <= 199)
            {
                return "One Hundred " + NumberToText(Number%100);
            }
            if(Number >= 200 && Number <= 999)
            {
                return NumberToText(Number/100) + "Hundreds " + NumberToText(Number %100);
            }
            if(Number >= 1000 && Number <= 1999)
            {
                return "One Thousand " + NumberToText(Number %1000);
            }
            if(Number >= 2000 && Number <= 999999)
            {
                return NumberToText(Number/1000) + "Thousands " + NumberToText(Number %1000);
            }
            if(Number >= 1000000 && Number <= 1999999)
            {
                return "One Million " + NumberToText(Number %1000000);
            }
            if(Number >= 2000000 && Number <= 999999999)
            {
                return NumberToText(Number/1000000) + "Millions " + NumberToText(Number %1000000);
            }
            if(Number >= 1000000000 && Number <= 1999999999)
            {
                return "One Billion " + NumberToText(Number %1000000000);
            } else {
                return NumberToText(Number/1000000000) + "Billions " + NumberToText(Number %1000000000);
            }
        }
};

