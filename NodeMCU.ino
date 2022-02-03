#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <SoftwareSerial.h>
                          
#define FIREBASE_HOST "quartets-9aec7-default-rtdb.firebaseio.com" //Your Firebase Project URL 
#define FIREBASE_AUTH "1ypsHmeCw3sCJd3o2pDSl9CJmshElmOYL84BIOI5" //Your Firebase Database Secret

#define WIFI_SSID "BHOOSHAN"              //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "BHOOSHAN"         //Password of your wifi network 
 

SoftwareSerial mySerial(D7,D6);         //rx & tx pins

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int appliance1, appliance2, appliance3, appliance4;


void setup() {

  Serial.begin(115200);    // Select the same baud rate if you want to see the datas on Serial Monitor
  mySerial.begin(115200);
  
  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                   //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() {


// Firebase Error Handling And Reading Data From Specified Path 
if (Firebase.getInt(firebaseData, "/IRIS/HomeAutomation/appliance1")) {  // On successful Read operation 

    if (firebaseData.dataType() == "int") {                            // print read data if it is integer

      appliance1 = firebaseData.intData();
      if (appliance1 == 1){
        String payload = "1";
        mySerial.println(payload);
        Serial.println("Bulb 1 is ON");
        }
        else{
          String payload = "5";
          mySerial.println(payload);
          Serial.println("Bulb 1 is OFF");
          }  
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }

  
if (Firebase.getInt(firebaseData, "/IRIS/HomeAutomation/appliance2")) { // On successful Read operation 

    if (firebaseData.dataType() == "int") {                            // print read data if it is integer

      appliance2 = firebaseData.intData();
      if (appliance2 == 1){
        String payload = "2";
        mySerial.println(payload);
        Serial.println("Bulb 2 is ON");
        }
        else{
          String payload = "6";
          mySerial.println(payload);
          Serial.println("Bulb 2 is OFF");
          }  
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.getInt(firebaseData, "/IRIS/HomeAutomation/appliance3")) {// On successful Read operation  

    if (firebaseData.dataType() == "int") {                            // print read data if it is integer

      appliance3 = firebaseData.intData();
      if (appliance3 == 1){
        String payload = "3";
        mySerial.println(payload);
        Serial.println("Bulb 3 is ON");
        }
        else{
          String payload = "7";
          mySerial.println(payload);
          Serial.println("Bulb 3 is OFF");
          }  
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.getInt(firebaseData, "/IRIS/HomeAutomation/appliance4")) {// On successful Read operation  

    if (firebaseData.dataType() == "int") {                            // print read data if it is integer

      appliance4 = firebaseData.intData();
      if (appliance4 == 1){
        String payload = "4";
        mySerial.println(payload);
        Serial.println("Bulb 4 is ON");
        }
        else{
          String payload = "8";
          mySerial.println(payload);
          Serial.println("Bulb 4 is OFF");
          }  
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }
 
 }
