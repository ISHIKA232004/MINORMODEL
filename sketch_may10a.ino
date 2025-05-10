
#define BLYNK_TEMPLATE_ID "TMPL3qpjOKJtE"
#define BLYNK_TEMPLATE_NAME "NodeMCU"
#define BLYNK_AUTH_TOKEN "BA_dEcV7iWeSzj1v9dzNH0I7Qv5JRWjB"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone";      // Your WiFi Name
char pass[] = "12346780";    // Your WiFi Password

// For value == 1, digitalWrite is LOW (relay ON)
// For value == 0, digitalWrite is HIGH (relay OFF)

BLYNK_WRITE(V1) {
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D5, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D5, HIGH);  
     Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  Serial.println(value);
  digitalWrite(D6, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Relay 2 ON" : "Relay 2 OFF");
}

BLYNK_WRITE(V3) {
  int value = param.asInt();
  Serial.println(value);
  digitalWrite(D7, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Relay 3 ON" : "Relay 3 OFF");
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  Serial.println(value);
  digitalWrite(D8, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Relay 4 ON" : "Relay 4 OFF");
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);

  // Set all relays OFF initially
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, HIGH);
}

void loop() {
  Blynk.run();
 


}
