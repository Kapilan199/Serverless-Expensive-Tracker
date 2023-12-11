#include "gtest/gtest.h"
#include "admin.h"

TEST(admintest, test1){
    ExpenseEntry *entry1 = new ExpenseEntry(1, "hr","blah blah balh",316.34,"3/14/20",36);

 
    ASSERT_TRUE(ExpenseEntry->submitReport(entry1, entry1));
}

TEST(admintest, test2){
    ExpenseEntry *entry2 = new ExpenseEntry(1, "hr","blah blah balh",316.34,"3/14/20",36);


    ASSERT_TRUE(ExpenseEntry->modifyReport(entry2, entry2));
}
