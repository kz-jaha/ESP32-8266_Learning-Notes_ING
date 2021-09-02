#include <driver/dac.h>
#include <math.h>
#define vPoints  240    // 一周期内输出点数量，越多越好，但频率也因此降低
#define vMaxValue 256   //DAC最大值，256对应3.1v，大了的话就失真了，为什么达不到3.3，这个我再考虑一下
float sin_tab[vPoints];

void getsin()
{
  float radian, vAng;    //弧度和角度
  vAng=360.000/vPoints;  //一个点对应的角度
  for(int i=0;i<vPoints;i++){
  radian=vAng*i;
  radian=radian*0.01744; // 弧度=角度*（π/180）= 0.01744
  sin_tab[i]=(vMaxValue/2)*sin(radian)+(vMaxValue/2);   //  i代表某点    radian为某角度对应的弧度      弧度=角度*（π/180） (vMaxValue/2)为正弦波零点处对应DA输入值，即DA满量程的一半；
  //printf("sin tab[%d]: %f\n", i, sin_tab[i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  dac_output_enable(DAC_CHANNEL_1);    //使能dac通道
  getsin();   // 获取正弦波的值
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<vPoints; i++){
    dac_output_voltage(DAC_CHANNEL_1, sin_tab[i]);    //输出电压
  }
}
