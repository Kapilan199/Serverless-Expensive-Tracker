#ifndef BWCRUD_H
#define BWCRUD_H

#include "BWSQL.h"

namespace bw {

#define _BWCRUD_VERSION "1.0.7"

class BWCRUD : public BWSQL {
    sqlite3 * _db;
    BWSQL * _sec_db = nullptr;   // for secondary queries
    const char * _table_name;
    const char ** _col_names;
    const char * _col_names_buf;
    int _col_count;

public:
    // ctor/dtor
    BWCRUD(const char * filename, const char * tablename = nullptr);

    // CRUD
    int insert(int zero, ...);
    int get_rows();
    int find_rows(const char * col, const char * value);
    const char ** find_row(const char * col, const char * value);
    int find_row_id(const char * col, const char * value);
    const char ** get_row(int id);
    int delete_row(int id);
    void begin();
    void commit();
    int col_count();
    const char ** col_names();
    int drop_table();


    // SQLITE SOURCE CODE DOCUMENTATION
    const char * cstring_join(int count, const char * sep, ...);
    const char * cstring_join(int count, const char * sep, const char ** strs);
    const char * cstring_multiply(int count, const char * sep, const char * str);
    const char * columns_string();
    const char * columns_placeholder_string();
    void table_name(const char *);
    const char * table_name();
    
    // missing from stdlib
    const char * bw_itoa(int, char *);

private:
    const char * _build_query(const char *);
    void _reset_table_name();
    void init_sec_db();
    
};

}

#endif // BWCRUD_H
