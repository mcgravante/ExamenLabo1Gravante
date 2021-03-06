#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Musico.h"
#include "Instrumento.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico arrayMusico[], int sizeArrayMusico, int* contadorID,
                Instrumento arrayInstrumento[], int sizeArrayInstrumento,
                Orquesta arrayOrquesta[], int sizeArrayOrquesta)
{
    int retorno=-1;
    int reintentosInstr=3;
    int reintentosOrq=3;
    int posicion;
    int posicionInstrumento;
    int posicionOrquesta;
    int auxIdInstrumento;
    int auxIdOrquesta;
    char auxNombre [TEXT_SIZE];
    char auxApellido [TEXT_SIZE];
    int auxEdad;
    char tipoInstrumento [TEXT_SIZE];
    if(arrayMusico!=NULL && sizeArrayMusico>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(arrayMusico,sizeArrayMusico,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayMusico[posicion].idMusico=*contadorID;                                                       //campo ID
            arrayMusico[posicion].isEmpty=0;
            utn_getName("\nNombre:\n ","\nError",1,TEXT_SIZE,1,auxNombre);                      //mensaje + cambiar campo nombre
            utn_getName("\nApellido:\n ","\nError",1,TEXT_SIZE,1,auxApellido);
            utn_getUnsignedInt("\nEdad:\n ","\nError",1,sizeof(int),1,100,1,&auxEdad);
            do
            {
                utn_getUnsignedInt("\nIdOrquesta:\n ","\nError",1,sizeof(int),1,1000,1,&auxIdOrquesta);
                if(!orquesta_buscarID(arrayOrquesta, sizeArrayOrquesta, auxIdOrquesta, &posicionOrquesta))
                {
                    arrayMusico[posicion].idOrquesta=auxIdOrquesta;
                    break;
                }
                else
                {
                    reintentosOrq--;
                    printf("No se encontró id de orquesta solicitado %d\nReintentos: %d\n", auxIdOrquesta, reintentosOrq);
                }
            }
            while (reintentosOrq>0);
            if (reintentosOrq>0)
            {
                do
                {
                    utn_getUnsignedInt("\nIdInstrumento:\n ","\nError",1,sizeof(int),1,1000,1,&auxIdInstrumento);
                    if(!instrumento_buscarID(arrayInstrumento, sizeArrayInstrumento, auxIdInstrumento, &posicionInstrumento))
                    {
                        if(arrayInstrumento[posicionInstrumento].tipo==1)
                        {
                            strcpy(tipoInstrumento, "Cuerdas");
                        }
                        else if(arrayInstrumento[posicionInstrumento].tipo==2)
                        {
                            strcpy(tipoInstrumento, "Vientos-madera");
                        }
                        else if(arrayInstrumento[posicionInstrumento].tipo==3)
                        {
                            strcpy(tipoInstrumento, "Vientos-metal");
                        }
                        else if(arrayInstrumento[posicionInstrumento].tipo==4)
                        {
                            strcpy(tipoInstrumento, "Percusión");
                        }
                        arrayMusico[posicion].idInstrumento=auxIdInstrumento;
                        strcpy(arrayMusico[posicion].nombre, auxNombre);
                        strcpy(arrayMusico[posicion].apellido, auxNombre);
                        arrayMusico[posicion].edad=auxEdad;
                        printf("\n ID: %d\n nombre: %s\n apellido: %s, instrumento: %s - %s",
                               arrayMusico[posicion].idMusico,arrayMusico[posicion].nombre,
                               arrayMusico[posicion].apellido, arrayInstrumento[posicionInstrumento].nombre,tipoInstrumento);
                        retorno=0;
                        break;
                    }
                    else
                    {
                        reintentosInstr--;
                        printf("No se encontró id de instrumento solicitado %d\nReintentos: %d\n", auxIdInstrumento, reintentosInstr);
                    }
                }
                while (reintentosInstr>0);
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray, Instrumento arrayInstrumento[], int sizeArrayInstrumento)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray, arrayInstrumento, sizeArrayInstrumento);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo edad
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0; i<sizeArray; i++)
        {
            if(array[i].idOrquesta==valorBuscado)
            {
                array[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s",
                       posicion, array[posicion].idMusico,array[posicion].edad,array[posicion].nombre,array[posicion].apellido);
                utn_getUnsignedInt("\nModificar: 1) Edad 2) Nombre 3) Apellido 4) Salir\n","\nError",1,sizeof(int),1,sizeArray,1,&opcion);
                switch(opcion)
                {
                case 1:
                    utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),1,99,1,&array[posicion].edad);           //mensaje + cambiar campo edad
                    break;
                case 2:
                    utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                    break;
                case 3:
                    utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
                    break;
                case 4:
                    break;
                default:
                    printf("\nOpcion no valida");
                }
            }
            while(opcion!=4);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorApellido(Musico array[],int size)                              //cambiar musico
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferEdad;

    char bufferApellido[TEXT_SIZE];                           //cambiar campo apellido

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idMusico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferEdad=array[i].edad;                                //cambiar campo edad
            strcpy(bufferApellido,array[i].apellido);          //cambiar campo apellido


            j = i - 1;
            while ((j >= 0) && strcmp(bufferApellido,array[j].apellido)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferEdad<array[j].edad
            {
                //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idMusico=array[j].idMusico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edad=array[j].edad;
                array[j + 1].idInstrumento=array[j].idInstrumento;                        //cambiar campo edad
                array[j + 1].idOrquesta=array[j].idOrquesta;                        //cambiar campo edad

                strcpy(array[j + 1].apellido,array[j].apellido);  //cambiar campo apellido

                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);                     //cambiar campo nombre
            array[j + 1].idMusico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edad=bufferEdad;                                                        //cambiar campo edad
            strcpy(array[j + 1].apellido,bufferApellido);                                  //cambiar campo apellido
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size, Instrumento arrayInstrumento[], int sizeArrayInstrumento)                      //cambiar musico
{
    int retorno=-1;
    int i;
    int posicionInstrumento;
    char tipoInstrumento [TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                instrumento_buscarID(arrayInstrumento, sizeArrayInstrumento, array[i].idInstrumento, &posicionInstrumento);
                if(arrayInstrumento[posicionInstrumento].tipo==1)
                {
                    strcpy(tipoInstrumento, "Cuerdas");
                }
                else if(arrayInstrumento[posicionInstrumento].tipo==2)
                {
                    strcpy(tipoInstrumento, "Vientos-madera");
                }
                else if(arrayInstrumento[posicionInstrumento].tipo==3)
                {
                    strcpy(tipoInstrumento, "Vientos-metal");
                }
                else if(arrayInstrumento[posicionInstrumento].tipo==4)
                {
                    strcpy(tipoInstrumento, "Percusión");
                }
                printf("\n ID: %d\n nombre: %s\n apellido: %s, instrumento: %s - %s, orquesta: %d",
                       array[i].idMusico,array[i].nombre,
                       array[i].apellido, arrayInstrumento[posicionInstrumento].nombre,tipoInstrumento,array[i].idOrquesta);
            }
        }
        retorno=0;
    }
    return retorno;
}


