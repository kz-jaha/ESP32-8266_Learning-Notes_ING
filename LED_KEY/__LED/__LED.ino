int led = 13; //对应ESP32板子上的G13引脚
int key = 12; //对应ESP32板子上的G12引脚
void setup() {
  // 把你的初始化代码放在这里，只运行一次:
  Serial.begin(115200); //初始化串口
  pinMode(led,OUTPUT);  //将GPIO13配置为输出模式
  pinMode(key,INPUT);
}

void loop() {
  // 把你的功能性（主）代码放在这里，重复运行:
  if(digitalRead(key) == HIGH) //当开关按时，12号引脚是高点平
  {
    delay(10);  //按键消抖
    digitalWrite(led,HIGH);  //LED一直亮状态
    Serial.println("按键按LED灯为一直亮！"); //并把这句话打印在串口
    while(digitalRead(key) == HIGH);  //一直到按键松开为止，12号引脚低电平
  }
  if(digitalRead(key) == LOW) //当开关松开时时，12号引脚是低点平
  {
    Serial.println("按键未按时为流水灯！"); //并把这句话打印在串口，再执行下面流水灯程序
    digitalWrite(led,HIGH);  //GPIO2输出高电平 灯亮
    delay(500);  //保持GPIO2高电平500毫秒，即灯亮500ms
    digitalWrite(led,LOW);  //GPIO2输出低电平 灯灭
    delay(500);  //保持GPIO低电平500毫秒，即灯灭500ms
  }
}
