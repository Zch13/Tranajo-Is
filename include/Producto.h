#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <cstdio>

struct Producto {
    int id;
    std::string nombre;
    std::string categoria;
    double precio;
    std::string descripcion;
};

inline std::string formatearPrecio(double precio) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.2f €", precio);
    return std::string(buffer);
}

#endif