#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "cine.hpp"
#include "video.hpp"
#include "serie.hpp"
#include "pelicula.hpp"
#include "usuario.hpp"

int main() {
    Cine cine;
    bool salir = false;
    cine.cargar_cartelera();

    Usuario usuario;
    string nombre;
    cout << "\n* Usted esta en Entretenimiento.com *" << endl;
    cout << "\nIngrese su nombre: "; getline(cin, nombre);
    usuario.set_nombre(nombre);
    cout << "\n*** Bienvenido " << usuario.get_nombre() << " ***" << endl;

    while (!salir) {
        try {
            cout << "\n----- MENU -----" << endl;
            cout << "1. Mostrar Cartelera" << endl;
            cout << "2. Mostrar Videos con cierta calificación" << endl;
            cout << "3. Mostrar Videos con cierto género" << endl;
            cout << "4. Mostrar Serie con cierta calificación y sus episodios" << endl;
            cout << "5. Mostrar Películas con cierta calificación" << endl;
            cout << "6. Mostrar Películas/Series por año de publicación" << endl;
            cout << "7. Mostrar Película con la mayor calificación" << endl;
            cout << "8. Mostrar Serie con la mayor calificación" << endl;
            cout << "9. Transmitir Pelicula/Serie" << endl;
            cout << "10. Calificar un Video" << endl;
            cout << "0. Salir\n" << endl;
            cout << "Ingrese una opción: ";
            int opcion;
            cin >> opcion;

            if (cin.fail())
                throw invalid_argument("Opción inválida. Intente nuevamente.");

            switch (opcion) {
                case 1: {
                    cine.mostrar_cartelera();
                    break;
                }
                case 2: {
                    bool calificacion_valida = false;
                    float calificacion;
                    cout << "\n--- Video por calificación ---" << endl;
                    while (!calificacion_valida) {
                        cout << "Ingrese la calificación mínima que desea (0-10): "; cin >> calificacion;
                        if (cin.fail() || calificacion < 0 || calificacion > 10) {
                            cout << "Calificación no válida. Ingrese un número flotante entre 0 y 10.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            calificacion_valida = true;
                        }
                    }
                    cine.mostrar_videos_por_calificacion(calificacion);
                    break;
                }
                case 3: {
                    bool genero_valido = false;
                    string genero;
                    cout << "\n--- Video por calificación ---" << endl;
                    while (!genero_valido) {
                        cout << "Ingrese el género que desea (con acentos si es necesario): "; cin.ignore(); getline(cin, genero);
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
                        if (cin.fail()) { 
                            cout << "Género no válido.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            genero_valido = true;
                        }
                    }
                    cine.mostrar_videos_por_genero(genero);
                    break;
                }
                case 4: {
                    bool calificacion_valida = false;
                    float calificacion;
                    cout << "\n--- Serie por calificación ---" << endl;
                    while (!calificacion_valida) {
                        cout << "Ingrese la calificación mínima que desea (0-10): "; cin >> calificacion;
                        if (cin.fail() || calificacion < 0 || calificacion > 10) {
                            cout << "Calificación no válida. Ingrese un número flotante entre 0 y 10.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            calificacion_valida = true;
                        }
                    }
                    cine.mostrar_serie_por_calificacion(calificacion);
                    break;
                }
                case 5: {
                    bool calificacion_valida = false;
                    float calificacion;
                    cout << "\n--- Película por calificación ---" << endl;
                    while (!calificacion_valida) {
                        cout << "Ingrese la calificación mínima que desea (0-10): "; cin >> calificacion;
                        if (cin.fail() || calificacion < 0 || calificacion > 10) {
                            cout << "Calificación no válida. Ingrese un número flotante entre 0 y 10.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            calificacion_valida = true;
                        }
                    }
                    cine.mostrar_pelicula_por_calificacion(calificacion);
                    break;
                }
                case 6: {
                    string tipo_video;
                    int anio_publicacion;
                    cout << "\n--- Películas/Series por año de publicación ---" << endl;
                    bool tipo_video_valido = false;
                    while (!tipo_video_valido) {
                        cout << "Ingrese el tipo de dato (Pelicula/Serie): "; cin >> tipo_video;
                        tipo_video[0] = toupper(tipo_video[0]);
                        transform(tipo_video.begin() + 1, tipo_video.end(), tipo_video.begin() + 1, ::tolower);
                        if (cin.fail() || (tipo_video != "Pelicula" && tipo_video != "Serie")) {
                            cout << "Tipo de video inválido. Ingrese 'Pelicula' o 'Serie'.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            tipo_video_valido = true;
                        }
                    }
                    bool anio_valido = false;
                    while (!anio_valido) {
                        cout << "Ingrese el año de publicación mínimo que desea: "; cin >> anio_publicacion;
                        if (cin.fail() || anio_publicacion < 0 || anio_publicacion > 2024) {
                            cout << "Año de publicación inválido. Ingrese un número entero.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            anio_valido = true;
                        }
                    }
                    cine.mostrar_pelicula_o_serie_por_anio_publicacion(tipo_video, anio_publicacion);
                    break;
                }
                case 7: {
                    Video* peliculaMayorCalificacion = cine.pelicula_con_mayor_calificacion();
                    if (peliculaMayorCalificacion != nullptr) {
                        cout << "\n\n--- Pelicula con la mayor calificación ---\n" << endl;
                        cout << "Tipo de video: " << peliculaMayorCalificacion->get_tipo_video() << endl;
                        cout << "Nombre: " << peliculaMayorCalificacion->get_nombre() << endl;
                        cout << "Género: " << peliculaMayorCalificacion->get_genero() << endl;
                        cout << "Duración: " << peliculaMayorCalificacion->get_duracion() << " minutos" << endl;
                        cout << "Calificación: " << peliculaMayorCalificacion->get_calificacion() << endl;
                        cout << "Año de publicación: " << peliculaMayorCalificacion->get_anio_publicacion() << endl;
                        cout << peliculaMayorCalificacion->toString() << endl;
                        cout << "------------------------" << endl;
                    } else {
                        cout << "No se encontró ninguna película." << endl;
                    }
                    break;
                }
                case 8: {
                    Video* serieMayorCalificacion = cine.serie_con_mayor_calificacion();
                    if (serieMayorCalificacion != nullptr) {
                        cout << "\n\n--- Serie con la mayor calificación ---\n" << endl;
                        cout << "Tipo de video: " << serieMayorCalificacion->get_tipo_video() << endl;
                        cout << "Nombre: " << serieMayorCalificacion->get_nombre() << endl;
                        cout << "Género: " << serieMayorCalificacion->get_genero() << endl;
                        cout << "Duración: " << serieMayorCalificacion->get_duracion() << " minutos" << endl;
                        cout << "Calificación: " << serieMayorCalificacion->get_calificacion() << endl;
                        cout << "Año de publicación: " << serieMayorCalificacion->get_anio_publicacion() << endl;
                        cout << serieMayorCalificacion->toString() << endl;
                        cout << "------------------------" << endl;
                    } else {
                        cout << "No se encontró ninguna película." << endl;
                    }
                    break;
                }
                case 9: {
                    string nombre;
                    cout << "\n--- Transmitir Pelicula/Serie ---" << endl;
                    bool nombre_valido = false;
                    while (!nombre_valido) {
                        cout << "Que Pelicula o Serie quieres transmitir? "; cin.ignore(); getline(cin, nombre);
                        if (cin.fail()) { 
                            cout << "Nombre no válido.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            nombre_valido = true;
                        }
                    }
                    cine.transmitir_video(nombre);
                    break;
                }
                case 10: {
                    string nombre;
                    float calificacion;
                    cout << "\n--- Calificar Video ---" << endl;
                    bool nombre_valido = false;
                    while (!nombre_valido) {
                        cout << "Ingrese el nombre del video a calificar: "; cin.ignore(); getline(cin, nombre);
                        if (cin.fail()) {
                            cout << "Nombre no válido.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            nombre_valido = true;
                        }
                    }
                    bool calificacion_valida = false;
                    while (!calificacion_valida) {
                        cout << "Ingrese la calificación otorgada: "; cin >> calificacion;
                        if (cin.fail() || calificacion < 0 || calificacion > 10) {
                            cout << "Calificación no válida. Ingrese un número flotante entre 0 y 10.\n" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else {
                            calificacion_valida = true;
                        }
                    }
                    cine.calificar_video(nombre, calificacion);
                    break;
                }
                case 0: {
                    cout << "\n--- Gracias por usar nuestro servicio de streaming ---\n--- Regresa pronto! ---" << endl;
                    cine.limpiar_cartelera();
                    salir = true;
                    break;
                }
                default:
                    cout << "Opción inválida. Intente nuevamente." << endl;
            }

            cout << endl;
        } catch (const invalid_argument& objError) {
            cout << "ERROR." << endl <<
                objError.what() << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }

    return 0;
}


