#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
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
        printf("........................................................");
        printf("............1.插入........................................");
        printf("............2.删除........................................");
        printf("............3.修改...........................................");
        printf("............4.查询...........................................");
        printf("............5.退出...........................................");
        printf("........................................................");

        printf("请输入>>>");
    choose = getchar();
    while (getchar()!=10);
    
        switch (choose)
        {
            case '1':
                do_inset();
                break;
            case '2':
                do_delete();
                break;
            case '3':
                do_update();
                break;
            case '4':
                do_select();
                break;
            case '5':
                goto END;
                break;
            
            default:
                printf("输入错误，请重新输入\n");
        }

        //请按任意键清屏
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