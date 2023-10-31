#include "Wire.h"
#include "dht11.h"
#include "LiquidCrystal_I2C.h"


dht11 DHT11;

const byte trigPin = 10;  // 超音波模組的觸發腳
const int echoPin = 9;    // 超音波模組的接收腳
unsigned long d;    

const byte dataPin = 2;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);


unsigned long ping() {
  digitalWrite(trigPin, HIGH);   // 觸發腳設定成高電位
  delayMicroseconds(5);          // 持續 5 微秒
  digitalWrite(trigPin, LOW);    // 觸發腳設定成低電位
 
  return pulseIn(echoPin, HIGH); // 傳回高脈衝的持續時間

 
}

void setup() {
  lcd.begin(16,2);
  lcd.backlight();
  delay(2000);
  lcd.noBacklight();
  delay(2000);
  lcd.backlight();
  delay(1000);
   pinMode(trigPin, OUTPUT);  // 觸發腳設定成「輸出」
  pinMode(echoPin, INPUT);   // 接收腳設定成「輸入」

  Serial.begin(9600); 
  
}

void loop() {
 
  d = ping() / 58; 
  
  
  Serial.print(d);       // 顯示距離
  Serial.print("cm");
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
int chk = DHT11.read(dataPin);

 Serial.println(chk);
  if (chk == 0) {
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

     delay(3000);
      lcd.begin(16, 2);
  }

    
}
