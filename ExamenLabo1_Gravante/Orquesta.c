#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_funciones.h"
#include "Orquesta.h"
#include "Musico.h"



/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)                                                   //cambiar campo ID
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
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
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)                          //cambiar orquesta
{
    int retorno=-1;
    int bufferTipo;
    char tipoOrquesta [TEXT_SIZE]="";
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)                          //cambiar orquesta
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquesta=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nTipo de Orquesta: 1) Sinfónica 2) Filarmónica 3) Cámara\n",
                        "\nError",1,sizeof(int),1,3,2,&bufferTipo);
            switch(bufferTipo)
            {
                case 1:
                    strcpy(tipoOrquesta, "Sinfónica");
                    break;
                case 2:
                    strcpy(tipoOrquesta, "Filarmónica");
                    break;
                case 3:
                    strcpy(tipoOrquesta, "Cámara");
                    break;
                default:
                    printf("Error");
                    return retorno;
            }
            array[posicion].tipo=bufferTipo;
            utn_getName("Nombre:\n ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getName("Ubicación:\n ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);
            /*printf("\n Posicion: %d\n ID: %d\n tipo: %s\n nombre: %s\n lugar: %s",
                posicion, array[posicion].idOrquesta,tipoOrquesta,array[posicion].nombre,array[posicion].lugar);*/
                retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta arrayOrquesta[], int sizeArrayOrquesta, Musico arrayMusico[], int sizeArrayMusico)
{
    int retorno=-1;
    int posicion;
    int idOrquesta;
    if(arrayOrquesta!=NULL && sizeArrayOrquesta>0)
    {
        orquesta_listar(arrayOrquesta, sizeArrayOrquesta);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArrayOrquesta,1,&idOrquesta);
        if(orquesta_buscarID(arrayOrquesta,sizeArrayOrquesta,idOrquesta,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            musico_bajaValorRepetidoInt(arrayMusico,sizeArrayMusico,idOrquesta);
            arrayOrquesta[posicion].isEmpty=1;

            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idOrquesta=0;                                                                   //cambiar campo id
                array[i].tipo=0;                                                               //cambiar campo tipo
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].lugar,"");                                               //cambiar campo lugar
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orquesta_modificar(Orquesta array[], int sizeArray)                                //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s\n lugar: %s",
                       posicion, array[posicion].idOrquesta,array[posicion].tipo,array[posicion].nombre,array[posicion].lugar);
                utn_getChar("\nModificar: A B C S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].tipo);           //mensaje + cambiar campo tipo
                        break;
                    case 'B':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar);             //mensaje + cambiar campo lugar
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorString(Orquesta array[],int size)                              //cambiar orquesta
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferTipo;                                              //cambiar buffer int
    char bufferLugar[TEXT_SIZE];                           //cambiar campo lugar

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferNombre,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idOrquesta;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferTipo=array[i].tipo;                                //cambiar campo tipo
            strcpy(bufferLugar,array[i].lugar);          //cambiar campo lugar


            j = i - 1;
            while ((j >= 0) && strcmp(bufferNombre,array[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferTipo<array[j].tipo
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idOrquesta=array[j].idOrquesta;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].tipo=array[j].tipo;                        //cambiar campo tipo
                strcpy(array[j + 1].lugar,array[j].lugar);  //cambiar campo lugar

                j--;
            }
            strcpy(array[j + 1].nombre,bufferNombre);                     //cambiar campo nombre
            array[j + 1].idOrquesta=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].tipo=bufferTipo;                                                        //cambiar campo tipo
            strcpy(array[j + 1].lugar,bufferLugar);                                  //cambiar campo lugar
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n tipo: %d\n nombre: %s\n lugar: %s",
                       array[i].idOrquesta,array[i].tipo,array[i].nombre,array[i].lugar);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


