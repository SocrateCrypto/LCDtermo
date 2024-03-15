/*
Creato da @SuperMarioTerminator t.me Telegram
per forum AlexGyver





*/


#include <Arduino.h>
//#include <SPI.h>
#include <U8g2lib.h>
#include <microDS18B20.h>
#include <Wire.h>
// Датчики на D2 и D3
MicroDS18B20<13> sensor1;
MicroDS18B20<A0> sensor2;
MicroDS18B20<A3> sensor3;
MicroDS18B20<A4> sensor4;
MicroDS18B20<A5> sensor5;
MicroDS18B20<1> sensor6;
/* Constructor */
U8G2_KS0108_128X64_F u8g2(U8G2_R0, 2, 3, 4, 5, 6, 7, 8, 9, /*enable=*/A2, /*dc=*/A1, /*cs0=*/10, /*cs1=*/11, /*cs2=*/U8X8_PIN_NONE, /* reset=*/12); // Set R/W to low!
/* u8g2.begin() is required and will sent the setup/init sequence to the display */
void setup(void) 
{
  u8g2.begin();
  //Serial.begin(9600);
}

void loop(void)
{
  
  static uint32_t tmr;
  if (millis() - tmr >= 800)
  {
    tmr = millis();

    // читаем прошлое значение
    if (sensor1.readTemp())
    {

    }
      //Serial.println(sensor1.getTemp());
    else{

    }
      //Serial.println("error");

    // запрашиваем новое измерение
    sensor1.requestTemp();
    if (sensor2.readTemp())
    {

    }
      //Serial.println(sensor2.getTemp());
    else{

    }
      //Serial.println("error");

    // запрашиваем новое измерение
    sensor2.requestTemp();
    if (sensor3.readTemp())
    {

    }
     // Serial.println(sensor3.getTemp());
    else{

    }
     // Serial.println("error");

    // запрашиваем новое измерение
    sensor3.requestTemp();
    if (sensor4.readTemp())
    {

    }
     // Serial.println(sensor4.getTemp());
    else{

    }
     // Serial.println("error");

    // запрашиваем новое измерение
    sensor4.requestTemp();
    if (sensor5.readTemp())
    {

    }
    //  Serial.println(sensor5.getTemp());
    else{

    }
     // Serial.println("error");

    // запрашиваем новое измерение
    sensor5.requestTemp();
    if (sensor6.readTemp())
    {

    }
     // Serial.println(sensor6.getTemp());
     else {

     };
     // Serial.println("error");

    // запрашиваем новое измерение
    sensor6.requestTemp();
  }
  


  u8g2.clearBuffer();
  u8g2.sendBuffer();

  u8g2.setFont(u8g2_font_resoledbold_tr);
  u8g2.drawStr(2, 12, "Sea");
  char buffer[15]; // Буфер для хранения строки

  // Преобразование float в строку
  dtostrf(sensor1.getTemp(), 4, 1, buffer);

  const char *temp1 = buffer;
  u8g2.setFont(u8g2_font_haxrcorp4089_tn);
  u8g2.drawStr(38, 12, temp1);
  // Преобразование float в строку
  dtostrf(sensor4.getTemp(), 4, 1, buffer);

  const char *temp4 = buffer;

  u8g2.drawStr(88, 12, temp4);
  u8g2.setFont(u8g2_font_resoledbold_tr);
  u8g2.drawStr(2, 38, "Cool");
  

  // Преобразование float в строку
  dtostrf(sensor2.getTemp(), 4, 1,  buffer);
  u8g2.setFont(u8g2_font_haxrcorp4089_tn);
  const char *temp2 = buffer;

  u8g2.drawStr(38, 38, temp2);
  // Преобразование float в строку
  dtostrf(sensor5.getTemp(), 4, 1, buffer);

  const char *temp5 = buffer;
  
  u8g2.drawStr(88, 38, temp5);
  u8g2.setFont(u8g2_font_resoledbold_tr);
  u8g2.drawStr(2, 62, "Oil");

  u8g2.setFont(u8g2_font_haxrcorp4089_tn);
  // Преобразование float в строку
  dtostrf(sensor3.getTemp(), 4, 1, buffer);

  const char *temp3 = buffer;

  u8g2.drawStr(38, 62, temp3);
  
  // Преобразование float в строку
  dtostrf(sensor6.getTemp(), 4, 1, buffer);

  const char *temp6 = buffer;

  u8g2.drawStr(88, 62, temp6);
  u8g2.setFont(u8g2_font_6x12_t_symbols);

  u8g2.drawGlyph(115,62,8451); /* dec 9731/hex 2603 Snowman */
  u8g2.drawGlyph(65, 62, 8451); /* dec 9731/hex 2603 Snowman */
  u8g2.drawGlyph(115, 38, 8451); /* dec 9731/hex 2603 Snowman */
  u8g2.drawGlyph(65, 38, 8451);   /* dec 9731/hex 2603 Snowman */
  u8g2.drawGlyph(115, 12, 8451); /* dec 9731/hex 2603 Snowman */
  u8g2.drawGlyph(65, 12, 8451);  /* dec 9731/hex 2603 Snowman */
  u8g2.sendBuffer();
  delay(1000);
}