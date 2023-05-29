#ifndef CLSSCREEN_H
#define CLSSCREEN_H

#include <iostream>
#include <iomanip>
#include "UGlobal.h"
#include "../../../Cpp_OOP_L1/OOP_Projects_Date/include/clsDate.h"

using namespace std;

class clsScreen
{
    public:
        clsScreen();
        virtual ~clsScreen();

    protected:
        static void _DrawScreenHeader(string Title, string SubTitle = "")
        {
            cout << setw(37) << left << "" << "==================================================\n" << endl;
            cout << "\t\t\t\t\t" << Title << endl;
            if(SubTitle != "")
            {   cout << "\n\t\t\t\t\t" << SubTitle ; }
            cout <<endl<< setw(37) << left << "" << "==================================================" << endl;
            cout << endl << setw(37) << left << "" << "\tUsername : " << Current_user.Get_Username() << "   * ";
            cout << "   Date : " << clsDate::DateToString(clsDate()) << endl << endl;
        }

        static bool CheckAccessRights(clsUsers::enPermissions permissions)
        {
            if(!Current_user.CheckAccessPermissions(permissions))
            {
                cout << setw(37) << left << "" << "==================================================\n" << endl;
                cout << "\t\t\t\t\t    Access Denied ! Contact Your Admin." << endl;
                cout <<endl<< setw(37) << left << "" << "==================================================" << endl;
                return false;
            }
            else
                {
                    return true;
                }
        }

    private:
};

#endif // CLSSCREEN_H
