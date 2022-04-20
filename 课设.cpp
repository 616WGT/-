#include  <reg51.h>             
#include  <stdio.h>
#include  <stdlib.h>
#include <absacc.h>
#define uint unsigned int     
#define uchar unsigned char  

void delay(uint xms);    //��ʱ����
void keyf1();   //��ת������ʽѡ����        
void keyz1();   //��ת������ʽѡ����       
void keyover();    //����תѡ����   

unsigned int i;   //iΪ��ȡ����ָ��

sbit Key0=P2^0;	     
sbit Key1=P2^1;
sbit Key2=P2^2;
sbit Key3=P2^3;
sbit Key4=P2^4;
sbit Key5=P2^5;
//����P2�ڵ�ƽ�ź�
uchar code dsz[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
uchar code dsf[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
uchar code shuangz[]={0x0c,0x06,0x03,0x09,0x0c,0x06,0x03,0x09};
uchar code shuangf[]={0x09,0x03,0x06,0x0c,0x09,0x03,0x06,0x0c};
uchar code danz[]={0x08,0x04,0x02,0x01,0x08,0x04,0x02,0x01};
uchar code danf[]={0x01,0x02,0x04,0x08,0x01,0x02,0x04,0x08};
//����ת�Լ����ֹ�����ʽ����Ҫ��P1���͵�����
void main()   //������
{
 while(1)
 {
  if(0==Key2)  //�ж��ܿ����Ƿ���
	{
		keyover(); 
	}
 }
}

void keyover()    //����ת���ƺ���            
{
 for(i=0;i<8;i++)  //ѭ��8�Σ���ȡ��������
 {
	if (1==Key2)  //�ж��ܿ���״̬
		 break;
  if(0==Key0&&Key1==1)   //K0��K1�رյ�����ת������ʽѡ����
	{
		keyz1(); 
	}
  else if(0==Key1&&1==Key0) //K1��K0�رյ��÷�ת������ʽѡ����
	{
		keyf1();
	}
	else
	{
	P1=danf[i];delay(400);
	}  //K0K1��û�д򿪻��߶��򿪰���Ĭ��״̬������ʽת��
  }
 return;
}

void keyz1()    //��ת������ʽѡ����
{
 for(i=0;i<8;i++)
 {
	if(1==Key2) 
	{
		return;
		}
  if(0==Key5&&1==Key4&&1==Key3) //��֮ǰ������ֻ��K5�򿪣���ȡ��˫��������
	{
	P1=dsz[i];delay(400);
	}
  else if(1==Key5&&0==Key4&&1==Key3) //��ȡ˫��������
	{
	P1=shuangz[i];delay(400);
	}
  else if(1==Key5&&1==Key4&&0==Key3) //��ȡ����������
	{
	P1=danz[i];delay(400);
	}
	else
	{
	P1=danz[i];delay(400);
	}
 }
}

void keyf1()     //��ת������ʽѡ����
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

void delay(uint xms)     //��ʱ����     
{
	uint i,j;
	for(i=110;i>0;i--)
		for(j=xms;j>0;j--);
	}
		
