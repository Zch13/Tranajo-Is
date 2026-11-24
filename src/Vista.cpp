#include "Vista.h"

std::string generarPaginaCatalogo(const std::vector<Producto>& catalogo) {
    std::string html = R"(
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Catálogo de Productos</title>
    <style>
        body { font-family: system-ui, sans-serif; background-color: #f4f6f8; color: #1f2937; margin: 0; padding: 40px 20px; }
        .contenedor { max-width: 1000px; margin: 0 auto; }
        h1 { text-align: center; margin-bottom: 30px; color: #111827; }
        .grid-catalogo { display: grid; grid-template-columns: repeat(auto-fill, minmax(260px, 1fr)); gap: 20px; }
        .tarjeta { background: #ffffff; border-radius: 10px; padding: 20px; box-shadow: 0 2px 8px rgba(0,0,0,0.08); display: flex; flex-direction: column; justify-content: space-between; }
        .categoria { font-size: 0.75rem; text-transform: uppercase; letter-spacing: 0.05em; color: #2563eb; font-weight: 700; margin-bottom: 6px; }
        .titulo { font-size: 1.2rem; font-weight: 600; margin: 0 0 10px 0; }
        .descripcion { font-size: 0.9rem; color: #4b5563; line-height: 1.4; margin-bottom: 20px; }
        .pie-tarjeta { display: flex; justify-content: space-between; align-items: center; border-top: 1px solid #e5e7eb; padding-top: 15px; }
        .precio { font-size: 1.25rem; font-weight: 700; color: #111827; }
        .boton { background-color: #2563eb; color: white; text-decoration: none; padding: 8px 14px; border-radius: 6px; font-size: 0.9rem; font-weight: 500; }
        .boton:hover { background-color: #1d4ed8; }
    </style>
</head>
<body>
    <div class="contenedor">
        <h1>Catálogo de Productos</h1>
        <div class="grid-catalogo">
)";

    for (const auto& item : catalogo) {
        html += "<div class=\"tarjeta\">";
        html += "  <div>";
        html += "    <div class=\"categoria\">" + item.categoria + "</div>";
        html += "    <h2 class=\"titulo\">" + item.nombre + "</h2>";
        html += "    <p class=\"descripcion\">" + item.descripcion + "</p>";
        html += "  </div>";
        html += "  <div class=\"pie-tarjeta\">";
        html += "    <span class=\"precio\">" + formatearPrecio(item.precio) + "</span>";
        html += "    <a href=\"/producto/" + std::to_string(item.id) + "\" class=\"boton\">Ver detalle</a>";
        html += "  </div>";
        html += "</div>";
    }

    html += R"(
        </div>
    </div>
</body>
</html>
)";
    return html;
}

std::string generarPaginaDetalle(const Producto& item) {
    return R"(
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>)" + item.nombre + R"(</title>
    <style>
        body { font-family: system-ui, sans-serif; background: #f4f6f8; padding: 40px 20px; }
        .ficha { max-width: 600px; margin: 0 auto; background: white; padding: 30px; border-radius: 10px; box-shadow: 0 2px 8px rgba(0,0,0,0.08); }
        .volver { display: inline-block; margin-bottom: 20px; color: #2563eb; text-decoration: none; font-weight: 500; }
        .precio { font-size: 1.5rem; font-weight: bold; color: #111827; margin: 20px 0; }
    </style>
</head>
<body>
    <div class="ficha">
        <a href="/" class="volver">&larr; Volver al catálogo</a>
        <div style="color:#2563eb; font-weight:bold; font-size:0.85rem;">)" + item.categoria + R"(</div>
        <h1>)" + item.nombre + R"(</h1>
        <p style="color:#4b5563; line-height:1.6;">)" + item.descripcion + R"(</p>
        <div class="precio">)" + formatearPrecio(item.precio) + R"(</div>
    </div>
</body>
</html>
)";
}