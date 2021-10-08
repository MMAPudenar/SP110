#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

// ------------ DEFINICION DE CONSTANTES ------------
// Ganancia de ADS lectura de Radiación solar
const float adsGain = 0.25; // [mV/paso]
const float calFactor = 5.0; // [W/m2*mV]
// Definicion de tiempos
const uint16_t TMedicion = 1000;
// ------------ DECLARACIÓN DE OBJETOS ------------
// ADS
Adafruit_ADS1015 ads;
// ------------ DEFINICION DE VARIABLES ------------
unsigned long tActual = 0; // Tiempo actual de millis()
unsigned long tPrevio = 0; // Tiempo previo de Medición

// ------------ SETUP ------------
void setup() {
  Serial.begin(115200);
  // Ajuste de ganancia ADS
  ads.setGain(GAIN_EIGHT); // Ganancia = 8x, VDD = +/- 0.512V, Resolución: 1 bit = 0.25mV
}

// ------------ LOOP ------------
void loop() {
  double rad;

  tActual = millis();

  if (tActual > tPrevio + TMedicion) {
    rad = ads.readADC_Differential_0_1() * adsGain * calFactor;

    Serial.println(rad);

    tPrevio = tActual;
  }
}