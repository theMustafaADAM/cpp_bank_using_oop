#ifndef CLSPERSON_H
#define CLSPERSON_H

#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
    private:
        string _FrstName;
        string _LastName;
        string _Email;
        string _Phone;

    public:
        clsPerson(string FrstName, string LastName, string Email, string Phone) :
            _FrstName(FrstName), _LastName(LastName), _Email(Email), _Phone(Phone) {    }
        virtual ~clsPerson(){   }

        string Get_FrstName()           { return _FrstName; }
        void Set_FrstName(string val)   { _FrstName = val; }

        string Get_LastName()           { return _LastName; }
        void Set_LastName(string val)   { _LastName = val; }

        string Get_Email()              { return _Email; }
        void Set_Email(string val)      { _Email = val; }

        string Get_Phone()              { return _Phone; }
        void Set_Phone(string val)      { _Phone = val; }

        string FullName()
        {
            return _FrstName + " " + _LastName ;
        }

    protected:
};

#endif // CLSPERSON_H
