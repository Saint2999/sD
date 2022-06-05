#include "InsuranceTransaction.h"

InsuranceTransaction::InsuranceTransaction()
{
    typeOfTransaction = "_";
    date = 0;
    InsuranceApplication *tempApplication = new InsuranceApplication;
    application = *tempApplication;
    delete tempApplication;
    paymentAmount = 0;
    filePath = "_";
}

InsuranceTransaction::InsuranceTransaction(string tempTypeOfTransaction, int tempDate, InsuranceApplication tempApplication, string tempFilePath)
{
    typeOfTransaction = tempTypeOfTransaction;
    date = tempDate;
    application = tempApplication;
    if (typeOfTransaction.compare("Страховая выплата")) paymentAmount = application.getFee();
    else paymentAmount = application.getAmount();
    filePath = tempFilePath;
}

string InsuranceTransaction::getTypeOfTransaction()
{
    return typeOfTransaction;
}

int InsuranceTransaction::getDate()
{
    return date;
}

InsuranceApplication InsuranceTransaction::getInsuranceApplication()
{
    return application;
}

float InsuranceTransaction::getPaymentAmount()
{
    return paymentAmount;
}

void InsuranceTransaction::getReceipt() {}
