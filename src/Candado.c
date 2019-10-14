/*=============================================================================
 * Author: was
 * Date: 2019/10/05
 *===========================================================================*/

/*=====[Inclusion de su propia cabecera]=====================================*/

#include "Candado.h"
#include "sapi.h"
#include "leds.h"

/*=====[Inclusiones de dependencias de funciones privadas]===================*/


/*=====[Macros de definicion de constantes privadas]=========================*/
#define TEC1	'PULSADOR_DESBLOQUEAR'
#define TEC2	'PULSADOR_BLOQUEAR'
#define TEC3    'PULSADOR_RECARGAR_BATERIA'
#define TEC4    'PULSADOR_CONSULTAR_ESTADO'
#define BUTTON_LOGIC BUTTON_ONE_IS_UP

/*=====[Macros estilo funcion privadas]======================================*/


/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
	ESTADO_DESBLOQUEADO,
	ESTADO_BLOQUEADO,
} CANDADO_ESTADO_t;

typedef enum {
	TECLA1,
	TECLA2,
	TECLA3,
	TECLA4,
} BOTON_PRESIONADO_t;
// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales publicas]=========================*/
bool_t valor;
// Button objects
   button_t myButton1;

/*=====[Definiciones de Variables globales privadas]=========================*/

static BOTON_PRESIONADO_t botonPresionado;
static CANDADO_ESTADO_t estadoCandado;
static uint8_t nivelBateria;


/*=====[Prototipos de funciones privadas]====================================*/



/*=====[Implementaciones de funciones publicas]==============================*/
void bloquear_Candado(void){
	estadoCandado = ESTADO_BLOQUEADO;
	LED_apagar(LUZ_AMARILLA);
}

void desbloquear_Candado(void){
	estadoCandado = ESTADO_DESBLOQUEADO;
	//prende luz amarilla significa que esta desbloqueado
	LED_encender(LUZ_AMARILLA);
}

void recargar_Bateria(void){
	//si el nivel de bateria es menor a 100 entonces suma en 5 el nivel de la misma cada vez que se aprieta el pulsador
	if (nivelBateria < 100){
		LED_encender(LUZ_VERDE);
		nivelBateria = nivelBateria + 5;
		LED_apagar(LUZ_VERDE);
			//mostrar el nivel de la bateria en la uart
	}

}

void descargar_bateria(void){
	if (nivelBateria > 0){
		nivelBateria = nivelBateria -1;
	}
}

void mostrar_Estado_Candado(void){
	//consultar valor de los parametros del candado
	//mostrar por la uart los mismos
	char str[12];
		sprintf(str, "%d", estadoCandado);
		char str2[12];
			sprintf(str2, "%d", nivelBateria);
	uartWriteString( UART_USB, "Estado del candado:" );
	uartWriteString( UART_USB, str );
	uartWriteString( UART_USB, "Nivel bateria:" );

	uartWriteString( UART_USB, str2 );
	delay(1);
}

void candado_inicializar_MEF(void){

	estadoCandado = ESTADO_BLOQUEADO;
	nivelBateria = 100;
	LED_apagar(LUZ_VERDE);
	LED_apagar(LUZ_ROJA);
	LED_apagar(LUZ_AMARILLA);

	uartConfig( UART_USB, 115200 );

}

void candado_Normal_MEF(uint8_t teclaPresionada) {

	switch (teclaPresionada) {

	case 1: //tecla 1 desbloquear el candado
		//consulta el estado y la tecla que el usuario presiono
		//si la tecla que presiono es para prender entonces, se desbloquea el candado

		if (estadoCandado == ESTADO_BLOQUEADO) {
			desbloquear_Candado();
			descargar_bateria();
			uartWriteString( UART_USB, "Candado desbloqueado" );
			//exit();
		}

		break;

	case 2: //tecla 2 bloquear el candado


		if (estadoCandado == ESTADO_DESBLOQUEADO) {
			bloquear_Candado();
			descargar_bateria();
			uartWriteString( UART_USB, "Candado bloqueado" );

		}

		if (estadoCandado == ESTADO_BLOQUEADO) {
			//se debe emitir una alerta de que ya esta bloqueado
			LED_encender(LUZ_ROJA);
			delay(500);
			LED_apagar(LUZ_ROJA);

		}

		break;


	case 3: //tecla 3 recargar bateria

		recargar_Bateria();

		break;

	case 4: //tecla 4 consultar estado
		descargar_bateria();
		mostrar_Estado_Candado();


	}

}


