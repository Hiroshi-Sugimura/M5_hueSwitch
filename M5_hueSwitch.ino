#include <M5Stack.h>
#include <WiFi.h>
#include "EL.h"

#define WIFI_SSID "your wifi ssid"
#define WIFI_PASS "your wifi pass"
#define HUE_IP    "hue bridge IP address"
#define HUE_USENAME "hue username e.g. AjE6JULce16fMDbVrjiGJrt8pYOL6SMCMDlqDFyb"

WiFiClient client;

// debug
void printNetData()
{
	Serial.println("-----------------------------------");

	// IP
	// print your WiFi shield's IP address:
	IPAddress ip = WiFi.localIP();
	Serial.print("IP  Address: ");
	Serial.println(ip);

	IPAddress dgwip = WiFi.gatewayIP();
	Serial.print("DGW Address: ");
	Serial.println(dgwip);

	IPAddress smip = WiFi.subnetMask();
	Serial.print("SM  Address: ");
	Serial.println(smip);

	Serial.println("-----------------------------------");
}

// 全部つける
void hueOn() {
	// 1
	if (client.connect(HUE_IP, 80)) {
		// Make a HTTP request:
		client.print("PUT /api/");
		client.print(HUE_USENAME);
		client.println("/lights/1/state HTTP/1.1");
		client.println("Host: M5Stack.local" );
		client.println("Connection: keep-alive");
		client.println("Content-Type: text/plain; charset=UTF-8");
		client.println("Content-Length: 11\r\n");
		client.print("{\"on\":true}");
	}
	// 2
	if (client.connect(HUE_IP, 80)) {
		// Make a HTTP request:
		client.print("PUT /api/");
		client.print(HUE_USENAME);
		client.println("/lights/2/state HTTP/1.1");
		client.println("Host: M5Stack.local" );
		client.println("Connection: keep-alive");
		client.println("Content-Type: text/plain; charset=UTF-8");
		client.println("Content-Length: 11\r\n");
		client.print("{\"on\":true}");
	}
	// 3
	if (client.connect(HUE_IP, 80)) {
		// Make a HTTP request:
		client.print("PUT /api/");
		client.print(HUE_USENAME);
		client.println("/lights/3/state HTTP/1.1");
		client.println("Host: M5Stack.local" );
		client.println("Connection: keep-alive");
		client.println("Content-Type: text/plain; charset=UTF-8");
		client.println("Content-Length: 11\r\n");
		client.print("{\"on\":true}");
	}
}

// 全部けす
void hueOff() {
	// 1
	if (client.connect(HUE_IP, 80)) {
		// Make a HTTP request:
		client.print("PUT /api/");
		client.print(HUE_USENAME);
		client.println("/lights/1/state HTTP/1.1");
		client.println("Host: M5Stack.local" );
		client.println("Connection: keep-alive");
		client.println("Content-Type: text/plain; charset=UTF-8");
		client.println("Content-Length: 12\r\n");
		client.print("{\"on\":false}");
	}
	// 2
	if (client.connect(HUE_IP, 80)) {
		// Make a HTTP request:
		client.print("PUT /api/");
		client.print(HUE_USENAME);
		client.println("/lights/2/state HTTP/1.1");
		client.println("Host: M5Stack.local" );
		client.println("Connection: keep-alive");
		client.println("Content-Type: text/plain; charset=UTF-8");
		client.println("Content-Length: 12\r\n");
		client.print("{\"on\":false}");
	}
	// 3
	if (client.connect(HUE_IP, 80)) {
		// Make a HTTP request:
		client.print("PUT /api/");
		client.print(HUE_USENAME);
		client.println("/lights/3/state HTTP/1.1");
		client.println("Host: M5Stack.local" );
		client.println("Connection: keep-alive");
		client.println("Content-Type: text/plain; charset=UTF-8");
		client.println("Content-Length: 12\r\n");
		client.print("{\"on\":false}");
	}
}

void setup() {
	// put your setup code here, to run once:
	Serial.begin(115200);
	Serial.println("");
	M5.begin();
	M5.Lcd.setTextSize(2);
	M5.Lcd.println("wifi connect start");

	WiFi.begin(WIFI_SSID, WIFI_PASS);
	while (WiFi.status() != WL_CONNECTED) {
		Serial.println("wait...");
		delay(1000);
	}
	M5.Lcd.println("wifi connect ok");
	M5.update();

	printNetData();

	M5.Lcd.fillScreen(BLACK);
	M5.Lcd.setTextColor(WHITE);
	M5.Lcd.setCursor(10, 10);
	M5.Lcd.setTextSize(2);
}

void loop() {
	M5.update();

	// BtnAを押したら全部つける
	if (M5.BtnA.wasPressed()) {
		hueOn();
		M5.Lcd.printf("A");
	}

	// BtnCを押したら全部けす
	if (M5.BtnC.wasPressed()) {
		hueOff();
		M5.Lcd.printf("C");
	}

	delay(100);
}

