#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Bicicletas.h"

static int isValidId(char* cadena);
static int isValidNombre(char* nombre,int longitud);
static int isValidTipo(char* nombre,int longitud);
static int isValidTiempo(char* cadena);


/**
 * brief construye una bicicleta en memoria
 * return retorna el puntero a la bicicleta creado
 */
eBicicleta* bicicleta_new()
{
	eBicicleta* auxiliarB;
	auxiliarB=(eBicicleta*)malloc(sizeof(eBicicleta));
	return auxiliarB;
}

/**
 * brief carga los datos ingresados por parametros en un puntero bicicleta
 * param idStr, id a cargar en el puntero bicicleta
 * param nombreStr,nombre a cargar en el puntero bicicleta
 * param tipoStr,tipo a cargar en el puntero bicicleta
 * param tiempoStr, tiempo a cargar en el puntero bicicleta
 * return retorno el puntero de bicicleta cargado
 */
eBicicleta* bicicleta_newParametrosTxt(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
	eBicicleta* punteroBici;
	punteroBici=bicicleta_new();

		if(punteroBici!=NULL && idStr!=NULL && nombreStr !=NULL && tipoStr != NULL && tiempoStr != NULL )
		{
			if(bici_setIdTxt(punteroBici,idStr)==-1 ||
			   bici_setNombre(punteroBici, nombreStr)==-1 ||
			   bici_setTipo(punteroBici, tipoStr)==-1 ||
			   bici_setTiempoTxt(punteroBici, tiempoStr)==-1)
			 {
				bicicleta_delete(punteroBici);
				punteroBici=NULL;
			 }

		}
		return punteroBici;
}

/**
 * brief carga los datos ingresados por parametros en un puntero bicicleta
 * param id, id a cargar en el puntero bicicleta
 * param nombre,nombre a cargar en el puntero bicicleta
 * param tipo,tipo a cargar en el puntero bicicleta
 * param tiempo, tiempo a cargar en el puntero bicicleta
 * return retorno el puntero de bicicleta cargado
 */
eBicicleta* bicicleta_newParametros(int id,char* nombre,char* tipo,float tiempo)
{
	eBicicleta* punteroBici;
	punteroBici=bicicleta_new();

	if(punteroBici!=NULL && id>=0 && nombre!=NULL && tipo!=NULL && tiempo>=0 )
	{
		if(bici_setId(punteroBici,id)==-1 ||
		   bici_setNombre(punteroBici, nombre)==-1 ||
		   bici_setTipo(punteroBici, tipo)==-1 ||
		   bici_setTiempo(punteroBici, tiempo)==-1)
		 {
			bicicleta_delete(punteroBici);
			punteroBici=NULL;
		 }
	}
	return punteroBici;
}

/**
 * brief libera una bicicleta de la memoria
 */
void bicicleta_delete(eBicicleta* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

/**
 * brief recibe un id  lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param id, es el id a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_setId(eBicicleta* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

/**
 * brief le asigna el valor del id del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param id,puntero cargado con el valor del id del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_getId(eBicicleta*this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
	   *id=this->id;
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un id en texto lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param id, es el id a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_setIdTxt(eBicicleta* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		if(isValidId(id))
		{
			this->id=atoi(id);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del id del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param id,puntero cargado con el valor del id del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_getIdTxt(eBicicleta* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
       sprintf(id,"%d",this->id);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un nombre lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param nombre, es el nombre a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_setNombre(eBicicleta* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(isValidNombre(nombre,NOMBRE_TAM))
		{
			strcpy(this->nombre,nombre);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del nombre del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param nombre,puntero cargado con el valor del nombre del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_getNombre(eBicicleta* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un tipo lo verifica y lo cargar en el punteroBici
 * param this, es un punteroBici
 * param tipo, es el tipo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_setTipo(eBicicleta* this,char* tipo)
{
	int retorno=-1;
	if(this!=NULL && tipo!=NULL)
	{
		if(isValidTipo(tipo,NOMBRE_TAM))
		{
			strcpy(this->tipo,tipo);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del tipo del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param tipo,puntero cargado con el valor del tipo del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_getTipo(eBicicleta* this,char* tipo)
{
	int retorno=-1;
	if(this!=NULL && tipo!=NULL)
	{
		strcpy(tipo,this->tipo);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un tiempo,lo verifica y lo cargar en el PunteroBici
 * param this, es un PunteroBici
 * param tiempo, es el tiempo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_setTiempo(eBicicleta* this,float tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo>=0)
	{
		retorno=0;
		this->tiempo=tiempo;
	}
	return retorno;
}

/**
 * brief le asigna el valor del tiempo del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param tiempo,puntero cargado con el valor del tiempo del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_getTiempo(eBicicleta* this,float* tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo!=NULL)
	{
	   retorno=0;
	  *tiempo=this->tiempo;
	}
	return retorno;
}

/**
 * brief recibe un tiempo en texto,lo verifica y lo carga en el PunteroBici
 * param this, es un PunteroBici
 * param tiempo, es el tiempo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_setTiempoTxt(eBicicleta* this,char* tiempo)
{
	int retorno=-1;
	float auxTiempo;
	if(this!=NULL && tiempo!=NULL)
	{
		if(isValidTiempo(tiempo))
		{
			auxTiempo= atof(tiempo);
			if(auxTiempo>=0)
			{
				this->tiempo=auxTiempo;
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del tiempo del punteroBici a otra variable recibida por parametro
 * param this, es un punteroBici
 * param tiempo,puntero cargado con el valor del tiempo del PunteroBici
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int bici_getTiempoTxt(eBicicleta* this,char* tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo!=NULL)
	{
	   sprintf(tiempo,"%f",this->tiempo);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Verifica si el nombre ingresado es un nombre valido
 * \param nombre Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
static int isValidNombre(char* nombre,int longitud)
{
	int i=0;
	int retorno = 1;

	if(nombre != NULL && longitud > 0)
	{
		for(i=0 ; nombre[i] != '\0' && i < longitud; i++)
		{
			if((nombre[i] < 'A' || nombre[i] > 'Z' ) && (nombre[i] < 'a' || nombre[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si el tipo ingresado es un tipo valido
 * \param nombre Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
static int isValidTipo(char* nombre,int longitud)
{
	int i=0;
	int retorno = 1;

	if(nombre != NULL && longitud > 0)
	{
		for(i=0 ; nombre[i] != '\0' && i < longitud; i++)
		{
			if((nombre[i] < 'A' || nombre[i] > 'Z' ) && (nombre[i] < 'a' || nombre[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es numerica entera
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidId(char* cadena)
{
	int retorno=1;
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

/**
 *\brief verifica si la cadena ingresada es flotante
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidTiempo(char* cadena)
{
	int retorno=1;
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

/** \brief Determina el orden del tipo
 *
 * \param a void* puntero a castear para que sea puntero eBicicleta
 * \param b void* puntero a castear para que sea puntero eBicicleta
 * \return retorna 0 si son iguales,1 si a>b y -1 si a<b
 *
 */
int biciCmpTipoTiempo(void* a, void* b)
{
    int retorno=0;
    eBicicleta* bici1;
    eBicicleta* bici2;
    if(a!=NULL && b!=NULL)
    {
       bici1=(eBicicleta*)a;//casteo
       bici2=(eBicicleta*)b;//casteo

       if(strcmp(bici1->tipo,bici2->tipo) > 0)
        {
            retorno = 1;
        }
        else if(strcmp(bici1->tipo,bici2->tipo) < 0)
        {
            retorno = -1;
        }
        else if(strcmp(bici1->tipo,bici2->tipo) == 0)
        {
            if(bici1->tiempo > bici2->tiempo)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

/** \brief Compara los elementos que tengan el mismo nombre
 *
 * \param pElement void* puntero al elemento a comparar
 * \return retorna 1 si son iguales 0 sino
 *
 */
int filterBmx(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eBicicleta*)pElement)->tipo,"BMX"))
     {
         retorno=1;
     }
     return retorno;
 }

 /** \brief Compara los elementos que tengan el mismo nombre
  *
  * \param pElement void* puntero al elemento a comparar
  * \return retorna 1 si son iguales 0 sino
  *
  */
 int filterMtb(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eBicicleta*)pElement)->tipo,"MTB"))
     {
         retorno=1;
     }
     return retorno;
 }

 /** \brief Compara los elementos que tengan el mismo nombre
  *
  * \param pElement void* puntero al elemento a comparar
  * \return retorna 1 si son iguales 0 sino
  *
  */
 int filterPaseo(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eBicicleta*)pElement)->tipo,"PASEO"))
     {
         retorno=1;
     }
     return retorno;
 }

 /** \brief Compara los elementos que tengan el mismo nombre
  *
  * \param pElement void* puntero al elemento a comparar
  * \return retorna 1 si son iguales 0 sino
  *
  */
 int filterPlayera(void* pElement)
 {
     int retorno=0;
     if(!strcmp(((eBicicleta*)pElement)->tipo,"PLAYERA"))
     {
         retorno=1;
     }
     return retorno;
 }

 /** \brief Asigna un tiempo aleatorio al elemento
  *
  * \param pElement void* puntero al elemento al cual se le va a cargar un tiempo aleatorio
  * \return Retorna el puntero al elemento con el tiempo aleatorio cargado
  *
  */
 void* valorTiempo(void* pElement)
 {
    int numero;
    int max=120;
    int min=50;

    numero= rand() % (max - min +1 ) + min;
    ((eBicicleta*)pElement)->tiempo= numero;

    return pElement;
 }


int filterMejores(void* pElement)
{
     int retorno=0;
     if(((eBicicleta*)pElement)->tiempo < 100)
     {
         retorno=1;
     }
  return retorno;
}

/** \brief Determina el orden del nombre
 *
 * \param a void* puntero a castear para que sea puntero eBicicleta
 * \param b void* puntero a castear para que sea puntero eBicicleta
 * \return retorna 0 si son iguales,1 si a>b y menor a 0 si a<b
 *
 */
int biciCmpNombre(void* a, void* b)
{
    int retorno=0;
    eBicicleta* bici1;
    eBicicleta* bici2;
    if(a!=NULL && b!=NULL)
    {
       bici1=(eBicicleta*)a;
       bici2=(eBicicleta*)b;

       retorno=strcmp(bici1->nombre,bici2->nombre);
    }
    return retorno;
}

