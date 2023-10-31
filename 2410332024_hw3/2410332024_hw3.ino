const byte LED = 13;
char val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("2410332024,");
Serial.print("\HI:");
Serial.print(LED);
Serial.print("\nBYE!");
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
   if (val == '1') { 
  digitalWrite(LED,HIGH);
  Serial.print("LED ON"); 
}
else if (val == '0') {
 digitalWrite(LED,LOW);
  Serial.print("LED OFF");
}
}
}
