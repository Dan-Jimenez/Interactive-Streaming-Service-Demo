#include "pelicula.hpp"

Pelicula::Pelicula(string tipo_video, string nombre, string genero, int duracion, float calificacion, string director, int anio_publicacion) 
    : Video(), director(director) {
    this->tipo_video = tipo_video;
    this->nombre = nombre;
    this->genero = genero;
    this->duracion = duracion;
    this->calificacion = calificacion;
    this->anio_publicacion = anio_publicacion;
}

string Pelicula::get_director() {
    return director;
}

void Pelicula::transmitir(string nombre) {
    cout << "Transmitiendo Pelicula: " << nombre << endl;
}

string Pelicula::toString() {
    return "Director: " + director;
}