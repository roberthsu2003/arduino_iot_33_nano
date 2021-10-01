#include <SPI.h>
#include <WiFiNINA.h>
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

int status = WL_IDLE_STATUS;
char server[] = "maker.ifttt.com";
WiFiSSLClient client;


void setup()
{
  Serial.begin(9600);
  delay(100);
  Serial.println();

  Serial.print("Connecting to Wi-Fi");
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED)
  {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();



  //連線ifttt
  //一開始就連線的測試
    if (client.connect(server, 443)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET /trigger/over30/with/key/eDqcZfqY_i_BHCZVXCwb6aq7GLPKpdV4q1ePja35Mjq?value1=35&value2=55 HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("Connection: close");
    client.println();
    }
  
}

void loop(){
  
}
