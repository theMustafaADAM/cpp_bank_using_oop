#ifndef CLSLOGINREGISTERSCREEN_H
#define CLSLOGINREGISTERSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsListUserScreen.h"
#include "clsLoginRecords.h"
#include "clsScreen.h"
#include "clsUsers.h"
#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
    private:

        static void PrintLoginRecordLine(clsLoginRecords LoginRegisterRecord)
        {
            cout << setw(12) << left << "" << "\t| " << left << setw(40) << LoginRegisterRecord.Get_dateTime();
            cout << "| " << left << setw(25) << LoginRegisterRecord.Get_username();
            cout << "| " << left << setw(15) << LoginRegisterRecord.Get_password();
            cout << "| " << left << setw(15) << LoginRegisterRecord.Get_permssion();
        }

    public:
        clsLoginRegisterScreen();
        virtual ~clsLoginRegisterScreen();

        static void ShowLoginRegister()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pLoginRegister))
            {
                return; /// exit and not continue
            }
            vector<clsLoginRecords> vLoginRegisterRecord = clsLoginRecords::GetLoginRegisterList();
            string Title = "\t   Login Register Screen ";
            string subTitle = "\t     (" + to_string(vLoginRegisterRecord.size()) + ") Record(s)\n";
            _DrawScreenHeader(Title/*, subTitle*/);
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            cout << setw(12) << left << "" << "\t| " << left << setw(40) << "Date and Time";
            cout << "| " << left << setw(25) << "User Name";
            cout << "| " << left << setw(15) << "Password";
            cout << "| " << left << setw(15) << "Permissions";
            cout << endl << endl << setw(8)  << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            if(vLoginRegisterRecord.size() == 0 )
            { cout << "\n\t\t\tNo Records Available In the System!"; }
            else
            {
                for(clsLoginRecords record : vLoginRegisterRecord)
                {
                    PrintLoginRecordLine(record); cout << endl;
                }
            }
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
        }
};

#endif // CLSLOGINREGISTERSCREEN_H
