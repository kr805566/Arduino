int sensorVoice = 3;
int sensorJidianqi = 8; // 
const byte potPin2 = A2;
int val2;
int ledsw=0;
int timed,timen,timel;
int ptime=0;

void setup() 
{ 
pinMode(sensorJidianqi, OUTPUT); 
pinMode(sensorVoice, INPUT); 
Serial.begin(9600); 
}
void loop() {

 val2=analogRead(potPin2);
// Serial.println(val2);

  
if( val2 >430) {
   Serial.println(val2);
    timen=millis();
    ptime++;
 Serial.println(timen);

  if(ptime==2){
    timen=millis();
    timed=timen-timel;
    //Serial.println(timed);
    if(timed>1000 && timed<1500){
      ledsw=1-ledsw;
      ptime=0;
    }else{
      ptime=1;
   }
    timel=timen;
    
 }








  
  
  if(ledsw==0){
  digitalWrite(sensorJidianqi, HIGH); //LOW to power on JiDianQi
  }else{
  digitalWrite(sensorJidianqi, LOW);
  }
//delay(500);
  
}else{

//digitalWrite(sensorJidianqi, LOW); //  
}


}
