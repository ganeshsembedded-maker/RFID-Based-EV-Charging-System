/***************************************************
 * Project: RFID-Based EV Charging System
 * Author : Ganesh S
 * MCU    : ATmega328
 * 
 * Description:
 * This project enables an EV charging system using
 * RFID authentication. Only authorized RFID cards
 * can activate the charging relay.
 ***************************************************/

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

/* ---------- Pin Definitions ---------- */
#define SS_PIN     10      // RFID SS pin
#define RST_PIN     9      // RFID RST pin
#define RELAY_PIN   7      // Relay control pin

/* ---------- Object Creation ---------- */
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(2, 3, 4, 5, 6, 8);

/* ---------- Authorized RFID UID ---------- */
byte authorizedUID[4] = {0x92, 0x5B, 0x3A, 0x1F};

/* ---------- Setup Function ---------- */
void setup() {
  Serial.begin(9600);          // Initialize serial communication
  SPI.begin();                 // Initialize SPI bus
  mfrc522.PCD_Init();          // Initialize RFID reader
  lcd.begin(16, 2);            // Initialize 16x2 LCD

  pinMode(RELAY_PIN, OUTPUT);  
  digitalWrite(RELAY_PIN, LOW); // Ensure charging is OFF

  lcd.setCursor(0, 0);
  lcd.print("EV Charging Sys");
  lcd.setCursor(0, 1);
  lcd.print("Tap RFID Card");
}

/* ---------- Main Loop ---------- */
void loop() {

  // Check for new RFID card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Check authorization
  if (checkUID()) {
    lcd.clear();
    lcd.print("Access Granted");
    lcd.setCursor(0, 1);
    lcd.print("Charging ON");

    digitalWrite(RELAY_PIN, HIGH); // Start charging
    delay(5000);                   // Charging duration (demo)
    digitalWrite(RELAY_PIN, LOW);  // Stop charging

    lcd.clear();
    lcd.print("Charging Done");
  } 
  else {
    lcd.clear();
    lcd.print("Access Denied");
    lcd.setCursor(0, 1);
    lcd.print("Invalid Card");
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(2000);
  lcd.clear();
  lcd.print("Tap RFID Card");
}

/* ---------- UID Verification Function ---------- */
bool checkUID() {
  for (byte i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != authorizedUID[i]) {
      return false;
    }
  }
  return true;
}
