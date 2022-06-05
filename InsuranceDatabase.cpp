#include "InsuranceDatabase.h"

InsuranceDatabase::InsuranceDatabase() {}

void InsuranceDatabase::addInsurance(Insurance insurance)
{
    insurances[insurance.getId()] = insurance;
}

void InsuranceDatabase::deleteInsurance(int id)
{
    insurances.erase(id);
}

Insurance InsuranceDatabase::getInsurance(int id)
{
    return insurances[id];
}
