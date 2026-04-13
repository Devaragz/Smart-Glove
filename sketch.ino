#define BLYNK_TEMPLATE_ID "TMPL3tKn9UsDE"
#define BLYNK_TEMPLATE_NAME "Smart Glove"
#define BLYNK_AUTH_TOKEN "fOKDdCipChptoOU1K9hFNPQLYP8wRuRr"

#include <Arduino.h>
#include<WiFi.h>
#include<WiFiClient.h>
#include<BlynkSimpleEsp32.h>
#include<Adafruit_MPU6050.h>
#include<Adafruit_Sensor.h>
#include<Wire.h>

char ssid[]="Wokwi-GUEST";
char pass[]="";

//pins and threshold
const int THUMB_PIN = 32;
const int INDEX_PIN = 33;
const int MIDDLE_PIN = 34;
const int THRESHOLD = 2000;

Adafruit_MPU6050 mpu;

bool isNotify=false;

void setup() {
  Serial.begin(115200);
  Serial.println("Smart Glove Ready...");
  if(!mpu.begin()){Serial.println("Failed to find MPU6050 chip");}
  //connect to Wifi & Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
}

void loop() {
  Blynk.run();
  sensors_event_t a,g,temp;
  mpu.getEvent(&a,&g,&temp);
  int thumb = analogRead(THUMB_PIN);
  int index = analogRead(INDEX_PIN);
  int middle = analogRead(MIDDLE_PIN);

  //wrist movement
  if(a.acceleration.x>15 || a.acceleration.y>15){
    Serial.println("Gesture: Emergency! (Hand shaking)");
    Blynk.virtualWrite(V1,"Emergency! (Hand shaking)");
    Blynk.virtualWrite(V2,"Emergency!");
    Blynk.logEvent("shake_alert","Emergency! Hand is shaking!");
    isNotify=true;}
    
    // 1.Thumb only
  else if (thumb > THRESHOLD && index < THRESHOLD && middle < THRESHOLD) {
      Serial.println("Gesture 1: I need water");
      Blynk.virtualWrite(V1,"I need water");
      Blynk.virtualWrite(V2,"Gesture-1 Detected");
      Blynk.logEvent("gesture_info","I need water");
      delay(2000);
  } 
    // 2.All fingers bent
  else if (thumb > THRESHOLD && index > THRESHOLD && middle > THRESHOLD) {
      Serial.println("Gesture 2: Help!");
      Blynk.virtualWrite(V1,"Help!");
      Blynk.virtualWrite(V2,"Gesture-2 Detected");
      Blynk.logEvent("gesture_info","Help!");
      delay(2000);
  }
    // 3.Index only
  else if (thumb < THRESHOLD && index > THRESHOLD && middle < THRESHOLD) {
      Serial.println("Gesture 3: Hello / Come here");
      Blynk.virtualWrite(V1,"Hello / Come here");
      Blynk.virtualWrite(V2,"Gesture-3 Detected");
      Blynk.logEvent("gesture_info","Hello");
      delay(2000);
  }
    // 4.Index and Middle
  else if (thumb < THRESHOLD && index > THRESHOLD && middle > THRESHOLD) {
      Serial.println("Gesture 4: Peace / All Good");
      Blynk.virtualWrite(V1,"Peace / All Good");
      Blynk.virtualWrite(V2,"Gesture-4 Detected");
      Blynk.logEvent("gesture_info","All Good");
      delay(2000);
  }
    // 5.Thumb and Middle only
  else if (thumb > THRESHOLD && index < THRESHOLD && middle > THRESHOLD) {
      Serial.println("Gesture 5: I need food");
      Blynk.virtualWrite(V1,"I need food");
      Blynk.virtualWrite(V2,"Gesture-5 Detected");
      Blynk.logEvent("gesture_info","I need food");
      delay(2000);
  }
  else{
    isNotify=false;
  }
  delay(100); //delay for stability
}