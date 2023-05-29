#ifndef CLSMANAGEUSERSCREEN_H
#define CLSMANAGEUSERSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsListUserScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsManageUserScreen : protected clsScreen
{
    public:
        clsManageUserScreen();
        virtual ~clsManageUserScreen();

        static void ShowManageUserMenue()
        {
            if(!CheckAccessRights(clsUsers::enPermissions::pManageUsers))
            {
                return; /// exit and not continue
            }
            system("clear");
            _DrawScreenHeader("\t    Manage User Screen");
            cout << endl << endl;
            cout << setw(37) << left << "" << "\t    Manage User Menu :" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n\n" << endl;
            cout << setw(37) << left << "" << "\t[1]  Show Users List. " << endl;
            cout << setw(37) << left << "" << "\t[2]  Add New User. " << endl;
            cout << setw(37) << left << "" << "\t[3]  Delete User. " << endl;
            cout << setw(37) << left << "" << "\t[4]  Update User. " << endl;
            cout << setw(37) << left << "" << "\t[5]  Find User. " << endl;
            cout << setw(37) << left << "" << "\t[6]  Main Menu. \n" << endl;
            cout << setw(37) << left << "" << "__________________________________________________\n" << endl;
            _PerformManageUserMenueOption((enManageUserMenuOptions)_ReadManageUserMenueOption());
        }

    private:

        enum enManageUserMenuOptions{ eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };

        static short _ReadManageUserMenueOption()
        {
            cout << setw(37) << left << "" << "\tChoose what you want to do ? [ 1 to 6 ] ? ";
            short  choice = clsInputValidate::ReadIntNumberBetween(1,6, "\n\t\t\t\t\tKindly Enter ONLY Between      1 to 6 !   ");
            return choice;
        }

        static void _GoBackToManageUserMenue()
        {
            cout << setw(37) << left << "" << "\n\t\t\t\t\t\tPress any key to go back to Manage User Menu ... \n" << endl;
            cin.ignore(); cin.get();
            ShowManageUserMenue();
        }

        static void _ShowAllUsersScreen()
        {
            clsListUserScreen::ShowUsersList();
        }

        static void _ShowAddNewUsersScreen()
        {
            clsAddNewUserScreen::ShowAddNewUserScreen();
        }

        static void _ShowDeleteUsersScreen()
        {
            clsDeleteUserScreen::ShowDeleteUser();
        }

        static void _ShowUpdateUsersScreen()
        {
            clsUpdateUserScreen::ShowUpdateUser();
        }

        static void _ShowFindUsersScreen()
        {
            clsFindUserScreen::ShowFindUserScreen();
        }

        static void _BackMainScreen()
        {
            cout << "\n\n\n\t\t\t\t\t\tBack Main Menu Screen Will be here ... \n" << endl;
        }

        static void _PerformManageUserMenueOption(enManageUserMenuOptions ManageUserMenueOption)
        {
            switch (ManageUserMenueOption)
            {
                case enManageUserMenuOptions::eListUsers:
                {
                    system("clear"); _ShowAllUsersScreen(); _GoBackToManageUserMenue();
                     break;
                }
                case enManageUserMenuOptions::eAddNewUser:
                {
                    system("clear"); _ShowAddNewUsersScreen(); _GoBackToManageUserMenue();
                    break;
                }
                case enManageUserMenuOptions::eDeleteUser:
                {
                    system("clear"); _ShowDeleteUsersScreen(); _GoBackToManageUserMenue();
                    break;
                }
                case enManageUserMenuOptions::eUpdateUser:
                {
                    system("clear"); _ShowUpdateUsersScreen(); _GoBackToManageUserMenue();
                    break;
                }
                case enManageUserMenuOptions::eFindUser:
                {
                    system("clear"); _ShowFindUsersScreen(); _GoBackToManageUserMenue();
                    break;
                }
                case enManageUserMenuOptions::eMainMenue:
                {
                    break;
                }
            }
        }
};

#endif // CLSMANAGEUSERSCREEN_H
