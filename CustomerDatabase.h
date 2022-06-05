#pragma once

#include "CustomerInfo.h"

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class CustomerDatabase
{
    private:
        map<int, CustomerInfo> customers;
        
	public:
		CustomerDatabase();

        void addCustomer(CustomerInfo customerInfo);

        CustomerInfo getCustomerInfo(int passportNumber);

        bool checkCustomerInfo(int passportNumber);
};