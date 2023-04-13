#include "key.h"

void hal_exti_init()
{
    /*********RCC init************/
    //GPIOF enable
    RCC->MP_AHB4ENSETR |= (0x1<<5);
    /*********GPIO init*********/

    /*********EXTI init*********/
}


void hal_gicd_init()
{

}


void hal_gicc_init()
{

}