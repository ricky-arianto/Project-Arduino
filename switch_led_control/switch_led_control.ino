const int pinS1 = 4;
const int pinS2 = 5;
const int pinS3 = 6;
const int pinS4 = 7;

const int pinLED1 = 8;
const int pinLED2 = 9;
const int pinLED3 = 10;
const int pinLED4 = 11;
void setup() {
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);
  pinMode(pinS1, INPUT);
  pinMode(pinS2, INPUT);
  pinMode(pinS3, INPUT);
  pinMode(pinS4, INPUT);
  digitalWrite(pinLED1,LOW);
  digitalWrite(pinLED2,LOW);
  digitalWrite(pinLED3,LOW);
  digitalWrite(pinLED4,LOW);
  digitalWrite(pinS1,HIGH);
  digitalWrite(pinS2,HIGH);
  digitalWrite(pinS3,HIGH);
  digitalWrite(pinS4,HIGH);
}

void loop() {
  if(digitalRead(pinS1)==0 && digitalRead(pinS2)==1 && digitalRead(pinS3)==1 && digitalRead(pinS4)==1){
    digitalWrite(pinLED1,HIGH);
    digitalWrite(pinLED2,LOW);
    digitalWrite(pinLED3,LOW);
    digitalWrite(pinLED4,LOW);
  }else
  if(digitalRead(pinS1)==1 && digitalRead(pinS2)==0 && digitalRead(pinS3)==1 && digitalRead(pinS4)==1){
    digitalWrite(pinLED1,LOW);
    digitalWrite(pinLED2,HIGH);
    digitalWrite(pinLED3,LOW);
    digitalWrite(pinLED4,LOW);
  }else
  if(digitalRead(pinS1)==1 && digitalRead(pinS2)==1 && digitalRead(pinS3)==0 && digitalRead(pinS4)==1){
    digitalWrite(pinLED1,LOW);
    digitalWrite(pinLED2,LOW);
    digitalWrite(pinLED3,HIGH);
    digitalWrite(pinLED4,LOW);
      }else
  if(digitalRead(pinS1)==1 && digitalRead(pinS2)==1 && digitalRead(pinS3)==1 && digitalRead(pinS4)==0){
    digitalWrite(pinLED1,LOW);
    digitalWrite(pinLED2,LOW);
    digitalWrite(pinLED3,LOW);
    digitalWrite(pinLED4,HIGH);
  }
  delay(300);
}
