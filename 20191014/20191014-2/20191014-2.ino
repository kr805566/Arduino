int val=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float rA;
  
  val=Serial.read();
  val=val-48;
  
   rA=A(val);
   if (val>0){
   Serial.println(rA);  
   }
  delay(1000);
}

float A(int i){
  float rA;
  rA=i*i*3.14;
  return rA;
}
