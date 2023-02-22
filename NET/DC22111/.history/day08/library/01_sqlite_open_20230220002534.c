#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include "03_func.h"

//将dict.txt的内容导入数据库
int load_db(sqlite3 *db,FILE *file);

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
    //1.创建一张表
    char sql[128] = "create table if not exists stu (id int,name char,score float);";
    //char *ptr = "create table stu (id int,name char,score float);";'
    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }

    char choose = 0;
    while (1)
    {
        printf("........................................................\n");
        printf("............1.插入......................................\n");
        printf("............2.删除......................................\n");
        printf("............3.修改......................................\n");
        printf("............4.查询......................................\n");
        printf("............5.退出......................................\n");
        printf("........................................................\n");

        printf("请输入>>>");
        choose = getchar();
        while (getchar()!=10);
    
        switch (choose)
        {
            case '1':
                do_insert(db);
                break;
            case '2':
                do_delete(db);
                break;
            case '3':
                do_update(db);
                break;
            case '4':
                do_select_1(db);
                break;
            case '5':
                goto END;
                break;
            
            default:
                printf("输入错误，请重新输入\n");
        }

        //请按任意键清屏
        printf("请按任意键清屏\n");
        while (getchar()!=10);
        system("clear");
        
    }
    
    
    



    /***************************main code body end************************************/
END:
    if(sqlite3_close(db)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 close failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
        sqlite3_errmsg(db));
        return -1;
    }
    printf("sqlite3 open close\n");

    return 0;
}



