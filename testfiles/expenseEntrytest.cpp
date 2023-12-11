#include "gtest/gtest.h"
#include "../expenseEntryHeader/ExpenseEntry.h"

TEST(ExpenseEntryTest, defaultconstruct) {
    ExpenseEntry anEntry;
    string str1 = "";
    string str2 = "0/0/0";
    string str3 = "";
    string str4 = anEntry.getCategory();
    string str5 = anEntry.getDate();
    string str6 = anEntry.getDescription();
    
    EXPECT_EQ(0.0, anEntry.getAmount());
    EXPECT_STREQ(str1.c_str(), str4.c_str());
    EXPECT_STREQ(str2.c_str(), str5.c_str());
    EXPECT_STREQ(str3.c_str(), str6.c_str());
    EXPECT_EQ(0, anEntry.getSID());
}

TEST(ExpenseEntryTest, parameterconstruct) {
    ExpenseEntry anEntry1(250.99, "Supplies", "Papers and Desk Supplies", 11, 18, 2023);
    string str7 = "Supplies";
    string str8 = "11/18/2023";
    string str9 = "Papers and Desk Supplies";
    string str10 = anEntry1.getCategory();
    string str11 = anEntry1.getDate();
    string str12 = anEntry1.getDescription();
    
    EXPECT_EQ(250.99, anEntry1.getAmount());
    EXPECT_STREQ(str7.c_str(), str10.c_str());
    EXPECT_STREQ(str8.c_str(), str11.c_str());
    EXPECT_STREQ(str9.c_str(), str12.c_str());
    EXPECT_EQ(1, anEntry1.getSID());
}

TEST(ExpenseEntryTest, SetAmount) {
    ExpenseEntry anEntry2;
    anEntry2.setAmount(150);

    EXPECT_EQ(150, anEntry2.getAmount());
}

TEST(ExpenseEntryTest, SetCategory) {
    ExpenseEntry anEntry3;
    anEntry3.setCategory("Repairs");
    string str13 = "Repairs";
    string str14 = anEntry3.getCategory();

    EXPECT_STREQ(str13.c_str(), str14.c_str());
}

TEST(ExpenseEntryTest, SetDate) {
    ExpenseEntry anEntry4;
    anEntry4.setDate(11, 18, 2023);
    string str15 = "11/18/2023";
    string str16 = anEntry4.getDate();

    EXPECT_STREQ(str15.c_str(), str16.c_str());
}

TEST(ExpenseEntryTest, SetDescription) {
    ExpenseEntry anEntry5;
    anEntry5.setDescription("Lobby and Office Supplies");
    string str17 = "Lobby and Office Supplies";
    string str18 = anEntry5.getDescription();

    EXPECT_STREQ(str17.c_str(), str18.c_str());
}

TEST(ExpenseEntryTest, SetSID) {
    ExpenseEntry anEntry6;
    anEntry6.setSID();

    EXPECT_NE(0, anEntry6.getSID());
}

