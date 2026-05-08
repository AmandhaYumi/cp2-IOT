#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "58d56f41a21e404084a39947b30d44ab.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;

const char* mqtt_user = "Dobuu";
const char* mqtt_password = "Dobu1112*";

#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define TRIG 33
#define ECHO 15

WiFiClientSecure espClient; 
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println("Conectando ao WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");

    if (client.connect("ESP32_Estufa", mqtt_user, mqtt_password)) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Erro MQTT, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);

  float distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  dht.begin();

  setup_wifi();
  espClient.setInsecure();

  client.setServer(mqtt_server, mqtt_port);
  client.setBufferSize(512);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  float distancia = getDistance();

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler DHT!");
    delay(2000);
    return;
  }

  Serial.println("------ ESTUFA ------");
  Serial.print("Temp: ");
  Serial.println(temperatura);

  Serial.print("Umidade: ");
  Serial.println(umidade);

  Serial.print("Nivel (dist): ");
  Serial.println(distancia);

  client.publish("estufa/temperatura", String(temperatura).c_str());
  client.publish("estufa/umidade", String(umidade).c_str());
  client.publish("estufa/nivel_agua", String(distancia).c_str());

  for (int i = 0; i < 50; i++) {
    client.loop();
    delay(100);
  }
}