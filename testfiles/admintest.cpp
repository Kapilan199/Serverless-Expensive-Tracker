#include "gtest/gtest.h"
#include "../adminheader/Admin.h"
#include "../expenseEntryHeader/ExpenseEntry.h"
#include <cstdio>
#include "../resource/BWCRUD.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(admintest, test1){
    Admin admin;
    
    ExpenseEntry expenseReport1(20050.99, "Supplies", "Papers and Desk Supplies", 10, 10, 10);
     admin.submitReport(expenseReport1);

  

       EXPECT_EQ(admin.getRow(5), " 5 250.99 Supplies 11/18/2023 Papers and Desk Supplies" ); 
}


TEST(admintest, test2){
    Admin admin;
    
    ExpenseEntry expenseReport1(20050.99, "Supplies", "Papers and Desk Supplies", 10, 10, 10);
     admin.submitReport(expenseReport1);

  

       EXPECT_NE(admin.getRow(6), " 5 250.99 Supplies 11/18/2023 Papers and Desk Supplies" ); 
}

TEST(admintest, test3) {

    Admin admin;
    ExpenseEntry expenseReport1(20050.99, "test", "Papers and Desk Supplies", 10, 10, 10);
    admin.submitReport(expenseReport1);


   
    EXPECT_EQ(admin.getRow(14), " 14 20050.99 Supplies 10/10/10 Papers and Desk Supplies" ); 

}

TEST(admintest, test4) {

    Admin admin;
    ExpenseEntry expenseReport1(20050.99, "test", "Papers and Desk Supplies", 10, 10, 10);
    admin.submitReport(expenseReport1);
    admin.modifyReport("10");

   
    ASSERT_TRUE(admin.getRow(10)==""); 

}




