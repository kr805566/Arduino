const byte potPin0 = A0;
const byte potPin1 = A1;
const byte LEDs[]={8,9,10,11,12,13};
const byte total = sizeof(LEDs);
byte buttonPin=2;
int val0,val1;
int buttonState = 0; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

 for (byte i = 0;i<=total;i++){
    pinMode(LEDs[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val0=analogRead(potPin0);
  Serial.print("電阻");
  Serial.println(val0);
  val1=analogRead(potPin1);
  Serial.print("光敏");
  Serial.println(val1);

  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("按紐OFF");
  }else{
    Serial.println("按鈕ON");
  }


  if(val0<300){
  Serial.println("1不亮");
  Serial.println("2不亮");
  Serial.println("3不亮");
  digitalWrite(LEDs[0], LOW);
  digitalWrite(LEDs[1], LOW);
  digitalWrite(LEDs[2], LOW);
  }else if(val0<600){
  Serial.println("1亮");
  Serial.println("2不亮");
  Serial.println("3不亮");
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], LOW);
  digitalWrite(LEDs[2], LOW);
  }else if(val0<900){
  Serial.println("1亮");
  Serial.println("2亮");
  Serial.println("3不亮");
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], HIGH);
  digitalWrite(LEDs[2], LOW);
  }else{
  Serial.println("1亮");
  Serial.println("2亮");
  Serial.println("3亮");  
  digitalWrite(LEDs[0], HIGH);
  digitalWrite(LEDs[1], HIGH);
  digitalWrite(LEDs[2], HIGH);
  }


  if(val1>=700){
  
    digitalWrite(LEDs[3], HIGH);
    Serial.println("4亮");  
  }else if(val1<=650){
  
    digitalWrite(LEDs[3], LOW);
    Serial.println("4不亮");  
  }


   buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("5不亮");
    digitalWrite(LEDs[4], LOW);
  }else{
    Serial.println("5亮");
    digitalWrite(LEDs[4], HIGH);
  
 }
   delay(5000);

}
