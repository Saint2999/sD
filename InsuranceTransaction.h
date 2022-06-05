#pragma once

#include "InsuranceApplication.h"

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class InsuranceTransaction
{
    private:
        string typeOfTransaction;
        
        int date;
        
        InsuranceApplication application;
        
        float paymentAmount;
        
        string filePath;
        
	public:
        InsuranceTransaction();
        
		InsuranceTransaction(string tempTypeOfTransaction, int tempDate, InsuranceApplication tempApplication, string tempFilePath);
		
        string getTypeOfTransaction();
        
        int getDate();
        
        InsuranceApplication getInsuranceApplication();
        
        float getPaymentAmount();
        
        void getReceipt();
};