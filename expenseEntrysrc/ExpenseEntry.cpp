#include "../expenseEntryHeader/ExpenseEntry.h"

// Default constructor
ExpenseEntry::ExpenseEntry() {
    reportCategory = "";
    reportDescription = "";
    reportAmount = 0.0;
    reportDate[1] = 0;
    reportDate[0] = 0;
    reportDate[2] = 0;
    submitterID = 0;
}

// Parameterized constructor
ExpenseEntry::ExpenseEntry(double amount, string category, string description, int month, int day, int year) {
    reportAmount = amount;
    reportCategory = category;
    reportDescription = description;
    reportDate[1] = day;
    reportDate[0] = month;
    reportDate[2] = year;

    submitterID = 1; //thissubmitter->getMemberID();
}

// Destructor
ExpenseEntry::~ExpenseEntry() {
}

// Setters
void ExpenseEntry::setAmount(double amount) {
    reportAmount = amount;
}

void ExpenseEntry::setCategory(string category) {
    reportCategory = category;
}

void ExpenseEntry::setDate(int month, int day, int year) {
    reportDate[1] = day;
    reportDate[0] = month;
    reportDate[2] = year;
}

void ExpenseEntry::setDescription(string description) {
    reportDescription = description;
}

void ExpenseEntry::setSID() {
    this->submitterID = 1;
}

// Getters
double ExpenseEntry::getAmount() {
    return reportAmount;
}

string ExpenseEntry::getCategory() {
    return reportCategory;
}

string ExpenseEntry::getDate() {
    string expenseprinted = to_string(reportDate[0]) + "/" + to_string(reportDate[1]) + "/" + to_string(reportDate[2]);
    return expenseprinted;
}

string ExpenseEntry::getDescription() {
    return reportDescription;
}

int ExpenseEntry::getSID() {
    return submitterID;
}
