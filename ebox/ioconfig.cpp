
#include "ebox.h"

#define MCU_PIN_100
#if defined (MCU_PIN_48)||defined (MCU_PIN_64)||defined (MCU_PIN_100) || defined ( MCU_PIN_144)


GPIO GPA0(GPIOA,GPIO_Pin_0);
GPIO GPA1(GPIOA,GPIO_Pin_1);
GPIO GPA2(GPIOA,GPIO_Pin_2);
GPIO GPA3(GPIOA,GPIO_Pin_3);
GPIO GPA4(GPIOA,GPIO_Pin_4);
GPIO GPA5(GPIOA,GPIO_Pin_5);
GPIO GPA6(GPIOA,GPIO_Pin_6);
GPIO GPA7(GPIOA,GPIO_Pin_7);
GPIO GPA8(GPIOA,GPIO_Pin_8);
GPIO GPA9(GPIOA,GPIO_Pin_9);
GPIO GPA10(GPIOA,GPIO_Pin_10);
GPIO GPA11(GPIOA,GPIO_Pin_11);
GPIO GPA12(GPIOA,GPIO_Pin_12);
GPIO GPA13(GPIOA,GPIO_Pin_13);
GPIO GPA14(GPIOA,GPIO_Pin_14);
GPIO GPA15(GPIOA,GPIO_Pin_15);

GPIO GPB0(GPIOB,GPIO_Pin_0);
GPIO GPB1(GPIOB,GPIO_Pin_1);
GPIO GPB2(GPIOB,GPIO_Pin_2);
GPIO GPB3(GPIOB,GPIO_Pin_3);
GPIO GPB4(GPIOB,GPIO_Pin_4);
GPIO GPB5(GPIOB,GPIO_Pin_5);
GPIO GPB6(GPIOB,GPIO_Pin_6);
GPIO GPB7(GPIOB,GPIO_Pin_7);
GPIO GPB8(GPIOB,GPIO_Pin_8);
GPIO GPB9(GPIOB,GPIO_Pin_9);
GPIO GPB10(GPIOB,GPIO_Pin_10);
GPIO GPB11(GPIOB,GPIO_Pin_11);
GPIO GPB12(GPIOB,GPIO_Pin_12);
GPIO GPB13(GPIOB,GPIO_Pin_13);
GPIO GPB14(GPIOB,GPIO_Pin_14);
GPIO GPB15(GPIOB,GPIO_Pin_15);

GPIO GPC13(GPIOC,GPIO_Pin_13);
GPIO GPC14(GPIOC,GPIO_Pin_14);
GPIO GPC15(GPIOC,GPIO_Pin_15);

GPIO GPD0(GPIOD,GPIO_Pin_0);
GPIO GPD1(GPIOD,GPIO_Pin_1);

//GPIO GPE5(GPIOE,GPIO_Pin_5);

#endif
#if defined (MCU_PIN_64)||defined (MCU_PIN_100) || defined ( MCU_PIN_144)

GPIO GPC0(GPIOC,GPIO_Pin_0);
GPIO GPC1(GPIOC,GPIO_Pin_1);
GPIO GPC2(GPIOC,GPIO_Pin_2);
GPIO GPC3(GPIOC,GPIO_Pin_3);
GPIO GPC4(GPIOC,GPIO_Pin_4);
GPIO GPC5(GPIOC,GPIO_Pin_5);
GPIO GPC6(GPIOC,GPIO_Pin_6);
GPIO GPC7(GPIOC,GPIO_Pin_7);
GPIO GPC8(GPIOC,GPIO_Pin_8);
GPIO GPC9(GPIOC,GPIO_Pin_9);
GPIO GPC10(GPIOC,GPIO_Pin_10);
GPIO GPC11(GPIOC,GPIO_Pin_11);
GPIO GPC12(GPIOC,GPIO_Pin_12);

GPIO GPD2(GPIOD,GPIO_Pin_2);

#endif

#if defined (MCU_PIN_100) || defined ( MCU_PIN_144)
GPIO GPE0(GPIOE,GPIO_Pin_0);
GPIO GPE1(GPIOE,GPIO_Pin_1);
GPIO GPE2(GPIOE,GPIO_Pin_2);
GPIO GPE3(GPIOE,GPIO_Pin_3);
GPIO GPE4(GPIOE,GPIO_Pin_4);
GPIO GPE5(GPIOE,GPIO_Pin_5);
GPIO GPE6(GPIOE,GPIO_Pin_6);
GPIO GPE7(GPIOE,GPIO_Pin_7);
GPIO GPE8(GPIOE,GPIO_Pin_8);
GPIO GPE9(GPIOE,GPIO_Pin_9);
GPIO GPE10(GPIOE,GPIO_Pin_10);
GPIO GPE11(GPIOE,GPIO_Pin_11);
GPIO GPE12(GPIOE,GPIO_Pin_12);
GPIO GPE13(GPIOE,GPIO_Pin_13);
GPIO GPE14(GPIOE,GPIO_Pin_14);
GPIO GPE15(GPIOE,GPIO_Pin_15);
#endif

#if defined MCU_PIN_144
GPIO GPF0(GPIOF,GPIO_Pin_0);
GPIO GPF1(GPIOF,GPIO_Pin_1);
GPIO GPF2(GPIOF,GPIO_Pin_2);
GPIO GPF3(GPIOF,GPIO_Pin_3);
GPIO GPF4(GPIOF,GPIO_Pin_4);
GPIO GPF5(GPIOF,GPIO_Pin_5);
GPIO GPF6(GPIOF,GPIO_Pin_6);
GPIO GPF7(GPIOF,GPIO_Pin_7);
GPIO GPF8(GPIOF,GPIO_Pin_8);
GPIO GPF9(GPIOF,GPIO_Pin_9);
GPIO GPF10(GPIOF,GPIO_Pin_10);
GPIO GPF11(GPIOF,GPIO_Pin_11);
GPIO GPF12(GPIOF,GPIO_Pin_12);
GPIO GPF13(GPIOF,GPIO_Pin_13);
GPIO GPF14(GPIOF,GPIO_Pin_14);
GPIO GPF15(GPIOF,GPIO_Pin_15);

GPIO GPG0(GPIOG,GPIO_Pin_0);
GPIO GPG1(GPIOG,GPIO_Pin_1);
GPIO GPG2(GPIOG,GPIO_Pin_2);
GPIO GPG3(GPIOG,GPIO_Pin_3);
GPIO GPG4(GPIOG,GPIO_Pin_4);
GPIO GPG5(GPIOG,GPIO_Pin_5);
GPIO GPG6(GPIOG,GPIO_Pin_6);
GPIO GPG7(GPIOG,GPIO_Pin_7);
GPIO GPG8(GPIOG,GPIO_Pin_8);
GPIO GPG9(GPIOG,GPIO_Pin_9);
GPIO GPG10(GPIOG,GPIO_Pin_10);
GPIO GPG11(GPIOG,GPIO_Pin_11);
GPIO GPG12(GPIOG,GPIO_Pin_12);
GPIO GPG13(GPIOG,GPIO_Pin_13);
GPIO GPG14(GPIOG,GPIO_Pin_14);
GPIO GPG15(GPIOG,GPIO_Pin_15);
#endif
