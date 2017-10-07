// Henry's Bench
// PCF8591 Simple Voltage Measurement
#include <Wire.h>

#define PCF8591 (0x90 >> 1) // I2C bus address
#define AIn0 0x00
#define AIn1 0x01

int RawValue0 = 0;
int RawValue1 = 0;
float Voltage0 = 0.0;
float Voltage1 = 0.0;
void setup()
{
 Wire.begin();
 Serial.begin(9600);
}
void loop()
{
//Input #00
 Wire.beginTransmission(PCF8591); // Start your PCF8591
 Wire.write(AIn0); // Tell it to make an Analog Measurement
 Wire.endTransmission(); //  
 Wire.requestFrom(PCF8591, 1); // Get the Measured Data
 RawValue0=Wire.read();
 Voltage0 = (RawValue0 * 5.0 )/ 256.0;
 //Input #01
 Wire.beginTransmission(PCF8591); // Start your PCF8591
 Wire.write(AIn1); // Tell it to make an Analog Measurement
 Wire.endTransmission(); //  
 Wire.requestFrom(PCF8591, 1); // Get the Measured Data
 RawValue1=Wire.read();
 Voltage1 = (RawValue1 * 5.0 )/ 256.0;
 
 Serial.print("Raw ADC Value = ");
 Serial.print(RawValue0);
 Serial.print(" | ");
 Serial.println(RawValue1);
 Serial.print("Voltage = ");
 Serial.print(Voltage0,3);
 Serial.print(" | ");
 Serial.println(Voltage1,3);
 delay(500); 
 
}
