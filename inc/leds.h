/*=====[Nombre del modulo]=====================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*=====[Evitar inclusion multiple comienzo]==================================*/

#ifndef _LEDS_H_
#define _LEDS_H_

/*=====[Inclusiones de dependencias de funciones publicas]===================*/

#include "sapi.h"
/*=====[C++ comienzo]========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Macros de definicion de constantes publicas]=========================*/
#define LUZ_ROJA     LED2
#define LUZ_AMARILLA LED1
#define LUZ_VERDE    LEDG

#define TIEMPO_EN_ROJO     3000 // ms
#define TIEMPO_EN_AMARILLO 1000 // ms
#define TIEMPO_EN_VERDE    2000 // ms


/*=====[Macros estilo funcion publicas]======================================*/


/*=====[Definiciones de tipos de datos publicos]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion


// Tipo de datos enumerado

// Tipo de datos estructua, union o campo de bits

/*=====[Prototipos de funciones publicas]====================================*/

void LED_encender( gpioMap_t lampara );

void LED_apagar( gpioMap_t lampara );

void LED_titilar( gpioMap_t lampara, int32_t tiempoON , uint8_t cantVeces);

/*=====[Prototipos de funciones publicas de interrupcion]====================*/



/*=====[C++ fin]=============================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Evitar inclusion multiple fin]=======================================*/

#endif /* _LEDS_H_ */
