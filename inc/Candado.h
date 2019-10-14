/*=============================================================================
 * Author: was
 * Date: 2019/10/05
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __CANDADO_H__
#define __CANDADO_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/
void bloquear_Candado(void);

void desbloquear_Candado(void);

void recargar_Bateria(void);

void descargar_bateria(void);

void obtener_Estado_Candado(void);

void candado_inicializar_MEF(void);

void candado_Normal_MEF(uint8_t);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __CANDADO_H__ */
