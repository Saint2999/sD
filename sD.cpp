#include "Insurance.h"
#include "InsuranceDatabase.h"
#include "InsuranceApplication.h"
#include "InsuranceTransaction.h"
#include "CustomerInfo.h"
#include "CustomerDatabase.h"
#include "userInterface.h"

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

int main()
{
    userInterface ui;
    InsuranceDatabase insuranceDB;
    CustomerDatabase customerDB;
    CustomerInfo *customer = 0;
    Insurance *insurance = 0;
    InsuranceApplication *insuranceApp = 0;
    InsuranceTransaction *insuranceTrans = 0; 
    delete customer;
    int tempInt1, tempInt2, tempInt3, i;
    float tempFloat1, tempFloat2;
    string tempString1, tempString2;
    ui.displayDayModeChoice();
    ui.menu();
    do
    {
        ui.setChoiceMenu(ui.menuChoice(ui.getChoiceMenu()));
        switch (ui.getChoiceMenu())
        {
            case 0: 
                ui.displayMessage("Введите идентификационный номер формы страховки, размер взноса и выплаты");
                cin >> tempInt1 >> tempFloat1 >> tempFloat2;
                insurance = new Insurance(tempInt1, tempFloat1, tempFloat2);
                insuranceDB.addInsurance(*insurance);
                delete insurance;
                ui.successMessage(1000);
                break;

            case 1:
                ui.displayMessage("Введите идентификационный номер формы страховки, номер паспорта клиента и текущую дату в виде (20220525)");
                cin>>tempInt1 >> tempInt2 >> tempInt3;
                tempInt3 += 10000;
                insuranceApp = new InsuranceApplication(tempInt2, tempInt3, "_", insuranceDB.getInsurance(tempInt1));
                if (customerDB.checkCustomerInfo(tempInt2))
                {
                    if (!customerDB.getCustomerInfo(tempInt2).getBlacklistStatus())
                    {
                        customer = new CustomerInfo(customerDB.getCustomerInfo(tempInt2));
                        customer->addActiveInsurance(*insuranceApp);
                        customerDB.addCustomer(*customer);
                    }
                }
                    else
                    {
                        customer = new CustomerInfo(insuranceApp->getPassportNumber(), false, *insuranceApp);
                        customerDB.addCustomer(*customer);
                    }
                delete insuranceApp;
                delete customer;
                ui.successMessage(1000);
                break;

            case 2:
                ui.displayMessage("Введите номер паспорта, идентификационный номер страховки, текущую дату в виде (20220525) и вид транзакции ('Взнос' или 'Выплата')");
                cin >> tempInt1 >> tempInt2 >> tempInt3 >> tempString1;
                insuranceTrans = new InsuranceTransaction(tempString1, tempInt3, customerDB.getCustomerInfo(tempInt1).getActiveInsurances()[tempInt2], "_");
                if (!customerDB.getCustomerInfo(tempInt1).getBlacklistStatus())
                    {
                        customer = new CustomerInfo(customerDB.getCustomerInfo(tempInt1));
                        customer->addInsuranceTransaction(*insuranceTrans);
                        customerDB.addCustomer(*customer);
                    }
                delete insuranceTrans;
                delete customer;
                ui.successMessage(1000);
                break;

            case 3:
                ui.displayMessage("Введите номер паспорта, идентификационный номер страховки и дату траназакции");
                cin >> tempInt1 >> tempInt2 >> tempInt3;
                ui.deleteLine(ui.getDefaultX(), ui.getDefaultY() + 6);
                cout << "Идентификационный номер страхвоки: " << customerDB.getCustomerInfo(tempInt1).getActiveInsurances().at(tempInt2).getId();
                cout << " Тип транзакции: " << customerDB.getCustomerInfo(tempInt1).getInsuranceTransactions().at(tempInt3).getTypeOfTransaction();
                cout << " Размер транзакции: " << customerDB.getCustomerInfo(tempInt1).getInsuranceTransactions().at(tempInt3).getPaymentAmount();
                ui.successMessage(10000);
                ui.deleteTableContent();
                break;

            case 4:
                ui.displayMessage("Введите номер паспорта и идентификационный номер страховки");
                cin >> tempInt1 >> tempInt2;
                ui.deleteLine(ui.getDefaultX(), ui.getDefaultY() + 6);
                cout << "Идентификационный номер страхвоки: " << customerDB.getCustomerInfo(tempInt1).getActiveInsurances()[tempInt2].getId();
                cout << " Размер взноса: " << customerDB.getCustomerInfo(tempInt1).getActiveInsurances().at(tempInt2).getFee(); 
                cout << " Размер выплаты: " << customerDB.getCustomerInfo(tempInt1).getActiveInsurances().at(tempInt2).getAmount();
                ui.successMessage(10000);
                ui.deleteTableContent();
                break;

            case 5:
                ui.displayMessage("Введите номер паспорта и запрос (например, 'Фамилия')");
                cin >> tempInt1 >> tempString1;
                ui.deleteLine(ui.getDefaultX(), ui.getDefaultY() + 6);
                cout << tempString1 << ": " <<customerDB.getCustomerInfo(tempInt1).getDetails(tempString1);
                ui.successMessage(10000);
                ui.deleteTableContent();
                break;

            case 6:
                ui.displayMessage("Введите идентификационный номер страховки и запрос (например, 'Вид')");
                cin >> tempInt1 >> tempString1;
                ui.deleteLine(ui.getDefaultX(), ui.getDefaultY() + 6);
                cout << tempString1 << ": " <<insuranceDB.getInsurance(tempInt1).getDetails(tempString1);
                ui.successMessage(10000);
                ui.deleteTableContent();
                break;

            case 7: 
                ui.displayMessage("Введите номер паспорта, запрос (например, 'Фамилия') и необходимую запись");
                cin >> tempInt1 >> tempString1 >> tempString2;
                customer = new CustomerInfo(customerDB.getCustomerInfo(tempInt1));
                customer->setDetails(tempString1, tempString2);
                customerDB.addCustomer(*customer);
                ui.successMessage(1000);
                delete customer;
                break;

            case 8: 
                ui.displayMessage("Введите идентификационный номер страховки, запрос (например, 'Вид') и необходимую запись");
                cin >> tempInt1 >> tempString1 >> tempString2;
                insurance = new Insurance(insuranceDB.getInsurance(tempInt1));
                insurance->setDetails(tempString1, tempString2);
                insuranceDB.addInsurance(*insurance);
                ui.successMessage(1000);
                delete insurance;
                break;

            case 9: 
                ui.displayMessage("Введите номер паспорта и нужный статус (1 - в черном списке, 0 - нет");
                cin >> tempInt1 >> tempInt2;
                customer = new CustomerInfo(customerDB.getCustomerInfo(tempInt1));
                customer->setBlacklistStatus(tempInt2);
                customerDB.addCustomer(*customer);
                ui.successMessage(1000);
                delete customer;
                break;

            case 10: 
                ui.displayMessage("Введите номер паспорта и идентификационный номер страховки для деактивации");
                cin >> tempInt1 >> tempInt2;
                customer = new CustomerInfo(customerDB.getCustomerInfo(tempInt1));
                customer->setInsuranceStatusInactive(tempInt2);
                customerDB.addCustomer(*customer);
                ui.successMessage(1000);
                delete customer;
                break;

            case 11:
                ui.displayMessage("Введите идентификационный номер страховки");
                cin >> tempInt1;
                insuranceDB.deleteInsurance(tempInt1);
                ui.successMessage(1000);
                break;

            case 12: break;
        }
    } while (ui.getChoiceMenu() != 12);
    system("cls");
    ui.setCursorPosition(0, ui.getDefaultY() + 30);
    int k = 30;
    while (k--) cout << "V";
    ui.setCursorPosition(0, ui.getDefaultY() + 30);
}