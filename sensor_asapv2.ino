//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "asap-a1ef8.firebaseio.com"
#define FIREBASE_AUTH "5pcR6bdS2nyViCXxTivsoRVZG9G83oEEMcnN7nZk"
#define WIFI_SSID "Momoland"
#define WIFI_PASSWORD "01010101"
#define sensor A0
#define buzzer  D4
#define ledAman D2
#define ledBahaya D3

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(ledAman, OUTPUT);
  pinMode(ledBahaya, OUTPUT);
  pinMode(buzzer,OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  Serial.println(analogRead(sensor));
  delay(100);
  Firebase.setInt("asap", analogRead(sensor));

  if (analogRead(sensor)>=400){
    
    digitalWrite(ledBahaya,HIGH); 
    delay(100);
    digitalWrite(ledBahaya,LOW); 
    delay(100); 
    digitalWrite(ledAman,LOW);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    
  }
  else{
    digitalWrite(ledAman,HIGH);
    digitalWrite(ledBahaya,LOW);
    digitalWrite(buzzer, LOW); 
  }
}
