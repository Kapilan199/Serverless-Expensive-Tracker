// main.cpp

#include "../adminheader/Admin.h"
#include "../expenseEntryHeader/ExpenseEntry.h"

#include "../adminheader/Employee.h"
#include <iostream>

int main() {
    Admin admin;
    Employee employee;
    ExpenseEntry expenseReport(250.99, "Supplies", "Papers and Desk Supplies", 11, 18, 2023);
    ExpenseEntry expenseReport1(20050.99, "Supplies", "Papers and Desk Supplies", 11, 18, 2023);
    // Call the submitReport function
    admin.submitReport(expenseReport);

  //  admin.modifyReport("1");

    employee.submitReport(expenseReport1);

    admin.displayreport();

    return 0;
}
