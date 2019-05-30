#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int edad;
    int idInstrumento;
    int idOrquesta;
    char apellido[TEXT_SIZE];

} Musico;


#endif // MUSICO_H_INCLUDED
#include "Orquesta.h"
#include "Instrumento.h"

int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);
int musico_alta(Musico arrayMusico[], int sizeArrayMusico, int* contadorID,
                Instrumento arrayInstrumento[], int sizeArrayInstrumento,
                Orquesta arrayOrquesta[], int sizeArrayOrquesta);
int musico_baja(Musico array[], int sizeArray, Instrumento arrayInstrumento[], int sizeArrayInstrumento);
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);
int musico_ordenarPorApellido(Musico array[],int size);
int musico_listar(Musico array[], int size, Instrumento arrayInstrumento[], int sizeArrayInstrumento);

