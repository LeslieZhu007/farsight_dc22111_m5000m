#ifndef __COMMAND_H__
#define __COMMAND_H__

char buf[128] = {0};

#define LED1_ON _IOW('a',1,int)
#define LED1_OFF _IOW('a',0,int)
#define LED2_ON _IOW('b',1,int)
#define LED2_OFF _IOW('b',0,int)
#define LED3_ON _IOW('c',1,int)
#define LED3_OFF _IOW('c',0,int)








#endif