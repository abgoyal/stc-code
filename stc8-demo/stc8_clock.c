/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC8A/STC8F 系列 时钟切换 --------------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966-------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.GXWMCU.com --------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序        */
/* 如果要在文章中应用此代码,请在文章中注明使用了STC的资料及程序        */
/*---------------------------------------------------------------------*/

//本示例在Keil开发环境下请选择Intel的8058芯片型号进行编译
//若无特别说明,工作频率一般为11.0592MHz

#include "reg51.h"

sfr P_SW2       =   0xba;

#define CKSEL       (*(unsigned char volatile xdata *)0xfe00)
#define CLKDIV      (*(unsigned char volatile xdata *)0xfe01)
#define IRC24MCR    (*(unsigned char volatile xdata *)0xfe02)
#define XOSCCR      (*(unsigned char volatile xdata *)0xfe03)
#define IRC32KCR    (*(unsigned char volatile xdata *)0xfe04)

void main()
{
    //测试内部IRC
    P_SW2 = 0x80;
//  CKSEL = 0x10;           //选择内部IRC,并1分频输出到P5.4
    CKSEL = 0x20;           //选择内部IRC,并2分频输出到P5.4
//  CKSEL = 0x40;           //选择内部IRC,并4分频输出到P5.4
//  CKSEL = 0x60;           //选择内部IRC,并8分频输出到P5.4
//  CKSEL = 0x80;           //选择内部IRC,并16分频输出到P5.4
//  CKSEL = 0xa0;           //选择内部IRC,并32分频输出到P5.4
//  CKSEL = 0xc0;           //选择内部IRC,并64分频输出到P5.4
//  CKSEL = 0xe0;           //选择内部IRC,并128分频输出到P5.4
//  CKSEL = 0x28;           //选择内部IRC,并2分频输出到P1.6
    P_SW2 = 0x00;

/*
    //测试外部晶振
    P_SW2 = 0x80;
    XOSCCR = 0xc0;          //启动外部晶振
    while (!(XOSCCR & 1));  //等待时钟稳定
    CLKDIV = 0x00;           //时钟不分频
//  CKSEL = 0x11;           //选择外部晶振,并1分频输出到P5.4
    CKSEL = 0x21;           //选择外部晶振,并2分频输出到P5.4
//  CKSEL = 0x41;           //选择外部晶振,并4分频输出到P5.4
//  CKSEL = 0x61;           //选择外部晶振,并8分频输出到P5.4
//  CKSEL = 0x81;           //选择外部晶振,并16分频输出到P5.4
//  CKSEL = 0xa1;           //选择外部晶振,并32分频输出到P5.4
//  CKSEL = 0xc1;           //选择外部晶振,并64分频输出到P5.4
//  CKSEL = 0xe1;           //选择外部晶振,并128分频输出到P5.4
    P_SW2 = 0x00;
*/

/*
    //测试内部32K IRC
    P_SW2 = 0x80;
    IRC32KCR = 0x80;        //启动内部32K IRC
    while (!(IRC32KCR & 1));//等待时钟稳定
    CLKDIV = 0x00;           //时钟不分频
//  CKSEL = 0x13;           //选择外部晶振,并1分频输出到P5.4
    CKSEL = 0x23;           //选择外部晶振,并2分频输出到P5.4
//  CKSEL = 0x43;           //选择外部晶振,并4分频输出到P5.4
//  CKSEL = 0x63;           //选择外部晶振,并8分频输出到P5.4
//  CKSEL = 0x83;           //选择外部晶振,并16分频输出到P5.4
//  CKSEL = 0xa3;           //选择外部晶振,并32分频输出到P5.4
//  CKSEL = 0xc3;           //选择外部晶振,并64分频输出到P5.4
//  CKSEL = 0xe3;           //选择外部晶振,并128分频输出到P5.4
    P_SW2 = 0x00;
*/

    while (1)
    {
        P0++;
    }
}

