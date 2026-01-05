#include <WiFi.h>
#include <ArduinoHttpClient.h>

const char* ssid = "*****";
const char* password = "****";

const char* serverIP = "192.168.1.12"; // Flask PC IP
int port = 8080;

WiFiClient wifi;
HttpClient client(wifi, serverIP, port);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  sendAPICall();   
}

void loop() {}

void sendAPICall() {
  Serial.println("Sending API call...");

  client.beginRequest();
  client.post("/plc/button");
  client.sendHeader("Content-Type", "application/json");

  String body = "{\"button\":\"JEEVA\"}";
  client.sendHeader("Content-Length", body.length());

  client.beginBody();
  client.print(body);
  client.endRequest();

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status Code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
}
