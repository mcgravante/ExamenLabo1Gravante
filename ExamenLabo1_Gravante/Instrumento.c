#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Instrumento.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)                                    //cambiar instrumento
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(; size>=0; size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idInstrumento==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)                                                   //cambiar campo tipo
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)                          //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int bufferTipo;
    char tipoInstrumento [TEXT_SIZE]="";
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar instrumento
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumento=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nNombre:\n ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getUnsignedInt("\nTipo de Instrumento: 1) Cuerdas  2) Viento-madera  3) Viento-metal  4) Percusión\n ",
                               "\nError",1,sizeof(int),1,4,1,&bufferTipo);
            switch(bufferTipo)
            {
            case 1:
                strcpy(tipoInstrumento, "Cuerdas");
                break;
            case 2:
                strcpy(tipoInstrumento, "Viento-madera");
                break;
            case 3:
                strcpy(tipoInstrumento, "Viento-metal");
                break;
            case 4:
                strcpy(tipoInstrumento, "Percusión");
                break;
            default:
                printf("Error");
                return retorno;
            }
            array[posicion].tipo=bufferTipo;
            printf("\n ID: %d\n tipo: %s\n nombre: %s\n",
                   array[posicion].idInstrumento,tipoInstrumento,array[posicion].nombre);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray)                                      //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idInstrumento=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo tipo
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0; i<sizeArray; i++)
        {
            if(array[i].idInstrumento==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idInstrumento=0;                                                                   //cambiar campo id
                array[i].tipo=0;                                                               //cambiar campo tipo
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int sizeArray)                                //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n",
                       posicion, array[posicion].idInstrumento,array[posicion].tipo,array[posicion].nombre);
                utn_getChar("\nModificar: A B S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                case 'A':
                    utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo tipo
                    break;
                case 'B':
                    utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                    break;
                case 'S':
                    break;
                default:
                    printf("\nOpcion no valida");
                }
            }
            while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorString(Instrumento array[],int size)                              //cambiar instrumento
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferTipo;                                              //cambiar buffer int

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idInstrumento;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferTipo=array[i].tipo;                                //cambiar campo tipo


            j = i - 1;
            while ((j >= 0) && strcmp(bufferNombre,array[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferTipo<array[j].tipo
            {
                //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idInstrumento=array[j].idInstrumento;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].tipo=array[j].tipo;                        //cambiar campo tipo

                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);                     //cambiar campo nombre
            array[j + 1].idInstrumento=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].tipo=bufferTipo;                                                        //cambiar campo tipo
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)                      //cambiar instrumento
{
    int retorno=-1;
    int i;
    char tipoInstrumento [TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                instrumento_tipo(array,tipoInstrumento,&i);
                printf("\n ID: %d\n tipo: %s\n nombre: %s\n",
                       array[i].idInstrumento,tipoInstrumento,array[i].nombre);      //cambiar todos
            }
        }
        retorno=0;
    }
    return retorno;
}

int instrumento_tipo(Instrumento array[],char* tipoInstrumento, int* indice)
{
    int auxTipoInstrumento;
    auxTipoInstrumento=array[*indice].tipo;
    switch(auxTipoInstrumento)
    {
    case 1:
        strcpy(tipoInstrumento, "Cuerdas");
        break;
    case 2:
        strcpy(tipoInstrumento, "Viento-madera");
        break;
    case 3:
        strcpy(tipoInstrumento, "Viento-metal");
        break;
    case 4:
        strcpy(tipoInstrumento, "Percusión");
        break;
    default:
        strcpy(tipoInstrumento, "No definido");
        break;
    }
    return 0;
}
