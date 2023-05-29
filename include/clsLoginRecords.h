#ifndef CLSLOGINRECORDS_H
#define CLSLOGINRECORDS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "filesGlobal.h"
#include "../../../Cpp_OOP_L1/OOP_Project_String_Class/include/clsString.h"
#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "../../../Cpp_OOP_L1/OOP_Projects_Date/include/clsDate.h"
#include "../../OOP_Projects_Utility_Class/include/clsUtil.h"

using namespace std;

class clsLoginRecords
{
        private:

        string _dateTime; string _username;
        string _password; int _permssion;

        static clsLoginRecords _ConvertLineToRecords(string Line, string Seperator = "#//#")
        {
            vector<string> vRecords;
            vRecords = clsString::Split(Line, Seperator);
            return clsLoginRecords(vRecords[0], vRecords[1], vRecords[2], stoi(vRecords[3]));
        }

        static string _ConvertRecordsToLine(clsLoginRecords log, string seperator = "#//#")
        {
            string records = "";
            records += log.Get_dateTime() + seperator;
            records += log.Get_username() + seperator;
            records += log.Get_password() + seperator;
            records += to_string(log.Get_permssion());
            return records;
        }

        static vector <clsLoginRecords> _LoadRecordsDataFromFile()
        {
            vector<clsLoginRecords> vloginrecords; fstream MyFile;
            MyFile.open(loginfile, ios::in); // read MODE
            if(MyFile.is_open())
            {
                string Line;
                while(getline(MyFile, Line))
                {
                    clsLoginRecords log = _ConvertLineToRecords(Line);
                    vloginrecords.push_back(log);
                } MyFile.close();
            } return vloginrecords;
        }

        static void _SaveLoginRecordsDataToFile(vector<clsLoginRecords> vlogin)
        {
            fstream myfile;
            myfile.open(loginfile, ios::out);
            string dataLine;
            if(myfile.is_open())
            {
                for(clsLoginRecords log : vlogin)
                {
                    dataLine = _ConvertRecordsToLine(log);
                    myfile << dataLine << endl;
                } myfile.close();
            }
        }

        static clsLoginRecords _GetEmptyLoginRecordsObject()
        {
            return clsLoginRecords("","", "", 0);
        }

    public:

        virtual ~clsLoginRecords();
        clsLoginRecords(string dateTime, string username, string password, int permssion)
        {
            _dateTime = dateTime; _username = username;
            _password = password; _permssion = permssion;
        }

        static vector <clsLoginRecords> GetLoginRegisterList()
        {
            return _LoadRecordsDataFromFile();
        }

        string Get_dateTime()           { return _dateTime; }
        void Set_dateTime(string val)   { _dateTime = val; }

        string Get_username()           { return _username; }
        void Set_username(string val)   { _username = val; }

        string Get_password()           { return _password; }
        void Set_password(string val)   { _password = val; }

        int Get_permssion()             { return _permssion; }
        void Set_permssion(int val)     { _permssion = val; }
};

#endif // CLSLOGINRECORDS_H
