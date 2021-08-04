
#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo, int reintentos);
int utn_getCadena(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getTexto(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int utn_getTelefono(char* pResultado,int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_H_ */
