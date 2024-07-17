#include "cine.hpp"
#include "pelicula.hpp"
#include "serie.hpp"
#include "sstream"
#include <cctype>
#include <limits>

Cine::Cine() {}

void Cine::cargar_cartelera() {
    ifstream archivo;
    archivo.open("cartelera.csv");
    string linea, tipo_video, nombre, genero, duracion, calificacion, num_episodios, director, anio_publicacion;
    while (getline(archivo, linea)) {
        stringstream token(linea);

        getline(token, tipo_video, ',');
        getline(token, nombre, ',');
        getline(token, genero, ',');
        getline(token, duracion, ',');
        getline(token, calificacion, ',');
        getline(token, num_episodios, ',');
        getline(token, director, ',');
        getline(token, anio_publicacion, ',');

        int i_duracion = stoi(duracion);
        float f_calificacion = stof(calificacion);
        int i_num_episodios = stoi(num_episodios);
        int i_anio_publicacion = stoi(anio_publicacion);
        if (!tipo_video.empty()) {
            tipo_video[0] = toupper(tipo_video[0]);
        }
        if (!genero.empty()) {
            bool capitalizeNext = true;
            for (char& c : genero) {
                if (capitalizeNext && isalpha(c)) {
                    c = toupper(c);
                    capitalizeNext = false;
                } else if (isspace(c)) {
                    capitalizeNext = true;
                }
            }
        }
        if (tipo_video == "Pelicula") {
            Pelicula* pelicula = new Pelicula(tipo_video, nombre, genero, i_duracion, f_calificacion, director, i_anio_publicacion);
            cartelera.push_back(pelicula);
        } else if (tipo_video == "Serie") {
            Serie* serie = new Serie(tipo_video, nombre, genero, i_duracion, f_calificacion, i_num_episodios, i_anio_publicacion);
            cartelera.push_back(serie);
        }
    }
    archivo.close();
}


void Cine::mostrar_cartelera() {
    cout << "\n*** CARTELERA ***\n" << endl;
    for (size_t i = 0; i < cartelera.size(); ++i) {
        Video* video = cartelera[i];

        cout << "Tipo de video: " << video->get_tipo_video() << endl;
        cout << "Nombre: " << video->get_nombre() << endl;
        cout << "Género: " << video->get_genero() << endl;
        cout << "Duración: " << video->get_duracion() << " minutos" << endl;
        cout << "Calificación: " << video->get_calificacion() << endl;
        cout << video->toString() << endl;
        cout << "Año de publicación: " << video->get_anio_publicacion() << endl;
        cout << "------------------------" << endl;
    }
}

void Cine::mostrar_videos_por_calificacion(float calificacion) {
    cout << "\n*** Videos con calificación igual o mayor a " << calificacion << " ***\n"<< endl;
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_calificacion() >= calificacion) {
            cout << "Tipo de video: " << video->get_tipo_video() << endl;
            cout << "Nombre: " << video->get_nombre() << endl;
            cout << "Género: " << video->get_genero() << endl;
            cout << "Duración: " << video->get_duracion() << " minutos" << endl;
            cout << "Calificación: " << video->get_calificacion() << endl;
            cout << video->toString() << endl;
            cout << "Año de publicación: " << video->get_anio_publicacion() << endl;
            cout << "------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron videos con calificación igual o mayor a " << calificacion << endl;
    }
}

void Cine::mostrar_videos_por_genero(string genero) {
    cout << "\n*** Videos del género: " << genero << " ***\n" << endl;
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_genero() == genero) {
            cout << "Tipo de video: " << video->get_tipo_video() << endl;
            cout << "Nombre: " << video->get_nombre() << endl;
            cout << "Género: " << video->get_genero() << endl;
            cout << "Duración: " << video->get_duracion() << " minutos" << endl;
            cout << "Calificación: " << video->get_calificacion() << endl;
            cout << video->toString() << endl;
            cout << "Año de publicación: " << video->get_anio_publicacion() << endl;
            cout << "------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron videos de " << genero << endl;
    }
}

void Cine::mostrar_serie_por_calificacion(float calificacion) {
    cout << "\n*** Series con calificación igual o mayor a " << calificacion << " ***\n" << endl;
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_tipo_video() == "Serie" && video->get_calificacion() >= calificacion) {
            cout << "Tipo de video: " << video->get_tipo_video() << endl;
            cout << "Nombre: " << video->get_nombre() << endl;
            cout << "Género: " << video->get_genero() << endl;
            cout << "Duración: " << video->get_duracion() << " minutos" << endl;
            cout << "Calificación: " << video->get_calificacion() << endl;
            cout << "Año de publicación: " << video->get_anio_publicacion() << endl;
            string cap_toString = video->toString();
            transform(cap_toString.begin(), cap_toString.end(), cap_toString.begin(), ::toupper);
            cout << cap_toString << endl;
            cout << "------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron Series con calificación igual o mayor a " << calificacion << endl;
    }
}

void Cine::mostrar_pelicula_por_calificacion(float calificacion) {
    cout << "\n*** Películas con calificación igual o mayor a " << calificacion << " ***\n" << endl;
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_tipo_video() == "Pelicula" && video->get_calificacion() >= calificacion) {
            cout << "Tipo de video: " << video->get_tipo_video() << endl;
            cout << "Nombre: " << video->get_nombre() << endl;
            cout << "Género: " << video->get_genero() << endl;
            cout << "Duración: " << video->get_duracion() << " minutos" << endl;
            cout << "Calificación: " << video->get_calificacion() << endl;
            cout << "Año de publicación: " << video->get_anio_publicacion() << endl;
            cout << video->toString() << endl;
            cout << "------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron Películas con calificación igual o mayor a " << calificacion << endl;
    }
}

void Cine::mostrar_pelicula_o_serie_por_anio_publicacion(string tipo_video, int anio_publicacion) {
    cout << "\n*** " << tipo_video << "s con año de publicación igual o posterior a " << anio_publicacion << " ***\n" << endl;
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_tipo_video() == tipo_video && video->get_anio_publicacion() >= anio_publicacion) {
            cout << "Tipo de video: " << video->get_tipo_video() << endl;
            cout << "Nombre: " << video->get_nombre() << endl;
            cout << "Género: " << video->get_genero() << endl;
            cout << "Duración: " << video->get_duracion() << " minutos" << endl;
            cout << "Calificación: " << video->get_calificacion() << endl;
            cout << "Año de publicación: " << video->get_anio_publicacion() << endl;
            cout << video->toString() << endl;
            cout << "------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron " << tipo_video << "s con año de publicación igual o posterior a " << anio_publicacion << endl;
    }
}

Video* Cine::pelicula_con_mayor_calificacion() {
    Video* mayor = nullptr;
    for (auto& video : cartelera) {
        if (video->get_tipo_video() == "Pelicula" && (mayor == nullptr || *video > *mayor)) {
            mayor = video;
        }
    }
    return mayor;
}

Video* Cine::serie_con_mayor_calificacion() {
    Video* mayor = nullptr;
    for (auto& video : cartelera) {
        if (video->get_tipo_video() == "Serie" && (mayor == nullptr || *video > *mayor)) {
            mayor = video;
        }
    }
    return mayor;
}

void Cine::transmitir_video(string nombre) {
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_nombre() == nombre) {
            if (video->get_tipo_video() == "Serie") {
                Serie* serie = dynamic_cast<Serie*>(video); // Cast to Serie*
                if (serie) {
                    int num_episodio;
                    cout << "Escoge el número de episodio que deseas ver: ";
                    cin >> num_episodio;
                    if (num_episodio > 0 && num_episodio <= serie->get_episodios()) {
                        cout << "\nCargando...\n" << endl;
                        video->transmitir(nombre);
                        cout << "Episodio: " << num_episodio << endl;
                        encontrado = true;
                    } else {
                        cout << "\nNúmero de episodio inválido." << endl;
                        encontrado = true;
                    }
                }
            }
            else {
                cout << "\nCargando...\n" << endl;
                video->transmitir(nombre);
                encontrado = true;
            }
        }
    }
    if (!encontrado) {
        cout << "\nNo se encontró la Pelicula o Serie llamada " << '"' << nombre << '"' << endl;
    }
}

void Cine::calificar_video(string nombre, float calificacion) {
    bool encontrado = false;
    for (auto& video : cartelera) {
        if (video->get_nombre() == nombre) {
            video->set_calificacion(calificacion);
            cout << "\nEl video " << nombre << " ha sido calificado con una puntuación de " << calificacion << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "\nError: No se encontró el video llamado " << '"' << nombre << '"';
    }
}


void Cine::limpiar_cartelera() {
    for (size_t i = 0; i < cartelera.size(); ++i) {
    delete cartelera[i];
    }
    cartelera.clear();
}
