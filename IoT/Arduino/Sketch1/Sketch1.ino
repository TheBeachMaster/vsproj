/*
 Name:		Sketch1.ino
 Created:	1/12/2017 09:22:36
 Author:	Kennedy
*/
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
int empty;
int full;
int kplcValue;
int val = 0;  // variable to store the value read
LiquidCrystal lcd(10, 11, 5, 4, 3, 2);
char CurrentBattery;
int KplcCurrentSecond;
int currentSecond;
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
	rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));



}

void loop()
{
	DateTime now = rtc.now();
	{
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
			switch (button1) { //button array
			case 1:
				100< batteryStatus <= 50;
				CurrentBattery = SOLARBATTERY;
				digitalWrite(CurrentBattery, HIGH);
				break;
			case 2:
				50< batteryStatus >= 25;
				CurrentBattery = SOLARBATTERY;

				if (kplc = HIGH) {
					100< batteryStatus <= 50;

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
			case 3:
				batteryStatus < 24;
				digitalWrite(KPLC, HIGH);
				break;
			default:
				digitalWrite(KPLC, HIGH);
				lcd.print(" put in the correct battery port ");
			}



			switch (button2) { // we used button 1 for situation where there is only one battery and button 2 for situation where there is 2 two batteries for longer discharging hours.
			case 1:
				100< batteryStatus <= 50;
				CurrentBattery = SOLARBATTERY;
				digitalWrite(CurrentBattery, HIGH);
				break;
			case 2:
				50< batteryStatus <= 25;
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
			int BatteryStatusB = analogRead(SOLARBATTERYb);
			const int voltageMin = 9.5;
			const int voltageMax = 13.0;
			BatteryStatusB = map(analogVal, empty, full, 25, 100);




			if (LastStatusB = HIGH && BatteryStatusB == 25) {
				if (LastStatus = LOW && batteryStatus == 20) {


					CurrentBattery = !CurrentBattery;
					LastStatus = LOW;
					LastStatusB = LOW;


					//for the code below use boolean to charge the battery


					switch (button2) {

						digitalRead(SolarPanel) == HIGH;
					case 1:
						90<BatteryStatusB<25;
						digitalWrite(solarChargerA, LOW);
						digitalWrite(solarChargerB, HIGH);
						break;

					case 2:
						BatteryStatusB>90 && 90< batteryStatus <24;
						digitalWrite(solarChargerA, HIGH);
						digitalWrite(solarChargerB, LOW);

						break;

					case 3:
						BatteryStatusB>90 && batteryStatus>90;
						digitalWrite(solarChargerA, LOW);

						break;
					}
				}

			}

			/*please help me create a varible that resets back to zero once 30 or 31 days have elaspe. so that i can use it to calculate KWH spent(unit metered by kplc) and KWH saved( units consumed while usin solar battery).
			and also debug*/

			{
				if (CurrentBattery == HIGH) {

					int currentSecond = 0;
					currentSecond = currentSecond + now.second();
				}

				if (KPLC == HIGH) {

					int Kplc_current_second = 0;
					KplcCurrentSecond = KplcCurrentSecond + now.second();
				}
				kplcPower = kplcValue*kplCurrent;
				kplcEnegyConsumed = kplcPower*KplcCurrentSecond / 3600000;
				totalkplcEnegyConsumed = totalkplcEnegyConsumed + kplcEnegyConsumed;

				solarPower = analogVal*solarCurrent;
				unitSaved = solarPower*currentSecond / 3600000;
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

				delay(3000); }
		}
	}


	
}


/*
The Simplest Way to check battery Status and display or do something...

1:Suppose I have 3 LEDs: LED1,LED2 and LED3,
1.1: I can decalre their pinValues
2: Declare where my Battery is
2.1: Continously AnalogRead the battery.
2.2: Attach an interrupt to monitor changes in the Battery Status
2.2.1: example  (modify this as needed)
										....
										other declarations eg batPin for batteryPin
										....
										volatile int  batteryStatus = analogRead(batPin);

										void setup(){
										...
										other stuff in the setup like pinMode declarations
										...
										attachInterrupt(0,bat_ISR,CHANGE);

										...The above code will help us monitor an Interrupt Request Service for any changes in the bat level
										other codes
										...
										}
										void loop(){

										...some other stuff

										}

										void bat_ISR(){
										...
										..code to check battery 
										...if 50% , do something
										...if 25% ,another thing
										...if <25% ,do something else
										}

				OR...

3.0 Simpler Code but not efficient....
	analogRead battery value...
	assign value to another variable
	map this variable:
						like so ...
					 	volatile int batVar = map(batteryStatus,0,12,0,100);

						...we're talking the value of the analog read
						switch(batVar){
									case >= 50 :
									...do something if battery status is greater than 50%
									break;
									case >=25 :
									..do stuff
									break;
									case <24 :
									...do more stuff
									break;
						}

4.0 : Reading time and Showing it...Ensure RTC is running...Set manually if not...
	: Break this code and see how you will fit it...

	have this in the setup() ...

	remember to use a suitable baud rate...
	   
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

	   then...in your loop() ... have this...
	   DateTime now = rtc.now();


	   Serial.print(" In 3 hours time... ");
	   Serial.print(now.year(), DEC);
	   Serial.print('/');
	   Serial.print(now.month(), DEC);
	   Serial.print('/');
	   Serial.print(now.day(), DEC);
	   Serial.print(' ');
	   Serial.print(now.hour(), DEC);
	   Serial.print(':');
	   Serial.print(now.minute(), DEC);
	   Serial.print(':');
	   Serial.print(now.second(), DEC);
	   Serial.println();

	   Serial.println();
	   delay(3000);


              
*/

