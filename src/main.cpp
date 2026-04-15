#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>


const char* WIFI_SSID = "SALA 09";
const char* WIFI_SENHA = "info@134";

void conectarWiFi();
void garantirWiFiConectado();


void setup() 
{
  Serial.begin(9600);
  Serial.println(" ");
  conectarWiFi();
}

void loop() 
{
  garantirWiFiConectado();
}

void conectarWiFi()
{
  Serial.println("============================");
  Serial.println("Iniciando conexão WiFI...");
  Serial.println("============================");

  // Configura o ESP32 como station, ou seja
  // ele vai se conectar a um roteador existente.
  WiFi.mode(WIFI_STA); 

  // Inicia a conexão com SSID e senha.
  WiFi.begin(WIFI_SSID, WIFI_SENHA);

  Serial.println("conectando");

  int tentativasWiFi = 0;
  const int maxTentativasWiFi = 30;

  // Aguarda a conexão por até 30 tentativas.
  while (WiFi.status() != WL_CONNECTED && tentativasWiFi < maxTentativasWiFi)
  {
    delay(500);
    Serial.print(".");
    tentativasWiFi++;
  }

  Serial.println();

  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("WiFi conectado com sucesso!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
  }

  else
  {
    Serial.println("Falha ao conectar no WiFi.");
    Serial.println("Verifique SSID ,senha e sinal de rede.");
  }
  
}

void garantirWiFiConectado()
{
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFI desconectado. Tentando reconectar...");
    conectarWiFi();
  }

  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Não foi possivel reconectar ao WIFi.");
  }
}