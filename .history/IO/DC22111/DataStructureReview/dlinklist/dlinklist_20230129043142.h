#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>






#endif