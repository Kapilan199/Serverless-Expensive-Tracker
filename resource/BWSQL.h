#ifndef BWSQL_H
#define BWSQL_H

#include "../adminheader/sqlite3.h"
#include "../adminheader/sqlcpp.h"
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <memory>

namespace bw {

#define _BWSQL_VERSION "1.0.7"

class BWSQL {
    const char * _filename = nullptr;
    sqlite3 * _db = nullptr;
    sqlite3_stmt * _stmt = nullptr;
    int _num_sql_columns = 0;
    const char ** _sql_colnames = nullptr;
    const char ** _row =  nullptr;

public:
    // ctor/dtor
    BWSQL(const char * filename);
    ~BWSQL();

    // sql methods
    int sql_prepare(const char * sql, ...);
    int sql_do(const char * sql, ...);
    const char * sql_value(const char * sql, ...);
    const char ** fetch_row();
    int num_sql_columns() const;

    // utilities
    const char * filename();
    void reset_stmt();
    void reset();
    sqlite3 * db() const;
    sqlite3_stmt * stmt() const;

    // rule of five stuff idk
    BWSQL()                     = delete;   // no default constructor
    BWSQL(const BWSQL &)        = delete;   // no copy
    BWSQL & operator = (BWSQL)  = delete;   // no assignment
    BWSQL(BWSQL &&)             = delete;   // no move

private:
    void _init();

protected:
    int _sql_prepare(const char * sql, va_list ap);
};

}

#endif // BWSQL_H
