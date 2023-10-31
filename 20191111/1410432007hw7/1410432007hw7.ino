const byte trigPin = 11;  // 超音波模組的觸發腳
const int echoPin = 3;    // 超音波模組的接收腳
unsigned long d;    
const byte ledPin1=9;
const byte ledPin2=10;




unsigned long ping() {
  digitalWrite(trigPin, HIGH);   // 觸發腳設定成高電位
  delayMicroseconds(5);          // 持續 5 微秒
  digitalWrite(trigPin, LOW);    // 觸發腳設定成低電位
 
  return pulseIn(echoPin, HIGH); // 傳回高脈衝的持續時間

 
}

void setup() {

  
   pinMode(trigPin, OUTPUT);  // 觸發腳設定成「輸出」
  pinMode(echoPin, INPUT);   // 接收腳設定成「輸入」

  Serial.begin(9600); 

   
  
}

void loop() {



  
  d = ping() / 58; 
Serial.println(d);
  if(d<5){
    analogWrite(ledPin1, 10);
    analogWrite(ledPin2, 10);
  
  }else if(d>=5 and d<10){
    analogWrite(ledPin1, 50);
    analogWrite(ledPin2, 50);
  }else if(d>=10 and d<15){
    analogWrite(ledPin1, 100);
    analogWrite(ledPin2, 100);
  
  }else{
    analogWrite(ledPin1, 200);
    analogWrite(ledPin2, 200);
  
  }



  

    
}
