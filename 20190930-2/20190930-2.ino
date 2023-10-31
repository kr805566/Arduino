const byte LEDs[]={8,9,10,11,12,13};
const byte total = sizeof(LEDs);
byte buttonPin=2;
byte index=0;
byte index2=0;
int buttonState = 0; 

byte data = B000001; 
//byte data = B100000;
byte shift = 0;
byte sw=0;


void setup() {
  for (byte i = 0;i<=total;i++){
    pinMode(LEDs[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);

  DDRB = B01111111;
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
  
PORTB = data<<shift;
  //PORTB = data>>shift;

  if(shift==5){sw=1;}
  if(shift==0){sw=0;}
  if(sw==0){
    shift++;
  }

   if(sw==1){
    shift--;
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
