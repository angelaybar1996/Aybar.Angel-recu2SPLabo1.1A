#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"

int parser_BiciFromText(FILE* pFile , LinkedList* pArrayListBici,char auxId[],char auxNombre[],char auxTipo[],char auxTiempo[]);
int parser_BiciFromBinary(FILE* pFile , LinkedList* pArrayListBici,eBicicleta* auxBici);

#endif /* PARSER_H_ */
