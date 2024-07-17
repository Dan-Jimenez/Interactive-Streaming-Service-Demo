#ifndef SERIE_H
#define SERIE_H
#include "video.hpp"

class Serie : public Video{

private:
    int num_episodios;

public:
    Serie(string tipo_video, string nombre, string genero, int duracion, float calificacion, int num_episodios, int anio_publicacion);
    int get_episodios();
    void transmitir(string nombre);
    string toString();
};
#endif