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
                        DoubleLoop L;
                        switch (menu1)
                        {
                        case 1:
                            {
                                //创建模块
                                L = list_create();
                            }
                            break;
                        case 2:
                            {
                                //添加数据
                                printf("开始录入人员信息:\n");
                                char input;
                                do
                                {
                                    datatype e;
                                    printf("请输入人员编号:");
                                    scanf("%d",&e.id);
                                    printf("请输入人员姓名:");
                                    scanf("%s",e.name);
                                    //吸收垃圾字符
                                    getchar();
                                    printf("请输入人员性别,F:女 M:男:");
                                    scanf("%c",&e.sex);
                                    printf("请输入人员电话:");
                                    scanf("%s",e.tel);
                                    //调用尾插法插入人员数据
                                    list_insert_tail(L,e);
                                    printf("是否继续录入? Y/N:");
                                    //吸收垃圾字符串
                                    getchar();
                                    scanf("%c",&input);
                                } while (input!='N');
                            }
                            break;
                        case 3:
                            {
                                //查找信息
                                printf("请输入要查找的姓名:\n");
                                char *name = NULL;
                                scanf("%s",name);
                                list_find_name(L,name);
                            }
                            break;
                        case 4:
                            {
                                //修改信息
                                datatype e;
                                printf("请输入要修改的人员姓名:");
                                scanf("%s",e.name);
                                printf("请输入要修改的人员编号:");
                                scanf("%d",&e.id);
                                
                                //吸收垃圾字符
                                getchar();
                                printf("请输入要修改的人员性别,F:女 M:男:");
                                scanf("%c",&e.sex);
                                printf("请输入要修改的人员电话:");
                                scanf("%s",e.tel);
                                list_update_contacts(L,e);
                            }
                            break;
                        case 5:
                            {
                                //删除信息  
                                printf("请输入要删除的姓名:\n");
                                char *name = NULL;
                                scanf("%s",name);
                                list_delete_name(L,name);
                            }
                            break;
                        case 6:
                            {
                                //插入信息
                                datatype einsert;
                                int pos;
                                printf("请输入要修改的人员姓名:");
                                scanf("%s",einsert.name);
                                printf("请输入要修改的人员编号:");
                                scanf("%d",&einsert.id);
                                
                                //吸收垃圾字符
                                getchar();
                                printf("请输入要修改的人员性别,F:女 M:男:");
                                scanf("%c",&einsert.sex);
                                printf("请输入要修改的人员电话:");
                                scanf("%s",einsert.tel);

                                printf("请输入要修改的位置:");
                                scanf("%d",&pos);
                                
                                list_insert_pos(L,pos,einsert);
                            }
                            break;
                        case 7:
                        {
                            //展示信息
                            list_show(L);
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
