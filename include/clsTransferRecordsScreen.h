#ifndef CLSTRANSFERRECORDSSCREEN_H
#define CLSTRANSFERRECORDSSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsDepositsScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsTransferRecordsScreen : protected clsScreen
{
    public:
        clsTransferRecordsScreen();
        virtual ~clsTransferRecordsScreen();

        static void ShowTransferRecords()
        {
            system("clear");
            vector<clsBankClient::stTransferRecords> vtransferRecord = clsBankClient::getTransferRecordsList();
            string title = "\t  Transfer Records Screen";
            string subtitle = "\t       (" + to_string(vtransferRecord.size()) + ") Record(s)\n";
            _DrawScreenHeader(title, subtitle);
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            cout << setw(4) << left << "" << "\t   | " << left << setw(30)  << "Date & Time ";
            cout << "| " << left << setw(10) << "src ID";
            cout << "| " << left << setw(10) << "dst ID";
            cout << "| " << left << setw(15) << "Amount";
            cout << "| " << left << setw(15) << "src Balance";
            cout << "| " << left << setw(15) << "dst Balance";
            cout << "| " << left << setw(10) << "Username";
            cout << endl << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            if(vtransferRecord.size()==0)
            {
                cout << endl << endl << setw(8) << left << ""
                 << "\t  No Records to Show! ";
            }else
            {
                for(clsBankClient::stTransferRecords rec : vtransferRecord )
                {
                    PrintTransferRecordLine(rec);
                    cout << endl;
                }
            }
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------"<< endl;
        }

    private:

        static void PrintTransferRecordLine(clsBankClient::stTransferRecords transferRecord)
        {
            cout << setw(4) << left << "" << "\t   | " << left << setw(30)  << transferRecord.dateTime;
            cout << "| " << left << setw(10) << transferRecord.sourcAccountNumber;
            cout << "| " << left << setw(10) << transferRecord.destnAccountNumber;
            cout << "| " << left << setw(15) << transferRecord.amount;
            cout << "| " << left << setw(15) << transferRecord.srcBalanceAfter;
            cout << "| " << left << setw(15) << transferRecord.dstBalanceAfter;
            cout << "| " << left << setw(10) << transferRecord.Username;
        }
};

#endif // CLSTRANSFERRECORDSSCREEN_H
