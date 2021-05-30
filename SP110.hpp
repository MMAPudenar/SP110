/**
 * \file SP110.hpp
 * \brief Archivo de cabecera para el piranómetro APOGEE SP110
 * \author Joseph Santiago Portilla Martínez - Karen Stefania Mirama Eraso
 */ 
#ifndef SP110_HPP
#define SP110_HPP

//---------------------------------------------------------
// DEFINICION DE CONSTANTES
//---------------------------------------------------------
// ADC ESP32
const float vRef = 3.3; // [V]
const float resolution = 1023.0; // bits
const float scaleFactor = vRef / resolution; // [V] / bits

//---------------------------------------------------------
// PROTOTIPOS DE FUNCIONES
//---------------------------------------------------------

/**
 * \brief Leer la medida analogica del piranometro y convertirla en Radiación
 * \param PiranometroPin: Pin de conexión del piranómetro
 * \param opampGain: Ganancia del amplificador operacional
 * \param radiacion: Puntero al valor de radiación
*/
void getRadiation(uint8_t PiranometroPin, float opampGain, float& radiacion);


#endif