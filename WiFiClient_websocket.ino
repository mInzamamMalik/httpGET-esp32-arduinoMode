#include <HTTPClient.h>

#include <WiFi.h>



//SSID:  TP-Link_FD7A
//Protocol: 802.11n
//Security type:  WPA2-Personal
//Network band: 2.4 GHz
//Network channel:  6
//IPv4 address: 192.168.0.137
//IPv4 DNS servers: 42.201.255.26
//42.201.255.130
//Manufacturer: Intel Corporation
//Description:  Intel(R) Centrino(R) Advanced-N 6205
//Driver version: 15.16.0.2
//Physical address (MAC): 8C-70-5A-B6-9C-AC

char in;

void setup()
{
  Serial.begin(9600);
  Serial.println("\n... Starting ESP32 ...");

  WiFi.begin("TP-Link_FD7A", "32373561");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  Serial.println("connected");
}


void loop() {

  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    HTTPClient http;

    http.begin("http://jsonplaceholder.typicode.com/comments?id=10"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request

    if (httpCode > 0) { //Check for the returning code

      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end(); //Free the resources
  }

  delay(10000);

  delay(1000);
}

