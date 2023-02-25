#include <stdio.h>
#include <string.h>
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)


int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    char temp[128] = {0};
    FILE *fp = fopen("dict_test.txt","r");
    char *ret = NULL;
    if (NULL == fp)
    {
        ERR_MSG("dict source file open");
        return -1;
    }
    
    int num = 1;
    char word[32] = {0};
    char meaning[64] = {0};
    
    while (1)
    {
        int m_index = 0;
        ret = fgets(buf,sizeof(buf),fp);
        if (NULL == ret)
        {
            break;
        } else
        {
            buf[strlen(buf)-1] = 0;
            //printf("[%d] %s\n",num,buf);
            strcpy(temp,buf);

            //遍历buf，找到第一个空格
            for (int i = 0; i < strlen(temp)+1; i++)
            {   
                word[i] = temp[i];
                if (temp[i] == ' ' && temp[i+1] == ' ')
                {
                    word[i] = 0;
                    m_index = i+2;
                }
                if (0!=m_index)
                {
                    meaning[m_index] = temp[m_index];
                    m_index++;
                }
            }
            printf("[%d] %s  %s\n",num,word,meaning);
            num++;
        }  
    }

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
