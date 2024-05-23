#ifndef _LCD_DRIVER_H_
#define _LCD_DRIVER_H_

#include "stm32f10x.h"

#define X_MAX_PIXEL	        128
#define Y_MAX_PIXEL	        160


/*********************颜色的宏定义*************************/
#define RED  		0xf800
#define GREEN		0x07e0
#define BLUE 		0x001f
#define WHITE		0xffff
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   			//灰色0 3165 00110 001011 00101
#define GRAY1   0x8410      	//灰色1      00000 000000 00000
#define GRAY2   0x4208      	//灰色2  1111111111011111

#define BROWN 	0XBC40 				//棕色
#define BRRED 	0XFC07 				//棕红色
#define GRAY  	0X8430 				//灰色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色 
#define UNKNOWBLUE			 0x5D9A	

/************************SPI通信接口 宏定义***************************/
#define LCD_SCL_CLK			RCC_APB2Periph_GPIOA
#define LCD_SCL_PORT    GPIOA
#define LCD_SCL_PIN     GPIO_Pin_5	

#define LCD_SDA_CLK			RCC_APB2Periph_GPIOA
#define LCD_SDA_PORT    GPIOA
#define LCD_SDA_PIN     GPIO_Pin_7

#define LCD_CS_CLK			RCC_APB2Periph_GPIOB
#define LCD_CS_PORT     GPIOB
#define LCD_CS_PIN      GPIO_Pin_1

#define LCD_LED_CLK			RCC_APB2Periph_GPIOA
#define LCD_LED_PORT    GPIOA
#define LCD_LED_PIN     GPIO_Pin_2

#define LCD_RS_CLK			RCC_APB2Periph_GPIOA
#define LCD_RS_PORT     GPIOA
#define LCD_RS_PIN      GPIO_Pin_4

#define LCD_RST_CLK			RCC_APB2Periph_GPIOA
#define LCD_RST_PORT    GPIOA
#define LCD_RST_PIN     GPIO_Pin_3


/***********************************************************
 *
 *			库函数绘制图形速度慢
 *
 ***********************************************************
 */
////液晶控制口置1操作语句宏定义
//#define	LCD_SCL_SET  	GPIO_SetBits(LCD_SCL_PORT,LCD_SCL_PIN)   
//#define	LCD_SDA_SET  	GPIO_SetBits(LCD_SDA_PORT,LCD_SDA_PIN) 
//#define	LCD_CS_SET  	GPIO_SetBits(LCD_CS_PORT,LCD_CS_PIN)
//#define	LCD_LED_SET  	GPIO_SetBits(LCD_LED_PORT,LCD_LED_PIN)   
//#define	LCD_RS_SET  	GPIO_SetBits(LCD_RS_PORT,LCD_RS_PIN)
//#define	LCD_RST_SET  	GPIO_SetBits(LCD_RST_PORT,LCD_RST_PIN)
////液晶控制口置0操作语句宏定义
//#define	LCD_SCL_CLR  	GPIO_ResetBits(LCD_SCL_PORT,LCD_SCL_PIN)  
//#define	LCD_SDA_CLR  	GPIO_ResetBits(LCD_SDA_PORT,LCD_SDA_PIN) 
//#define	LCD_CS_CLR  	GPIO_ResetBits(LCD_CS_PORT,LCD_CS_PIN)  
//#define	LCD_LED_CLR  	GPIO_ResetBits(LCD_LED_PORT,LCD_LED_PIN) 
//#define	LCD_RS_CLR  	GPIO_ResetBits(LCD_RS_PORT,LCD_RS_PIN)
//#define	LCD_RST_CLR  	GPIO_ResetBits(LCD_RST_PORT,LCD_RST_PIN)



//液晶控制口置1操作语句宏定义
#define	LCD_SCL_SET  	LCD_SCL_PORT->BSRR=LCD_SCL_PIN    
#define	LCD_SDA_SET  	LCD_SDA_PORT->BSRR=LCD_SDA_PIN   
#define	LCD_CS_SET  	LCD_CS_PORT->BSRR=LCD_CS_PIN   
#define	LCD_LED_SET  	LCD_LED_PORT->BSRR=LCD_LED_PIN   
#define	LCD_RS_SET  	LCD_RS_PORT->BSRR=LCD_RS_PIN 
#define	LCD_RST_SET  	LCD_RST_PORT->BSRR=LCD_RST_PIN 
//液晶控制口置0操作语句宏定义
#define	LCD_SCL_CLR  		LCD_SCL_PORT->BRR=LCD_SCL_PIN  
#define	LCD_SDA_CLR  		LCD_SDA_PORT->BRR=LCD_SDA_PIN 
#define	LCD_CS_CLR  		LCD_CS_PORT->BRR=LCD_CS_PIN    
#define	LCD_LED_CLR  		LCD_LED_PORT->BRR=LCD_LED_PIN 
#define	LCD_RS_CLR  		LCD_RS_PORT->BRR=LCD_RS_PIN 
#define	LCD_RST_CLR  		LCD_RST_PORT->BRR=LCD_RST_PIN



//LCD基本函数
void Lcd_Init(void);
void Lcd_Clear(u16 Color);
void LCD_GPIO_Init(void);
void Lcd_WriteIndex(u8 Index);
void Lcd_WriteData(u8 Data);
void Lcd_WriteReg(u8 Index,u8 Data);
void Lcd_Reset(void);
void Lcd_SetXY(u16 x,u16 y);
void Gui_DrawPoint(u16 x,u16 y,u16 Data);
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
void LCD_WriteData_16Bit(u16 Data);

//LCD功能函数
void Gui_Circle(u16 X,u16 Y,u16 R,u16 fc); 
void Gui_DrawLine(u16 x0, u16 y0,u16 x1, u16 y1,u16 Color);  
void Gui_DrawFont_GBK16(u16 x, u16 y, u16 fc, u16 bc, u8 *s);
void Gui_DrawFont_GBK24(u16 x, u16 y, u16 fc, u16 bc, u8 *s);
void Lcd_Fill(u16 x0, u16 y0, u16 width, u16 height,u16 Color);
void Lcd_Show_Photo(u16 x0, u16 y0, u16 width, u16 height,const unsigned char * photo);



#endif
