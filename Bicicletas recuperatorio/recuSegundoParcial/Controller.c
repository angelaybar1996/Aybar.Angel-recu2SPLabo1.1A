#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "parser.h"

/**\brief Carga los datos de las bicicletas desde el archivo bicicletas.csv (modo texto).
 * \param path char* es el nombre del archivo
 * \param pArrayListBici LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBici)
{

	int retorno=-1;
	FILE* fpArchivo;
	char auxNombre[NOMBRE_TAM];
	char auxTipo[100];
	char auxId[100];
	char auxTiempo[100];
	char confirma;

	if(pArrayListBici!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"r");
		if(fpArchivo==NULL)
        {
            printf("\nEl archivo no existe");
        }
		else
		{
		    retorno=0;
		    if(ll_len(pArrayListBici)>0)//si hay elementos
            {
                printf("\nCuidado se van a sobreescribir las bicicletas.Confirma?(s / n):");
                fflush(stdin);
                scanf("%c",&confirma);
            }
            if(ll_len(pArrayListBici)==0 || confirma=='s')
            {
                ll_clear(pArrayListBici);
                parser_BiciFromText(fpArchivo, pArrayListBici, auxId, auxNombre, auxTipo, auxTiempo);
            }
		}
		fclose(fpArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los paises desde el archivo data.bin (modo binario).
 * \param path char* es el nombre del archivo
 * \param pArrayListPais LinkedList* el puntero de array de paises
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
 /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListPais)
{
	int retorno=-1;
	FILE* fpArchivo;
	ePais* auxPais=NULL;
	char confirma;

	if(pArrayListPais!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"rb");

		if(fpArchivo==NULL)
		{
		    printf("\nEl archivo no existe);
		}
		else
        {
            retorno=0;
            if(ll_len(pArrayListPais)>0)
            {
                printf("\nCuidado se van a sobreescribir las bicicletas.Confirma?(s / n):");
                fflush(stdin);
                scanf("%c",&confirma);
            }

            if(ll_len(pArrayListPais)==0 || confirma=='s')
            {
              ll_clear(pArrayListBici);
              parser_PaisFromBinary(fpArchivo,pArrayListPais,auxPais);
            }
        }
		fclose(fpArchivo);
	}
	return retorno;
}
*/

/** \brief Listar bicicletas
 *
 * \param pArrayListBici LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_ListBicicletas(LinkedList* pArrayListBici)
{
	int retorno=-1;
	int i;
	eBicicleta* auxBici;
	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxTipo[TIPO_TAM];
	float auxTiempo;

	if(pArrayListBici!=NULL)
	{
		printf("\n----------LISTA BICICLETAS-------------\n");
		for(i=0;i<ll_len(pArrayListBici);i++)
		{
			auxBici=(eBicicleta*)ll_get(pArrayListBici, i);

			if(!bici_getId(auxBici,&auxId) &&
			   !bici_getNombre(auxBici,auxNombre) &&
			   !bici_getTipo(auxBici,auxTipo) &&
			   !bici_getTiempo(auxBici,&auxTiempo))
			{
				printf("ID: %d - Nombre: %s - Tipo: %s - Tiempo: %.2f\n",auxId,auxNombre,auxTipo,auxTiempo);
			}
		}
		retorno=0;
	}

	return retorno;
}

/** \brief Ordenar las bicicletas por tipos y si es del mismo tipo por tiempo
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_sortBici(LinkedList* pArrayListBici)
{
    int retorno=-1;
    if(pArrayListBici!=NULL)
    {
        ll_sort(pArrayListBici, biciCmpTipoTiempo, 1);//ascendente

    	retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los bicicletas en el archivo data.csv (modo texto).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBici)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	eBicicleta* auxBicicleta;

	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxTipo[TIPO_TAM];
	float auxTiempo;
	char confirma='s';


	if(pArrayListBici!=NULL && path!=NULL)
	{
	    fpArchivo=fopen(path,"r");//lo utilizo para ver si el archivo existe
        if(fpArchivo!=NULL)
        {
           printf("\nCuidado el archivo existe y se va a sobrescribir.Confirma (s / n)?:");
           fflush(stdin);
           scanf("%c",&confirma);
        }
        fclose(fpArchivo);

        if(confirma=='s')
        {
            fpArchivo=fopen(path,"w");
            if(fpArchivo!=NULL)
            {
                retorno=0;
                for(i=0;i<ll_len(pArrayListBici);i++)
                {
                    auxBicicleta=(eBicicleta*)ll_get(pArrayListBici,i);

                    if(!bici_getId(auxBicicleta,&auxId) &&
                       !bici_getNombre(auxBicicleta, auxNombre) &&
                       !bici_getTipo(auxBicicleta,auxTipo) &&
                       !bici_getTiempo(auxBicicleta, & auxTiempo))
                    {
                        fprintf(fpArchivo,"%d,%s,%s,%f\n",auxId,auxNombre,auxTipo,auxTiempo);
                    }
                }
                fclose(fpArchivo);
            }
        }
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;
	Employee* auxEmpleado;
	char confirma='s';


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
	   fpArchivo=fopen(path,"rb");
	   if(fpArchivo !=NULL)
       {
			printf("\nCuidado el archivo existe y se va a sobrescribir.Confirma (s / n)?:");
            fflush(stdin);
            scanf("%c",&confirma);
       }
       fclose(fpArchivo);

       if(confirma='s')
       {
          fpArchivo=fopen(path,"wb");
          if(fpArchivo!=NULL)
          {
                retorno=0;
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                    fwrite(auxEmpleado,sizeof(Employee),1,fpArchivo);
                }
          }
          fclose(fpArchivo);
       }
	}
	return retorno;
}
*/

/** \brief Busca el id mas grande del pArrayListBici previamente cargado de un archivo
 *  y le suma 1 para que el siguiente id dado de alta sea continuo
 *
 * \param pArrayListBici LinkedList*  el puntero de array de bicicletas
 * \param id, es el id actual a ser actualizado
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int buscarMayorId(LinkedList* pArrayListBici,int* id)
{
    int retorno=-1;
    eBicicleta* auxBici=NULL;
    int mayor;
    if(pArrayListBici!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListBici);i++)
        {
            auxBici=(eBicicleta*)ll_get(pArrayListBici,i);
            if(i==0 || auxBici->id > mayor)
            {
                bici_getId(auxBici, &mayor);
            }
        }
        *id=mayor+1;

        retorno=0;
    }
    return retorno;
}

/** \brief Recibe el linkedlist original y filtra por tipo de bicicleta y crea un nuevo archivo segun tipo
 *
 * \param pArrayListBici LinkedList* puntero linkedList de la lista de bicicletas
 * \return retorna 0(EXITO) -1(ERROR)
 *
 */
int controller_filtrarPorTipo(LinkedList* pArrayListBici)
{
    int opcion;
    LinkedList* bmx=ll_newLinkedList();
    LinkedList* mtb=ll_newLinkedList();
    LinkedList* paseo=ll_newLinkedList();
    LinkedList* playera=ll_newLinkedList();
    int retorno=-1;
    if(pArrayListBici!=NULL)
    {
        do{
            if(utn_getNumero(&opcion,
                 "\n---------------------\n"
                 "FILTRAR POR TIPO\n"
                 "---------------------\n"
                 "\n1. BMX"
                 "\n2. MTB"
                 "\n3. PASEO"
                 "\n4. PLAYERA"
                 "\n5. Salir\n\n"
                 "Ingrese opcion:",
                 "Opcion no valida",1,5,3)==0)
           {
                switch(opcion)
                {
                    case 1:
                        bmx=ll_filter(pArrayListBici,filterBmx);
                        if(!controller_saveAsText("bmx.csv",bmx))
                        {
                            printf("Archivo  bmx.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(bmx);
                    break;
                   case 2:
                        mtb=ll_filter(pArrayListBici,filterMtb);
                        if(!controller_saveAsText("mtb.csv",mtb))
                        {
                            printf("Archivo  mtb.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(mtb);
                    break;
                    case 3:
                        paseo=ll_filter(pArrayListBici,filterPaseo);
                        if(!controller_saveAsText("paseo.csv",paseo))
                        {
                            printf("Archivo  paseo.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(paseo);
                   break;
                    case 4:
                        playera=ll_filter(pArrayListBici,filterPlayera);
                        if(!controller_saveAsText("playera.csv",playera))
                        {
                            printf("Archivo  playera.csv generado con exito\n");
                        }
                        ll_deleteLinkedList(playera);
                   break;
                }
           }
        }while(opcion != 5);
         retorno=0;
    }
    return retorno;
}

/** \brief Recibe el LinkedList y le asigna tiempos aleatorios a sus elementos
 *
 * \param pArrayBici LinkedList* puntero LinkedList
 * \return  Retorna -1(ERROR) 0 (EXITO)
 *
 */
int controller_asignarTiempos(LinkedList* pArrayBici)
{
    int retorno=-1;
    LinkedList* nuevoLinkedList=ll_newLinkedList();

    if(pArrayBici!=NULL)
    {
        nuevoLinkedList=ll_map(pArrayBici,valorTiempo);
        pArrayBici=nuevoLinkedList;
        retorno=0;
    }

    return retorno;
}

int controller_SumaTiemposTipos(LinkedList* pArrayBici)
{

    int retorno=-1;
    int tam;
    eBicicleta* auxB;
    float sumaBmx=0;
    float sumaMtb=0;
    float sumaPaseo=0;
    float sumaPlayera=0;

    if(pArrayBici!=NULL)
    {
        tam=ll_len(pArrayBici);
        for(int i=0;i<tam;i++)
        {
            auxB=ll_get(pArrayBici,i);
            if(!strcmp(auxB->tipo,"BMX"))
            {
               sumaBmx=sumaBmx+auxB->tiempo;
            }
            else if(!strcmp(auxB->tipo,"MTB"))
            {
                sumaMtb=sumaMtb+auxB->tiempo;
            }
            else if(!strcmp(auxB->tipo,"PASEO"))
            {
                sumaPaseo=sumaPaseo+auxB->tiempo;
            }
            else if(!strcmp(auxB->tipo,"PLAYERA"))
            {
                sumaPlayera=sumaPlayera+auxB->tiempo;
            }
        }
        printf("\nLa suma de todos los tiempos de cada tipo es:");
        printf("\nBMX: %.2f\nMTB:%.2f\nPASEO:%.2f\nPLAYERA:%.2f\n",sumaBmx,sumaMtb,sumaPaseo,sumaPlayera);
        retorno=0;

    }
    return retorno;
}

int controller_filtrarPorTiempo(LinkedList* pArrayListBici)
{
    LinkedList* mejoresTiempos=ll_newLinkedList();
    int retorno=-1;
    if(pArrayListBici!=NULL)
    {
        mejoresTiempos=ll_filter(pArrayListBici,filterMejores);
        if(!controller_saveAsText("mejores.csv",mejoresTiempos))
        {
            printf("Archivo  mejores.csv generado con exito\n");
        }
        ll_deleteLinkedList(mejoresTiempos);

         retorno=0;
    }
    return retorno;
}

/** \brief Ordena por nombre ascendente la lista de bicicletas
 *
 * \param pArrayListBici LinkedList* puntero LinkedList de la lista de bicicletas
 * \return retorno -1(ERROR) 0 (EXITO)
 *
 */
int controller_sortNombres(LinkedList* pArrayListBici)
{
    int retorno=-1;
    if(pArrayListBici!=NULL)
    {
        ll_sort(pArrayListBici, biciCmpNombre, 1);//ascendente

    	retorno=0;
    }
    return retorno;
}


