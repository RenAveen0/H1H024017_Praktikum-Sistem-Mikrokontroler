#include <Arduino.h> // library dasar Arduino

// ===================== PIN SETUP =====================
const int potPin = A0;   // Pin analog untuk potensiometer
const int ledPin = 9;    // Pin digital PWM untuk LED

// ===================== VARIABEL =====================
int nilaiADC = 0;  // Variabel penyimpan nilai 10-bit (0-1023)
int pwm = 0;       // Variabel penyimpan nilai 8-bit (0-255)

void setup() {
  // ===================== OUTPUT SETUP =====================
  // Atur pin LED sebagai output
  pinMode(ledPin, OUTPUT);

  // ===================== SERIAL MONITOR =====================
  // Aktifkan komunikasi serial
  Serial.begin(9600); 
}

void loop() {
  // ===================== PEMBACAAN SENSOR =====================
  // Baca nilai analog dari potensiometer (0–1023)
  nilaiADC = analogRead(potPin);

  // ===================== PEMROSESAN DATA (SCALING) =====================
  // Ubah nilai ADC (10-bit) menjadi nilai PWM (8-bit)
  // ADC: 0 s/d 1023 -> PWM: 0 s/d 255
  pwm = map(nilaiADC, 0, 1023, 0, 255);

  // ===================== OUTPUT PWM =====================
  // Kirim sinyal PWM ke LED
  analogWrite(ledPin, pwm); 

  // ===================== MONITORING DATA =====================
  Serial.print("ADC: ");
  Serial.print(nilaiADC); 

  Serial.print(" | PWM: ");
  Serial.println(pwm); 

  // ===================== STABILISASI SISTEM =====================
  delay(50); 
}