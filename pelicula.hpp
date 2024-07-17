 #ifndef PELICULA_H
#define PELICULA_H
#include "video.hpp"

class Pelicula : public Video {

private:
    string director;

public:
    Pelicula(string tipo_video, string nombre, string genero, int duracion, float calificacion, string director, int anio_publicacion);
    string get_director();
    void transmitir(string nombre);
    string toString();
};
#endif