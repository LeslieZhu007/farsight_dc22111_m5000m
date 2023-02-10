#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        fprintf(stdout,"3 params at least");
        return -1;
    }
    
    FILE *fp_r,*fp_w;
    fp_r = fopen(argv[1],"r");
    if(NULL == fp_r)
    {
        perror("fopen fp_r\n");
        return -1;
    }

    fp_w = fopen(argv[2],"w");
    if(NULL == fp_w)
    {
        perror("fopen fp_w\n");
        return -1;
    }

    char c = 0;
    while ((c=fgetc(fp_r))!=-1)
    {
        fputc(c,fp_w);
    }
    
    if(fclose(fp_r) < 0)
    {
        perror("fp_r fclose");
        return -1;
    }

    if(fclose(fp_w) < 0)
    {
        perror("fp_w fclose");
        return -1;
    }

    return 0;
}