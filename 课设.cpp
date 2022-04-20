#include  <reg51.h>             
#include  <stdio.h>
#include  <stdlib.h>
#include <absacc.h>
#define uint unsigned int     
#define uchar unsigned char  

void delay(uint xms);    //延时函数
void keyf1();   //反转工作方式选择函数        
void keyz1();   //正转工作方式选择函数       
void keyover();    //正反转选择函数   

unsigned int i;   //i为读取数组指针

sbit Key0=P2^0;	     
sbit Key1=P2^1;
sbit Key2=P2^2;
sbit Key3=P2^3;
sbit Key4=P2^4;
sbit Key5=P2^5;
//保存P2口电平信号
uchar code dsz[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
uchar code dsf[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
uchar code shuangz[]={0x0c,0x06,0x03,0x09,0x0c,0x06,0x03,0x09};
uchar code shuangf[]={0x09,0x03,0x06,0x0c,0x09,0x03,0x06,0x0c};
uchar code danz[]={0x08,0x04,0x02,0x01,0x08,0x04,0x02,0x01};
uchar code danf[]={0x01,0x02,0x04,0x08,0x01,0x02,0x04,0x08};
//正反转以及三种工作方式下需要往P1口送的数据
void main()   //主函数
{
 while(1)
 {
  if(0==Key2)  //判断总开关是否开启
	{
		keyover(); 
	}
 }
}

void keyover()    //正反转控制函数            
{
 for(i=0;i<8;i++)  //循环8次，读取数组数据
 {
	if (1==Key2)  //判断总开关状态
		 break;
  if(0==Key0&&Key1==1)   //K0打开K1关闭调用正转工作方式选择函数
	{
		keyz1(); 
	}
  else if(0==Key1&&1==Key0) //K1打开K0关闭调用反转工作方式选择函数
	{
		keyf1();
	}
	else
	{
	P1=danf[i];delay(400);
	}  //K0K1都没有打开或者都打开按照默认状态工作方式转动
  }
 return;
}

void keyz1()    //正转工作方式选择函数
{
 for(i=0;i<8;i++)
 {
	if(1==Key2) 
	{
		return;
		}
  if(0==Key5&&1==Key4&&1==Key3) //在之前条件下只有K5打开，读取单双八拍数组
	{
	P1=dsz[i];delay(400);
	}
  else if(1==Key5&&0==Key4&&1==Key3) //读取双四拍数组
	{
	P1=shuangz[i];delay(400);
	}
  else if(1==Key5&&1==Key4&&0==Key3) //读取单四拍数组
	{
	P1=danz[i];delay(400);
	}
	else
	{
	P1=danz[i];delay(400);
	}
 }
}

void keyf1()     //反转工作方式选择函数
{
  for(i=0;i<8;i++)
 {
	if(1==Key2) 
	{
		return;
	}
  if(0==Key5&&1==Key4&&1==Key3) 
	{
	P1=dsf[i];delay(400);
	}
  else if(1==Key5&&0==Key4&&1==Key3) 
	{
	P1=shuangf[i];delay(400);
	}
  else if(1==Key5&&1==Key4&&0==Key3) 
	{
	P1=danf[i];delay(400);
	} 		
	else
	{
	P1=danf[i];delay(400);
	}
 }
}

void delay(uint xms)     //延时函数     
{
	uint i,j;
	for(i=110;i>0;i--)
		for(j=xms;j>0;j--);
	}
		
