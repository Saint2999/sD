#pragma once

#include "Insurance.h"

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class InsuranceDatabase
{
    private:
        map<int, Insurance> insurances;

	public:
		InsuranceDatabase();

		void addInsurance(Insurance insurance);

        void deleteInsurance(int id);
        
        Insurance getInsurance(int id);	
};