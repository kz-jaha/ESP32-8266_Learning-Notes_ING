#include <Wire.h>   //这是与OLED显示器进行I2C通信所需的
#include "SSD1306.h"  //SSD1306.h库是oled显示需要的函数库
#define SDA 21    
#define SCL 22


SSD1306 display(0x3c, SDA, SCL);  //我们还将使用#define宏来指定ESP32 目前SDA引脚对应21，SCL对应22。

void setup() {
  display.init();    //调用SSD1306对象的init方法初始化显示

  display.setTextAlignment(TEXT_ALIGN_LEFT);  // 设置文本为左对齐

  //设置字体大小,这些对应的字体大小分别为10、16和24
  display.setFont(ArialMT_Plain_10);       //设置字体大小为10
  display.drawString(0, 0, "hello jaha");  //指定位置输出文字

  display.setFont(ArialMT_Plain_16);       //设置字体大小16
  display.drawString(0, 10, "hello jaha");  //指定位置输出文字

  display.setFont(ArialMT_Plain_24);       //设置字体大小24
  display.drawString(0, 25, "hello jaha");  //指定位置输出文字
  display.display();    //显示缓存中的内容
}

void loop() {
 
}
