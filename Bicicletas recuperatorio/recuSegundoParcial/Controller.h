#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Bicicletas.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBici);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListPais);
int controller_ListBicicletas(LinkedList* pArrayListBici);
int controller_sortBici(LinkedList* pArrayListBici);
int controller_saveAsText(char* path , LinkedList* pArrayListPais);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListPais);

int buscarMayorId(LinkedList* pArrayListBici,int* id);

int controller_filtrarPorTipo(LinkedList* pArrayListBici);
int controller_asignarTiempos(LinkedList* pArrayBici);

int controller_SumaTiemposTipos(LinkedList* pArrayBici);
int controller_filtrarPorTiempo(LinkedList* pArrayListBici);
int controller_sortNombres(LinkedList* pArrayListBici);

#endif /* CONTROLLER_H_ */







