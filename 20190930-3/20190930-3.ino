const byte led=13;
char val;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello");
  


}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
      val=Serial.read();
      if(val=='1'){
           digitalWrite(led, HIGH); 
            Serial.print("LED ON");
      }else if(val=='0'){
         digitalWrite(led, LOW);  
          Serial.print("LED OFF");
      }
   }


}
