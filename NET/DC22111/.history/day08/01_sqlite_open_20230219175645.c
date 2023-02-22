#include <stdio.h>
#include <sqlite3.h>
int main(int argc, char const *argv[])
{
    sqlite3 *db = NULL;
    if(sqlite3_open("sq.db",&db)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 open failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
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
            int (*callback)(void*,int,char**,char**),  /* Callback function */  查询相关语句使用，其余时候填空
            void *,                                    /* 1st argument to callback */ 若回调函数为NULL，则该参数也为NULL
            char **errmsg                              /* Error msg written here
            );
    */

    //1.创建一张表
    char sql[128] = "create table if not exists stu (id int,name char,score float);";
    //char *ptr = "create table stu (id int,name char,score float);";'
    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    
    



    /***************************main code body end************************************/
    if(sqlite3_close(db)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 close failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
        sqlite3_errmsg(db));
        return -1;
    }
    printf("sqlite3 open close\n");

    return 0;
}
