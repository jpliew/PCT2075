#ifndef PCT2075_H_
	#define PCT2075_H_
	
	#include <Arduino.h>
	#include <Wire.h>
	
	#define PCT2075_REG_TEMP		0x00
	#define PCT2075_REG_CONF		0x01
	#define PCT2075_REG_THYST		0x02
	#define PCT2075_REG_TOS			0x03
	#define PCT2075_REG_TIDLE		0x04
	
	#define PCT2075_BIT_ACTIVE_LOW	0x00
	#define PCT2075_BIT_ACTIVE_HIGH	0x04
	
	#define PCT2075_BIT_COMPARATOR	0x00
	#define PCT2075_BIT_INTERRUPT	0x02
	
	#define PCT2075_BIT_NORMAL		0x00
	#define PCT2075_BIT_SHUTDOWN	0x01
	
	#define PCT2075_BIT_FAULT_1X	0x00
	#define PCT2075_BIT_FAULT_2X	0x08
	#define PCT2075_BIT_FAULT_4X	0x10
	#define PCT2075_BIT_FAULT_6X	0x18	
	
	class PCT2075 {
		private: 
			uint8_t _i2c_address;

		public: 
			PCT2075(uint8_t address);
			void begin(uint8_t config=PCT2075_BIT_ACTIVE_LOW|PCT2075_BIT_COMPARATOR|PCT2075_BIT_NORMAL|PCT2075_BIT_FAULT_6X); 
			void setThyst(uint16_t threshold);
			void setTos(uint16_t threshold);
			void shutdown(void);
			void normal(void);
			void setTidle(uint8_t time);
			bool isShutdown(void);
			float getTempC(void);
			float getTempF(void);
			int16_t getTempRaw(void);
			uint16_t getThyst(void);
			uint16_t getTos(void);
			uint8_t getConfig(void);
	};
	
#endif