#include "httplib.h"
#include "Producto.h"
#include "Vista.h"
#include <vector>

int main() {
    httplib::Server svr;

    std::vector<Producto> catalogo = {
        {1, "Teclado Mecánico 75%", "Periféricos", 89.99, "Switches táctiles silenciosos, retroiluminación blanca y chasis de aluminio."},
        {2, "Ratón Inalámbrico Pro", "Periféricos", 59.50, "Sensor óptico de 26.000 DPI, peso ultraligero de 63g y batería de 70 horas."},
        {3, "Monitor IPS 27\" 144Hz", "Pantallas", 229.00, "Resolución QHD (2560x1440), tiempo de respuesta de 1ms y soporte ajustable."},
        {4, "Hub USB-C 7 en 1", "Accesorios", 34.95, "Salida HDMI 4K, 3 puertos USB 3.0, lector de tarjetas SD y carga rápida PD."}
    };

    svr.Get("/", [&catalogo](const httplib::Request&, httplib::Response& res) {
        res.set_content(generarPaginaCatalogo(catalogo), "text/html; charset=UTF-8");
    });

    svr.Get(R"(/producto/(\d+))", [&catalogo](const httplib::Request& req, httplib::Response& res) {
        int idBuscado = std::stoi(req.matches[1]);

        for (const auto& item : catalogo) {
            if (item.id == idBuscado) {
                res.set_content(generarPaginaDetalle(item), "text/html; charset=UTF-8");
                return;
            }
        }

        res.status = 404;
        res.set_content("<h1>Producto no encontrado</h1><a href=\"/\">Volver</a>", "text/html; charset=UTF-8");
    });

    svr.listen("0.0.0.0", 8080);
    return 0;
}