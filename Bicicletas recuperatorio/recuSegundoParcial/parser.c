#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Parsea los datos de las bicicletas desde el archivo data.csv (modo texto).
 *
 * \param pFile, puntero del archivo que se va a cargar en el linkedList
 * \param pArrayListBici puntero de la lista de bicicletas
 * \param auxId es el buffer donde se va a cargar en un principio el id obtenido del archivo
 * \param auxNombre es el buffer donde se va a cargar en un principio el nombre obtenido del archivo
 * \param auxTipo es el buffer donde se va a cargar en un principio las horas obtenido del archivo
 * \param auxTiempo es el buffer donde se va a cargar en un principio el sueldo obtenido del archivo
 * \return retorno -1(ERROR) 0 (EXITO)
 *
 */
int parser_BiciFromText(FILE* pFile , LinkedList* pArrayListBici,char auxId[],char auxNombre[],char auxTipo[],char auxTiempo[])
{

	eBicicleta* auxBici;
	int retorno=-1;

	do
	{
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxTipo,auxTiempo)==4)
		{
			auxBici= bicicleta_newParametrosTxt(auxId, auxNombre, auxTipo, auxTiempo);
			if(auxBici!=NULL)
			{
				ll_add(pArrayListBici, auxBici);
			}
		}

	}while(!feof(pFile));
	retorno=0;

    return retorno;
}

/** \brief Parsea los datos de las bicicletas desde el archivo data.bin (modo binario).
 *
 * \param param pFile, puntero del archivo que se va a cargar en el linkedList
 * \param pArrayListBici puntero de la lista de paises
 * \param auxBici,puntero bicicleta donde se cargan los datos del archivo en un principio
 * \return retorno -1(ERROR) 0 (EXITO)
 *
 */
int parser_BiciFromBinary(FILE* pFile , LinkedList* pArrayListBici,eBicicleta* auxBici)
{
	int cant;
	int retorno=-1;

	do
	{
		auxBici=bicicleta_new();

		if(auxBici!=NULL)
		{
			cant = fread(auxBici,sizeof(eBicicleta),1,pFile);
			if(cant<1)
			{
				break;
			}
			else
			{
				ll_add(pArrayListBici, auxBici);
			}
		}

	}while(!feof(pFile));
	retorno=0;

    return retorno;
}



