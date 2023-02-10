#include "contact.h"

int main(int argc, char const *argv[])
{
    int menu1;
    char username[20];
    char pwd[20];

NEXT:
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
                    return -1;
                }
                //将信息保存到文件中
                fprintf(fp,"%s %s\n",username,pwd);
                //关闭文件
                fclose(fp);
      
            }
            break;

            case 2:
            {
                char loginname[20];
                char passwd[20];
                printf("请输入登录账号: ");
                scanf("%s",loginname);
                printf("请输入登录密码: ");
                scanf("%s",passwd);
                //获取数据库中的账号和密码
                FILE *fp = fopen("./account.txt","r");
                if (NULL == fp)
                {
                    printf("文件打开失败\n");
                    return -1;
                }
                //读取信息
                while (!feof(fp))
                {
                    fscanf(fp,"%s%s",username,pwd);
                    printf("username = %s\n",username);
                    printf("pwd = %s\n",pwd);

                    if (strcmp(username,loginname) == 0 && strcmp(pwd,passwd) == 0)
                    {
                        printf("登录成功\n");
                        
                        while (1)
                        {
                        printf("二级菜单\n");
                        printf("\t\t1.创建模块\n");
                        printf("\t\t2.添加数据\n");
                        printf("\t\t3.查找信息\n");
                        printf("\t\t4.修改信息\n");
                        printf("\t\t5.删除信息\n");
                        printf("\t\t6.插入信息\n");
                        printf("\t\t7.展示信息\n");
                        printf("\t\t8.导出信息\n");
                        printf("\t\t9.查找信息\n");
                        printf("\t\t10.按照姓名将通讯录排序\n");
                        printf("\t\t11.返回上一级\n");
                        printf("请输入功能选项: ");
                        scanf("%d",&menu1);
                        switch (menu1)
                        {
                        case 1:
                            {
                                //创建模块
                                
                            }
                            break;
                        case 2:
                            {
                                //添加数据
                            }
                            break;
                        case 3:
                            {
                                //查找信息
                            }
                            break;
                        case 4:
                            {
                                //修改信息
                            }
                            break;
                        case 5:
                            {
                                //删除信息
                            }
                            break;
                        case 6:
                            {
                                //插入信息
                            }
                            break;
                        case 7:
                        {
                            //展示信息
                        }
                            break;

                        case 8:
                        {
                            //导出信息
                            
                        }
                            break;
                        case 9:
                        {
                            //查找信息
                        }
                            break;
                        case 10:
                        {
                            //按照姓名将通讯录排序
                        }
                            break;
                        case 11:
                        {
                            //返回上一级
                            goto NEXT;
                        }
                            break;

                        default:
                            break;
                        }
                        }
                        
                        //TODO
                        
                        
                    }
                    
                }
                printf("登录失败\n");
                fclose(fp);
                
            }
            break;

            case 0:
            {
                printf("退出系统\n");
                exit(1);
            }
            break;
        }
    }
    





    return 0;
}
