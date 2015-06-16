#include <SoftwareSerial.h>
const int rx = 0;
const int tx = 1;
int data1,data2,data3;
int val1,val2,val3,val4,val5,val6,val7,val8;
int i = 0;
// angles of servos;
SoftwareSerial ser(0, 1);
int clock = 0;

void setup() {
  ser.begin(4800);
  data1 = 0; data2 = 0; data3 = 0;
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  
}
void loop() {
  if(ser.available()){
      
      val8 = val7;
      val7 = val6;
      val6 = val5;
      val5 = val4;
      val4 = val3;
      val3 = val2;
      val2 = val1;
      //val1 = ser.read();
      char b = ser.read();
      val1 = (int)b;
      if(b == 'A'){
        data1 = (int)val4;
        data2 = (int)val3;
        data3 = (int)val2;
      }
      //ser.flush();
  }
    
    if(data1 <10)
    data1 = 10;
    if(data1 > 50)
    data1 = 50;
    
    if(data2 <0)
    data2 = 0;
    if(data2 > 50)
    data2 = 50;
    
    if(data3 <0)
    data3 = 0;
    if(data3 > 50)
    data3 = 50;
  
    clock ++;
    if(clock >= 8){
      servo(8,data1,10,50);
      servo(7,data2,0,50);
      servo(6,data3,50,0);
      clock = 0;
      //delay(5);
      delayMicroseconds(300);
    }
    delay(5);
}
void servo(int pin, int value,int low,int high){
  int tPulse        = 4000;         // Total pulse length on 1 Mhz clock 
  int degree0 = 135; // 135 ~ 700
  
  int servoData = map(value,low,high,135,2000);

  if(servoData < 135){
    servoData = 135;
  }else if(servoData > 2000){
    servoData = 2000;
  }
  //ser.print((char)map(servoData,135,2000,0,100));
  digitalWrite(pin,250);
  delayMicroseconds(servoData);
  digitalWrite(pin,0);
  delayMicroseconds(tPulse - servoData);
}
