#pragma once

#include "InsuranceTransaction.h"
#include "InsuranceApplication.h"

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class CustomerInfo
{
    private:
        int passportNumber;

        bool blacklistStatus;

        map<string, string> details;

        map<int, InsuranceApplication> activeInsurances;

        map<int, InsuranceApplication> inactiveInsurances;

        map<int, InsuranceTransaction> insuranceTransactions;
        
	public:
        CustomerInfo();

		CustomerInfo(int tempPassportNumber, bool tempBlacklistStatus, InsuranceApplication insuranceApplication);

        map<int, InsuranceApplication> getActiveInsurances();

        map<int, InsuranceApplication> getInactiveInsurances();

        map<int, InsuranceTransaction> getInsuranceTransactions();

        int getPassportNumber();

        bool getBlacklistStatus();

        string getDetails(string query);

        void addActiveInsurance(InsuranceApplication application);

        void addInsuranceTransaction(InsuranceTransaction transaction);

        void setPassportNumber(int tempPassportNumber);

        void setBlacklistStatus(bool tempBlacklistStatus);

        void setDetails(string query, string entry);

        void setInsuranceStatusInactive(int id);
};