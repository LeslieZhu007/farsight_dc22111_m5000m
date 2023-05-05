#ifndef __COMMAND_H__
#define __COMMAND_H__
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
char buf[128] = {0};

#define LED1_ON _IOW('a',1,int)
#define LED1_OFF _IOW('a',0,int)
#define LED2_ON _IOW('b',1,int)
#define LED2_OFF _IOW('b',0,int)
#define LED3_ON _IOW('c',1,int)
#define LED3_OFF _IOW('c',0,int)








#endif