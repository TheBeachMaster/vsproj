/*
 Name:		RTCTime.ino
 Created:	1/12/2017 10:01:20
 Author:	Kennedy
*/

#include <RTClib.h>
#include <Wire.h>

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
#define Serial SerialUSB
#endif

RTC_DS1307 rtc;

// the setup function runs once when you press reset or power the board

void setup() {
	//Init Serial
	Serial.begin(57600);
	if (!rtc.begin()) {
		Serial.println("Couldn't find RTC");
		while (1);
	}

	//If RTC is Running ...Adjust the date to Now
	if (!rtc.isrunning()) {
		Serial.println("RTC is NOT running!");
		// following line sets the RTC to the date & time this sketch was compiled
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
		//use  rtc.adjust(DateTime(2017, 1, 12, 11, 0, 0)); to set the clock manually
	}
}


void loop() {
	//Instantiate RTC
	DateTime now = rtc.now();

	//Get the Date  in 3 hours 45 mins and 13 seconds from Now...
	DateTime future(now + TimeSpan(0, 3, 45, 13));
  
	Serial.print(" In 3 hours time... ");
	Serial.print(future.year(), DEC);
	Serial.print('/');
	Serial.print(future.month(), DEC);
	Serial.print('/');
	Serial.print(future.day(), DEC);
	Serial.print(' ');
	Serial.print(future.hour(), DEC);
	Serial.print(':');
	Serial.print(future.minute(), DEC);
	Serial.print(':');
	Serial.print(future.second(), DEC);
	Serial.println();

	Serial.println();
	delay(3000);
}
