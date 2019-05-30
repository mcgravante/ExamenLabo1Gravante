#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "informes.h"


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
    orquesta_listar(arrayOrquesta,ORQUESTA_CANT);
    instrumento_listar(arrayInstrumento,INSTRUMENTO_CANT);
    musico_listar(arrayMusico,MUSICO_CANT, arrayInstrumento, INSTRUMENTO_CANT);

    hardCodearDatos(arrayOrquesta, arrayMusico, arrayInstrumento);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Acceder a Informes \n6) Salir\n",
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
            do
            {
                utn_getUnsignedInt("\n\n1) INFORMES_A \n2) INFORMES_B \n3) INFORMES_C \n4) INFORMES_D \n5) INFORMES_E \n6) INFORMES_F \n7) INFORMES_G \n8) INFORMES_H \n9) Salir\n",
                                   "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                case 1:
                    informes_a(arrayOrquesta,ORQUESTA_CANT,arrayMusico,MUSICO_CANT);
                    break;
                case 2:
                    informes_b(arrayOrquesta,ORQUESTA_CANT,arrayMusico,MUSICO_CANT,arrayInstrumento,INSTRUMENTO_CANT);
                    break;
                case 3:
                    informes_c(arrayOrquesta,ORQUESTA_CANT);
                    break;
                case 4:
                    informes_d(arrayOrquesta,ORQUESTA_CANT,arrayMusico,MUSICO_CANT,arrayInstrumento,INSTRUMENTO_CANT);
                    break;
                case 5:
                    informes_e(arrayOrquesta,ORQUESTA_CANT,arrayMusico,MUSICO_CANT,arrayInstrumento,INSTRUMENTO_CANT);
                    break;
                case 6:
                    informes_f(arrayOrquesta,ORQUESTA_CANT,arrayMusico, MUSICO_CANT);
                    break;
                case 7:
                    informes_g(arrayMusico,MUSICO_CANT,arrayInstrumento,INSTRUMENTO_CANT);
                    break;
                case 8:
                    informes_h(arrayOrquesta,ORQUESTA_CANT,arrayMusico,MUSICO_CANT);
                    break;
                case 9:
                    break;
                default:
                    printf("\nOpcion no valida");
                }
            }
            while(opcion!=9);
            break;
        case 6:
            break;
        default:
            printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
