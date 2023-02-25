#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)


#define WORD_INSERT_FORMAT "insert into dictionary values(\"%s\",\"%s\");"

int main(int argc, char const *argv[])
{
    char sql[128] = {0};
    sqlite3 *db = NULL;
    
    char *errmsg = NULL;
    //构建sql插入数据
    sprintf(sql,WORD_INSERT_FORMAT,"abandonment","n.放弃");
    printf("sql=%s\n",sql);
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"dict insert failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    printf(" %s  %s inserted ok\n","abandonment","n.放弃");

    /*
    
    char buf[128] = {0};
    FILE *fp = fopen("dict.txt","r");
    char *ret = NULL;
    if (NULL == fp)
    {
        ERR_MSG("dict source file open");
        return -1;
    }
    
    int num = 1;
    char word[64] = {0};
    char meaning[64] = {0};
    printf("sizeof buf = %d\n",sizeof(buf));
    printf("strlen buf = %d\n",strlen(buf));
    while (1)
    {
        bzero(word,sizeof(word));
        bzero(meaning,sizeof(meaning));
        bzero(buf,sizeof(buf));
        int m_index = 0;
        int j = 0;
        if (NULL == fgets(buf,sizeof(buf),fp))
        {
            break;
        } else
        {
            buf[strlen(buf)-1] = 0;
            //printf("[%d] %s\n",num,buf);
            //遍历buf，找到第一个空格
            for (int i = 0; i < strlen(buf); i++)
            {   
                word[i] = buf[i];
                if (buf[i] == ' ' && buf[i+1] == ' ' && buf[i+2] == ' ')
                {
                    word[i] = 0;
                    m_index = i+3;
                }
                if (0!=m_index)
                {
                    if (j < sizeof(meaning))
                    {
                        meaning[j] = buf[m_index];
                        m_index++;
                        j++;
                    }
                }
            }
  
            printf("[%d] %s  %s\n",num,word,meaning);
            
            num++;
        }  
    }
    printf("sizeof buf = %d\n",sizeof(buf));
    printf("strlen buf = %d\n",strlen(buf));
    */


/*
   char word[32] = {0};
   char meaning[64] = {0};
   int fret = 0;
   while (1)
   {
      fret = fscanf(fp,"%s %s\n",word,meaning);
      if (fret <=0)
      {
        break;
      } else
      {
        printf("[%d] %s %s\n",num,word,meaning);
        num++;
      }
      
   }
*/
    


    return 0;
}
