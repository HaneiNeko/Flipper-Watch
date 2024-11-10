#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int y = 5;

#define buttonUpPin 12
#define buttonSelectPin 11
#define buttonDownPin 10
#define buttonBackPin 9

void setup() {
  pinMode(buttonUpPin, INPUT_PULLUP);
  pinMode(buttonSelectPin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonBackPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  delay(100);

  menu();
}

void loop() {
  if (digitalRead(buttonDownPin) == LOW) {
    display.clearDisplay();
    y = y + 15;

    if (y > 50) {
      y = 5;
    }

    menu();
  }

  if (digitalRead(buttonUpPin) == LOW) {
    display.clearDisplay();
    y = y - 15;

    if (y < 5) {
      y = 50;
    }

    menu();
  }

  if ((digitalRead(buttonSelectPin) == LOW) && (y == 5)) {
    display.clearDisplay();
    time();
  }

  if ((digitalRead(buttonSelectPin) == LOW) && (y == 20)) {
    display.clearDisplay();
    rfid();
  }

  if ((digitalRead(buttonSelectPin) == LOW) && (y == 35)) {
    display.clearDisplay();
    signal_mhz();
  }

  if ((digitalRead(buttonSelectPin) == LOW) && (y == 50)) {
    display.clearDisplay();
    bad_usb();
  }

  if (digitalRead(buttonBackPin) == LOW) {
    menu();
  }

  delay(50);

  display.display();
}

void menu() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 5);
  display.println("Time");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.println("RFID / NFC");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 35);
  display.println("433 mHz");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 50);
  display.println("Bad USB");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5, y);
  display.println(">");
}

void time() {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println("TIME !");
}

void rfid() {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println("RFID / NFC !");
}

void signal_mhz() {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println("433 MHZ !");
}

void bad_usb() {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println("BAD USB !");
}
