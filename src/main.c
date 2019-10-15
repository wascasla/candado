/*=============================================================================
 * Author: was
 * Date: 2019/10/05
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"
#include "Candado.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   candado_inicializar_MEF();
   bool_t valor;

   // ----- Repeat for ever -------------------------
   while( true ) {

	   //dependiendo de que boton del controlador presiono
	   	valor = !gpioRead(TEC1); //boton1  desbloquear candado
	   	if (valor == 1) {
	   		candado_Update_MEF(1);
	   	}
	   	valor = !gpioRead(TEC2); //boton2 bloquear candado
	   	if (valor == 1) {

	   		candado_Update_MEF(2);
	   	}
	   	valor = !gpioRead(TEC3); // boton3

	   	if (valor == 1) {

	   		candado_Update_MEF(3);
	   	}
	   	valor = !gpioRead(TEC4);// boton 4 consultar estado del candado

	   	if (valor == 1) {

	   		candado_Update_MEF(4);
	   	}

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
