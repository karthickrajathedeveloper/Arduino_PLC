#include <WiFi.h>
#include <ArduinoHttpClient.h>

/* -------- WiFi -------- */
const char* ssid     = "*******";
const char* password = "*****";

/* -------- Blynk -------- */
const char* server = "blr1.blynk.cloud";
const char* token  = "Snjuvrxe58fBDZrxN4-qmHVJANfw1NJj";
int port = 443;   

#define BUTTON_PIN I1

WiFiSSLClient sslClient;   
HttpClient client(sslClient, server, port);

int lastButtonState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
}

void loop() {
  int button_state = digitalRead(BUTTON_PIN);

  if (button_state != lastButtonState) {
    sendToBlynk(button_state);
    lastButtonState = button_state;
    delay(300);
  }
}

void sendToBlynk(int state) {
  String url = "/external/api/update?token=" + String(token) + "&V1=" + String(state);

  Serial.print("API Call: ");
  Serial.println(url);

  client.get(url);

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
}
