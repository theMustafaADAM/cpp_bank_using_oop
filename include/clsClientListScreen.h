#ifndef CLSCLIENTLISTSCREEN_H
#define CLSCLIENTLISTSCREEN_H

#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsClientListScreen : protected clsScreen
{
    public:
        clsClientListScreen();
        virtual ~clsClientListScreen();

        static void ShowClientsList()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pListClients))
            {
                return; /// exit and not continue
            }
            vector<clsBankClient> vClients = clsBankClient::GetClientsList();
            string Title = "\t   Clients List Screen ";
            string subTitle = "\t     (" + to_string(vClients.size()) + ") Client(s)\n";
            _DrawScreenHeader(Title, subTitle);
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            cout << setw(8) << left << "" << "\t| " << left << setw(11)  << "Acc. ID";
            cout << "| " << left << setw(28) << "Client Name";
            cout << "| " << left << setw(13) << "Phone";
            cout << "| " << left << setw(21) << "Email";
            cout << "| " << left << setw(9)  << "PIN";
            cout << "| " << left << setw(11) << "Balance";
            cout << endl << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
            if(vClients.size() == 0 )
            { cout << "\n\t\t\tNo Clients Available In the System!"; }
            else
            {
                for(clsBankClient client : vClients)
                {
                    PrintClientRecordLine(client); cout << endl;
                }
            }
            cout << endl << setw(8) << left << ""
                 << "--------------------------------------------------------------";
            cout << "--------------------------------------------------------------\n"<< endl;
        }

    protected:

    private:
        static void PrintClientRecordLine(clsBankClient client)
        {
            cout << setw(8) << left << "" << "\t| " << left << setw(11)  << client.Get_AccountNumber();
            cout << "| " << left << setw(28) << client.FullName();
            cout << "| " << left << setw(13) << client.Get_Phone();
            cout << "| " << left << setw(21) << client.Get_Email();
            cout << "| " << left << setw(9)  << client.Get_PinCode();
            cout << "| " << left << setw(11) << client.Get_AccountBalance();
        }

};

#endif // CLSCLIENTLISTSCREEN_H
