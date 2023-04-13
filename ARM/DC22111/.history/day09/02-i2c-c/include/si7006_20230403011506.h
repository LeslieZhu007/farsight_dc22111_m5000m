#ifndef __SI7006_H__
#define __SI7006_H__

#include "iic.h"
#define        SI7006_SLAVE      0x40

void si7006_init(void);

unsigned short si7006_read_hum_data(unsigned char slave_addr, unsigned char reg_addr);


#endif //__SI7006_H__
