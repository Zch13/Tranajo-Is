#include "httplib.h"

int main() {
    httplib::Server svr;

    // Responde a la ruta principal ("/") con un HTML totalmente en blanco
    svr.Get("/", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(
            "<!DOCTYPE html>"
            "<html lang=\"es\">"
            "<head><meta charset=\"UTF-8\"><title></title></head>"
            "<body></body>"
            "</html>",
            "text/html"
        );
    });

    // Inicia el servidor en http://localhost:8080
    svr.listen("0.0.0.0", 8080);
    return 0;
}
