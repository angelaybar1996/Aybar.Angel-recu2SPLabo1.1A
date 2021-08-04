#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Bicicletas.h"
#include "parser.h"
#include "utn.h"

int main()
{
    srand(time(NULL));
    int opcion;
    char path[50];
    char path2[50];
    int nextId=0;
    int flag5=0;
    LinkedList* listaBicicletas = ll_newLinkedList();

    do{
    	if(utn_getNumero(&opcion,
			 "\n---------------------\n"
			 "BICICLETAS\n"
			 "---------------------\n"
			 "\n1. Cargar archivo"
			 "\n2. Imprimir lista"
			 "\n3. Asignar Tiempos"
			 "\n4. Filtrar por tipo"
			 "\n5. Mostrar posiciones"
			 "\n6. Guardar posiones"
			 "\n7. Suma de los tiempos de cada tipo"
			 "\n8. Filtrar por tiempo menor a 100 minutos"
			 "\n9. Ordenar por nombre ascendente"
			 "\n10. Salir\n\n"
			 "Ingrese opcion:",
			 "Opcion no valida",1,10,10)==0)
       {
			switch(opcion)
			{
				case 1:
                    ll_clear(listaBicicletas);
                    printf("\nIngrese nombre del archivo(bicicletas.csv):");
                    fflush(stdin);
                    gets(path);
                    if(!controller_loadFromText(path,listaBicicletas))
                    {
                        buscarMayorId(listaBicicletas,&nextId);
                        printf("\nDatos cargados del archivo texto exitosamente");
                    }
				break;
				case 2:
				    if(ll_len(listaBicicletas)>0 )
					{
						controller_ListBicicletas(listaBicicletas);
					}
					else
					{
						printf("\nPrimero debe cargar un archivo");
					}
			    break;
				case 3:
				    if(!strcmp(path,"bicicletas.csv"))
					{
						if(!controller_asignarTiempos(listaBicicletas))
						{
							printf("\nAsignacion de tiempos exitosa");
							controller_ListBicicletas(listaBicicletas);
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv");
					}
			   break;
				case 4:
				    if(!strcmp(path,"bicicletas.csv"))
					{
						if(!controller_filtrarPorTipo(listaBicicletas))
						{
							printf("\nOpcion finalizada");
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv");
					}
			   break;
				case 5:
					if(!strcmp(path,"bicicletas.csv") && flag5==0 )
					{
						if(!controller_sortBici(listaBicicletas))
						{
							printf("\nOrdenamiento bicicletas exitosa");
							controller_ListBicicletas(listaBicicletas);
							flag5=1;
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv");
					}
			   break;
				case 6:
                    if(!strcmp(path,"bicicletas.csv") && flag5==1)
					{
					    printf("\nIngrese nombre del archivo que desea guardar:");
                        fflush(stdin);
                        gets(path2);
						if(!controller_saveAsText(path2,listaBicicletas))
						{
							printf("\nDatos guardados en archivo de texto exitosamente");
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv y entrar a la opcion 5");
					}
					break;
                case 7:
                    if(!strcmp(path,"bicicletas.csv") )
					{
					    if(!controller_SumaTiemposTipos(listaBicicletas))
                        {
                            printf("Suma realizada con exito!!");
                        }
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv");
					}
					break;
                case 8:
				    if(!strcmp(path,"bicicletas.csv"))
					{
						if(!controller_filtrarPorTiempo(listaBicicletas))
						{
							printf("\nOpcion finalizada");
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv");
					}
			       break;
                case 9:
					if(!strcmp(path,"bicicletas.csv") )
					{
						if(!controller_sortNombres(listaBicicletas))
						{
							printf("\nOrdenamiento bicicletas exitosa");
							controller_ListBicicletas(listaBicicletas);
						}
					}
					else
					{
						printf("\nPrimero debe cargar el archivo bicicletas.csv");
					}
			   break;
			}
       }
    }while(opcion != 10);

     ll_deleteLinkedList(listaBicicletas);

    return 0;
}

