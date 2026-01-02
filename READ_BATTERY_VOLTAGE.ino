////////////////////////////////////////////////
//This code was inspired by:
//https://github.com/Yveaux/Arduino_Vcc
//I made a few modifications to read out the volatage of batteries attached to the arduino.
//The positive terminal of the battery should be connected to Analog pin A0 through a voltage divider(both R1 & R2 are 10k ohms each)
//NOTE: 1. Always make sure both R1 & R2 resistors have the same ohm values(even if you use resistor values of your choice)
//      2. Add the Vcc.h and Vcc.cpp files to your Arduino libraries folder before uploading
//visit https://www.youtube.com/delali to learn more about electronics and building smart things from scratch
////////////////////////////////////////////////


//BATTERY IS CONNECTED TO A0
#define batt_pin A0

#include "Vcc.h"

//MORE DECIMAL PLACES LEAD TO MUCH ACCURATE BATTERY READING(thus for VccMax and VccCorrection)
const float VccMin = 0.0;       // Minimum expected Vcc level, in Volts.
const float VccMax = 5;         // Maximum expected Vcc level, in Volts(Use a multimeter to measure the maximum output voltage of your regulator. Thus when you connect a fully charged battery to it).
const float VccCorrection = 0.964;  //0.98544;  // Tweak this value until the output of "v" on line 38 is the same as what you measured with your multimeter above for VccMax

//const float lowBat = 0;     //Indicate the value your battery manufacturer states as absolutely dead battery
//const float fullBat = 3.3;  //Indicate the value your fully charged battery will be at

float v = 0;
float batt_volt = 0;
Vcc vcc(VccCorrection);

void setup() {
  Serial.begin(115200);
}

void loop() {
  //READ CURRENT REGULATOR OUTPUT VOLTAGE(VCC)
  v = vcc.Read_Volts();
  delay(5);

  //Serial.print("VCC: ");
  //Serial.print(v, 3);

  //USING THE CURRENT VCC VOLTAGE AS REFFERENCE TO CALCULATE BATTERY VOLTAGE
  batt_volt = ((analogRead(batt_pin) * (v / 1023.0)));

 // Serial.print("V Battery: ");
  Serial.print(batt_volt, 2);
 // Serial.print("V ");
  //CONVERTING BATTERY VOLTAGE TO PERCENTAGE ASSUMING 4.19V AS THE FULL CHARGE VALUE
 // Serial.print(((batt_volt - lowBat) / (fullBat - lowBat)) * 100);
  //Serial.print("%");
  //Serial.println("");
  delay(5000);
  
}
