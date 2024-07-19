/* library: RTClib by Adafruit */ 

#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  // Start the I2C communication on custom pins
  Wire.begin(15, 16); // SDA to pin 15 and SCL to pin 16
  
  Serial.begin(115200);
  
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    // The following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // To set the time manually, use:
    // rtc.adjust(DateTime(2024, 7, 19, 12, 0, 0));
  }
}

void loop() {
  DateTime now = rtc.now();
  
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  
  delay(1000);
}
