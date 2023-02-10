#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr,"请输入两个文件名，源文件在前，目标文件在后\n");
        return -1;
    }
    
    int fd_src = open(argv[1],O_RDONLY);
    if (fd_src < 0)
    {
        perror("src open");
        return -1;
    }

    int fd_dest = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);
    if (fd_dest < 0)
    {
        perror("dest open");
        return -1;
    }

    /******************main code begin********************/
    //求文件大小
    off_t file_size = lseek(fd_src,0,SEEK_END);
    printf("file_size = %ld\n",file_size);
    int first_half = file_size/2;   //第一部分大小为 0~size/2 ==> 父进程  //size/2 ~ size ==>子进程


    pid_t pid = fork();

    lseek(fd_src,0,SEEK_SET);
  
    if (pid > 0)
    {
        //父进程拷贝前半部分
        lseek(fd_src,0,SEEK_SET);
        lseek(fd_dest,0,SEEK_SET);
        char c=0;
        for (int i = 0; i < file_size/2; i++)
        {
            read(fd_src,&c,1);
            write(fd_dest,&c,1);
        }
        
        printf("前半部分拷贝完毕\n");
    } else if(0 == pid)
    {
       //子进程拷贝后半部分
        lseek(fd_src,size/2,SEEK_SET);
        lseek(fd_dest,0,SEEK_SET);
        char c=0;
        for (int i = 0; i < file_size/2; i++)
        {
            read(fd_src,&c,1);
            write(fd_dest,&c,1);
        }
        
        printf("后半部分拷贝完毕\n");

    } else
    {
        perror("fork");
        return -1;
    }

    /******************main code end********************/
    close(fd_src);
    close(fd_dest);
    
    return 0;
}
