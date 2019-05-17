#ifndef FICHERO_H
#define FICHERO_H

class Fichero
{
    private:
    FILE* f;
    const char * nombre;
    const char * modo;

    public:
    //Constructor por defecto. Se crea archivo "defecto.txt"
    Fichero();

    //Contructor asignando nombre de archivo por parametro
    Fichero(const char *);

    //Contructor asignando nombre y modo por parametro
    Fichero(const char *,const char * );

    //Abre fichero se pasa por parametro el modo de apertura
    void abrir(const char *);

    //Leer
    template<typename T> T leer();

    //Grabar
    template<typename T> void grabar(T);

    //Devuelve true si hay siguiente, false fin de archivo
    bool haySiguiente();

    //Retorna cantidad de registros
    template <typename T> int cantRegistros();

    //Cerrar fichero
    void cerrar();
};

#endif // FICHERO_H
