#ifndef CLSPERIOD_H
#define CLSPERIOD_H

#include "../../OOP_Projects_Date/include/clsDate.h"
#include <iostream>

using namespace std;

class clsPeriod
{
    private:

    public:
        clsDate _frstDate;
        clsDate _scndDate;

        clsPeriod(clsDate frstDate, clsDate scndDate)
        {
            this->_frstDate = frstDate;
            this->_scndDate = scndDate;
        }
        virtual ~clsPeriod()
        {

        }

        clsDate Get_frstDate()          { return _frstDate; }
        void Set_frstDate(clsDate val)  { _frstDate = val; }
        clsDate Get_scndDate()          { return _scndDate; }
        void Set_scndDate(clsDate val)  { _scndDate = val; }

        enum enCompareDates{ Befor=-1, Equal = 0, After = 1};
        static bool IsOverLapPeriods(clsPeriod FrstPriod, clsPeriod ScndPriod)
        {
            if(clsDate::CompareTowDates( ScndPriod._scndDate, FrstPriod._frstDate )
               == clsDate::enCompareDates::Befor ||
               clsDate::CompareTowDates( ScndPriod._frstDate, FrstPriod._scndDate )
               == clsDate::enCompareDates::After)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool IsOverLapPeriods(clsPeriod ScndPriod)
        {
            return IsOverLapPeriods(*this, ScndPriod);
        }

        void Print()
        {
            cout << "\nPeriod Start : " ; _frstDate.Print();
            cout << "Period End   : " ; _scndDate.Print();
        }
};

#endif // CLSPERIOD_H
