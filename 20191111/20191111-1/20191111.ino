// 動手做10-1：調光器
// 詳細的程式說明，請參閱第十章，10-6頁。

byte potPin = A0; // 類比輸入腳位
byte ledPin = 11; // 類比輸出腳位
byte ledPinR = 10; // 類比輸出腳位
int potValue = 0; // 類比輸出值
byte val = 0;     // 儲存轉換範圍值

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  randomSeed(analogRead(A5));
}
void loop() {
  potValue = analogRead(potPin);
  val = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, val);

   analogWrite(ledPinR, random(200));
  delay(1000);
}

