#include "CustomerInfo.h"

CustomerInfo::CustomerInfo()
{
    passportNumber = 0;
    blacklistStatus = 0;
}

CustomerInfo::CustomerInfo(int tempPassportNumber, bool tempBlacklistStatus, InsuranceApplication insuranceApplication)
{
    passportNumber = tempPassportNumber;
    blacklistStatus = tempBlacklistStatus;
    activeInsurances[insuranceApplication.getId()] = insuranceApplication;
}

map<int, InsuranceApplication> CustomerInfo::getActiveInsurances()
{
    return activeInsurances;
}

map<int, InsuranceApplication> CustomerInfo::getInactiveInsurances()
{
    return inactiveInsurances;
}

map<int, InsuranceTransaction> CustomerInfo::getInsuranceTransactions()
{
    return insuranceTransactions;
}

int CustomerInfo::getPassportNumber()
{
    return passportNumber;
}

bool CustomerInfo::getBlacklistStatus()
{
    return blacklistStatus;
}
string CustomerInfo::getDetails(string query)
{
    return details[query];
}

void CustomerInfo::addActiveInsurance(InsuranceApplication application)
{
    activeInsurances[application.getId()] = application;
}

void CustomerInfo::addInsuranceTransaction(InsuranceTransaction transaction)
{
    insuranceTransactions[transaction.getDate()] = transaction;
}

void CustomerInfo::setPassportNumber(int tempPassportNumber)
{
    passportNumber = tempPassportNumber;
}

void CustomerInfo::setBlacklistStatus(bool tempBlacklistStatus)
{
    blacklistStatus = tempBlacklistStatus;
}

void CustomerInfo::setDetails(string query, string entry)
{
    details[query] = entry;
}

void CustomerInfo::setInsuranceStatusInactive(int id)
{
    inactiveInsurances[id] = activeInsurances[id];
    activeInsurances.erase(id);
}