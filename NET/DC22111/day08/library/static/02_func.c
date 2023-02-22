#include "03_func.h"


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
   // printf("column = %d line:%d\n",column,__LINE__);
    int flag = *(int *)arg;
    if (0==flag)
    {
        for (int i = 0; i < column; i++)
        {
            printf("%s\t",column_name[i]);
        }
        putchar(10);
        *(int *)arg = 1;
    }
    
    

    for (int i = 0; i < column; i++)
    {
        printf("%s\t",column_text[i]);
    }
    putchar(10);
    /*
    
    printf("0:%s\n",column_text[0]);
    printf("1:%s\n",column_text[1]);
    printf("2:%s\n",column_text[2]);

    printf("0:%s\n",column_name[0]);
    printf("1:%s\n",column_name[1]);
    printf("2:%s\n",column_name[2]);
    */
    return 0; //必须返回0，否则失败
}

//查询
int do_select(sqlite3 *db)
{
    char sql[128] = "select * from stu";
    char *errmsg = NULL;
    int flag = 0;
    if (sqlite3_exec(db,sql,select_callback,&flag,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3 exec failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    //
    return 0;
}

int do_select_1(sqlite3 *db)
{
    /*
    char ***pazResult,    
    int *pnRow,            
    int *pnColumn,        
    char **pzErrmsg   
    */
    char **pres = NULL;
    int row,column;
    char *errmsg = NULL;
    char sql[128] = "select * from stu";
    if(sqlite3_get_table(db,sql,&pres,&row,&column,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3_get_table failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    printf("row = %d,row =%d\n",row,column);

    int count = 0;
    //row中不包含表头的一行，但是结果中有表头的内容，所以需要将表头的一行加上
    for (int i = 0; i < row+1; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%s\t",pres[count++]);
        }
        putchar(10);
    }
}




//将dict.txt的内容导入数据库
int load_db(sqlite3 *db,FILE *file)
{

}
