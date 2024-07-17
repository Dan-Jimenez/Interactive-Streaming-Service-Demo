#ifndef CINE_H
#define CINE_H

#include "video.hpp"
#include <vector>

class Cine {
private:
    vector <Video*> cartelera;

public:
    Cine();
    void cargar_cartelera();
    void mostrar_cartelera();
    void mostrar_videos_por_calificacion(float calificacion);
    void mostrar_videos_por_genero(string genero);
    void mostrar_serie_por_calificacion(float calificacion);
    void mostrar_pelicula_por_calificacion(float calificacion);
    void mostrar_pelicula_o_serie_por_anio_publicacion(string tipo_video, int anio_publicacion);
    Video* pelicula_con_mayor_calificacion();
    Video* serie_con_mayor_calificacion();
    void transmitir_video(string nombre);
    void calificar_video(string nombre, float calificacion);
    void limpiar_cartelera();
};

#endif
