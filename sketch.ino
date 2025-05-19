#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "mottu/patio";

WiFiClient espClient;
PubSubClient client(espClient);

const int trigPin = 5;
const int echoPin = 18;
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      if (client.connect("ESP32Client")) {
        Serial.println("Connected to MQTT Broker!");
      } else {
        delay(5000);
      }
    }
  }
  client.loop();

  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  String status;
  if (distance < 20) {
    digitalWrite(ledPin, HIGH);
    status = "{\"vagaA\":\"ocupada\"}";
  } else {
    digitalWrite(ledPin, LOW);
    status = "{\"vagaA\":\"livre\"}";
  }

  client.publish(mqttTopic, status.c_str());
  Serial.println(status);
  delay(2000);
}
