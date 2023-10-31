#include <ESP8266WiFi.h>
const char* ssid ="Android1011";
const char* password ="05130513";

const int swPin=16; //磁簧開關接腳 D0
const int buzzer = 14; // 輸出方波至蜂鳴器 D5
const byte trigPin = 13;  // 超音波模組的觸發腳 D7
const int echoPin = 12;    // 超音波模組的接收腳 D6
unsigned long d;          // 儲存高脈衝的持續時間
int buttonState = 0;

bool opened=false;
bool passed=false;

WiFiServer server(80);

unsigned long ping() {
  digitalWrite(trigPin, HIGH);   // 觸發腳設定成高電位
  delayMicroseconds(5);          // 持續 5 微秒
  digitalWrite(trigPin, LOW);    // 觸發腳設定成低電位
 
  return pulseIn(echoPin, HIGH); // 傳回高脈衝的持續時間
}

void setup() {
  pinMode(trigPin, OUTPUT);  // 觸發腳設定成「輸出」
  pinMode(echoPin, INPUT);   // 接收腳設定成「輸入」
  pinMode(swPin, INPUT);   // 磁簧開關接腳設定成「輸入」
  pinMode(buzzer,OUTPUT); // 蜂鳴器設定成「輸出」
  
  Serial.begin(115200);
  delay(10);

  Serial.println("");
  Serial.print("連線到");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500)  ;
    Serial.print(".");
   }
   Serial.println("WiFi 成功");

   server.begin();
    Serial.println("開啟伺服器");

     Serial.print("IP:");
     Serial.print(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if(!client) return;
  
  String s="<script>window.AppInventor.setWebViewString('";

  buttonState = digitalRead(swPin);//判斷磁簧開關
  if(buttonState==LOW){opened=true;}
  
  d = ping() / 58;       // 把高脈衝時間值換算成公分單位
  if(d<=100){passed=true;}
 
if (opened) {//有人開門傳回Opened
      s+=" Opened";
        for ( int i=0; i<5; i++ ) {
            tone(buzzer,1000);
            delay(20);
            tone(buzzer,500);
            delay(20);
        }
        tone(buzzer,0);
 }
if(passed){//有經過傳回Passed
        s+=" Passed";
        for ( int i=0; i<5; i++ ) {
            tone(buzzer,1000);
            delay(20);
            tone(buzzer,500);
            delay(20);
        }
        tone(buzzer,0);
 }

if(!opened && !passed){s+=" Safe";}//無偵測傳回Safe

s+="');</script>";
client.print(s);
      
}
