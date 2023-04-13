#ifndef __KEY_H__
#define __KEY_H__
#include "stm32mp1xx_exti.h"
#include "stm32mp1xx_gic"

//EXTI init
void hal_exti_init();


void hal_gicd_init();


void hal_gicc_init();




#endif