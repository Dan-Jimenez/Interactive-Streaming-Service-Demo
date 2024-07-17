#include "serie.hpp"

Serie::Serie(string tipo_video, string nombre, string genero, int duracion, float calificacion, int num_episodios, int anio_publicacion)
    : Video(), num_episodios(num_episodios) {
    this->tipo_video = tipo_video;
    this->nombre = nombre;
    this->genero = genero;
    this->duracion = duracion;
    this->calificacion = calificacion;
    this->anio_publicacion = anio_publicacion;
}

int Serie::get_episodios() {
    return num_episodios;
}

void Serie::transmitir(string nombre) {
    cout << "Transmitiendo Serie: " << nombre << endl;
}

string Serie::toString() {
    return "Número de episodios: " + to_string(num_episodios);
}