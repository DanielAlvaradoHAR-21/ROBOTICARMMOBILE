#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(11,12); //Tx es pin 11 y Rx es pin 12 del bluetooth..

Servo pinsa;
Servo munneca1;
Servo munneca2;
Servo codo;
Servo hombro;

char control;
int i;
int cpinsa=80;
int cmunneca1=80;
int cmunneca2=80;
int ccodo=80;
int chombro=80;

void setup() {
  
  bluetooth.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinsa.attach(6);
  munneca1.attach(7);
  munneca2.attach(8);
  codo.attach(9);
  hombro.attach(10);

  pinsa.write(80);
  munneca1.write(80);
  munneca2.write(80);
  codo.write(80);
  hombro.write(80);

}

void loop() {
  if(bluetooth.available()>0){
    control=bluetooth.read();
  }
  if(control =='A'){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
  if(control =='D'){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
  if(control=='C'){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }  
  if(control=='B'){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
  if(control=='X'){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  if(control=='E'){
   for(i=0;i<5;i++){
    cpinsa++;
    pinsa.write(cpinsa);
    delay(20);
   }
   control='O';
  }
  if(control=='F'){
   for(i=0;i<5;i++){
    cpinsa--;
    pinsa.write(cpinsa);
    delay(20);
   }
   control='O';
  }
  if(control=='G'){
   for(i=0;i<5;i++){
    cmunneca1++;
    munneca1.write(cmunneca1);
    delay(20);
   }
   control='O';
  }
  if(control =='H'){
   for(i=0;i<5;i++){
    cmunneca1--;
    munneca1.write(cmunneca1);
    delay(20);
   }
   control='O';
  }
  if(control=='I'){
    for(i=0;i<5;i++){
      cmunneca2++;
      munneca2.write(cmunneca2);
      delay(20);
    } 
   control='O';
  }
  if(control=='J'){
   for(i=0;i<5;i++){
      cmunneca2--;
      munneca2.write(cmunneca2);
      delay(20);
    } 
   control='O';
  }
  if(control=='K'){
    for(i=0;i<5;i++){
      ccodo++;
      codo.write(ccodo);
      delay(20);
    }
    control='O'; 
  }
  if(control=='L'){
    for(i=0;i<5;i++){
      ccodo--;
      codo.write(ccodo);
      delay(20);
    }
    control='O';
   }
  if(control=='M'){
    for(i=0;i<5;i++){
      chombro++;
     hombro.write(chombro);
     delay(20); 
    }
    control='O';
  }
  if(control=='N'){ 
    for(i=0;i<5;i++){
      chombro--;
     hombro.write(chombro);
     delay(20); 
    }
    control='O';
  }
}
