#include "../adminheader/Admin.h"
#include "../expenseEntryHeader/ExpenseEntry.h"
#include <cstdio>
#include "../resource/BWCRUD.h"
#include <sstream>

void display_row(bw::BWCRUD & db, const char ** row) {
    for(int i = 0; i < db.col_count(); ++i) {
        printf("%s ", row[i]);
    }
    puts("");
}

void display_rows(bw::BWCRUD & db) {
    const char ** row = nullptr;
    while((row = db.fetch_row())) {
        display_row(db, row);
    }
}

void Admin::submitReport(ExpenseEntry report) {
    // code to submit an expense report as an admin
    
    // this would add a data record to the database
    constexpr const char * sql_drop =   "DROP TABLE IF EXISTS temp";
    constexpr const char * db_file =    DB_PATH "/expenseEntry.db";
    constexpr const char * table_name = "expenses";
    constexpr const char * sql_create = "CREATE TABLE IF NOT EXISTS expenses"
                                    "( id INTEGER PRIMARY KEY, a DOUBLE, b TEXT, c TEXT , d TEXT )";

    std::string getAmount = std::to_string(report.getAmount());
    std::string getCategory = report.getCategory();
    std::string getDate = report.getDate();
    std::string getDescription = report.getDescription();
                                    
    const char * insert_report[] = {
    getAmount.c_str(),
    getCategory.c_str(),
    getDate.c_str(),
    getDescription.c_str()
};

    bw::BWCRUD db(db_file, table_name);
    const char ** row = nullptr;
 //   puts(sql_drop);
    db.sql_do(sql_drop);
 //   puts(sql_create);
    db.sql_do(sql_create);
    puts("begin");
    db.begin();

        puts("insert rows");
    int num_cols = db.col_count() - 1;  // don't count id
    int num_rows = sizeof(insert_report) / sizeof(const char *) / num_cols;
    int index = 0;
    int count = 0;
    for(int row_no = 0; row_no < num_rows; ++row_no) {
        const char * col1 = insert_report[index++];
        const char * col2 = insert_report[index++];
        const char * col3 = insert_report[index++];
        const char * col4 = insert_report[index++];
        count += db.insert(0, col1, col2, col3, col4);
    }


    puts("commit");
    printf("%d rows inserted\n", count);
    db.commit();
    // puts("get rows");
    // db.get_rows();
    // display_rows(db);
    //     puts("drop table");
 

}

void Admin::modifyReport(string id) {
    // code to modify an expense report
    //this would work by checking the databse by primary key and then modifying accodringly
    constexpr const char * sql_drop =   "DROP TABLE IF EXISTS temp";
    constexpr const char * db_file =    DB_PATH "/expenseEntry.db";
    constexpr const char * table_name = "expenses";
    constexpr const char * sql_create = "CREATE TABLE IF NOT EXISTS expenses"
                                    "( id INTEGER PRIMARY KEY, a DOUBLE, b TEXT, c TEXT , d TEXT )";

    bw::BWCRUD db(db_file, table_name);
    const char ** row = nullptr;
    // puts(sql_drop);
    // db.sql_do(sql_drop);
  //  puts(sql_create);
    db.sql_do(sql_create);
  
   
  //  puts("find row id for b is four");
    int row_id = db.find_row_id("id", id.c_str());
  //  printf("row id is %d\n", row_id);
    row = db.get_row(row_id);
    display_row(db, row);

    printf("delete row %d\n", row_id);
    db.delete_row(row_id);

    // puts("get rows");
    // db.get_rows();
    // display_rows(db);





    //     puts("drop table");
    // db.drop_table();
}


void Admin::modifyReport_name(string amount) {
    // code to modify an expense report
    //this would work by checking the databse by primary key and then modifying accodringly
    constexpr const char * sql_drop =   "DROP TABLE IF EXISTS temp";
    constexpr const char * db_file =    DB_PATH "/expenseEntry.db";
    constexpr const char * table_name = "expenses";
    constexpr const char * sql_create = "CREATE TABLE IF NOT EXISTS expenses"
                                    "( id INTEGER PRIMARY KEY, a DOUBLE, b TEXT, c TEXT , d TEXT )";

    bw::BWCRUD db(db_file, table_name);
    const char ** row = nullptr;
    // puts(sql_drop);
    // db.sql_do(sql_drop);
    puts(sql_create);
    db.sql_do(sql_create);
  
   
 //   puts("find row id for b is four");
    int row_id = db.find_row_id("a", amount.c_str());
  //  printf("row id is %d\n", row_id);
    row = db.get_row(row_id);
    display_row(db, row);

    printf("delete row %d\n", row_id);
    db.delete_row(row_id);

    // puts("get rows");
    // db.get_rows();
    // display_rows(db);
    //     puts("drop table");
    // db.drop_table();
}


void Admin::displayreport() {
    constexpr const char * db_file =    DB_PATH "/expenseEntry.db";
    constexpr const char * table_name = "expenses";
    bw::BWCRUD db(db_file, table_name);
    const char ** row = nullptr;

    puts("get rows");
    db.get_rows();
    display_rows(db);
}

string Admin::getRow(int id) {
    constexpr const char * db_file =    DB_PATH "/expenseEntry.db";
    constexpr const char * table_name = "expenses";
    bw::BWCRUD db(db_file, table_name);
    const char ** row = nullptr;
    string total = "";
    row = db.get_row(id);

      for(int i = 0; i < db.col_count(); ++i) {
        total = total + " " + row[i];
    }

    return total;
    
 }