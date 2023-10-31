#include "Wire.h"
#include "dht11.h"
#include "LiquidCrystal_I2C.h"


dht11 DHT11;

const byte LEDs[]={8,9,12,13};
const byte total = sizeof(LEDs);
const byte trigPin = 11;  // 超音波模組的觸發腳
const int echoPin = 10;    // 超音波模組的接收腳
unsigned long d;    

const byte dataPin = 7;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
const byte potPin = A0;
int val;

unsigned long ping() {
  digitalWrite(trigPin, HIGH);   // 觸發腳設定成高電位
  delayMicroseconds(5);          // 持續 5 微秒
  digitalWrite(trigPin, LOW);    // 觸發腳設定成低電位
 
  return pulseIn(echoPin, HIGH); // 傳回高脈衝的持續時間

 
}

void setup() {
  lcd.begin(16,2);
  lcd.backlight();
  delay(1000);
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  delay(1000);
   pinMode(trigPin, OUTPUT);  // 觸發腳設定成「輸出」
  pinMode(echoPin, INPUT);   // 接收腳設定成「輸入」

  Serial.begin(9600); 

   for (byte i = 0;i<=total;i++){
    pinMode(LEDs[i], OUTPUT);
  }
  
}

void loop() {

  val=analogRead(potPin);
   Serial.print("R:");
  Serial.println(val);


  

  if(val<450){
  digitalWrite(LEDs[0], LOW);
  digitalWrite(LEDs[1], LOW);
  lcd.setCursor(0,0);
  Serial.println("LED0 LED1 OFF");
  lcd.print("LED0 LED1 OFF");
  }else if(val<900){
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], LOW);
 lcd.setCursor(0,0);
 Serial.println("LED0 ON LED1 OFF");
  lcd.print("LED0 ON LED1 OFF");
  }else {
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], HIGH);
   lcd.setCursor(0,0);
    Serial.println("LED0 LED1 ON");
  lcd.print("LED0 LED1 ON");
  }
 
  delay(1000);
  ////////////////////////////////

int chk = DHT11.read(dataPin);

 /*Serial.println(chk);
  if (chk == -1) {*/
     lcd.begin(16, 2);
    lcd.setCursor(4, 0);
  lcd.print("Temp");
  lcd.setCursor(0, 1);
  lcd.print("Humidity");
    
    lcd.setCursor(9, 0);   // 顯示溫度
    lcd.print((float)DHT11.temperature, 2);
    lcd.print((char) 0xDF);
    lcd.print("C");
 
    lcd.setCursor(9, 1);   // 顯示濕度
    lcd.print((float)DHT11.humidity, 2);
    lcd.print("%");
     Serial.print("temperature");
     Serial.print((float)DHT11.temperature);
    Serial.println("C");
     Serial.print("humidity");
     Serial.print((float)DHT11.humidity);
      Serial.println("%");

      if((float)DHT11.temperature<28){
    digitalWrite(LEDs[2], HIGH);
    Serial.println("LED2 ON");
  }else{
    digitalWrite(LEDs[2], LOW);
     Serial.println("LED2 OFF");
  }
  
       delay(1000);
  //}



  //////////////////////////
  lcd.begin(16, 2);

  
  d = ping() / 58; 

  if(d<10){
    digitalWrite(LEDs[3], HIGH);
    Serial.println("LED3 ON");
  }else{
    digitalWrite(LEDs[3], LOW);
    Serial.println("LED3 OFF");
  }

  Serial.print(d);       // 顯示距離
  Serial.print("cm ");
  
  Serial.println();

  
  
  lcd.setCursor(0,0);
  lcd.print(d);
  lcd.print("cm   ");
  
  
  delay(1000);
  
  
  /*lcd.setCursor(0,1);
  lcd.print("Good Morning    ");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Nice to meet you");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Have a nice day ");
  delay(3000);*/

  

    
}
