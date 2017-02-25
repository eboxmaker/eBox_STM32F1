/**
  ******************************************************************************
  * @file   : *.cpp
  * @author : shentq
  * @version: V1.2
  * @date   : 2016/08/14

  * @brief   ebox application example .
  *
  * Copyright 2016 shentq. All Rights Reserved.         
  ******************************************************************************
 */
 
 
#include "ebox.h"
#include "bsp.h"
CanRxMsg RxMessage;
uint8_t data[8];


void test()
{
    uart1.printf("can rx interrupt");
}
void setup()
{
    ebox_init();
    PB7.mode(OUTPUT_PP);
    uart1.begin(115200);
    uart1.printf("can rx test\r\n");
    can1.begin(BSP_CAN_500KBPS);
    can1.set_filter_idmask(CAN_ID_STD,0,0x321,0XFFFFFFFF);
    //can1.set_filter_idlist(CAN_ID_STD,0,0X320);

}
int main(void)
{
    setup();
    while(1)
    {
        delay_ms(100);
        PB7.toggle();
        if(can1.available())
        {
            can1.read(&RxMessage);
            uart1.printf("Rx:%s\n",RxMessage.Data);

        }
    }

}


