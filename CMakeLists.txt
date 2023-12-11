cmake_minimum_required(VERSION 3.20)

ADD_SUBDIRECTORY(googletest)

project(SQLiteExample)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    ./resource/sqlite3.c
    ./adminsrc/test.cpp
    ./resource/BWCRUD.cpp
    ./resource/BWSQL.cpp
    ./expenseEntrysrc/ExpenseEntry.cpp
    ./adminsrc/Admin.cpp
    ./adminsrc/Employee.cpp
)

set(SOURCES1
    ./resource/sqlite3.c
    ./adminsrc/test.cpp
    ./resource/BWCRUD.cpp
    ./resource/BWSQL.cpp
    ./expenseEntrysrc/ExpenseEntry.cpp
    ./adminsrc/Employee.cpp
    ./adminsrc/Admin.cpp
)

set(SOURCES2
    ./resource/sqlite3.c
    ./adminsrc/display.cpp
    ./resource/BWCRUD.cpp
    ./resource/BWSQL.cpp
    ./expenseEntrysrc/ExpenseEntry.cpp
    ./adminsrc/Employee.cpp
    ./adminsrc/Admin.cpp
)

set(SOURCES3
    ./resource/sqlite3.c
    ./testfiles/expenseEntrytest.cpp
    ./testfiles/employeetest.cpp
    ./testfiles/admintest.cpp
    ./resource/BWCRUD.cpp
    ./resource/BWSQL.cpp
    ./expenseEntrysrc/ExpenseEntry.cpp
    ./adminsrc/Employee.cpp
    ./adminsrc/Admin.cpp
)

add_executable(valgrind ${SOURCES2})

add_executable(test ${SOURCES3})

add_executable(display ${SOURCES2})

add_executable(admin ${SOURCES})

add_executable(employee ${SOURCES1})

# Link against SQLite
target_link_libraries(admin PRIVATE dl)
target_link_libraries(admin PRIVATE pthread)

target_link_libraries(employee PRIVATE dl)
target_link_libraries(employee PRIVATE pthread)

target_link_libraries(display PRIVATE dl)
target_link_libraries(display PRIVATE pthread)

target_link_libraries(valgrind PRIVATE dl)
target_link_libraries(valgrind PRIVATE pthread)


target_link_libraries(test PRIVATE dl pthread gtest)
target_compile_definitions(test PRIVATE gtest_disable_pthreads=ON)
