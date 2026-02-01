#include <stdio.h>


int main() {
    int opcion;
    float precio;
    float moneda_ingresada;
    float cambio;
    char otra_compra = 'S';

    do {
        printf("\n---MENU DE PRODUCTOS---\n");
        printf("1. Papas fritas - $10.00\n");
        printf("2. Refresco - $15.00\n");
        printf("3. Galletas - $20.00\n");
        printf("4. Jugo - $25.00\n");
        printf("5. Bebida energetica - $30.00\n");
        printf("6. Salir\n");

        // Encas de seleccion incorrecta
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 6) {
            printf("Seleccion incorrecta, intente de nuevo (1 al 6).\n");
            continue; 
        }

        if (opcion == 6) {
            printf("Saliendo.\n");
            break;
        }

        switch (opcion) {
            case 1:
                precio = 10.00f;
                printf("Has seleccionado Papas fritas. Precio: $%.2f\n", precio);
                break;
            case 2:
                precio = 15.00f;
                printf("Has seleccionado Refresco. Precio: $%.2f\n", precio);
                break;
            case 3:
                precio = 20.00f;
                printf("Has seleccionado Galletas. Precio: $%.2f\n", precio);
                break;
            case 4:
                precio = 25.00f;
                printf("Has seleccionado Jugo. Precio: $%.2f\n", precio);
                break;
            case 5:
                precio = 30.00f;
                printf("Has seleccionado Bebida energetica. Precio: $%.2f\n", precio);
                break;
        }

        // Logica de pago
        moneda_ingresada = 0.0f;

        while (moneda_ingresada < precio) {
            float moneda;
            printf("Ingrese una moneda (1, 2, 5, 10): $");
            scanf("%f", &moneda);

            if (moneda == 1 || moneda == 2 || moneda == 5 || moneda == 10) {
                moneda_ingresada += moneda;
                printf("Total ingresado: $%.2f\n", moneda_ingresada);
            } else {
                printf("Moneda no valida. Intente nuevamente.\n");
            }
        }

        // Entrega de producto y cambio
        cambio = moneda_ingresada - precio;
        printf("Producto entregado correctamente.\n");

        if (cambio > 0) {
            printf("Su cambio es: $%.2f\n", cambio);
        } else {
            printf("Pago exacto!\n");
        }

        // Otra compra
        printf("Desea realizar otra compra? (S/N): ");
        scanf(" %c", &otra_compra);

        if (otra_compra == 'S' || otra_compra == 's') {
            printf("Continuando con la compra.\n");
        } else if (otra_compra == 'N' || otra_compra == 'n') {
            printf("Gracias por usar el despachador.\n");
            break;
        } else {
            printf("Opcion no valida. Se terminara el programa.\n");
            break;
        }

    } while (1);

    return 0;

}
