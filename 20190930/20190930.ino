const byte LEDs[]={3,5,7,9,11,13};
const byte total = sizeof(LEDs);
byte buttonPin=2;
byte index=0;
byte index2=0;
int buttonState = 0; 


void setup() {
  for (byte i = 0;i<=total;i++){
    pinMode(LEDs[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
      for (byte i = 0;i<total;i++){
        digitalWrite(LEDs[i], LOW);
      }
      for (byte i = 0;i<=3;i++){
        digitalWrite(LEDs[i*2+index2], HIGH);
      }
      
      if (index2==1){
        index2=0;
      }else{
        index2=1;
      }
    delay(1000);
 } else {
      for (byte i = 0;i<total;i++){
        digitalWrite(LEDs[i], LOW);
      }
      
      if(index>=total){
        index=0;
      }
      digitalWrite(LEDs[index], HIGH);
      index++;
      delay(100);
 
  }
}
