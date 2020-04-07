#include <Servo.h>

Servo myservoL, myservoR;

const byte ServoR_pin = 12;
const byte ServoL_pin = 13;

const byte ss1 = 2; // sensor 1
const byte ss2 = 3; // sensor 2
const byte ss3 = 4; // sensor 3
const byte ss4 = 5; // sensor 4
const byte ss5 = 6; // sensor 5
const byte ss6 = 8; // sensor Near
const byte clp = 7; // sensor CLP

/*byte v1;
byte v2;*/
byte r = 0;

void setup() {
  myservoR.attach(ServoR_pin);
  myservoL.attach(ServoL_pin);
  
  myservoR.write(90);
  myservoL.write(90);
  
  Serial.begin(9600);
  r = 0;
  pinMode(ss1, INPUT);
  pinMode(ss2, INPUT);
  pinMode(ss3, INPUT);
  pinMode(ss4, INPUT);
  pinMode(ss5, INPUT);
  //pinMode(ss6, INPUT);
  pinMode(clp, INPUT);
}

int getSensorData(int p) {
  if (/*digitalRead(ss6) == 1 ||*/ digitalRead(clp) == 1)
    return(0);
  else if (digitalRead(ss3) == 0)
    return(1);
  else if (digitalRead(ss5) == 0)
    return(2);
  else if (digitalRead(ss1) == 0)
    return(-2);
  else if (digitalRead(ss4) == 0)
    return(2);
  else if (digitalRead(ss2) == 0)
    return(-2);
  else
    return(p);
}

void loop() {
  /*v1 = getSensorData(v2);
  v2 = v1;
  switch(v2) {
    case 1:  //直行
      myservoR.write(86);
      myservoL.write(94);
      break;
    case 2:  //右轉
      myservoR.write(93);
      myservoL.write(93);
      break;
    case -2: //左轉
      myservoR.write(87);
      myservoL.write(87);
      break;
    case 0:  //停
      myservoR.write(90);
      myservoL.write(90);
      break;
  }*/
  while(1) {
    if(r > 9) {
      myservoR.write(90);
      myservoL.write(90);
      delay(500);
    }
    if(digitalRead(ss3) == 0 && digitalRead(ss4) == 0 && digitalRead(ss2) == 0) {
      myservoR.write(0);
      myservoL.write(180);
    }
    if(digitalRead(clp) == 1) {
      myservoR.write(180);
      myservoL.write(0);
      r = 0;
      continue;
    }
    if(digitalRead(ss3) == 0 && digitalRead(ss2) == 0) {
      r++;
    }
    else if(digitalRead(ss3) == 0 && digitalRead(ss4) == 0) {
      r++;
    }
    else
      r = 0;
    if((digitalRead(ss3) == 0 && digitalRead(ss1) == 0 && digitalRead(ss2) == 0) || (digitalRead(ss1) == 0 && digitalRead(ss2) == 0)) {
      /*myservoR.write(60);
      myservoL.write(120);
      delay(300);*/
      myservoR.write(0);
      myservoL.write(0);
      delay(300);
      continue;
    }
    if((digitalRead(ss3) == 0 && digitalRead(ss5) == 0 && digitalRead(ss4) == 0) || (digitalRead(ss5) == 0 && digitalRead(ss4) == 0)) {
      /*myservoR.write(60);
      myservoL.write(120);
      delay(300);*/
      myservoR.write(180);
      myservoL.write(180);
      delay(300);
      continue;
    }
    if(digitalRead(ss2) == 0 || digitalRead(ss1) == 0) {
      myservoR.write(82);
      myservoL.write(82);
    }
    if(digitalRead(ss4) == 0 || digitalRead(ss5) == 0) {
      myservoR.write(98);
      myservoL.write(98);
    }
    if(digitalRead(ss3) == 0) {
      myservoR.write(0);
      myservoL.write(180);
    }
    if(digitalRead(ss3) != 0 && digitalRead(ss5) != 0 && digitalRead(ss4) != 0 && digitalRead(ss1) != 0 && digitalRead(ss2) != 0) {
      myservoR.write(0);
      myservoL.write(180);
    }
    
    delay(60);
  }
}
