#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Musico.h"
#include "Instrumento.h"
#include "Orquesta.h"


int ordenarPorIdOrquesta(Musico arrayMusico[], int sizeMusico)
{
    int flagSwap;
    int i;
    int j;
    Musico bufferMusico[sizeMusico];
    if(arrayMusico!= NULL && sizeMusico>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < sizeMusico; i++)
                for (j = 0; j < sizeMusico - 1; j++)
                {
                    if(arrayMusico[j].isEmpty==0 && arrayMusico[j+1].isEmpty==0
                            && arrayMusico[j].idOrquesta>arrayMusico[j+1].idOrquesta)
                    {
                        strcpy(bufferMusico[0].apellido,arrayMusico[j+1].apellido);
                        strcpy(bufferMusico[0].nombre,arrayMusico[j+1].nombre);
                        bufferMusico[0].edad=arrayMusico[j+1].edad;
                        bufferMusico[0].idOrquesta=arrayMusico[j+1].idOrquesta;
                        bufferMusico[0].idInstrumento=arrayMusico[j+1].idInstrumento;
                        bufferMusico[0].idMusico=arrayMusico[j+1].idMusico;
                        bufferMusico[0].isEmpty=arrayMusico[j+1].isEmpty;

                        strcpy(arrayMusico[j+1].apellido,arrayMusico[j].apellido);
                        strcpy(arrayMusico[j+1].nombre,arrayMusico[j].nombre);
                        arrayMusico[j+1].edad=arrayMusico[j].edad;
                        arrayMusico[j+1].idOrquesta=arrayMusico[j].idOrquesta;
                        arrayMusico[j+1].idInstrumento=arrayMusico[j].idInstrumento;
                        arrayMusico[j+1].idMusico=arrayMusico[j].idMusico;
                        arrayMusico[j+1].isEmpty=arrayMusico[j].isEmpty;

                        strcpy(arrayMusico[j].apellido,bufferMusico[0].apellido);
                        strcpy(arrayMusico[j].nombre,bufferMusico[0].nombre);
                        arrayMusico[j].edad=bufferMusico[0].edad;
                        arrayMusico[j].idOrquesta=bufferMusico[0].idOrquesta;
                        arrayMusico[j].idInstrumento=bufferMusico[0].idInstrumento;
                        arrayMusico[j].idMusico=bufferMusico[0].idMusico;
                        arrayMusico[j].isEmpty=bufferMusico[0].isEmpty;
                        flagSwap=1;
                    }
                }
        }
        while (flagSwap==1);
    }
    return 0;
}

int informes_a(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico)
{
    int i;
    int contadorIdOrquestaIguales=1;
    int idOrquesta=0;
    int posicionOrquesta=0;
    if(arrayMusico!= NULL && sizeMusico>=0)
    {
        ordenarPorIdOrquesta(arrayMusico,sizeMusico);
        for(i=0; i<sizeMusico-1; i++)
        {
            if(arrayMusico[i].isEmpty==0 && arrayMusico[i+1].isEmpty==0
                    && arrayMusico[i].idOrquesta==arrayMusico[i+1].idOrquesta)
            {
                contadorIdOrquestaIguales++;
                if(contadorIdOrquestaIguales>5)
                {
                    idOrquesta=arrayMusico[i].idOrquesta;
                    orquesta_buscarID(arrayOrquesta,sizeOrquesta,idOrquesta, &posicionOrquesta);
                    printf("\nidOrquesta: %d nombre: %s tipo: %d lugar: %s\n",arrayMusico[i].idOrquesta,
                           arrayOrquesta[posicionOrquesta].nombre, arrayOrquesta[posicionOrquesta].tipo,
                           arrayOrquesta[posicionOrquesta].lugar);
                    do
                    {
                        if(arrayMusico[i].isEmpty==0 && arrayMusico[i+1].isEmpty==0
                                && arrayMusico[i].idOrquesta==arrayMusico[i+1].idOrquesta)
                        {
                            i++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    while(i<sizeMusico);
                    contadorIdOrquestaIguales=1;

                }
            }
            else
            {
                contadorIdOrquestaIguales=1;

            }
        }
    }
    return 0;
}

int informes_b(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
               int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int i=0;
    int posicionInstrumento=0;
    int posicionOrquesta=0;
    int idInstrumento=0;
    int idOrquesta=0;

    for (i=0; i<sizeMusico; i++)
    {
        if(arrayMusico[i].isEmpty==0 && arrayMusico[i].edad>30)
        {
            idInstrumento=arrayMusico[i].idInstrumento;
            idOrquesta=arrayMusico[i].idOrquesta;
            instrumento_buscarID(arrayInstrumento,sizeInstrumento,idInstrumento, &posicionInstrumento);
            orquesta_buscarID(arrayOrquesta,sizeOrquesta,idOrquesta, &posicionOrquesta);

            printf("\nidMusico: %d nombre: %s apellido: %s edad: %d Instrumento: %s Orquesta: %s\n",
                   arrayMusico[i].idMusico, arrayMusico[i].nombre, arrayMusico[i].apellido,
                   arrayMusico[i].edad, arrayInstrumento[posicionInstrumento].nombre, arrayOrquesta[posicionOrquesta].nombre);
        }
    }
    return 0;
}

int informes_c(Orquesta arrayOrquesta[], int sizeOrquesta)
{
    int i=0;
    int auxTipoOrquesta;
    char tipoOrquesta [TEXT_SIZE];
    char lugarBuscado[TEXT_SIZE];
    utn_getAlfanumerico("\nIngrese lugar deseado: ","\nError",1,TEXT_SIZE,2,lugarBuscado);
    for (i=0; i<sizeOrquesta; i++)
    {
        if(arrayOrquesta[i].isEmpty==0 && strcmp(arrayOrquesta[i].lugar,lugarBuscado)==0)
        {
            auxTipoOrquesta=arrayOrquesta[i].tipo;
            switch(auxTipoOrquesta)
            {
            case 1:
                strcpy(tipoOrquesta,"Sinfónica");
                break;
            case 2:
                strcpy(tipoOrquesta,"Filarmónica");
                break;
            case 3:
                strcpy(tipoOrquesta,"Cámara");
                break;
            default:
                strcpy(tipoOrquesta,"No definido");
                break;
            }
            printf("\nidOrquesta: %d, nombre: %s, tipo: %s, lugar: %s",
                   arrayOrquesta[i].idOrquesta,arrayOrquesta[i].nombre,tipoOrquesta,
                   arrayOrquesta[i].lugar);
        }
    }
    return 0;
}

int informes_d(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
               int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int i;
    int idOrquesta;
    int posicionInstrumento;
    int tipoInstrumento;
    int contadorVientos=0;
    int contadorCuerdas=0;
    int contadorPercusion=0;
    if(arrayMusico!= NULL && sizeMusico>=0)
    {
        ordenarPorIdOrquesta(arrayMusico,sizeMusico);
        for(i=0; i<sizeMusico; i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                idOrquesta=arrayMusico[i].idOrquesta;
                instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&posicionInstrumento);
                tipoInstrumento=arrayInstrumento[posicionInstrumento].tipo;
                switch(tipoInstrumento)
                {
                case 1:
                    contadorCuerdas++;
                    break;
                case 2:
                    contadorVientos++;
                    break;
                case 3:
                    contadorVientos++;
                    break;
                case 4:
                    contadorPercusion++;
                    break;
                }
                if (arrayMusico[i].idOrquesta!=arrayMusico[i +1].idOrquesta)
                {
                    if(contadorCuerdas>=5&&contadorVientos>=3&&contadorPercusion>=2)
                    {
                        orquesta_imprimirById(arrayOrquesta,sizeOrquesta,idOrquesta);
                    }
                    contadorCuerdas=0;
                    contadorVientos=0;
                    contadorPercusion=0;
                }
            }
        }
    }
    return 0;
}

int informes_e(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
               int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int i;
    int idOrquestaBuscado;
    int posicionInstrumento;
    char tipoInstrumento[TEXT_SIZE];
    utn_getUnsignedInt("\nIngrese id de orquesta requerido: ","\nError",1,sizeof(int),1,9999,2,&idOrquestaBuscado);
    for (i=0; i<sizeMusico; i++)
    {
        if(arrayMusico[i].isEmpty==0 && arrayMusico[i].idOrquesta==idOrquestaBuscado)
        {
            instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento,&posicionInstrumento);
            instrumento_tipo(arrayInstrumento,tipoInstrumento,&i);
            printf("\nidMusico: %d nombre: %s apellido: %s edad: %d Nombre Instrumento: %s Tipo Instrumento: %s\n",
                   arrayMusico[i].idMusico, arrayMusico[i].nombre, arrayMusico[i].apellido,
                   arrayMusico[i].edad, arrayInstrumento[posicionInstrumento].nombre, tipoInstrumento);
        }
    }
    return 0;
}

int informes_f(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico)
{
    int i;
    int j;
    int k;
    int cantidadMusicosPorOrquesta=1;
    int contadorOrquestaConMasMusicos=0;
    int idOrquesta=0;
    int idOrquestasMismaCantidadMusicos[sizeOrquesta];

    if(arrayMusico!= NULL && sizeMusico>=0)
    {
        ordenarPorIdOrquesta(arrayMusico,sizeMusico);
        for(i=0; i<sizeMusico-1; i++)
        {
            if(arrayMusico[i].isEmpty==0 && arrayMusico[i+1].isEmpty==0
                    && arrayMusico[i].idOrquesta==arrayMusico[i+1].idOrquesta)
            {
                cantidadMusicosPorOrquesta++;
            }
            else
            {
                idOrquesta=arrayMusico[i].idOrquesta;
                if(cantidadMusicosPorOrquesta>contadorOrquestaConMasMusicos)
                {
                    j=0;
                    contadorOrquestaConMasMusicos=cantidadMusicosPorOrquesta;
                    utn_inicializarArrayInt(idOrquestasMismaCantidadMusicos,sizeOrquesta);
                    idOrquestasMismaCantidadMusicos[j]=idOrquesta;
                    j++;
                }
                else if(cantidadMusicosPorOrquesta==contadorOrquestaConMasMusicos)
                {
                    idOrquestasMismaCantidadMusicos[j]=idOrquesta;
                    j++;
                }
                cantidadMusicosPorOrquesta=1;
            }
        }
        for(k=0; k<sizeOrquesta; k++)
        {
            if(idOrquestasMismaCantidadMusicos[k])
                orquesta_imprimirById(arrayOrquesta,sizeOrquesta,idOrquestasMismaCantidadMusicos[k]);
        }
    }
    printf("\n \n Cantidad de músicos: %d", contadorOrquestaConMasMusicos);
    return 0;
}

int informes_g(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int i;
    int j=0;
    int posicionInstrumento=0;
    int idInstrumento=0;
    int auxTipoInstrumento;
    char tipoInstrumento[TEXT_SIZE];
    Musico auxMusico[sizeMusico];
    musico_Inicializar(auxMusico,sizeMusico);

    for (i=0; i<sizeMusico; i++)
    {
        if(arrayMusico[i].isEmpty==0)
        {
            idInstrumento=arrayMusico[i].idInstrumento;
            instrumento_buscarID(arrayInstrumento,sizeInstrumento,idInstrumento, &posicionInstrumento);
            auxTipoInstrumento=arrayInstrumento[posicionInstrumento].tipo;
            if (auxTipoInstrumento==1)
            {
                strcpy(auxMusico[j].apellido,arrayMusico[i].apellido);
                strcpy(auxMusico[j].nombre,arrayMusico[i].nombre);
                auxMusico[j].edad=arrayMusico[i].edad;
                auxMusico[j].idOrquesta=arrayMusico[i].idOrquesta;
                auxMusico[j].idInstrumento=arrayMusico[i].idInstrumento;
                auxMusico[j].idMusico=arrayMusico[i].idMusico;
                auxMusico[j].isEmpty=arrayMusico[i].isEmpty;
                j++;
            }
        }
    }
    musico_ordenarPorApellido(auxMusico,sizeMusico);
    for(i=0; i<sizeMusico; i++)
    {
        if(auxMusico[i].isEmpty==0)
        {
            idInstrumento=auxMusico[i].idInstrumento;
            instrumento_buscarID(arrayInstrumento,sizeInstrumento,idInstrumento, &posicionInstrumento);
            instrumento_tipo(arrayInstrumento,tipoInstrumento,&posicionInstrumento);
            printf("\n id: %d apellido: %s nombre: %s edad: %d Instrumento: %s - %s\n",
                  auxMusico[i].idMusico, auxMusico[i].apellido,auxMusico[i].nombre, auxMusico[i].edad,
                   arrayInstrumento[posicionInstrumento].nombre, tipoInstrumento);
        }
    }
    return 0;
}

int informes_h(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico)
{
    int i;
    int cantidadOrquestas=0;
    int cantidadMusicos=0;
    float promedioMusicosPorOrquesta;
    if(arrayMusico!= NULL && sizeMusico>=0)
    {
        for(i=0; i<sizeMusico; i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                cantidadMusicos++;
            }
        }
    }
    if(arrayOrquesta!= NULL && sizeOrquesta>=0)
    {
        for(i=0; i<sizeOrquesta; i++)
        {
            if(arrayOrquesta[i].isEmpty==0)
            {
                cantidadOrquestas++;
            }
        }
    }
    promedioMusicosPorOrquesta=(float)cantidadMusicos/(float)cantidadOrquestas;
    printf("Cantidad de musicos por orquesta: %.2f",promedioMusicosPorOrquesta);
    return 0;
}


int hardCodearDatos(Orquesta arrayOrquesta[], Musico arrayMusico[], Instrumento arrayInstrumento[])
{
    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[0].idOrquesta=1;
    strcpy(arrayOrquesta[0].lugar,"Lugar1");
    strcpy(arrayOrquesta[0].nombre,"Orquesta1");
    arrayOrquesta[0].tipo=1;

    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].idOrquesta=2;
    strcpy(arrayOrquesta[1].lugar,"Lugar1");
    strcpy(arrayOrquesta[1].nombre,"Orquesta2");
    arrayOrquesta[1].tipo=2;

    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].idOrquesta=3;
    strcpy(arrayOrquesta[2].lugar,"Lugar2");
    strcpy(arrayOrquesta[2].nombre,"Orquesta3");
    arrayOrquesta[2].tipo=3;

    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].idOrquesta=4;
    strcpy(arrayOrquesta[3].lugar,"Lugar3");
    strcpy(arrayOrquesta[3].nombre,"Orquesta4");
    arrayOrquesta[3].tipo=3;

    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].idInstrumento=1;
    arrayInstrumento[0].tipo=1;
    strcpy(arrayInstrumento[0].nombre,"Inst1");

    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].idInstrumento=2;
    arrayInstrumento[1].tipo=2;
    strcpy(arrayInstrumento[1].nombre,"Inst2");

    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].idInstrumento=3;
    arrayInstrumento[2].tipo=2;
    strcpy(arrayInstrumento[2].nombre,"Inst3");

    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].idInstrumento=4;
    arrayInstrumento[3].tipo=3;
    strcpy(arrayInstrumento[3].nombre,"Inst4");

    arrayInstrumento[4].isEmpty=0;
    arrayInstrumento[4].idInstrumento=5;
    arrayInstrumento[4].tipo=4;
    strcpy(arrayInstrumento[4].nombre,"Inst4");

    arrayMusico[0].isEmpty=0;
    arrayMusico[0].edad=30;
    arrayMusico[0].idInstrumento=2;
    arrayMusico[0].idMusico=1;
    arrayMusico[0].idOrquesta=1;
    strcpy(arrayMusico[0].nombre,"Mus1");
    strcpy(arrayMusico[0].apellido,"Amus1");

    arrayMusico[1].isEmpty=0;
    arrayMusico[1].edad=20;
    arrayMusico[1].idInstrumento=5;
    arrayMusico[1].idMusico=2;
    arrayMusico[1].idOrquesta=2;
    strcpy(arrayMusico[1].nombre,"Mus2");
    strcpy(arrayMusico[1].apellido,"Amus2");

    arrayMusico[2].isEmpty=0;
    arrayMusico[2].edad=25;
    arrayMusico[2].idInstrumento=2;
    arrayMusico[2].idMusico=3;
    arrayMusico[2].idOrquesta=4;
    strcpy(arrayMusico[2].nombre,"Mus3");
    strcpy(arrayMusico[2].apellido,"Amus3");

    arrayMusico[3].isEmpty=0;
    arrayMusico[3].edad=27;
    arrayMusico[3].idInstrumento=1;
    arrayMusico[3].idMusico=4;
    arrayMusico[3].idOrquesta=4;
    strcpy(arrayMusico[3].nombre,"Mus4");
    strcpy(arrayMusico[3].apellido,"Amus4");

    arrayMusico[4].isEmpty=0;
    arrayMusico[4].edad=22;
    arrayMusico[4].idInstrumento=3;
    arrayMusico[4].idMusico=5;
    arrayMusico[4].idOrquesta=1;
    strcpy(arrayMusico[4].nombre,"Mus5");
    strcpy(arrayMusico[4].apellido,"Amus5");

    arrayMusico[5].isEmpty=0;
    arrayMusico[5].edad=35;
    arrayMusico[5].idInstrumento=4;
    arrayMusico[5].idMusico=6;
    arrayMusico[5].idOrquesta=3;
    strcpy(arrayMusico[5].nombre,"Mus6");
    strcpy(arrayMusico[5].apellido,"Amus6");
    return 0;
}
