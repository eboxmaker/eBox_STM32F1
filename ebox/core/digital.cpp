#include "common.h"
//GPIO GPA0(GPIOA,GPIO_Pin_0);
//GPIO GPA1(GPIOA,GPIO_Pin_1);
//GPIO GPA2(GPIOA,GPIO_Pin_2);
//GPIO GPA3(GPIOA,GPIO_Pin_3);
//GPIO GPA4(GPIOA,GPIO_Pin_4);
//GPIO GPA5(GPIOA,GPIO_Pin_5);
//GPIO GPA6(GPIOA,GPIO_Pin_6);
//GPIO GPA7(GPIOA,GPIO_Pin_7);
//GPIO GPA8(GPIOA,GPIO_Pin_8);
//GPIO GPA9(GPIOA,GPIO_Pin_9);
//GPIO GPA10(GPIOA,GPIO_Pin_10);
//GPIO GPA11(GPIOA,GPIO_Pin_11);
//GPIO GPA12(GPIOA,GPIO_Pin_12);
//GPIO GPA13(GPIOA,GPIO_Pin_13);
//GPIO GPA14(GPIOA,GPIO_Pin_14);
//GPIO GPA15(GPIOA,GPIO_Pin_15);

//GPIO GPB0(GPIOB,GPIO_Pin_0);
//GPIO GPB1(GPIOB,GPIO_Pin_1);
//GPIO GPB2(GPIOB,GPIO_Pin_2);
//GPIO GPB3(GPIOB,GPIO_Pin_3);
//GPIO GPB4(GPIOB,GPIO_Pin_4);
//GPIO GPB5(GPIOB,GPIO_Pin_5);
//GPIO GPB6(GPIOB,GPIO_Pin_6);
//GPIO GPB7(GPIOB,GPIO_Pin_7);
//GPIO GPB8(GPIOB,GPIO_Pin_8);
//GPIO GPB9(GPIOB,GPIO_Pin_9);
//GPIO GPB10(GPIOB,GPIO_Pin_10);
//GPIO GPB11(GPIOB,GPIO_Pin_11);
//GPIO GPB12(GPIOB,GPIO_Pin_12);
//GPIO GPB13(GPIOB,GPIO_Pin_13);
//GPIO GPB14(GPIOB,GPIO_Pin_14);
//GPIO GPB15(GPIOB,GPIO_Pin_15);

//GPIO GPC0(GPIOC,GPIO_Pin_0);
//GPIO GPC1(GPIOC,GPIO_Pin_1);
//GPIO GPC2(GPIOC,GPIO_Pin_2);
//GPIO GPC3(GPIOC,GPIO_Pin_3);
//GPIO GPC4(GPIOC,GPIO_Pin_4);
//GPIO GPC5(GPIOC,GPIO_Pin_5);
//GPIO GPC6(GPIOC,GPIO_Pin_6);
//GPIO GPC7(GPIOC,GPIO_Pin_7);
//GPIO GPC8(GPIOC,GPIO_Pin_8);
//GPIO GPC9(GPIOC,GPIO_Pin_9);
//GPIO GPC10(GPIOC,GPIO_Pin_10);
//GPIO GPC11(GPIOC,GPIO_Pin_11);
//GPIO GPC12(GPIOC,GPIO_Pin_12);
//GPIO GPC13(GPIOC,GPIO_Pin_13);
//GPIO GPC14(GPIOC,GPIO_Pin_14);
//GPIO GPC15(GPIOC,GPIO_Pin_15);

//GPIO GPD0(GPIOD,GPIO_Pin_0);
//GPIO GPD1(GPIOD,GPIO_Pin_1);
//GPIO GPD2(GPIOD,GPIO_Pin_2);
//GPIO GPD3(GPIOD,GPIO_Pin_3);
//GPIO GPD4(GPIOD,GPIO_Pin_4);
//GPIO GPD5(GPIOD,GPIO_Pin_5);
//GPIO GPD6(GPIOD,GPIO_Pin_6);
//GPIO GPD7(GPIOD,GPIO_Pin_7);
//GPIO GPD8(GPIOD,GPIO_Pin_8);
//GPIO GPD9(GPIOD,GPIO_Pin_9);
//GPIO GPD10(GPIOD,GPIO_Pin_10);
//GPIO GPD11(GPIOD,GPIO_Pin_11);
//GPIO GPD12(GPIOD,GPIO_Pin_12);
//GPIO GPD13(GPIOD,GPIO_Pin_13);
//GPIO GPD14(GPIOD,GPIO_Pin_14);
//GPIO GPD15(GPIOD,GPIO_Pin_15);



//GPIO* PC0 = new GPIO(GPIOC,GPIO_Pin_0);

GPIO::GPIO(GPIO_TypeDef* _port,uint16_t _pin)
{
	port = _port;
	pin = _pin;
	switch((uint32_t)port)
	{
		case (uint32_t)GPIOA:
			rcc = RCC_APB2Periph_GPIOA;
			break;

		case (uint32_t)GPIOB:
			rcc = RCC_APB2Periph_GPIOB;
			break;

		case (uint32_t)GPIOC:
			rcc = RCC_APB2Periph_GPIOC;
			break;

		case (uint32_t)GPIOD:
			rcc = RCC_APB2Periph_GPIOD;
			break;

		case (uint32_t)GPIOE:
			rcc = RCC_APB2Periph_GPIOE;
			break;
		
		case (uint32_t)GPIOF:
			rcc = RCC_APB2Periph_GPIOF;
			break;
	}
}

void GPIO::mode(PINMODE modeVal)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	if(modeVal == _AF_OD || modeVal == _AF_PP)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //

	RCC_APB2PeriphClockCmd(rcc,ENABLE);
	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = (GPIOMode_TypeDef)modeVal;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port, &GPIO_InitStructure);   //��ʼ��GPIOC�˿�
}

void GPIO::set()
{
		port->BSRR = pin;
}
void GPIO::reset()
{
		port->BRR = pin;
}

void GPIO::write(uint8_t val)
{
	if(val == 0)
		port->BRR = pin;
	else
		port->BSRR = pin;
}

void GPIO::read(uint8_t* val)
{
	*val = port->IDR & pin;
}		

uint8_t GPIO::read(void)
{
	if(port->IDR & pin)
		return 1;
	return  0;
}

uint8_t shiftIn(GPIO* dataPin, GPIO* clockPin, uint8_t bitOrder) {
	uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		clockPin->write(HIGH);
		if (bitOrder == LSBFIRST)
			value |= dataPin->read() << i;
		else
			value |= dataPin->read() << (7 - i);
		clockPin->write(LOW);
	}
	return value;
}

void shiftOut(GPIO* dataPin, GPIO* clockPin, uint8_t bitOrder, uint8_t val)
{
	int i;
	for (i = 0; i < 8; i++)  
	{
		if (bitOrder == LSBFIRST)
			dataPin->write(!!(val & (1 << i)));
		else	
			dataPin->write(!!(val & (1 << (7 - i))));
			clockPin->write(HIGH);
			clockPin->write(LOW);

	}
}
