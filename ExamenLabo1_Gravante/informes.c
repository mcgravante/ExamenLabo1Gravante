#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Musico.h"
#include "Instrumento.h"
#include "Orquesta.h"


int informes_a(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico)
{
    int retorno=-1;
    int flagSwap;
    int i;
    int contadorIdOrquestaIguales;
    Musico bufferMusico[sizeMusico];
    musico_Inicializar(bufferMusico,sizeMusico);
    if(arrayMusico!= NULL && sizeMusico>=0)
    {
    do{
        flagSwap=0;
        for(i=0;i<sizeMusico;i++)
        {
            if(arrayMusico[i].idOrquesta>arrayMusico[i+1].idOrquesta)
            {
                strcpy(bufferMusico[0].apellido,arrayMusico[i+1].apellido);
                strcpy(bufferMusico[0].nombre,arrayMusico[i+1].nombre);
                bufferMusico[0].edad=arrayMusico[i+1].edad;
                bufferMusico[0].idOrquesta=arrayMusico[i+1].idOrquesta;
                bufferMusico[0].idInstrumento=arrayMusico[i+1].idInstrumento;
                bufferMusico[0].idMusico=arrayMusico[i+1].idMusico;
                bufferMusico[0].isEmpty=arrayMusico[i+1].isEmpty;

                strcpy(arrayMusico[i+1].apellido,arrayMusico[i].apellido);
                strcpy(arrayMusico[i+1].nombre,arrayMusico[i].nombre);
                arrayMusico[i+1].edad=arrayMusico[i].edad;
                arrayMusico[i+1].idOrquesta=arrayMusico[i].idOrquesta;
                arrayMusico[i+1].idInstrumento=arrayMusico[i].idInstrumento;
                arrayMusico[i+1].idMusico=arrayMusico[i].idMusico;
                arrayMusico[i+1].isEmpty=arrayMusico[i].isEmpty;

                strcpy(arrayMusico[i].apellido,bufferMusico[0].apellido);
                strcpy(arrayMusico[i].nombre,bufferMusico[0].nombre);
                arrayMusico[i].edad=bufferMusico[0].edad;
                arrayMusico[i].idOrquesta=bufferMusico[0].idOrquesta;
                arrayMusico[i].idInstrumento=bufferMusico[0].idInstrumento;
                arrayMusico[i].idMusico=bufferMusico[0].idMusico;
                arrayMusico[i].isEmpty=bufferMusico[0].isEmpty;

                flagSwap=1;
            }
        }
    }
    while (flagSwap==1);
    for(i=0;i<sizeMusico;i++)
    {
        if(arrayMusico[i+1].idOrquesta==arrayMusico[i].idOrquesta)
        {
            contadorIdOrquestaIguales++;
            if(contadorIdOrquestaIguales>5)
            {
                int posicionOrquesta;
                orquesta_buscarID(arrayOrquesta,sizeOrquesta,arrayMusico[i].idOrquesta, &posicionOrquesta);
                printf("idOrquesta: %d nombre: %s tipo: %d lugar: %s\n",arrayMusico[i].idOrquesta,
                    arrayOrquesta[posicionOrquesta].nombre, arrayOrquesta[posicionOrquesta].tipo,
                    arrayOrquesta[posicionOrquesta].lugar);
            }
        }
    }
    }
    return retorno;
}

int informes_b(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
            int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento )
{
    int i;
    for (i=0;i<sizeMusico;i++)
    {
        if(arrayMusico[i].edad>30)
        {
            int posicionInstrumento;
            instrumento_buscarID(arrayInstrumento,sizeInstrumento,arrayMusico[i].idInstrumento, &posicionInstrumento);
            int posicionOrquesta;
            orquesta_buscarID(arrayOrquesta,sizeOrquesta,arrayMusico[i].idOrquesta, &posicionOrquesta);

            printf("idMusico: %d nombre: %s apellido: %s edad: %d Instrumento: %s Orquesta: %s\n",
            arrayMusico[i].idMusico, arrayMusico[i].nombre, arrayMusico[i].apellido,
            arrayMusico[i].edad, arrayInstrumento[posicionInstrumento].nombre, arrayOrquesta[posicionOrquesta].nombre);
        }
    }
    return 0;
}
