#include <NewPing.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

const int ECHO1 = 9;
const int TRIG1 = 8;

const int ECHO2 = 11;
const int TRIG2 = 10;

unsigned int jarak1, jarak2, k, timer;
unsigned int masuk, keluar, pengunjung;

void ukur_jarak1(){
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);
  timer = pulseIn(ECHO1, HIGH);
  jarak1 = timer/58;
}

void ukur_jarak2(){
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);
  timer = pulseIn(ECHO2, HIGH);
  jarak2 = timer/58;
}

void setup() {
  lcd.begin(16,2);
  lcd.print("penghitung orang");
  lcd.setCursor(0, 1);
  lcd.print(" 2 PINTU");
  delay(2000);

  lcd.clear();
  lcd.print("In=0    Out=0");
  lcd.setCursor(0, 1);
  lcd.print("visitor=0");

  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG2, OUTPUT);

}

void loop() {
  ukur_jarak1();
  if (jarak1 <=70){
    do
        ukur_jarak1();
        while (jarak1 <70);
        pengunjung++;
        masuk++;
        lcd.setCursor(3, 0);
        lcd.print(masuk);
        lcd.setCursor(8, 1);
        delay(1000);
  }
  ukur_jarak2();
  if (jarak2 <= 70 && masuk > 0){
    do
        ukur_jarak2();
        while (jarak2 <70);
        keluar++;
        masuk--;
        lcd.setCursor(3,0);
        lcd.print(masuk);
        lcd.setCursor(12,0);
        lcd.print(keluar);
        lcd.setCursor(8,1);
        lcd.print(pengunjung);
        delay(500);
  }
  jarak1 = 200;
  jarak2 = 200;
  delay(100);
}
