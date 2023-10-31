#include <SoftwareSerial.h>



SoftwareSerial BT(8,9);
char val;
const byte led1 = 12;
const byte led2 = 13;
void setup(){
  Serial.begin(9600);
  Serial.println("BT is ready!");
  BT.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  if (Serial.available()){
    val = Serial.read();
    BT.print(val);
  }
  if(BT.available()){
    val = BT.read();
    Serial.print(val);
    if (val == '1'){
      digitalWrite(led1,HIGH);
    }else if(val == '2'){
      digitalWrite(led1,LOW);
    }else if(val == '3'){
      digitalWrite(led2,HIGH);
    }else if(val == '4'){
      digitalWrite(led2,LOW);
    }
  }
}

