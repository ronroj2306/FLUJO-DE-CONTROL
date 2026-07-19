#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Configurar la consola para mostrar dos decimales en los precios/monedas
    cout << fixed << setprecision(2);

    double sueldoBruto = 0.0;

    cout << "==================================================" << endl;
    cout << "   CALCULADORA DE ISR - REPUBLICA DOMINICANA 2026 " << endl;
    cout << "==================================================" << endl;
    cout << "Ingrese el sueldo mensual bruto del empleado (RD$): ";
    cin >> sueldoBruto;

    // 1. Deducción de Seguridad Social (TSS) obligatoria en RD (5.91% total)
    // 2.87% AFP + 3.04% SFS = 5.91%
    double descuentoTSS = sueldoBruto * 0.0591;
    double sueldoNetoGravable = sueldoBruto - descuentoTSS;

    double isrMensual = 0.0;

    // 2. Evaluación del flujo de control usando la escala mensual de la DGII 2026
    if (sueldoNetoGravable <= 34685.00) {
        isrMensual = 0.0; // Exento
    }
    else if (sueldoNetoGravable <= 52027.42) {
        isrMensual = (sueldoNetoGravable - 34685.01) * 0.15;
    }
    else if (sueldoNetoGravable <= 72260.25) {
        isrMensual = 2601.33 + ((sueldoNetoGravable - 52027.43) * 0.20);
    }
    else {
        isrMensual = 6648.00 + ((sueldoNetoGravable - 72260.26) * 0.25);
    }

    // 3. Mostrar resultados en pantalla
    cout << "\n==================================================" << endl;
    cout << "               DETALLE DE NOMINA                  " << endl;
    cout << "==================================================" << endl;
    cout << "Sueldo Bruto Ingresado:  RD$ " << sueldoBruto << endl;
    cout << "Descuento TSS (5.91%):   RD$ " << descuentoTSS << endl;
    cout << "Sueldo Neto Gravable:    RD$ " << sueldoNetoGravable << endl;
    cout << "--------------------------------------------------" << endl;

    if (isrMensual > 0) {
        cout << "Descuento ISR Aplicado:  RD$ " << isrMensual << endl;
        cout << "Sueldo Neto a Recibir:   RD$ " << (sueldoNetoGravable - isrMensual) << endl;
    }
    else {
        cout << "Descuento ISR Aplicado:  0 (N/A - Exento)" << endl;
        cout << "Sueldo Neto a Recibir:   RD$ " << sueldoNetoGravable << endl;
    }
    cout << "==================================================" << endl;

    return 0;
}