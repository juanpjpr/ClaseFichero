#include <iostream>
#include "Fichero.h"


using namespace std;

//Constructor por defecto. Se crea archivo "defecto.txt"
Fichero::Fichero()
{
    f=NULL;
    nombre="defecto.txt";
}

//Contructor asignando nombre de archivo por parametro
Fichero::Fichero(const char * n)
{
    f=NULL;
    nombre=n;
}

//Contructor asignando nombre y modo por parametro
Fichero::Fichero(const char * n,const char * m)
{
    nombre=n;
    modo=m;
    f=fopen(nombre,modo);
}

//Abre fichero se pasa por parametro el modo de apertura
void Fichero::abrir(const char * modo)
{
    f=fopen(nombre,modo);
}

//Leer
template<typename T>
T Fichero::leer()
{
    T dato;
    fread(&dato,sizeof(dato),1,f);
    return dato;
}

//Grabar
template<typename T>
void Fichero::grabar(T dato)
{
    fwrite(&dato,sizeof(dato),1,f);
}

//Devuelve true si hay siguiente, false fin de archivo
bool Fichero::haySiguiente()
{
    return !feof(f);
}

//Retorna cantidad de registros
template <typename T>
int Fichero::cantRegistros()
{
    int cant;
    fseek(f,0,SEEK_END);
    cant= ftell(f)/sizeof(T);
    return cant;
}

//Cerrar fichero
void Fichero::cerrar()
{
    fclose(f);
}


