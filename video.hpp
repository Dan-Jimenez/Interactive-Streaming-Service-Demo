#ifndef VIDEO_H
#define VIDEO_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Video{

protected:
    string tipo_video;
    string nombre;
    string genero;
    int duracion;
    float calificacion;
    int anio_publicacion;
    Video();

public:
    virtual ~Video() {}
    string get_tipo_video();
    string get_nombre();
    string get_genero();
    int get_duracion();
    float get_calificacion();
    void set_calificacion(float calificacion);
    int get_anio_publicacion();
    friend bool operator>(const Video &calif1, const Video &calif2);
    virtual string toString() = 0; // abstracto
    virtual void transmitir(string nombre) = 0; // abstracto
};
#endif