#include <WiFi.h>

const char* ssid = "Embedded";
const char* password = "0987654321";

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  int retry = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    retry++;
    if (retry > 30) {
      Serial.println("\nWiFi FAILED");
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi CONNECTED");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }
}

void loop() {}
