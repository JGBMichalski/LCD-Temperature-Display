#include <LCD4Bit_mod.h> // LCD4Bit_mod by dpavlin
#include <OneWire.h> // OneWire v2.3.6 by Paul Stroffregen
#include <DallasTemperature.h> // DallasTemperature v3.9.0 by Miles Burton

#define INPUT_PIN 14 // Input pin on the Arduino

OneWire oneWire(INPUT_PIN); 
DallasTemperature tempSensor(&oneWire);
LCD4Bit_mod lcd = LCD4Bit_mod(2);

void setup(void){ 
  Serial.begin(9600);

  // Setup LCD 
  lcd.init();
  lcd.clear();
  lcd.printIn("Temperature:");

  // Setup Sensor
  tempSensor.begin(); 
}

void loop(void){ 
  // Get temperature from sensor
  tempSensor.requestTemperatures();

  // Convert temperature to readable value
  char result[8];
  dtostrf(sensors.getTempCByIndex(0), 6, 2, result);

  // Debug temperature
  Serial.print("Temperature is: %s\r\n", result); 

  // Update temperature on LCD
  lcd.cursorTo(2,0);
  lcd.printIn(result);

  // Delay for 1 second before next read
  delay(1000); 
} 
