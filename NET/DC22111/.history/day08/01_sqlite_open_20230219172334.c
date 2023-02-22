#include <stdio.h>
#include <sqlite3.h>
int main(int argc, char const *argv[])
{
    sqlite3 *db = NULL;
    if(sqlite3_open("/home/linux/my.db",&db)!= SQLITE_OK)
    {

        return -1;
    }
    printf("sqlite3 open success\n");
    return 0;
}
