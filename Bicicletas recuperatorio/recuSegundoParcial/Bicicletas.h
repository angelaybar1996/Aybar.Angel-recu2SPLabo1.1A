#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
#define NOMBRE_TAM 128
#define TIPO_TAM 128
typedef struct
{
    int id;
    char nombre[NOMBRE_TAM];
    char tipo[TIPO_TAM];
    float tiempo;

}eBicicleta;

eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametrosTxt(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);
eBicicleta* bicicleta_newParametros(int id_bike,char* nombre,char* tipo,float tiempo);
void bicicleta_delete(eBicicleta* this);

int bici_setId(eBicicleta* this,int id);
int bici_getId(eBicicleta*this,int* id);
int bici_setIdTxt(eBicicleta* this,char* id);//texto
int bici_getIdTxt(eBicicleta* this,char* id);//texto

int bici_setNombre(eBicicleta* this,char* nombre);
int bici_getNombre(eBicicleta* this,char* nombre);

int bici_setTipo(eBicicleta* this,char* tipo);
int bici_getTipo(eBicicleta* this,char* tipo);

int bici_setTiempo(eBicicleta* this,float tiempo);
int bici_getTiempo(eBicicleta* this,float* tiempo);
int bici_setTiempoTxt(eBicicleta* this,char* tiempo);//texto
int bici_getTiempoTxt(eBicicleta* this,char* tiempo);//texto

int biciCmpTipoTiempo(void* a, void* b);

int filterBmx(void* pElement);
int filterMtb(void* pElement);
int filterPaseo(void* pElement);
int filterPlayera(void* pElement);

void* valorTiempo(void* pElement);

int filterMejores(void* pElement);
int biciCmpNombre(void* a, void* b);


#endif // BICICLETAS_H_INCLUDED
