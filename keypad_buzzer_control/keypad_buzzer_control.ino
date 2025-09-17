#include <Keypad.h>
#include <LiquidCrystal.h>
#include<EEPROM.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 4;
const byte COLS = 4;
char hexakeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {A0,A1,A2,A3};
byte colPins[COLS] = {9, 8, 7, 6};
const int buzzer=13;

Keypad customKeypad = Keypad( makeKeymap(hexakeys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);
  lcd.begin(16,2);
  lcd.print("Keypad:");
  Serial.begin(9600);

}

void loop() {
  char customKey = customKeypad.getKey();
  lcd.setCursor(0,1);

  if (customKey != NO_KEY ) {
    lcd.print(customKey);
  }
  switch(customKey){
    case '1':
      kedip(1);
      break;
    case '2':
      kedip(2);
      break;
    case '3':
      kedip(3);
      break;
    case '4':
      kedip(4);
      break;
  }
}
void kedip(int jumlah){
  for(int i=1; i<=jumlah; i++){
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
  }
}