#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

int do_insert(sqlite3 *db);
int do_delete(sqlite3 *db);
int do_update(sqlite3 *db);
int do_select(sqlite3 *db);

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
                do_select(db);
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



int do_insert(sqlite3 *db)
{
    //从终端拿取插入数据
    //
    printf("请输入学生的id,姓名及成绩====>");
    char name[20] = {0};
    int id;
    float score;
    fscanf(stdin,"%d %s %f",&id,name,&score);
    while (getchar()!=10);
    printf("id = %d,name = %s,score = %f\n",id,name,score);
    char sql[128] = {0};
    //sprintf(sql,"insert into stu values(%d,'%s',%.2f)",id,name,score);
    //sprintf(sql,"insert into stu values(%d,\"%s\",%.2f)",id,name,score);
    sprintf(sql,"insert into stu values(%d,\"%s\",%g)",id,name,score);
    printf("sql = %s \n",sql);

    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    return 0;
}


int do_delete(sqlite3 *db)
{
    printf("请输入要删除的学生信息的id:");
    int id;
    char sql[128] = {0};
    fscanf(stdin,"%d",&id);
    while (getchar()!=10);
    sprintf(sql,"delete from stu where id = %d",id);
    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    return 0;
}




int do_update(sqlite3 *db)
{
    printf("请输入要删除的学生信息的id:");
    int id;
    char sql[128] = {0};
    fscanf(stdin,"%d",&id);
    while (getchar()!=10);
    sprintf(sql,"update stu set score = 60 where id = %d",id);
    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    return 0;
}

//查询相关的回调函数
int select_callback(void* arg,int column,char **column_text,char **column_name)
{
    printf("column = %d line:%d\n",column,__LINE__);

    printf("0:%s\n",column_text[0]);
    printf("1:%s\n",column_text[1]);
    printf("2:%s\n",column_text[2]);

    printf("0:%s\n",column_name[0]);
    printf("1:%s\n",column_name[1]);
    printf("2:%s\n",column_name[2]);
    return 0;
}

//查询
int do_select(sqlite3 *db)
{
    char sql[128] = "select * from stu";
    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,select_callback,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    return 0;
}





//将dict.txt的内容导入数据库
int load_db(sqlite3 *db,FILE *file)
{

}
