#ifndef CLSUSERS_H
#define CLSUSERS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "filesGlobal.h"
#include "../../OOP_Projects_Utility_Class/include/clsUtil.h"
#include "../../../Cpp_OOP_L1/OOP_Projects_Date/include/clsDate.h"
#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"

using namespace std;

class clsUsers : public clsPerson
{
    private:

        enum enMode { EmptyMode = 0, UpdatMode = 1, AdNewMode = 2 };
        bool _MarkedforDelete;  int _Permession; enMode _Mode;
        string _Username;       string _Password;

        string _PrepareLoginRecord(string seperator = "#//#")
        {
            string loginrecord = "";
            loginrecord += clsDate::GetSystemDateTimeString() + seperator;
            loginrecord += Get_Username() + seperator;
            loginrecord += clsUtil::EncryptText(Get_Password()) + seperator;
            loginrecord += to_string(Get_Permession());
            return loginrecord;
        }

        static clsUsers _ConvertLineToUserObject(string Line, string Seperator = "#//#")
        {
            vector<string> vUserData;
            vUserData = clsString::Split(Line, Seperator);
            return clsUsers(enMode::UpdatMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
                                 vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
        }

        static string _ConvertUserObjectToLine(clsUsers user, string Seperator = "#//#")
        {
            string UserRecord = "";
            UserRecord += user.Get_FrstName() + Seperator;
            UserRecord += user.Get_LastName() + Seperator;
            UserRecord += user.Get_Email() + Seperator;
            UserRecord += user.Get_Phone() + Seperator;
            UserRecord += user.Get_Username() + Seperator;
            UserRecord += clsUtil::EncryptText(user.Get_Password()) + Seperator;
            UserRecord += to_string(user.Get_Permession());
            return UserRecord;
        }

        static vector <clsUsers> _LoadUsersDataFromFile()
        {
            vector<clsUsers> vUsers; fstream myfile;
            myfile.open(userfile, ios::in); // read MODE
            if(myfile.is_open())
            {
                string Line;
                while(getline(myfile, Line))
                {
                    clsUsers user = _ConvertLineToUserObject(Line);
                    vUsers.push_back(user);
                } myfile.close();
            } return vUsers;
        }

        static void _SaveUsersDataToFile(vector <clsUsers> vUsers)
        {
            fstream myFile;
            myFile.open(userfile, ios::out); // overwrite MODE
            string DataLine;
            if(myFile.is_open())
            {
                for(clsUsers u : vUsers)
                {
                    if(u.Get_MarkedforDelete() == false)
                    {
                        DataLine = _ConvertUserObjectToLine(u);
                        myFile << DataLine << endl;
                    }
                } myFile.close();
            }
        }

        void _AddNew()
        {
            _AddDataLineToFile(_ConvertUserObjectToLine(*this));
        }

        void _Update()
        {
            vector <clsUsers> _vUsers;
            _vUsers = _LoadUsersDataFromFile();
            for(clsUsers& u : _vUsers)
            {
                if(u.Get_Username() == Get_Username())
                {
                    u = *this; break;
                }
            } _SaveUsersDataToFile(_vUsers);
        }

        void _AddDataLineToFile(string stDataLine)
        {
            fstream myFile;
            myFile.open(userfile,ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << stDataLine << endl;
                myFile.close();
            }
        }

        static clsUsers _GetEmptyUserObject()
        {
            return clsUsers(enMode::EmptyMode,"", "", "","","","",0);
        }

    public:

        //struct stLoginRegisterRecords {
        //    string dateTime; string username;
        //    string password; int permissions; };

        enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32,
        pManageUsers = 64, pLoginRegister = 128 , pCurrencyExchange = 256 };

        clsUsers(enMode Mode, string FrstName, string LastName, string Email, string Phone, string Username, string Password, unsigned int Permession)
        : clsPerson(FrstName, LastName, Email, Phone)
        {
            _Mode = Mode;
            _Username = Username;
            _Password = Password;
            _Permession = Permession;
        }
        virtual ~clsUsers();

        bool IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }

        int Get_Permession()           { return _Permession; }
        void Set_Permession(int val)   { _Permession = val; }

        string Get_Username()                   { return _Username; }
        void Set_Username(string val)           { _Username = val; }

        string Get_Password()                   { return _Password; }
        void Set_Password(string val)           { _Password = val; }

        bool Get_MarkedforDelete()              { return _MarkedforDelete; }
        void Set_MarkedForDelete(bool val)      { _MarkedforDelete = val; }

        static clsUsers GetAddNewUserObject(string Username)
        {
            return clsUsers(enMode::AdNewMode, "", "", "", "", Username, "", 0);
        }

        static clsUsers Find(string Username)
        {
            fstream myFile;
            myFile.open(userfile,ios::in);
            if(myFile.is_open())
            {
                string Line;
                while(getline(myFile, Line))
                {
                    clsUsers user = _ConvertLineToUserObject(Line);
                    if(user.Get_Username() == Username)
                    {
                        myFile.close(); return user;
                    }
                } myFile.close();
            } return _GetEmptyUserObject();
        }

        static clsUsers Find(string Username, string Password)
        {
            fstream myFile;
            myFile.open(userfile,ios::in);
            if(myFile.is_open())
            {
                string Line;
                while(getline(myFile, Line))
                {
                    clsUsers User = _ConvertLineToUserObject(Line);
                    if(User.Get_Username() == Username
                       && User.Get_Password() == Password)
                    {
                        myFile.close(); return User;
                    }
                } myFile.close();
            } return _GetEmptyUserObject();
        }

        static bool IsUserExist(string Username)
        {
            clsUsers user = clsUsers::Find(Username);
            return (!user.IsEmpty());
        }

        enum enSaveResults { svFailEmptyObject = 0, svSucceded = 1, svFailUsernameExist = 2 };
        enSaveResults Save()
        {
            switch(_Mode)
            {
                case enMode::EmptyMode:
                {
                    return enSaveResults::svFailEmptyObject; break;
                }
                case enMode::AdNewMode:
                {
                    if(clsUsers::IsUserExist(_Username))
                    {   return enSaveResults::svFailUsernameExist; }
                    else
                    {
                        _AddNew(); _Mode = enMode::UpdatMode;
                        return enSaveResults::svSucceded;
                    } break;
                }
                case enMode::UpdatMode:
                {
                    _Update();
                    return enSaveResults::svSucceded; break;
                }

            } return enSaveResults::svSucceded;
        }

        static void ReadUserInfo(clsUsers& user)
        {
            cout << "\nFirst Name   : " ; user.Set_FrstName(clsInputValidate::ReadString());
            cout << "\nLast  Name   : " ; user.Set_LastName(clsInputValidate::ReadString());
            cout << "\nEmail        : " ; user.Set_Email(clsInputValidate::ReadString());
            cout << "\nPhone        : " ; user.Set_Phone(clsInputValidate::ReadString());
            cout << "\nPassword     : " ; user.Set_Password(clsInputValidate::ReadString());
            cout << "\nPermissions  : " ; user.Set_Permession(clsInputValidate::ReadIntNumber());
            cout << "\n\t----------------------------------";
        }

        bool Delete()
        {
            vector <clsUsers> _vUser;
            _vUser = _LoadUsersDataFromFile();
            for(clsUsers& u : _vUser)
            {
                if(u.Get_Username() == Get_Username())
                {
                    u.Set_MarkedForDelete(true); break;
                }
            } _SaveUsersDataToFile(_vUser);
            *this = _GetEmptyUserObject();
            return true;
        }

        static vector<clsUsers> GetUsersList()
        {
            return _LoadUsersDataFromFile();
        }

        bool CheckAccessPermissions(enPermissions permissions)
        {
            if(this->Get_Permession() == enPermissions::eAll)
            {
                return true;
            }
            if((permissions & this->Get_Permession())== permissions)
            {
                return true;
            }
            else
                {
                    return false;
                }
        }

        void RegisterLogin()
        {
            string dataline = _PrepareLoginRecord();
            fstream myfile;
            myfile.open(loginfile, ios::out | ios::app);
            if(myfile.is_open())
            {
                myfile << dataline << endl; myfile.close();
            }
        }
};

#endif // CLSUSERS_H
