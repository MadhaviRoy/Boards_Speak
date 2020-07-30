
//Program to read the LDR value connected (in potential divider arrangement) to GPIO 34 (Analog ADC1_CH6) and update the status tag (on the basis of threshold) in the firebase database. 

// LDR is connected to GPIO 34 (Analog ADC1_CH6) 

#include<WiFi.h>                  //header file from preinstalled WiFi library
#include <FirebaseESP32.h>        //header file from preinstalled FirebaseESP32Client library
const char* ssid = "******";      //SSID of your WiFi network
const char* password ="******";   //Passwork of your WiFi network
const int LDRPin = 34;            //Define GPIO Pin number for LDR
#define FIREBASE_HOST "https://********.firebaseio.com/"  //Link to your firebase database page
#define FIREBASE_AUTH "2U2SL5B7eHmoTnO********6ivdxUPmoOZoFErQg" //Database secret/Authentication key

FirebaseData firebaseData;

// variable for storing the LDR value
int LDRValue = 0;

void setup() {
  Serial.begin(115200);           //Initiate Serial communication at a baudrate of 115200
  delay(1000);
  WiFi.begin(ssid,password);      //Initiate WiFi using the SSID and Password
  while(WiFi.status()!= WL_CONNECTED){            
    delay(500);
    Serial.println("Connecting to WiFi...");      //Print this message on the serial monitor untill connected to WiFi
    }
  Serial.println("Coonected to WiFi network");    //Print this message once connected to WiFi
  Serial.println(WiFi.localIP());                 //Print the IP address provoded to WROOM32
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   //Connect to the firebase database webpage using the credentials 
    Firebase.reconnectWiFi(true);
}

void loop() {
  
  LDRValue = analogRead(LDRPin);      // Reading LDR value
  Serial.println(LDRValue);           //Print the value on serial monitor (required for calibration)
  delay(500);
  if (LDRValue<=2000)                 //Compare the value with the threshold (here 2000 according to the light condition at my place) 
  {
     if(Firebase.setInt(firebaseData, "/IoTDemoApp/Status", 0)) //set the value of Status tag to 0
  {
    //Success
     Serial.println("Set int data success 0");    //print success message for verification

  }
  }else if(potValue>2000)           //Compare the value with the threshold
  {
     if(Firebase.setInt(firebaseData, "/IoTDemoApp/Status", 1))     //set the value of Status tag to 1
  {
    //Success
     Serial.println("Set int data success 1");      //print success message for verification


  }
    //Failed?, get the error reason from firebaseData
  }
  else{
    Serial.print("Error in setInt, ");
    Serial.println(firebaseData.errorReason());
  }
    }
