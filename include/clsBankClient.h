#ifndef CLSBANKCLIENT_H
#define CLSBANKCLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "UGlobal.h"
#include "../include/clsUtil.h"
#include "../include/clsInputValidate.h"

using namespace std;

class clsBankClient : public clsPerson
{
    private:
        enum enMode { EmptyMode = 0, UpdatMode = 1, AdNewMode = 2 };
        string _AccountNumber;
        string _PinCode;
        double _AccountBalance;
        enMode _Mode;
        bool _MarkedForDelete = false;

        static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
        {
            vector<string> vClientData;
            vClientData = clsString::Split(Line, Seperator);
            return clsBankClient(vClientData[0], vClientData[1], vClientData[2], vClientData[3],
                                 vClientData[4], vClientData[5], stod(vClientData[6]), enMode::UpdatMode);
        }

        static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
        {
            string stClientRecord = "";
            stClientRecord += Client.Get_FrstName() + Seperator;
            stClientRecord += Client.Get_LastName() + Seperator;
            stClientRecord += Client.Get_Email() + Seperator;
            stClientRecord += Client.Get_Phone() + Seperator;
            stClientRecord += Client.Get_AccountNumber() + Seperator;
            stClientRecord += Client.Get_PinCode() + Seperator;
            stClientRecord += to_string(Client.Get_AccountBalance());
            return stClientRecord;
        }

        static vector <clsBankClient> _LoadClientsDataFromFile()
        {
            vector<clsBankClient> vClients;
            fstream MyFile;
            MyFile.open(clientfile, ios::in); // read MODE
            if(MyFile.is_open())
            {
                string Line;
                while(getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(Line);
                    vClients.push_back(Client);
                } MyFile.close();
            } return vClients;
        }

        static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
        {
            fstream myFile;
            myFile.open(clientfile, ios::out); // overwrite MODE
            string DataLine;
            if(myFile.is_open())
            {
                for(clsBankClient c : vClients)
                {
                    if(c.Get_MarkedForDelete() == false)
                    {
                        DataLine = _ConvertClientObjectToLine(c);
                        myFile << DataLine << endl;
                    }
                } myFile.close();
            }
        }

        void _AddNew()
        {
            _AddDataLineToFile(_ConvertClientObjectToLine(*this));
        }

        void _Update()
        {
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();
            for(clsBankClient& c : _vClients)
            {
                if(c.Get_AccountNumber() == Get_AccountNumber())
                {
                    c = *this; break;
                }
            } _SaveClientsDataToFile(_vClients);
        }

        void _AddDataLineToFile(string stDataLine)
        {
            fstream myFile;
            myFile.open(clientfile,ios::out | ios::app);
            if(myFile.is_open())
            {
                myFile << stDataLine << endl;
                myFile.close();
            }
        }

        static clsBankClient _GetEmptyClientObject()
        {
            return clsBankClient("", "", "","","","",0,enMode::EmptyMode);
        }

        string _prepareTransferRecords(double amount, clsBankClient destinationclient, string Username, string seperator = "#//#")
        {
            string transfeRecord = "";
            transfeRecord += clsDate::GetSystemDateTimeString() + seperator;
            transfeRecord += Get_AccountNumber() + seperator;
            transfeRecord += destinationclient.Get_AccountNumber() + seperator;
            transfeRecord += to_string(amount) + seperator;
            transfeRecord += to_string(Get_AccountBalance()) + seperator;
            transfeRecord += to_string(destinationclient.Get_AccountBalance()) + seperator;
            transfeRecord += Username;
            return transfeRecord;
        }

        void _registerTransferRecords(double amount, clsBankClient destinationclient, string Username)
        {
            string strDataline = _prepareTransferRecords(amount, destinationclient, Username);
            fstream myfile;
            myfile.open(transferfile, ios::out | ios::app);
            if(myfile.is_open())
            {
                myfile << strDataline << endl;  myfile.close();
            }
        }

    public:

        struct stTransferRecords
        {
            string dateTime;
            string sourcAccountNumber;
            string destnAccountNumber;
            double amount;
            double srcBalanceAfter;
            double dstBalanceAfter;
            string Username;
        };

        clsBankClient(string FrstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance, enMode Mode)
        : clsPerson(FrstName, LastName, Email, Phone)
        {
            _Mode = Mode; _AccountNumber = AccountNumber; _AccountBalance = AccountBalance; _PinCode = PinCode;
        }
        virtual ~clsBankClient(){   }

        bool IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }

        string Get_AccountNumber()          { return _AccountNumber; }

        string Get_PinCode()                { return _PinCode; }
        void Set_PinCode(string val)        { _PinCode = val; }

        double Get_AccountBalance()         { return _AccountBalance; }
        void Set_AccountBalance(double val) { _AccountBalance = val; }

        bool Get_MarkedForDelete()         { return _MarkedForDelete; }
        void Set_MarkedForDelete(bool val) { _MarkedForDelete = val; }

        static clsBankClient GetAddNewClientObject(string AccountNumber)
        {
            return clsBankClient("", "", "", "", AccountNumber, "", 0, enMode::AdNewMode);
        }

        static clsBankClient Find(string AccountNumber)
        {
            fstream myFile;
            myFile.open(clientfile,ios::in);
            if(myFile.is_open())
            {
                string Line;
                while(getline(myFile, Line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(Line);
                    if(Client.Get_AccountNumber() == AccountNumber)
                    {
                        myFile.close(); return Client;
                    }
                } myFile.close();
            } return _GetEmptyClientObject();
        }

        static clsBankClient Find(string AccountNumber, string PinCode)
        {
            fstream myFile;
            myFile.open(clientfile,ios::in);
            if(myFile.is_open())
            {
                string Line;
                while(getline(myFile, Line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(Line);
                    if(Client.Get_AccountNumber() == AccountNumber
                       && Client.Get_PinCode() == PinCode)
                    {
                        myFile.close(); return Client;
                    }
                } myFile.close();
            } return _GetEmptyClientObject();
        }

        enum enSaveResults { svFailEmptyObject = 0, svSucceded = 1, svFailAccNumberExist = 2 };
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
                    if(clsBankClient::IsClientExist(_AccountNumber))
                    {   return enSaveResults::svFailAccNumberExist; }
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

        static bool IsClientExist(string AccountNumber)
        {
            clsBankClient client = clsBankClient::Find(AccountNumber);
            return (!client.IsEmpty());
        }

        static void ReadClientInfo(clsBankClient& client)
        {
            cout << "\nFirst Name   : " ; client.Set_FrstName(clsInputValidate::ReadString());
            cout << "\nLast  Name   : " ; client.Set_LastName(clsInputValidate::ReadString());
            cout << "\nEmail        : " ; client.Set_Email(clsInputValidate::ReadString());
            cout << "\nPhone        : " ; client.Set_Phone(clsInputValidate::ReadString());
            cout << "\nPassword     : " ; client.Set_PinCode(clsInputValidate::ReadString());
            cout << "\nAcc. Balance : " ; client.Set_AccountBalance(clsInputValidate::ReadDblNumber());
            cout << "\n\t----------------------------------";
        }

        bool Delete()
        {
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();
            for(clsBankClient& c : _vClients)
            {
                if(c.Get_AccountNumber() == Get_AccountNumber())
                {
                    c.Set_MarkedForDelete(true); break;
                }
            } _SaveClientsDataToFile(_vClients);
            *this = _GetEmptyClientObject();
            return true;
        }

        static vector<clsBankClient> GetClientsList()
        {
            return _LoadClientsDataFromFile();
        }

        static double GetTotalBalances()
        {
            vector<clsBankClient> vClients = GetClientsList();
            double TotalBalances = 0;
            for(clsBankClient clinet : vClients)
            {
                TotalBalances += clinet.Get_AccountBalance();
            } return TotalBalances;
        }

        void Deposit(double amount)
        {
            _AccountBalance += amount;
            Save();
        }
        void Withdraw(double amount)
        {
            _AccountBalance -= amount;
            Save();
        }

        bool Transfer(double amount, clsBankClient& destinationclient, string Username = Current_user.Get_Username())
        {
            if(amount > Get_AccountBalance())
            {   return false;   }
            Withdraw(amount);
            destinationclient.Deposit(amount);
            _registerTransferRecords(amount, destinationclient, Username);
            return true;
        }

        static vector <stTransferRecords> getTransferRecordsList()
        {
            vector <stTransferRecords> vTransferRecords;
            fstream myfile;
            myfile.open(transferfile, ios::in);
            if(myfile.is_open())
            {
                string line; stTransferRecords transferRecords;
                while(getline(myfile,line))
                {
                    transferRecords = _ConvertTransferRecordToLine(line);
                    vTransferRecords.push_back(transferRecords);
                } myfile.close();
            } return vTransferRecords;
        }

        static stTransferRecords _ConvertTransferRecordToLine(string line, string seperator = "#//#")
        {
            stTransferRecords transferRecord;
            vector<string> vtransferRecords = clsString::Split(line,seperator);
            transferRecord.dateTime = vtransferRecords[0];
            transferRecord.sourcAccountNumber = vtransferRecords[1];
            transferRecord.destnAccountNumber = vtransferRecords[2];
            transferRecord.amount = stod(vtransferRecords[3]);
            transferRecord.srcBalanceAfter = stod(vtransferRecords[4]);
            transferRecord.dstBalanceAfter = stod(vtransferRecords[5]);
            transferRecord.Username = vtransferRecords[6];
            return transferRecord;
        }
};

#endif // CLSBANKCLIENT_H
