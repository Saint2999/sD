#include "CustomerDatabase.h"

CustomerDatabase::CustomerDatabase()
{
    CustomerInfo *customer = new CustomerInfo;
    customers[0] = *customer;
}
void CustomerDatabase::addCustomer(CustomerInfo customerInfo)
{
    customers[customerInfo.getPassportNumber()] = customerInfo;
}

CustomerInfo CustomerDatabase::getCustomerInfo(int passportNumber)
{
    return customers[passportNumber];
}

bool CustomerDatabase::checkCustomerInfo(int passportNumber)
{
    if (customers.find(passportNumber) != customers.end())
        return true;
        else
            return false;
}