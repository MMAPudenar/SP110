/**
 * \file SP110.cpp
 * \brief Archivo de implementación para el piranómetro APOGEE SP110
 * \author Joseph Santiago Portilla Martínez - Karen Stefania Mirama Eraso
 */ 
#include <Arduino.h>
#include "SP110.hpp"

//---------------------------------------------------------
// IMPLEMENTACIÓN DE FUNCIONES
//---------------------------------------------------------

/**
 * \brief Leer la medida analogica del piranometro y convertirla en Radiación
 * \param PiranometroPin: Pin de conexión del piranómetro
 * \param opampGain: Ganancia del amplificador operacional
 * \param radiacion: Puntero al valor de radiación
*/
void getRadiation(uint8_t PiranometroPin, float opampGain, float& radiacion) {
  float volts;
  
  volts = analogRead(PiranometroPin) * (scaleFactor / opampGain); // [V]
  // Radiación total de onda corta [W/m^2] = Señal de salida del sensor [mV] * Factor de calibración [5 W/m^2 por mV]
  radiacion = volts * 5; // [W/m^2]
}