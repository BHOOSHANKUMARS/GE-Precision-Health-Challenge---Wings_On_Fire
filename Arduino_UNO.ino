#include<SoftwareSerial.h>
#define app1 2 //appliance
#define app2 3 //appliance
#define app3 4 //appliance
#define app4 5 //appliance
SoftwareSerial mySerial(6,7); // rx and tx pins

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(115200);
  pinMode(app1,OUTPUT);
  pinMode(app2,OUTPUT);
  pinMode(app3,OUTPUT);
  pinMode(app4,OUTPUT);

  //Serial.begin(115200);
  //
  /*while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}*/
}

void loop() {
  // put your main code here, to run repeatedly:
if (mySerial.available()>0) {
  String payload = mySerial.readStringUntil('\r');
  Serial.println(payload);
  
  if (payload == "1"){
    digitalWrite(app1,HIGH);
    }
  if (payload == "5"){
    digitalWrite(app1,LOW);
    }
    if (payload == "2"){
    digitalWrite(app2,HIGH);
    }
  if (payload == "6"){
    digitalWrite(app2,LOW);
    }
  if (payload == "3"){
    digitalWrite(app3,HIGH);
    }
  if (payload == "7"){
    digitalWrite(app3,LOW);
    }
  if (payload == "4"){
    digitalWrite(app4,HIGH);
    }
  if (payload == "8"){
    digitalWrite(app4,LOW);
    }
  //int data = (Serial.read());
  //Serial.println(data);

}
}
