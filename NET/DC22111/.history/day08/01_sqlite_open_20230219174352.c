#include <stdio.h>
#include <sqlite3.h>
int main(int argc, char const *argv[])
{
    sqlite3 *db = NULL;
    if(sqlite3_open("sq.db",&db)!= SQLITE_OK)
    {
        fprintf("sqlite3 open failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
        sqlite3_errmsg(db));
        return -1;
    }
    printf("sqlite3 open success\n");

    /***************************main code body begin************************************/
    /*
        One-Step Query Execution Interface
            int sqlite3_exec(
            sqlite3*,                                  /* An open database */
            const char *sql,                           /* SQL to be evaluated */
            int (*callback)(void*,int,char**,char**),  /* Callback function */
            void *,                                    /* 1st argument to callback */
            char **errmsg                              /* Error msg written here
            );
    */
    



    /***************************main code body end************************************/
    if(sqlite3_close(db)!= SQLITE_OK)
    {
        fprintf("sqlite3 close failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
        sqlite3_errmsg(db));
        return -1;
    }
    printf("sqlite3 open close\n");

    return 0;
}
