const byte LEDs[]={8,9,10,11,12,13};
const byte total = sizeof(LEDs);
char val;
byte data = B000001; 
//byte data = B100000;
byte shift = 0;
byte sw=0;
byte index=0;
byte index2=0;

void setup() {
 for (byte i = 0;i<=total;i++){
    pinMode(LEDs[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Hello");
  
  DDRB = B01111111;
  


}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
      val=Serial.read();

      if(val=='1'){
        digitalWrite(LEDs[0], HIGH);
      }
      
      if(val=='2'){
        digitalWrite(LEDs[0], LOW);
      }
      
      if(val=='3'){
        digitalWrite(LEDs[1], HIGH);
      }
      
      if(val=='4'){
        digitalWrite(LEDs[1], LOW);
      }
      
      if(val=='5'){
        digitalWrite(LEDs[2], HIGH);
      }
      
      if(val=='6'){
        digitalWrite(LEDs[2], LOW);
      }

      
      if(val=='7'){
        for (byte i = 0;i<total;i++){
          PORTB = data<<shift;
          shift++;
          delay(100);
        }
          
      }else if(val=='8'){
        for (byte i = 0;i<total;i++){
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
    delay(100);
      }
      }
   }


}
