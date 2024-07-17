#include "video.hpp"

Video::Video() {
    tipo_video = "";
    nombre = "";
    genero = "";
    duracion = 0;
    calificacion = 0;
    anio_publicacion = 0;
}

string Video::get_tipo_video() {
    return tipo_video;
}

string Video::get_nombre() {
    return nombre;
}

int Video::get_duracion() {
    return duracion;
}

string Video::get_genero() {
    return genero;
}

float Video::get_calificacion() {
    return calificacion;
}

void Video::set_calificacion(float calificacion) {
    this->calificacion = calificacion;
}

int Video::get_anio_publicacion() {
    return anio_publicacion;
}

bool operator>(const Video& calif1, const Video& calif2) {
    return calif1.calificacion > calif2.calificacion;
}