# PCT2075 Digital Temperature Sensor Library for Arduino

The PCT2075 is a temperature-to-digital converter featuring ±1°C accuracy over -25°C to +100°C range. It uses an on-chip band gap temperature sensor and Sigma-Delta A-to-D conversion technique with an overtemperature detection output that is a drop-in replacement for other LM75 series thermal sensors.

## Installation 

Create a folder named PCT2075 in Arduino's libraries folder.  You will have the following folder structure:

	cd arduino/libraries
	git clone https://github.com/jpliew/PCT2075.git PCT2075

## Arduino Sketch

Execute Arduino IDE, select Example-->PCT2075-->PCT2075Test

### Example
<pre><code>
#include &lt;PCT2075.h&gt;

PCT2075 temp = PCT2075(0x37);

void setup() {
	Serial.begin(115200);
	Wire.begin();
	temp.begin();
}

void loop() {
	float tempC = temp.getTempC();
	Serial.print("Temp = ");
	Serial.print(tempC);
	Serial.println(" C");
}
</code></pre>


Written by [JP Liew](http://jpliew.com)

*This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.*

*This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.*