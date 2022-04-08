#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */

#define BLYNK_TEMPLATE_ID "TMPLPT3cTHDx"
#define BLYNK_DEVICE_NAME "Lights"
#define BLYNK_AUTH_TOKEN "8ClqPylXAfjEPAUBWpZu0Eb3pIB8bfMU"

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Robert_iPhone";
char pass[] = "0926656000";
char auth[] = BLYNK_AUTH_TOKEN;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
