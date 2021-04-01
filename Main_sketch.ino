#define TRIGGER  4
#define ECHO     5
#define TRIGGER2 12
#define ECHO2    14

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "7fzPf6PVUjFVn2sCAu_dQz2xyId_gLzX";


char ssid[] = "bloom_corp";
char pass[] = "bloom_wrench";
void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;

  long duration2, distance2;
  digitalWrite(TRIGGER2, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER2, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER2, LOW);
  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = (duration2/2) / 29.1;

  Serial.print(distance);
  Serial.println("Centimeter:");
  Blynk.virtualWrite(V5, distance);
  Serial.print(distance2);
  Serial.println("Centimeter:");
  Blynk.virtualWrite(V6, distance2);
  delay(200);
  Blynk.run();
}
