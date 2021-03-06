/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC15F4K60S4 系列 INT0唤醒掉电模式举例--------------------------*/
/* --- Mobile: (86)13922805190 -------------- -------------------------*/
/* --- Fax: 86-755-82905966 -------------------------------------------*/
/* --- Tel: 86-755-82948412 -------------------------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了宏晶科技的资料及程序   */
/* 如果要在文章中应用此代码,请在文章中注明使用了宏晶科技的资料及程序   */
/*---------------------------------------------------------------------*/

//本示例在Keil开发环境下请选择Intel的8058芯片型号进行编译
//假定测试芯片的工作频率为18.432MHz

#include "reg51.h"
#include "intrins.h"

//-----------------------------------------------

bit FLAG;                       //1:上升沿中断 0:下降沿中断
sbit P10 = P1^0;

//-----------------------------------------
//中断服务程序
void exint0() interrupt 0       //INT0中断入口
{
    P10 = !P10;                 //将测试口取反
    FLAG = INT0;                //保存INT0口的状态, INT0=0(下降沿); INT0=1(上升沿)
}

//-----------------------------------------------

void main()
{
    IT0 = 0;                    //设置INT0的中断类型为上升沿和下降沿,上升沿和下降沿均可唤醒
//  IT0 = 1;                    //设置INT0的中断类型为仅下降沿,下降沿唤醒

    EX0 = 1;                    //使能INT0中断
    EA = 1;

    while (1)
    {
        PCON = 0x02;            //MCU进入掉电模式
        _nop_();                //掉电模式被唤醒后,首先执行此语句,然后再进入中断服务程序
        _nop_();
    }
}

