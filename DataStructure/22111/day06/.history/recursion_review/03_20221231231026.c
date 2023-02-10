#include<stdio.h>

void show(char str[])
{
    if (str[0]!='\0')
    {
        show(str+1);
    }
    
    printf("%c\t",str[0]);

}


int main(int argc, char const *argv[])
{
    
    

    show("hey how are you");




    return 0;
}
