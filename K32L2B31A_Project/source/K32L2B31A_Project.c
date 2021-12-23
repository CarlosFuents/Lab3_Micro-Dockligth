/*! @file : K32L2B31A_Project.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 0.0.000
 * @date    23/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include <limits.h>
#include <float.h>

#include <iot_sdk_peripherals_leds.h>
#include <iot_sdk_peripherals_light.h>
#include "iot_sdk_peripherals_buttons.h"
#include "iot_sdk_peripheral_temperature.h"

#include "iot_sdk_ irq_lptimer0.h"
#include "iot_sdk_irq_lpuart0.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
enum kat_list {
	kAT = 0,
	kATE0,
	kAT_CFUN0,
	kAT_CFUN1,
	kAT_CPIN,
	kAT_QCSQ,
	kAT_CREG,
	kAT_CGREG,
	kAT_CEREG,
	kesperando_respuesta,
};

enum kled_sensor_list {
	kOn_led_green = 0,
	kOff_led_green,
	kOn_led_red,
	kOff_led_red,
	kluminosidad,
	ktemperatura,
};

#define COMANDOS_DISPONIBLES_LEDS_SENSOR 6
#define COMANDOS_DISPONIBLES_AT 12
#define BYTES_EN_BUFFER	100


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void esperando_respuesta(void);
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
const char *comandos_at[] = {
				"AT",
		        "ATE0",
				"AT+CFUN=0",
				"AT+CFUN=1",
    			"AT+CPIN?",
    			"AT+QCSQ",
    			"AT+CREG?",
    			"AT+CGREG?",
				"AT+CEREG?",
    	};

    //Lista de respuestas a cada comando AT
    const char  *repuestas_at[]={
    		        "OK",		//AT
					"OK",	    //ATE0
					 "OK",		//AT+CFUN=0
					"OK",		//AT+CFUN=1
    				"READY",	//AT+CPIN?
    				"LTE",    //AT+QCSQ
    				"0,1",	//AT+CREG? = GSM,REGISTERED
    				"0,1", //AT+CGREG?
					"0,1", //AT+CEREG?

    };

    const char  *repuestas_LEDS[]={
       		        "On_led_green",
       				"Off_led_green",
       				"On_led_red",
       				"Off_led_red",
					"luminosidad",
					"temperatura"

       };


    uint8_t buffer_rx[BYTES_EN_BUFFER];		//almacena las datos que provienen del modem
    uint8_t index_buffer_rx = 0;				//apuntador de buffer de datos


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

    void BorrarBufferRX(void){
        	uint8_t i;

        	//LLenar de ceros buffer que va a recibir datos provenientes del modem
        	for(i=0;i<BYTES_EN_BUFFER;i++){
        		buffer_rx[i]=0;
        	}

        	//borra apuntador de posicion donde se va a almacenar el proximo dato
        	//Reset al apuntador
        	index_buffer_rx=0;
        }


 int main(void) {
	float light_value;
	float temperature_value;
	bool sw1;
	bool sw2;
	int j=0;
	int i=0;
	//int k=0;
	uint8_t nuevo_byte_lpuart0;


    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /* Activa LPTMR0 para que iniciar contador y posterior IRQ cada 1 segundo*/
    LPTMR_StartTimer(LPTMR0);


    while(1) {

    	//for(int j=0; j<COMANDOS_DISPONIBLES_AT; j++){
    		switch(j){

    		    case kAT:
    		    	printf("%s\r\n",comandos_at[kAT]);
    		    	i=kAT;
    		    	j= kesperando_respuesta;

    		    break;

    		    case kATE0:
    		        printf("%s\r\n",comandos_at[kATE0]);
    		        i=kATE0;
    		        j= kesperando_respuesta;

    		    break;

    		    case kAT_CFUN0:
					printf("%s\r\n",comandos_at[kAT_CFUN0]);
					i=kAT_CFUN0;
					j= kesperando_respuesta;

				break;

    		    case kAT_CFUN1:
					printf("%s\r\n",comandos_at[kAT_CFUN1]);
					i=kAT_CFUN1;
					j= kesperando_respuesta;

				break;

    		    case kAT_CPIN:
    		        printf("%s\r\n",comandos_at[kAT_CPIN]);
    		        i=kAT_CPIN;
    		        j= kesperando_respuesta;

    		    break;

    		    case kAT_QCSQ:
    		         printf("%s\r\n",comandos_at[kAT_QCSQ]);
    		         i=kAT_QCSQ;
    		         j= kesperando_respuesta;
    		    break;

    		    case kAT_CREG:
    		         printf("%s\r\n",comandos_at[kAT_CREG]);
    		         i=kAT_CREG;
    		         j= kesperando_respuesta;

    		    break;

    		    case kAT_CGREG:
    		         printf("%s\r\n",comandos_at[kAT_CGREG]);
    		         i=kAT_CGREG;
    		         j= kesperando_respuesta;

    		    break;

    		    case kAT_CEREG:
					 printf("%s\r\n",comandos_at[kAT_CEREG]);
					 i=kAT_CEREG;
					 j= kesperando_respuesta;

				break;

    		    case kesperando_respuesta:

    		    	if (uart0CuantosDatosHayEnBuffer() !=0) {
    		    	    		nuevo_byte_lpuart0 = LeerByteDesdeBuffer();
                                //printf("nuevo byte:%c\r\n",nuevo_byte_lpuart0);
    		    	    					//almacena dato en buffer rx
    		    	    					buffer_rx[index_buffer_rx] = nuevo_byte_lpuart0;
    		    	    					//incrementa apuntador de datos en buffer
    		    	    					index_buffer_rx++;


    		    	    					char *puntero_ok;
    		    	    					char *puntero_ok2;

    		    	    					if(nuevo_byte_lpuart0 == '\n'){

    		    	    						if(i<COMANDOS_DISPONIBLES_AT){

    		    	    						puntero_ok = (char*) (strstr((char*) (&buffer_rx[0]),(char*) (repuestas_at[i])));


    		    	    						   if(puntero_ok!=0){
    		    	    						    	switch(i){


    		    	    								   case kAT:

    		    	    									   printf("Respuesta identificada\r\n");
    		    	    									   BorrarBufferRX();
    		    	    									   j=kATE0;


    		    	    						    	   break;

    		    	    								   case kATE0:


    		    	    								        printf("Respuesta identificada\r\n");
    		    	    								        BorrarBufferRX();
    		    	    								       j=kAT_CFUN0;

    		    	    								   break;

    		    	    								   case kAT_CFUN0:


																printf("Respuesta identificada\r\n");
																BorrarBufferRX();
															   j=kAT_CFUN1;

														   break;

    		    	    								   case kAT_CFUN1:


																printf("Respuesta identificada\r\n");
																BorrarBufferRX();
															   j=kAT_CPIN;

														   break;

    		    	    								   case kAT_CPIN:

    		    	    								        printf("Respuesta identificada\r\n");
    		    	    								        BorrarBufferRX();
    		    	    								       j=kAT_QCSQ;

    		    	    								   break;

    		    	    								   case kAT_QCSQ:

    		    	    								         printf("Respuesta identificada\r\n");
    		    	    								         BorrarBufferRX();
    		    	    								       j=kAT_CREG;

    		    	    								   break;

    		    	    								   case kAT_CREG:

    		    	    								         printf("Respuesta identificada\r\n");
    		    	    								         BorrarBufferRX();
    		    	    								        j=kAT_CGREG;

    		    	    								    break;

    		    	    								   case kAT_CGREG:

																 printf("Respuesta identificada\r\n");
																 BorrarBufferRX();
																j=kAT_CEREG;

															break;

    		    	    								   case kAT_CEREG:

    		    	    								         printf("Respuesta identificada\r\n");
    		    	    								         BorrarBufferRX();
    		    	    								         j=kesperando_respuesta;
    		    	    								         i=kesperando_respuesta;


    		    	    								   break;



    		    	    						   }
    		    	    						}

    		    	    					}

    		    	    						if(i==kesperando_respuesta){

    		    	    						  for(int k=0; k<COMANDOS_DISPONIBLES_LEDS_SENSOR; k++){
    		    	    						   puntero_ok2 = (char*) (strstr((char*) (&buffer_rx[0]),(char*) (repuestas_LEDS[k])));

    		    	    						   if(puntero_ok2!=0){

    		    	    							  switch(k){


    		    	    						       	case kOn_led_green:

    		    	    						       		GPIO_PinWrite(GPIOD,5,0);
    		    	    						       		BorrarBufferRX();

    		    	    						        break;

    		    	    						        case kOff_led_green:

    		    	    						        	GPIO_PinWrite(GPIOD,5,1);
    		    	    						        	BorrarBufferRX();

    		    	    						        break;

    		    	    						        case kOn_led_red:

    		    	    						        	GPIO_PinWrite(GPIOE,31U,0);
    		    	    						        	BorrarBufferRX();

    		    	    						       	break;

    		    	    						        case kOff_led_red:

    		    	    						        	GPIO_PinWrite(GPIOE,31U,1);
    		    	    						        	BorrarBufferRX();

    		    	    						        break;

    		    	    						       case kluminosidad:

    		    	    						    	   light_value=getLightADC();
    		    	    						    	   printf("luminosidad: %d\r\n", light_value);
    		    	    						    	   printf("\r\n");
    		    	    						    	   BorrarBufferRX();

    		    	    						       break;

    		    	    						       case ktemperatura:

    		    	    						    	   temperature_value=getTemperatureValue();
    		    	    						    	   printf("temperatura: %f\r\n", temperature_value);
    		    	    						    	   printf("\r\n");
    		    	    						    	   BorrarBufferRX();


    		    	    						       break;



    		    	    						     }
    		    	    						    }
    		    	    						}
    		    	    					}




    		    	    		}
    		    	           }


    		    break;

    		 }








    	if(lptmr0_ticks!=0){
    		lptmr0_ticks=0;
    		 sw1 = leerBoton1();
    		 sw2 = leerBoton2();
    		 if (sw1!=true){

    			 printf("boton 1\r\n");
    			  printf("\r\n");
    		 }

    		 if (sw2!=true){

    			 printf("boton 2\r\n");
    			  printf("\r\n");
    		 }

    	}

    //}

    }
    return 0 ;
}
