#include "PCT2075.h"

PCT2075::PCT2075(uint8_t address) { 
	_i2c_address = address;
}

void PCT2075::begin(uint8_t config) {
	Wire.begin(); 
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_CONF);
	Wire.write(config);
	Wire.endTransmission();
}

uint8_t PCT2075::getConfig(void) {
	uint8_t x;
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_CONF); 
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)1); 
	x = Wire.read(); 
	return x; 
}

int16_t PCT2075::getTempRaw(void) {
	int16_t temp; 
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_TEMP);
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)2); 
	temp = Wire.read();
	temp<<=8;
	temp |= Wire.read();
	temp>>=5;
	return temp; 
}

float PCT2075::getTempC(void) {
	return getTempRaw() * 0.125;
}

float PCT2075::getTempF(void) {
	return getTempRaw() * 0.125 * 1.8 + 32;
}

void PCT2075::setThyst(uint16_t threshold) {
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_THYST); 
	Wire.write(threshold);
	threshold>>=8;
	Wire.write(threshold); 
	Wire.endTransmission(); 
}

void PCT2075::setTos(uint16_t threshold) {
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_TOS); 
	Wire.write(threshold); 
	threshold>>=8;
	Wire.write(threshold); 
	Wire.endTransmission();
}

uint16_t PCT2075::getThyst(void) {
	uint16_t x; uint16_t y; 
	Wire.beginTransmission(_i2c_address);
	Wire.write(PCT2075_REG_THYST); 
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)2); 
	x = Wire.read(); 
	y = Wire.read(); 
	x <<= 8; 
	x |= y;
	x >>= 8; 
	return x; 
}

uint16_t PCT2075::getTos(void) {
	uint16_t x; uint16_t y; 
	Wire.beginTransmission(_i2c_address);
	Wire.write(PCT2075_REG_TOS); 
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)2); 
	x = Wire.read(); 
	y = Wire.read(); 
	x <<= 8; 
	x |= y;
	x >>= 8; 
	return x;
}

void PCT2075::shutdown(void) {
	uint8_t data; 
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_CONF); 
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)1);
	data = Wire.read(); 
	data |= 0x01; 
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_CONF);
	Wire.write(data); 
	Wire.endTransmission(); 
}

void PCT2075::normal(void) {
	uint8_t data; 
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_CONF); 
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)1);
	data = Wire.read(); 
	data &= 0x1E; 
	Wire.beginTransmission(_i2c_address);
	Wire.write(PCT2075_REG_CONF); 
	Wire.write(data); 
	Wire.endTransmission(); 
}

bool PCT2075::isShutdown(void) {
	uint8_t state; 
	
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_CONF); 
	Wire.endTransmission(); 
	Wire.requestFrom(_i2c_address, (uint8_t)1);
	state = Wire.read(); 
	state &= 0x01;  
	return state; 
}

void PCT2075::setTidle(uint8_t time) {
	time = (time & 0x1F);
	Wire.beginTransmission(_i2c_address); 
	Wire.write(PCT2075_REG_TIDLE); 
	Wire.write(time);
	Wire.endTransmission();
}