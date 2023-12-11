#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../expenseEntryHeader/ExpenseEntry.h"

class Employee {
public:
    void submitReport(ExpenseEntry report);
    string getRow(int id);
};

#endif // EMPLOYEE_H
