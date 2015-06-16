#include <SoftwareSerial.h>
const int rx = 0;
const int tx = 1;
const int s1p = 2;
const int s2p = 4;
const int s3p = 6;
int data1,data2,data3;

SoftwareSerial ser(rx, tx);

void setup() {
  ser.begin(4800);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  delay(100);
}
void loop() {
  data1 = analogRead(s1p);
  data2 = analogRead(s2p);
  data3 = analogRead(s3p);
  
  ser.write(1);
  ser.write(2);
  ser.write(3);
  ser.write(4);
  ser.write(highByte(data1));
  ser.write(lowByte(data1));
  ser.write(highByte(data2));
  ser.write(lowByte(data2));
  ser.write(highByte(data3));
  ser.write(lowByte(data3));
  
  delay(10);
}
