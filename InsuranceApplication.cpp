#include "InsuranceApplication.h"

InsuranceApplication::InsuranceApplication()
{
    passportNumber = expirationDate = 0;
    filePath = "_";
}

InsuranceApplication::InsuranceApplication(int tempPassportNumber, int tempExpirationDate, string tempFilePath, Insurance tempInsurance): Insurance(tempInsurance)
{
    passportNumber = tempPassportNumber;
    expirationDate = tempExpirationDate;
    filePath = tempFilePath;
}

int InsuranceApplication::getPassportNumber()
{
    return passportNumber;
}

int InsuranceApplication::getExpirationDate()
{
    return expirationDate;
}

void InsuranceApplication::getDocument() {}