#ifndef EXPENSEENTRY_H
#define EXPENSEENTRY_H

#include <iostream>
#include <string>
#include <vector>
//#include "Admin.h"

using namespace std;

class ExpenseEntry {
//friend class Admin;
private:
    // Private member variables
    //int reportID; reportID will is now based on the position in vector
    string reportCategory;
    string reportDescription;
    double reportAmount;
    int reportDate[3];
    int submitterID;
    /*submitterID will be set using the getter of the respective class, thus ExpenseEntry
    would need to be a friend class of the employee/admin class*/
    // Add more member variables as needed

public:
    //constructors
    ExpenseEntry();  //default
    ExpenseEntry(double amount, string cateogry,  string description, int month, int day, int year);

    //destructor
    ~ExpenseEntry();

    //setters
    void setAmount(double amount);
    void setCategory(string Category);
    void setDate(int month, int day, int year);
    void setDescription(string Description);
    void setSID();

    //getters
    double getAmount();
    string getCategory();
    string getDate();
    string getDescription();
    int getSID();
    
    //void displayExpenseReport();
};

#endif //EXPENSEENTRY_H