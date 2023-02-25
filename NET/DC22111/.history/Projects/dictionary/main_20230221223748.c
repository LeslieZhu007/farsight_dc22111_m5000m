#include "dictionary.h"  

//main文件仅用于测试
int main(int argc, char const *argv[])
{
    char* t = get_system_time();
    write(1,t,sizeof(t));
    
    return 0;
}
