#include "gtest/gtest.h"
#include "../adminheader/Employee.h"
#include "../expenseEntryHeader/ExpenseEntry.h"
#include <cstdio>
#include "../resource/BWCRUD.h"


TEST(employeetest, test1){
     Employee employee;
    
    ExpenseEntry expenseReport1(20050.99, "Supplies", "Papers and Desk Supplies", 10, 10, 10);
     employee.submitReport(expenseReport1);

  

       EXPECT_EQ(employee.getRow(5), " 5 250.99 Supplies 11/18/2023 Papers and Desk Supplies" ); 
}


TEST(employeetest, test2){
      Employee employee;
    
    ExpenseEntry expenseReport1(20050.99, "Supplies", "Papers and Desk Supplies", 10, 10, 10);
     employee.submitReport(expenseReport1);

  

       EXPECT_NE(employee.getRow(6), " 5 250.99 Supplies 11/18/2023 Papers and Desk Supplies" ); 
}

TEST(employeetest, test3) {

      Employee employee;
    ExpenseEntry expenseReport1(20050.99, "test", "Papers and Desk Supplies", 10, 10, 10);
    employee.submitReport(expenseReport1);


   
    EXPECT_EQ(employee.getRow(14), " 14 20050.99 Supplies 10/10/10 Papers and Desk Supplies" ); 

}






