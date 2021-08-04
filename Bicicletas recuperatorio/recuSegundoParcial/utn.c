#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//numeros enteros
static int getInt(int* pResultado);
static int esNumerica(char* cadena);
//numeros flotantes
static int getFloat(float* pResultado);
static int esFlotante(char* cadena);
//cadena
static int getCadena(char* pResultado,int longitud);
static int esCadena(char* cadena,int longitud);
//texto
static int getTexto(char* pResultado, int longitud);
static int esTexto(char* cadena,int longitud);
//telefono
static int getTelefono(char* pResultado, int longitud);
static int esTelefono(char* cadena,int longitud);




/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)//seria el antiguo myGets
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 *\brief solicita un numero al usuario, luego de verificarlo devuelve una respuesta
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param mensaje, es el mensaje a ser mostrado
 *\param mensajeError, es el mensaje de error a ser mostrado cuando sea necesario
 *\param minimo, es el numero minimo a ser aceptado
 *\param maximo, es el numero maximo a ser aceptado
 *\param reintentos, es la cantidad de oportunidades que tiene el usuario de operar
 *\return retorna 0 si es un numero y  retorna -1 si no lo es
 */
int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno=-1;
	int buffer;

	if(pResultado!=  NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);

			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);

		}while(reintentos>=0);
	}
	return retorno;
}
/**
 *\brief verifica si la cadena ingresada es entera
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0(Exito) y -1 (Error)
 */
static int getInt(int* pResultado)
{
	int retorno;
	retorno=-1;
	char buffer[4096];

	if(getString(buffer,sizeof(buffer))==0 && esNumerica (buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es numerica entera
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna -1 si es verdadera y 0 si es falsa
 */
static int esNumerica(char* cadena)
{
	int retorno=-1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i] >'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

//NUMEROS FLOTANTES
/**
 *\brief solicita un numero al usuario, luego de verificarlo devuelve una respuesta
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param mensaje, es el mensaje a ser mostrado
 *\param mensajeError, es el mensaje de error a ser mostrado cuando sea necesario
 *\param minimo, es el numero minimo a ser aceptado
 *\param maximo, es el numero maximo a ser aceptado
 *\param reintentos, es la cantidad de oportunidades que tiene el usuario de operar
 *\return retorna 0 si es un numero y  retorna -1 si no lo es
 */
int utn_getNumeroFlotante(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo, int reintentos)
{
	int retorno;
	retorno=-1;
	float buffer;

	if(pResultado!=  NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);

		}while(reintentos>=0);
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es flotante
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0(Exito) y -1 (Error)
 */
static int getFloat(float* pResultado)
{
	int retorno;
	retorno=-1;
	char buffer[4096];

	if(getString(buffer,sizeof(buffer))==0 && esFlotante (buffer))
	{
		retorno=0;
		*pResultado=atof(buffer);
	}
	return retorno;
}


/**
 *\brief verifica si la cadena ingresada es flotante
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna -1 si es verdadera y 0 si es falsa
 */
static int esFlotante(char* cadena)
{
	int retorno=-1;
	int i=0;
	int contadorPuntos=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i] >'9')
			{
				if(cadena[i]=='.' && contadorPuntos==0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno=0;
				    break;
				}
			}
		}
	}
	return retorno;
}
//CADENA
/**
 * \brief Solicita una cadena al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getCadena(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como cadena
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getCadena(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esCadena(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una cadena valido
 * \param cadena Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esCadena(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//TEXTO
/**
 * \brief Solicita un texto al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el texto y -1 si no
 *
 */
int utn_getTexto(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getTexto(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como texto
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \return Retorna 0 (EXITO) si se obtiene un texto y -1 (ERROR) si no
 *
 */
static int getTexto(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL && longitud>0)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esTexto(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un texto valida
 * \param cadena Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esTexto(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) &&
              (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) &&  cadena[i] != '@')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//CARACTER
/**
 * \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param reintentos Es la cantidad de reintentos para hacerlo
 * \return Retorna 0 si se obtuvo el caracter y -1 si no
 */
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno=-1;
	char auxiliar;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>0 )
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&auxiliar);

            if(auxiliar=='m' || auxiliar=='f'|| auxiliar=='F' || auxiliar=='M')
            {
                *pResultado=auxiliar;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }

        }while(reintentos>=0);
    }
	return retorno;
}

/**
 *\brief solicita un telefono al usuario, luego de verificarlo devuelve una respuesta
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param longitud, limite del array a ser analizado
 *\param mensaje, es el mensaje a ser mostrado
 *\param mensajeError, es el mensaje de error a ser mostrado cuando sea necesario
 *\param reintentos, es la cantidad de oportunidades que tiene el usuario de operar
 *\return retorna 0 si es un telefono, retorna -1 si no lo es
 */
int utn_getTelefono(char* pResultado,int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getTelefono(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/**
 *\brief verifica si la cadena ingresada es Telefono
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param longitud, Limite del array a ser analizado
 *\return retorna 0(Exito) y -1 (Error)
 */
static int getTelefono(char* pResultado, int longitud)
{
	int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esTelefono(buffer,sizeof(buffer))==0 &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es un telefono
 * \param cadena Array con la cadena a ser analizada
 * \param longitud Limite del array a ser analizado
 * \return 0 [EXITO] -1 [ERROR]
 */

static int esTelefono(char* cadena,int longitud)
{
	int i=0;
	int retorno = -1;
	int contadorGuiones=0;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < '0' || cadena[i] > '9' ) && (cadena[i] != ' ' && cadena[i] != '-' ))
			{
				retorno = -1;
				break;
			}
			if(cadena[i] == '-')
            {
                contadorGuiones++;
            }
		}
		if(contadorGuiones==1)// debe tener un guion
       {
           retorno=0;
       }
	}
	return retorno;
}



