// 定义pwm引脚的序号，可以自己设定，其他引脚也可以，比如我用的是G13
const int pwmPin = 13;  // 13对应于 GPIO13

// 设定 PWM 特性
const int freq = 200000;    //频率  最大频率是312.515khz，你设大了也只能输出最大频率，产生的波形感觉还可以
const int pwmChannel = 0; //通道
const int resolution = 8; //分辨率  2的8次方次=256
int dutycycle = 0;

void setup(){
  // 配置 PWM 功能(初始化)
  ledcSetup(pwmChannel, freq, resolution);
  
  // 将通道连接至 GPIO 以便控制
  ledcAttachPin(pwmPin, pwmChannel);
  n = 256*0.5;
  ledcWrite(pwmChannel, dutycycle);   // dutycycle=2^resolution*占空比
}
 
void loop(){
  
}
