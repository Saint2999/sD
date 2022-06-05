#pragma once

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class Insurance
{
    protected:
        int id;

        float fee;

        float amount;

        map<string, string> details;

	public:
        Insurance(){}

		Insurance(int tempId, float tempFee, float tempAmount);

		int getId();

        float getFee();

        float getAmount();

        string getDetails(string query);

        void setDetails(string query, string entry);	
};
