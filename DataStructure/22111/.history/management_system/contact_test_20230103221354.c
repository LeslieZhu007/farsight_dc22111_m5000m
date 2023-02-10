#include "contact.h"


int main(int argc, char const *argv[])
{
    
    //创建
    DoubleLoop L =  list_create();
    if(NULL  == L)
    {
        return -1;
    }

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
    
    printf("录入信息结束,接下来展示录入人员信息:\n");
    list_show(L);

    //查找信息
    /*
    list_find_name(L,"jack");
    list_find_name(L,"tonny");
    */
    //修改联系人信息
    /*
    datatype emodify = {88,"jack",'F',"13057085613"};
    list_update_contacts(L,emodify);
    printf("修改后所有的人员信息如下:\n");
    list_show(L);
    */

   /*
    list_delete_name(L,"kate1");
    */
    datatype einsert = {99,"yamamoto",'M',"13057085614"};
    list_insert_pos(L,0,einsert);
    list_show(L);

    return 0;
}
