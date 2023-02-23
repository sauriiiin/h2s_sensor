#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int h2sSensor = 0; //define sensor analog pin
float sensorValue = 0; //variable to store sensor value

void setup()
{
  Serial.begin(9600); // sets the serial port to 9600
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Gas sensor warming up!");
  display.display();
  delay(20000); // allow the MQ-6 to warm up
}

void loop()
{
  sensorValue = analogRead(h2sSensor); // read analog input pin 0
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("Sensor Value: ");
  display.println(sensorValue);
  display.display();
  delay(1000); // wait 1s for next reading
}