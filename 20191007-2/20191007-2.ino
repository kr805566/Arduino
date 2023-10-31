const byte potPin = A0;
const byte LEDs[]={8,9,10,11,12,13};
const byte total = sizeof(LEDs);
int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

 for (byte i = 0;i<=total;i++){
    pinMode(LEDs[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  val=analogRead(potPin);
  Serial.println(val);
  delay(500);


  if(val<300){
  digitalWrite(LEDs[0], LOW);
  digitalWrite(LEDs[1], LOW);
  digitalWrite(LEDs[2], LOW);
  }else if(val<600){
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], LOW);
  digitalWrite(LEDs[2], LOW);
  }else if(val<900){
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], HIGH);
  digitalWrite(LEDs[2], LOW);
  }else{
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], HIGH);
  digitalWrite(LEDs[2], HIGH);
  }


}
