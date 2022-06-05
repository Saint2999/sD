#include "Insurance.h"

Insurance::Insurance(int tempId, float tempFee, float tempAmount)
{
    id = tempId; fee = tempFee; amount = tempAmount;
}

int Insurance::getId()
{
    return id;
}

float Insurance::getFee()
{
    return fee;
}

float Insurance::getAmount()
{
    return amount;
}

string Insurance::getDetails(string query)
{
    return details[query];
}

void Insurance::setDetails(string query, string entry)
{
    details[query] = entry;
}