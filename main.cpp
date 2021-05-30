#include <Arduino.h>
#include "SP110.hpp"

// ------------ DEFINICION DE CONSTANTES ------------
// INA128
const float opGain = 8.3;
const uint8_t SP110pin = 34;
// Definicion de tiempos
const uint16_t TMedicion = 2000;

// ------------ DEFINICION DE VARIABLES ------------
unsigned long tActual = 0; // Tiempo actual de millis()
unsigned long tPrevio = 0; // Tiempo previo de Medición

// ------------ SETUP ------------
void setup() {
  Serial.begin(115200);
  pinMode(SP110pin, INPUT);
}

// ------------ LOOP ------------
void loop() {
  float rad;

  tActual = millis();

  if (tActual > tPrevio + TMedicion) {
    getRadiation(SP110pin, opGain, rad);
    
    Serial.print(rad);

    tPrevio = tActual;
  }
}