#ifndef VISTA_H
#define VISTA_H

#include "Producto.h"
#include <string>
#include <vector>

std::string generarPaginaCatalogo(const std::vector<Producto>& catalogo);
std::string generarPaginaDetalle(const Producto& item);

#endif