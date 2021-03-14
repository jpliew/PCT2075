#include "PCT2075.h"

PCT2075 temp = PCT2075(0x37);

void setup() {
	Serial.begin(115200);
	Wire.begin();
	temp.begin();
}

void loop() {
	if (temp.isShutdown() == 0) {
		float tempC = temp.getTempC();
		Serial.print("Temp = ");
		Serial.print(tempC);
		Serial.print(" C");
		Serial.print("\t");
		Serial.print("Thyst = ");
		Serial.print(temp.getThyst()); 
		Serial.print("C");
		Serial.print("\t");
		Serial.print("Tos = ");
		Serial.print(temp.getTos()); 
		Serial.print("C");
		Serial.print("\t");
		Serial.print("Config: ");
		Serial.print("0b");
		Serial.print(temp.getConfig(), BIN);
		Serial.print("\t");
		Serial.print("isShutdown = ");
		Serial.println(temp.isShutdown()); 
	}
	else {
		Serial.println("Temperature sensor is shutdown! Turning it on..."); 
		temp.normal(); 
	}
}