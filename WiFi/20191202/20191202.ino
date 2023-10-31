#include <ESP8266WiFi.h>
const char* ssid ="a73005151";
const char* password ="05110212";

WiFiServer server(80);





void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(12,1);
  digitalWrite(13,1);

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
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(!client) return;

  String req=client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  int val;
  if(req.indexOf("/LED1_L") != -1){
    val=0;
    digitalWrite(12,LOW);
  }
  else if(req.indexOf("/LED1_H") != -1){
    val=1;
    digitalWrite(12,HIGH);
  }
  else if(req.indexOf("/LED2_L") != -1){
    val=2;
    digitalWrite(13,LOW);
  }
  else if(req.indexOf("/LED2_H") != -1){
    val=3;
    digitalWrite(13,HIGH);
  }
  else  {
    Serial.println("invalid request");
    client.stop();
    return;
  }


}
