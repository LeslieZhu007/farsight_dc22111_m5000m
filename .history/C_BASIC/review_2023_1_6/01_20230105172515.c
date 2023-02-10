#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//char *y = (char *)malloc(40); // gives an error here
int main()
{
char *y = (char *)malloc(40); // gives an error here
strcpy(y,"hello world");
}