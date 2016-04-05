/*
file   : rtc.cpp
author : shentq
version: V1.1
date   : 2015/7/5

Copyright 2015 shentq. All Rights Reserved.

Copyright Notice
No part of this software may be used for any commercial activities by any form or means, without the prior written consent of shentq.

Disclaimer
This specification is preliminary and is subject to change at any time without notice. shentq assumes no responsibility for any errors contained herein.
*/
#include "rtc.h"

#define RTC_CFG_FLAG 0XA5A5

RTC_CLASS rtc;
callback_fun_type rtc_callback_table[3];//

void RTC_CLASS::begin()
{

    //	if(isConfig() == 0)
    //	{
    config();
    set_config_flag(RTC_CFG_FLAG);
    //	}
    //	else
    //	{
    //		/* Check if the Power On Reset flag is set */
    //		if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
    //		{
    //			;
    //		}
    //		/* Check if the Pin Reset flag is set */
    //		else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
    //		{
    //			;
    //		}
    //		/* Wait for RTC registers synchronization */
    //		RTC_WaitForSynchro();
    //
    //		/* Wait until last write operation on RTC registers has finished */
    //		RTC_WaitForLastTask();
    //	}
}
void RTC_CLASS::config(void)
{

    /* Enable PWR and BKP clocks */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

    /* Allow access to BKP Domain */
    PWR_BackupAccessCmd(ENABLE);

    /* Reset Backup Domain */
    BKP_DeInit();
    if(RTC_CLOCK_SOURCE)
    {
        /* Enable LSE */
        RCC_LSEConfig(RCC_LSE_ON);
        /* Wait till LSE is ready */
        while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
        {}

        /* Select LSE as RTC Clock Source */
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
    }
    else
    {
        RCC_LSICmd(ENABLE);
        /* Wait till LSI is ready */
        while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

        /* Enable RTC Clock */
        RCC_RTCCLKCmd(ENABLE);

    }

    /* Wait for RTC registers synchronization */
    RTC_WaitForSynchro();

    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();

    /* Enable the RTC Second */
    RTC_ITConfig(RTC_IT_SEC, ENABLE);

    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    if(RTC_CLOCK_SOURCE)
    {
        /* Set RTC prescaler: set RTC period to 1sec */
        RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */
    }
    else
    {
        /* Set RTC prescaler: set RTC period to 1sec */
        RTC_SetPrescaler(39999); /* RTC period = RTCCLK/RTC_PR = (40 KHz)/(39999+1) */

    }

    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    
    
    
    nvic(ENABLE);

}
uint8_t RTC_CLASS::is_config(uint16_t configFlag)
{
    uint8_t flag = 0;
    if(BKP_ReadBackupRegister(BKP_DR1) == configFlag)
        flag = 1;
    return flag;
}
void RTC_CLASS::set_config_flag(uint16_t configFlag)
{
    BKP_WriteBackupRegister(BKP_DR1, configFlag);
}
void RTC_CLASS::set_counter(uint32_t count)
{
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    /* Change the current time */
    RTC_SetCounter(count);

    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
}
void RTC_CLASS::set_alarm(uint32_t count)
{
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    /* Change the current time */
    RTC_SetAlarm(count);

    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
}


void RTC_CLASS::nvic(FunctionalState state)
{

    NVIC_InitTypeDef NVIC_InitStructure;

    /* Configure one bit for preemption priority */
    //	NVIC_PriorityGroupConfig(NVIC_GROUP_CONFIG);

    /* Enable the RTC Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = state;
    NVIC_Init(&NVIC_InitStructure);
}

void RTC_CLASS::attach_sec_interrupt(void (*cb_fun)(void))
{
    rtc_callback_table[0] = cb_fun;
}
void RTC_CLASS::attach_alarm_interrupt(void (*cb_fun)(void))
{
    rtc_callback_table[1] = cb_fun;
}
void RTC_CLASS::attach_overflow_interrupt(void (*cb_fun)(void))
{
    rtc_callback_table[2] = cb_fun;
}

void RTC_CLASS::sec_interrupt(FunctionalState state)
{
    /* Wait for RTC registers synchronization */
    RTC_WaitForSynchro();
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    if(state == ENABLE)
        RTC->CRH |= (1<<0);
    else
         RTC->CRH &= ~(1<<0);
}

void RTC_CLASS::alarm_interrupt(FunctionalState state)
{
    /* Wait for RTC registers synchronization */
    RTC_WaitForSynchro();
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    if(state == ENABLE)
        RTC->CRH |= (1<<1);
    else
         RTC->CRH &= ~(1<<1);
}

void RTC_CLASS::overflow_interrupt(FunctionalState state)
{
     
    /* Wait for RTC registers synchronization */
    RTC_WaitForSynchro();
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    if(state == ENABLE)
        RTC->CRH |= (1<<2);
    else
         RTC->CRH &= ~(1<<2);
}

uint32_t RTC_CLASS::get_counter()
{
    return RTC_GetCounter();
};
extern "C" {
    void RTC_IRQHandler(void)
    {
        if (RTC_GetITStatus(RTC_IT_SEC) != RESET)
        {
            rtc_callback_table[0]();
            RTC_ClearITPendingBit(RTC_IT_SEC);
        }
        if (RTC_GetITStatus(RTC_IT_ALR) != RESET)
        {
            rtc_callback_table[1]();
            RTC_ClearITPendingBit(RTC_IT_ALR);
        }
        if (RTC_GetITStatus(RTC_IT_OW) != RESET)
        {
            rtc_callback_table[2]();
            RTC_ClearITPendingBit(RTC_IT_OW);
        }
    }
}
