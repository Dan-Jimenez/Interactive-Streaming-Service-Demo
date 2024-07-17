#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario{

private:
    std::string nombre;

public: 
    Usuario();
    std::string get_nombre();
    void set_nombre(std::string nombre);
};
#endif
