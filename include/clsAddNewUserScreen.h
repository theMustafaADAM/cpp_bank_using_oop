#ifndef CLSADDNEWUSERSCREEN_H
#define CLSADDNEWUSERSCREEN_H

#include "../../OOP_Projects_InputValidation/include/clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsers.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
    public:
        clsAddNewUserScreen();
        virtual ~clsAddNewUserScreen();

        static void ShowAddNewUserScreen()
        {
            _DrawScreenHeader("\t  Add New User Screen");
            string Username = "";
            cout << "\n\n\tFirst, Let's check if chosen username existing! ";
            cout << "\n\n\tKindly enter new username : ";
            Username = clsInputValidate::UpperString(clsInputValidate::ReadString());
            while(clsUsers::IsUserExist(Username))
            {
                cout << "\n\tThe entered username is already exist, Kindly write a new one : ";
                Username = clsInputValidate::UpperString(clsInputValidate::ReadString());
            }
            cout << "\n\n\tYour entered [ " + Username + " ] is new username ! Would you like to continue ? [ y / n ] ? ";
            char answer ='n'; cin>>answer;
            if(!clsInputValidate::AnswerYesNo(answer))
            {
                cout << "\n\n\tError : Adding a new user was canceled !\n\n"; return;
            }
            else {
                clsUsers newUser = clsUsers::GetAddNewUserObject(Username);
                cout << "\n\n\tAdd New user Info under username no. [ " + Username + " ] : ";
                cout << "\n\n\t----------------------------------";
                _ReadUserInfo(newUser);
                clsUsers::enSaveResults SaveResult;
                SaveResult = newUser.Save();
                switch(SaveResult)
                {
                    case clsUsers::enSaveResults::svSucceded:
                    {
                        cout << "\n\n\tUser Added Successfully :-)\n";
                        _PrintUser(newUser); break;
                    }
                    case clsUsers::enSaveResults::svFailUsernameExist:
                    {
                        cout << "\n\n\tError : User was not saved : Acc. is exist!\n"; break;
                    }
                    case clsUsers::enSaveResults::svFailEmptyObject:
                    {
                        cout << "\n\n\tError : User was not saved : it's empty!"; break;
                    }
                }
            }
        }

    private:

        static void _ReadUserInfo(clsUsers& user)
        {
            cout << "\n\n\tEnter First Name       : " ; user.Set_FrstName(clsInputValidate::ReadString());
            cout << "\n\tEnter Last  Name       : " ; user.Set_LastName(clsInputValidate::ReadString());
            cout << "\n\tEnter the Email        : " ; user.Set_Email(clsInputValidate::ReadString());
            cout << "\n\tEnter the Phone        : " ; user.Set_Phone(clsInputValidate::ReadString());
            cout << "\n\tEnter the Password     : " ; user.Set_Password(clsInputValidate::ReadString());
            cout << "\n\tSelect the Permissions : " ; user.Set_Permession(_ReadPermissionsToSet());
            cout << "\n\t----------------------------------";
        }

        static int _ReadPermissionsToSet()
        {
            int permissions = 0;
            char answer = 'n';
            cout << "\tDo you want to give this user full access ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                return -1;
            }
            cout << "\n\tDo you want to give this user access to : \n\n";
            cout << "\t- Show Client List ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pListClients;
            }
            cout << "\n\t- Add New Client ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pAddNewClient;
            }
            cout << "\n\t- Delete Client ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pDeleteClient;
            }
            cout << "\n\t- Update Client ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pUpdateClient;
            }
            cout << "\n\t- Find Clients ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pFindClient;
            }
            cout << "\n\t- Transactions ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pTransactions;
            }
            cout << "\n\t- Manage Users ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pManageUsers;
            }
            cout << "\n\t- Showing Login Records ? [ y / n ] ";
            cin>>answer;
            if(clsInputValidate::AnswerYesNo(answer))
            {
                permissions += clsUsers::enPermissions::pLoginRegister;
            }
            return permissions;
        }

        static void _PrintUser(clsUsers user)
        {
            cout << "\n\n\tUser Card: ";
            cout << "\n\t----------------------------------";
            cout << "\n\n\tUsername     : " << user.Get_Username();
            cout << "\n\n\tFirst Name   : " << user.Get_FrstName();
            cout << "\n\tLast  Name   : "   << user.Get_LastName();
            cout << "\n\tFull  Name   : "   << user.FullName();
            cout << "\n\n\tEmail        : " << user.Get_Email();
            cout << "\n\tPhone        : "   << user.Get_Phone();
            cout << "\n\n\tPassword     : " << user.Get_Password();
            cout << "\n\tPermissions  : "   << user.Get_Permession();
            cout << "\n\n\t----------------------------------";
        }
};

#endif // CLSADDNEWUSERSCREEN_H
