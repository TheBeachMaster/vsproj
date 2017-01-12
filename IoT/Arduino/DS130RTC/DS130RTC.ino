/*
 Name:		DS130RTC.ino
 Created:	1/12/2017 10:42:46
 Author:	Kennedy
*/

#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

const int button = 2;
const int led = 8;

int buttonState = 0;
time_t timeStart;
time_t timeEnd;

void setup() {
	Serial.begin(9600);

	pinMode(button, INPUT);
	pinMode(led, OUTPUT);

	while (!Serial); // wait until Arduino Serial Monitor opens
	setSyncProvider(RTC.get);   // the function to get the time from the RTC
	if (timeStatus() != timeSet)
		Serial.println("Unable to sync with the RTC");
	else
		Serial.println("RTC has set the system time");
	Serial.println();
	Serial.print("timeStart");
	Serial.print("\t");
	Serial.print("timeEnd");
	Serial.print("\t");
	Serial.print("\t");
	Serial.print("timeEnd-timeStart");
	Serial.println();
}

void loop() {

	buttonState = digitalRead(button);

	timeStart = (hour() * 60 * 60) + (minute() * 60) + second();

	Serial.print(timeStart);
	Serial.print("\t");

	if (buttonState == HIGH) {
		timeEnd = ((hour() * 60 * 60) + (minute() * 60) + second()) + 5;
	}

	Serial.print(timeEnd);
	Serial.print("\t");
	Serial.print("\t");
	Serial.print(timeEnd - timeStart);

	if ((timeEnd - timeStart) >= 5) {
		digitalWrite(led, LOW);
	}
	else {
		digitalWrite(led, HIGH);
	}

	Serial.println();
	delay(1000);
}