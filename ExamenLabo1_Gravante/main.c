#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"

#define MUSICO_CANT 1000
#define ORQUESTA_CANT 50
#define INSTRUMENTO_CANT 20

int main()
{
    int opcion;
    int aceptar;
    int contadorIdOrquesta=0;
    int contadorIdMusico=0;
    int contadorIdInstrumento=0;

    Orquesta arrayOrquesta[ORQUESTA_CANT];
    orquesta_Inicializar(arrayOrquesta,ORQUESTA_CANT);
    Musico arrayMusico[MUSICO_CANT];
    musico_Inicializar(arrayMusico,MUSICO_CANT);
    Instrumento arrayInstrumento[INSTRUMENTO_CANT];
    instrumento_Inicializar(arrayInstrumento,INSTRUMENTO_CANT);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1:
                utn_getUnsignedInt("\n\n1) Orquesta \n2) Instrumento \n3) Musico \n4) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        if(!orquesta_alta(arrayOrquesta,ORQUESTA_CANT,&contadorIdOrquesta))
                        {
                            printf("Alta OK. Id de orquesta: %d\n", contadorIdOrquesta);
                        }
                        break;
                    case 2:
                        instrumento_alta(arrayInstrumento,INSTRUMENTO_CANT,&contadorIdInstrumento);
                        break;
                    case 3:
                        utn_getUnsignedInt("\nDEBE DAR DE ALTA SU INSTRUMENTO PRIMERO, CONTINUAR? 1)Si 2)No","\nError",1,sizeof(int),1,2,1,&aceptar);
                        if(aceptar== 1)
                        {
                            musico_alta(arrayMusico,MUSICO_CANT,&contadorIdMusico,
                                        arrayInstrumento, INSTRUMENTO_CANT, arrayOrquesta,ORQUESTA_CANT);
                            break;
                        }
                        printf("ERROR");
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                break;

            case 2:
                utn_getUnsignedInt("\n1) Musico \n2) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        musico_modificar(arrayMusico,MUSICO_CANT);
                        break;
                    case 2:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                break;

            case 3:
                utn_getUnsignedInt("\n\n1) Orquesta \n2) Instrumento \n3) Musico \n4) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        orquesta_baja(arrayOrquesta,ORQUESTA_CANT, arrayMusico, MUSICO_CANT);
                        break;
                    case 2:
                        instrumento_baja(arrayInstrumento,INSTRUMENTO_CANT);
                        break;
                    case 3:
                        musico_baja(arrayMusico,MUSICO_CANT, arrayInstrumento, INSTRUMENTO_CANT);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                break;

            case 4:
                utn_getUnsignedInt("\n\n1) Orquesta \n2) Instrumento \n3) Musico \n4) Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        orquesta_listar(arrayOrquesta,ORQUESTA_CANT);
                        break;
                    case 2:
                        instrumento_listar(arrayInstrumento,INSTRUMENTO_CANT);
                        break;
                    case 3:
                        musico_listar(arrayMusico,MUSICO_CANT, arrayInstrumento, INSTRUMENTO_CANT);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                break;

            case 5:
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);
    return 0;
}
