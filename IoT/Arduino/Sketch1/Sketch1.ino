/*
 Name:		Sketch1.ino
 Created:	1/12/2017 09:22:36
 Author:	Kennedy
*/

/* the project below is basically to design a domestic power autochanger between kplc and solar panel battery.
*  1.first it checks whether power from kplc is on or off. if power is ON the kplc output relay goes high to supply the load.
if power is off, the current (selected) battery goes high.
2. it checks whether it is within a certain range to avoid surges.
3. once the battery is full and it was perviously empty it switches from kplc relay to current (selected) battery.
4. once the battery is fully discharged and it was perviously empty it switches from current (selected) battery to kplc output while charging relay pin 6 and 7 goes high respectively .
5. i am using a time function to calculate units spent in thougth kplc terminal and units saved through solar battery terminal
2.please help me create a varible that resets back to zero once 30 or 31 days have elaspe. so that i can use it to calculate KWH spent(unit metered by kplc) and KWH saved( units consumed while usin solar battery).
and also debug. (almost at the end
)*/



#include <LiquidCrystal.h>
#include <RTClib.h>
#include <Wire.h>

RTC_DS1307 rtc;

char buf1[20];


int kplc = A2; // ac voltage is step down, rectified and connected to analog pin 7
int KPLC = 13;//  pin 13 is conected to relay of kplc
int button1 = 8; // button to select one battery
int button2 = 9; //button to select two battery
int solarbattery = A3; // pin A3 is connected to the battery to measure battery votage
int solarbatteryB = 14;
int SOLARBATTERY = 12;//Relay of the solar batery is connected pin 12
int batteryStatus;
int solarChargerA = 6; //relay for charging the first battery.
int solarChargerB = 7; //relay for charging the second battery
int kplCurrent = A0;//pin A0 is connect to the current sensor 
int solarCurrent = A1;
int SOLARBATTERYb = A4;// pin A4 is connected to the second solar battery to measure it's voltage.
int SolarPanel = A5;// pin A5 is conncected to check whether the solar panel is active.
int _DATE_;
int _TIME_;
boolean LastStatus = LOW;
boolean LastStatusB = LOW;
int transformeRatio = 50; //this is the transformer ratio of the step down transformer. 
int analogVal;

int kplcValue;
int val = 0;  // variable to store the value read
LiquidCrystal lcd(10, 11, 5, 4, 3, 2);
char CurrentBattery;
int OnKplcMinutes;
int OnSolarMinutes;
float kplcPower;
float totalCurrentUnitsUsed;
float totalUnitSaved;
float unitSaved;
float solarPower;
float totalkplcEnegyConsumed;
float kplcEnegyConsumed;




void setup()

{

	Serial.begin(9600);  //  setup serial
	pinMode(kplc, INPUT);
	pinMode(solarbattery, INPUT);
	pinMode(button1, INPUT);
	pinMode(button2, INPUT);
	pinMode(kplCurrent, INPUT);
	pinMode(KPLC, OUTPUT);
	pinMode(SOLARBATTERY, OUTPUT);
	pinMode(solarbatteryB, OUTPUT);
	pinMode(SOLARBATTERYb, INPUT);
	pinMode(solarChargerA, INPUT);
	pinMode(solarChargerB, INPUT);
	lcd.begin(16, 2);
	lcd.clear();
	Wire.begin();
	rtc.begin();
	rtc.adjust(DateTime(F(_DATE_), F(_TIME_)));



}

void loop()
{
	{ DateTime now = rtc.now();

	Serial.print(F("Date/Time: "));
	Serial.println(buf1);
	delay(1000);
	}

	val = analogRead(kplc);    // read the input pin

	Serial.println(val);             // debug value


									 // code to check whether kplc is on or off
									 // if kplc( utility company) is on, relay connected to it switches in and power from utility company is used.

	if (digitalRead(kplc) == HIGH) {
		digitalWrite(KPLC, HIGH);
		digitalWrite(CurrentBattery, LOW);
		lcd.print("kplc is on... ");
		lcd.blink();

		delay(3000);

	}
	// if kplc is off relay connected to solar battery switches on thus power is supplied from the battery. 
	else {
		digitalWrite(CurrentBattery, HIGH);
		digitalWrite(KPLC, LOW);
		lcd.clear();
		lcd.print("kplc is off... ");
		lcd.blink();

		delay(3000);

	}


	//
	// the loop routine runs over and over again forever:
	// read the input on analog pin 0:
	{int kplcVoltage = analogRead(kplc);
	// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
	float voltage = kplcVoltage * (5.0 / 1023.0);
	kplcValue = voltage * transformeRatio *(1023.0 / 5.0);
	// print out the value you read:
	Serial.println(kplcValue);

	}
	if (237< kplcValue<243) //to prevent surges the voltage must be between the given range
	{
		digitalWrite(KPLC, HIGH);

		digitalWrite(CurrentBattery, LOW);
		lcd.clear();
		lcd.print("kplc is healthy");

		delay(2000);

		lcd.clear();
		lcd.print(kplcValue);

		delay(3000);


	}
	else {

		digitalWrite(CurrentBattery, HIGH);
		digitalWrite(KPLC, LOW);
		lcd.clear();
		lcd.print("kplc is not healthy");

		delay(2000);


	}







	analogVal = analogRead(solarbattery);
	const int voltageMin = 9;
	const int voltageMax = 13.0;
	batteryStatus = map(analogVal, voltageMin, voltageMax, 20, 100);

	{
		if (analogVal<10) {
			digitalWrite(KPLC, HIGH);
			digitalWrite(CurrentBattery, LOW);
		}
		else {
			digitalWrite(CurrentBattery, HIGH);
			digitalWrite(KPLC, LOW);
		}




		// DISCHARGING MODE OF THE BATTERY.

		{
			{
				if (analogVal > 13.0 && LastStatus == LOW || LastStatusB == LOW) {//to discharging the battery we check whether it was previously fully discharged and now it is fully charged. 

					CurrentBattery = !CurrentBattery;
					LastStatus = HIGH;
					LastStatusB = HIGH;
				}
				else {
					LastStatus = digitalRead(CurrentBattery);
				}
				digitalWrite(CurrentBattery, HIGH);
			}
			// we used button 1 for situation where there is only one battery and button 2 for situation where there is 2 two batteries for longer discharging hours.
			switch (button1) {
			case ('100< batteryStatus <=50'):
				CurrentBattery = SOLARBATTERY;
				digitalWrite(CurrentBattery, HIGH);
				break;
			case (' 50< batteryStatus >=25'):
				CurrentBattery = SOLARBATTERY;

				if ('100< batteryStatus <=50' && digitalRead(kplc) == HIGH) {
					digitalWrite(CurrentBattery, LOW);
					digitalWrite(KPLC, HIGH);
				}
				else {
					if (solarCurrent<5) {
						digitalWrite(CurrentBattery, HIGH);
						digitalWrite(KPLC, LOW);
						delay(9000);
					}
				}

				break;
			case ('batteryStatus < 24'):
				digitalWrite(KPLC, HIGH);
				break;
			default:
				digitalWrite(KPLC, HIGH);
				lcd.print(" put in the correct battery port ");
			}



			switch (button2) { // we used button 1 for situation where there is only one battery and button 2 for situation where there is 2 two batteries for longer discharging hours.
			case ('100< batteryStatus <=50'):
				CurrentBattery = SOLARBATTERY;
				digitalWrite(CurrentBattery, HIGH);
				break;
			case (' 50< batteryStatus <=25'):
				CurrentBattery = solarbatteryB;

				if (solarCurrent<5) {
					digitalWrite(CurrentBattery, HIGH);
				}
				else {
					digitalWrite(CurrentBattery, LOW);
					delay(9000);
				}
				break;
			case 3://( batteryStatus<25):    
				digitalWrite(SOLARBATTERY, HIGH);
				break;
			default:
				digitalWrite(KPLC, HIGH);
				lcd.print(" put in the correct battery port ");
			}

		}



		// CHARGING MODE IF THE BATTERIES
		{
			BatteryStutusB = analogRead(SOLARBATTERYb);
			const int voltageMin = 9.5;
			const int voltageMax = 13.0;
			BatteryStutusB = map(analogVal, empy, full, 25, 100);




			if (LastStatusB = HIGH || LastStatus = LOW && BatteryStutusB == empy || batteryStatus == voltageMin) {

				CurrentBattery = !CurrentBattery;
				LastStatus = LOW;
				LastStatusB = LOW;


				//for the code below use boolean to charge the battery


				switch (digitalRead(SolarPanel) == HIGH && button2) {
				case ('90<BatteryStutusB<25'):
					digitalWrite(solarCharger, HIGH);
					digitalWrite(solarChargerB, LOW);
					break;

				case('BatteryStutusB>90 && 90< batteryStatus <24'):
					digitalWrite(solarChargerA, HIGH);
					digitalWrite(solarChargeB, LOW);
					break;

				case('BatteryStutusB>90 && batteryStatus>90 '):
					digitalWrite(solarChargerA, LOW);
					digitalWrite(solarChargeB, LOW);
					break;
				}

			}

			/*please help me create a varible that resets back to zero once 30 or 31 days have elaspe. so that i can use it to calculate KWH spent(unit metered by kplc) and KWH saved( units consumed while usin solar battery).
			and also debug*/

			while (now.day()>1, now.day() <= 31) {
				if (CurrentBattery == HIGH) {

					int current_second = 0;
					current_second = current_second + now.second();
				}

				if (KPLC == HIGH) {

					int Kplc_current_second = 0;
					Kplc_current_second = Kplc_current_second + now.second();
				}
				kplcPower = kplcValue*kplCurrent;
				kplcEnegyConsumed = kplcPower*Kplc_current_second / 3600000;
				totalkplcEnegyConsumed = totalkplcEnegyConsumed + kplcEnegyConsumed;

				solarPower = analogVal*solarCurrent;
				unitSaved = solarPower*current_second / 3600000;
				totalUnitSaved = totalUnitSaved + unitSaved;
				totalCurrentUnitsUsed = totalUnitSaved + totalkplcEnegyConsumed;

				lcd.clear();
				lcd.print("kplcvoltage ");
				lcd.print(kplcValue);

				delay(3000);

				lcd.clear();
				lcd.print("current ");
				lcd.print(kplCurrent);

				delay(3000);


				lcd.clear();
				lcd.print(" energy");
				lcd.print(totalkplcEnegyConsumed);

				delay(3000);


				lcd.clear();
				lcd.print("S voltage ");
				lcd.print(analogVal);

				delay(3000);

				lcd.clear();
				lcd.print("S current ");
				lcd.print(solarCurrent);

				delay(3000);


				lcd.clear();
				lcd.print(" S energy");
				lcd.print(totalUnitSaved);

				delay(3000);


				lcd.clear();
				lcd.print("total units ");
				lcd.print(totalCurrentUnitsUsed);

				delay(3000);
			}
		}



