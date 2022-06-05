#pragma once

#include "Insurance.h"

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class InsuranceApplication: public Insurance
{
    private:
        int passportNumber;

        int expirationDate;

        string filePath;

	public:
        InsuranceApplication();
        
		InsuranceApplication(int tempPassportNumber, int tempExpirationDate, string tempFilePath, Insurance tempInsurance);
		
        int getPassportNumber();
        
        int getExpirationDate();

        void getDocument();
};