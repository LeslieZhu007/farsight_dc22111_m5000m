#include "dictionary.h"  

//main文件仅用于测试
int main(int argc, char const *argv[])
{
    //1.获取当前时间测试 ==> [PASS]
    /*
    char time_buf[128] = {0};
    while (1)
    {
        get_system_time(time_buf);
        printf("%s\r",time_buf);
        fflush(stdout);
        sleep(1);
    }
    */
    sqlite3 db;
    database_init(&db);
    char *filepath = "dict_test.txt";
    load_db(&db,filepath);
    return 0;
}
