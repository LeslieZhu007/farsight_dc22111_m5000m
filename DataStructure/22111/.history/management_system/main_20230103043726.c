#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int menu1;
    char username[20];
    char pwd[20];

    while(1)
    {
        printf("\t\t========员工登录系统==========\n");
        printf("\t\t1.注册信息\n");
        printf("\t\t2.用户登录\n");
        printf("\t\t0.退出\n");
        printf("请输入功能选项: ");
        scanf("%d",&menu1);

        switch(menu1)
        {
            case 1:
            {
                for (;; )
                {
                    printf("请输入注册账号: ");
                    scanf("%s",username);
                    printf("请输入注册密码: ");
                    scanf("%s",pwd);
                    if (strlen(pwd) < 6)
                    {
                        printf("您输入的密码不合法，请重新输入\n");
                    } else
                    {
                        printf("注册成功\n");
                        break;
                    }
                }
                //将新用户的账号和密码保存到文件中
                FILE *fp = fopen("./account.txt","a+");
                if (NULL == fp)
                {
                    printf("文件打开失败\n");
                    return;
                }
                //将信息保存到文件中
                fprintf(fp,"%s %s\n",username,pwd)
                
                
            }
            break;

            case 2:
            {

            }
            break;
        }
    }
    





    return 0;
}
