byte dispseg[17] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0xFF};

int m,n;

void disp7seg(int angka){
  byte temp;
  temp = dispseg[angka];
  digitalWrite(4, temp & 0x01);
  digitalWrite(5, temp & 0x02);
  digitalWrite(6, temp & 0x04);
  digitalWrite(7, temp & 0x08);
  digitalWrite(8, temp & 0x10);
  digitalWrite(9, temp & 0x20);
  digitalWrite(10, temp & 0x40);
  digitalWrite(11, temp & 0x80);
  return;
}

void blank7seg(){
  for (n=4;n<=11;n++)
  {
    digitalWrite(n,LOW);
  }
}
void setup() {
  for(n=4;n<=11;n++){
    pinMode(n, OUTPUT);
  }
  blank7seg();
}
void loop() {
  for(m=0;m<17;m++){
    disp7seg(m);
    delay(1000);
  }
    blank7seg();
    delay(1000);
}
