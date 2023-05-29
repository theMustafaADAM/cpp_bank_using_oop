#pragma once


#include <iostream>
#include <string>
#include <vector>

;using namespace std;

class clsString
{
    public:
        clsString()                         { _value = "";  }
        clsString(string val) : _value(val) {               }
        virtual ~clsString()                {               }

        /// Property Set and Get
        string Get_value()          { return _value;    }
        void Set_value(string val)  { _value = val;     }

        enum enLetterCout {SmallLetter =0, CaptlLetter = 1, All_Letters = 2};

        /// string Length
        static size_t Length(string str)
        {
            return str.length();
        }
        size_t Length()
        {
            return Length(_value);
        }

        /// Count String
        static size_t CountWords(string TheString)
        {
            string sWord, delim = " "; size_t pos = 0, Counter =0;
            while((pos = TheString.find(delim)) != std::string::npos)
            {
                ///Create First and followed Word
                sWord = TheString.substr(0,pos);
                if(sWord != "") ++Counter;
                TheString.erase(0, pos + delim.length());
            }
            /// Create Last Word
            if(TheString != "") ++Counter;
            return Counter;
        }
        size_t CountWords()
        {
            return CountWords(_value);
        }

        /// Upper First Letter of Each Word
        static string UpperFirstLetterOfEachWord(string TheString)
        {
            bool IsFrstLetter = true;
            for(size_t i =0; i < TheString.length(); i++)
            {
                if(TheString[i] != ' ' && IsFrstLetter)
                {   TheString[i] = toupper(TheString[i]);   }
                IsFrstLetter = (TheString[i] == ' ' ? true : false);
            }
            return TheString;
        }
        void UpperFirstLetterOfEachWord()
        {
            _value = UpperFirstLetterOfEachWord(_value);
        }

        /// Invert Letter Case
        static char InvertCase(char myChar)
        {   return  islower(myChar) ? toupper(myChar) : tolower(myChar);    }

        /// Invert All Case String
        static string InvertAllCaseString(string TheString)
        {
            for(size_t i =0; i < TheString.length(); i++)
            {   TheString[i] = InvertCase(TheString[i]);   }
            return TheString;
        }
        void InvertAllCaseString()
        {
            _value = InvertAllCaseString(_value);
        }

        /// Lower First Letter of Each Word
        static string LowerFirstLetterOfEachWord(string TheString)
        {
            bool IsFrstLetter = true;
            for(size_t i =0; i < TheString.length(); i++)
            {
                if(TheString[i] != ' ' && IsFrstLetter)
                {   TheString[i] = tolower(TheString[i]);   }
                IsFrstLetter = (TheString[i] == ' ' ? true : false);
            }
            return TheString;
        }
        void LowerFirstLetterOfEachWord()
        {
            _value = LowerFirstLetterOfEachWord(_value);
        }

        /// Lower All Strings
        static string LowerAllStrings(string TheString)
        {
            for(size_t i = 0; i < TheString.length(); i++)
            {   TheString[i] = tolower(TheString[i]);   }
            return TheString;
        }
        void LowerAllStrings()
        {
            _value = LowerAllStrings(_value);
        }

        /// Upper All Strings
        static string UpperAllStrings(string TheString)
        {
            for(size_t i =0; i < TheString.length(); i++)
            {   TheString[i] = toupper(TheString[i]);   }
            return TheString;
        }
        void UpperAllStrings()
        {
            _value = UpperAllStrings(_value);
        }

        /// Counting letter
        static size_t CountingLetters(string theString, enLetterCout LetterCount = enLetterCout::All_Letters)
        {
            if(LetterCount == enLetterCout::All_Letters)    return theString.length();
            short Counter = 0;
            for (size_t i = 0; i < theString.length(); i ++)
            {
                if(LetterCount==enLetterCout::SmallLetter && islower(theString[i])) Counter++;
                if(LetterCount==enLetterCout::CaptlLetter && isupper(theString[i])) Counter++;
            }
            return Counter;
        }
        size_t CountingLetters(enLetterCout LetterCount = enLetterCout::All_Letters)
        {
            return CountingLetters(_value);
        }

        /// Count Capital letters
        static size_t CountCapitalLetter(string TheString)
        {
            int Cptal = 0;
            for(size_t i =0; i < TheString.length(); i++)
            {   if( isupper(TheString[i])) Cptal++ ; }
            return Cptal;
        }
        size_t CountCapitalLetter()
        {
            return CountCapitalLetter(_value);
        }

        /// Count Small letters
        static size_t CountSmallLetter(string TheString)
        {
            int Cptal = 0;
            for(size_t i =0; i < TheString.length(); i++)
            {   if( !isupper(TheString[i])) Cptal++ ; }
            return Cptal;
        }
        size_t CountSmallLetter()
        {
            return CountSmallLetter(_value);
        }

        /// Count specific Letter of strings
        static int CountExactLetter(string TheString, char TheChar, bool MatchCase = true)
        {
            int Counter = 0;
            for(size_t i =0; i < TheString.length(); i++)
            {
                if(MatchCase)
                {
                    if(TheString[i] == TheChar) Counter++;
                }
                else
                {
                    if(tolower(TheString[i]) == tolower(TheChar))   Counter++;
                }
            }
            return Counter;
        }
        int CountExactLetter(char TheChar, bool MatchCase = true)
        {
            return CountExactLetter(_value, TheChar);
        }

        /// Is Vowel
        static bool IsVowel(char myChar)
        {
            myChar = tolower(myChar);
            return ((myChar == 'a') || (myChar == 'e') || (myChar == 'i') || (myChar == 'o') || (myChar == 'u'));
        }

        /// Count Vowel
        static int CountVowelLetters(string TheString)
        {
            int Counter=0;
            for(size_t i = 0; i < TheString.length(); i ++)
            {   if(IsVowel(TheString[i]))   ++Counter;  }
            return Counter;
        }
        int CountVowelLetters()
        {
            return CountVowelLetters(_value);
        }

        /// split string
        static vector <string> Split(string TheString, string delim)
        {
            vector <string> vWord; string nwWord; size_t pos = 0;
            while((pos = TheString.find(delim)) != std::string::npos)
            {
                ///Create First and followed Word
                nwWord = TheString.substr(0,pos);
                /*if(nwWord != "")*/    vWord.push_back(nwWord);
                TheString.erase(0, pos + delim.length());
            }
            /// Create Last Word
            if(TheString != "") vWord.push_back(TheString);
            return vWord;
        }
        vector <string> Split(string delim)
        {
            return Split(_value,delim);
        }

        /// Trim Left : Right : All Strings
        static string TrimLeft(string TheString)
        {
            char sp = ' ';
            for(size_t i = 0; i < TheString.length(); i++)
            {
                if(TheString[i] != sp)  return TheString.substr(i, TheString.length() -1);
            }
            return "";
        }
        void TrimLeft()
        {
            _value = TrimLeft(_value);
        }

        static string TrimRght(string TheString)
        {
            char sp = ' ';
            for(size_t i = TheString.length()-1; i >= 0; i--)
            {
                if(TheString[i] != sp)  return TheString.substr(0, i + 1);
            }
            return "";
        }
        void TrimRght()
        {
            _value = TrimRght(_value);
        }

        static string Trim(string TheString)
        {
            return TrimRght(TrimLeft(TheString));
        }
        void Trim()
        {
            _value =  Trim(_value);
        }

        /// Join String vector : array
        static string Join(vector <string> vString, string delim)
        {
            string sWord = "";
            for(auto &nString : vString)
            {   sWord = sWord + nString + delim;   }
            return sWord.substr(0,sWord.length()-delim.length());
        }
        static string Join(string arrString[], int arrlength, string delim)
        {
            string sWord = "";
            for(int i = 0; i < arrlength; i ++)
            {   sWord = sWord + arrString[i]+ delim;    }
            return sWord.substr(0,sWord.length()-delim.length());
        }

        /// Revers Strings
        static string Reverse(string myString)
        {
            vector <string> vWord ; string sd = "";
            vWord = Split(myString, " ");
            vector <string>::iterator iter = vWord.end();
            while(iter != vWord.begin())
            {
                --iter; sd += *iter + " ";
            }
            return sd = sd.substr(0, sd.length() -1);
        }
        void Reverse()
        {
            _value = Reverse(_value);
        }

        /// Replace Words
        static string ReplaceWords(string TheString, string deletedSting, string replaceString, bool MatchCase = true)
        {
            vector <string> vString = Split(TheString, " ");
            for(auto &sString : vString)
            {
                if(MatchCase)
                {
                    if(sString == deletedSting) sString = replaceString;
                }
                else
                {
                    if(UpperAllStrings(sString)== UpperAllStrings(deletedSting))    sString = replaceString;
                }
            }
            return Join(vString, " ");
        }
        string ReplaceWords(string deletedSting, string replaceString, bool MatchCase = true)
        {
            return ReplaceWords(_value, deletedSting, replaceString);
        }

        /// Remove Punctuations
        static string RemovePunc(string sString)
        {
            string nwstring = "";
            for (size_t i = 0; i < sString.length(); ++i)
            {
                if(!ispunct(sString[i]))    nwstring += sString[i];
            }
            return nwstring;
        }
        void RemovePunc()
        {
            _value = RemovePunc(_value);
        }

    private:
        string _value;

};

