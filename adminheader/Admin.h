#ifndef ADMIN_H
#define ADMIN_H

#include "../expenseEntryHeader/ExpenseEntry.h"

class Admin {
public:
    void submitReport(ExpenseEntry report);
    void modifyReport(string id);
    void modifyReport_name(string amount);
    void displayreport();
    string getRow(int id);
};

#endif // ADMIN_H
