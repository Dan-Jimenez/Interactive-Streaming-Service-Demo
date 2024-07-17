#include "usuario.hpp"

Usuario::Usuario() {}

std::string Usuario::get_nombre() {
    return nombre;
}

void Usuario::set_nombre(std::string nombre) {
    this->nombre = nombre;
}