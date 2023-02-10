#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
int main(int argc,const char* argv[])
{
    LinkList L = list_create();

    //制作菜单
    int num;  //菜单编号
    for (; ; )
    {
        //显示菜单
        printf("\t\t====链表管理功能====\n");
        printf("\t\t\t1、头插\n");
        printf("\t\t\t2、任意位置插入\n");
        printf("\t\t\t3、查看\n");
        printf("\t\t\t4、头删\n");
        printf("\t\t\t5、任意位置删除\n");
        printf("\t\t\t6、按位置修改\n");
        printf("\t\t\t0、退出\n");

        printf("请输入您要进行的操作:");
        scanf("%d",&num);
        getchar();

        //对输入的选项进行多分支选择
        switch (num)
        {
            case 1:
                {
                    //头插
                    datatype e;
                    printf("请输入要插入的元素: ");
                    e = getchar();
                    list_insert_head(L,e);
                    break;
                }
            case 2:
                {
                    //任意位置插入
                    int pos;
                    datatype e;
                    printf("请输入要插入的位置");
                    list_insert_pos(L,pos,e);
                    break;
                }
            case 3:
                {
                    //查看
                    list_show(L);
                    break;
                }
            case 4:
                {
                    //头删
                    break;
                }
            case 5:
                {
                    //任意位置删除
                    break;
                }
            case 6:
                {
                    //按位置修改
                    break;
                }
            case 0:
                {
                    exit(0); //结束整个进程
                }   
            
            default:
                break;
        }

    }
    
    
    return 0;
}