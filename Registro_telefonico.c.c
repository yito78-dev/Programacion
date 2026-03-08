#include <stdio.h>
#include <string.h>

#define MAX 100

// Estructura para guardar los datos de cada línea telefónica
struct LineaTelefonica {
    int id;
    char curp[20];
    char nombre[50];
    char telefono[11];
    char operadora[20];
    int activa;
};

// Prototipos de funciones
void registrarLinea(struct LineaTelefonica lineas[], int *total);
void buscarLinea(struct LineaTelefonica lineas[], int total);
void eliminarLinea(struct LineaTelefonica lineas[], int total);

int main() {
    // Arreglo de estructuras para almacenar hasta 100 líneas
    struct LineaTelefonica lineas[MAX];

    // Variables de control
    int total = 0;
    int opcion;

    do {
        printf("\n===============================================\n");
        printf("      SISTEMA DE REGISTRO DE LINEAS TELEFONICAS\n");
        printf("===============================================\n");
        printf("Nombre completo: Erik Rodriguez Torres\n");
        printf("Matricula: ES261129259\n");
        printf("Grupo: DS-DFPR-2601-B1-023\n");
        printf("===============================================\n\n");

        printf("              MENU PRINCIPAL\n");
        printf("===============================================\n");
        printf("1. Lineas registradas\n");
        printf("2. Buscar linea\n");
        printf("3. Eliminar una linea\n");
        printf("4. Salir del sistema\n");
        printf("===============================================\n");
        printf("Seleccione una opcion (1-4): ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registrarLinea(lineas, &total);
                break;

            case 2:
                buscarLinea(lineas, total);
                break;

            case 3:
                eliminarLinea(lineas, total);
                break;

            case 4:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    } while(opcion != 4);

    return 0;
}

// Función para registrar una línea telefónica
void registrarLinea(struct LineaTelefonica lineas[], int *total) {
    int criterio;

    if (*total < MAX) {
        printf("\n===============================================\n");
        printf("        REGISTRO DE NUEVA LINEA TELEFONICA\n");
        printf("===============================================\n");

        lineas[*total].id = *total + 1;
        lineas[*total].activa = 1;

        printf("ID asignado: %d\n", lineas[*total].id);

        printf("CURP (18 caracteres alfanumericos): ");
        scanf("%s", lineas[*total].curp);

        printf("Nombre completo: ");
        scanf(" %[^\n]", lineas[*total].nombre);

        do {
            printf("Numero de telefono (10 digitos): ");
            scanf("%s", lineas[*total].telefono);

            if (strlen(lineas[*total].telefono) != 10) {
                printf("Error: el numero debe tener 10 digitos.\n");
            }

        } while (strlen(lineas[*total].telefono) != 10);

        printf("Seleccione operadora:\n");
        printf("1. Telcel\n");
        printf("2. AT&T\n");
        printf("3. Unefon\n");
        printf("Opcion (1-3): ");
        scanf("%d", &criterio);

        if (criterio == 1) {
            strcpy(lineas[*total].operadora, "TELCEL");
        } else if (criterio == 2) {
            strcpy(lineas[*total].operadora, "AT&T");
        } else if (criterio == 3) {
            strcpy(lineas[*total].operadora, "UNEFON");
        } else {
            strcpy(lineas[*total].operadora, "NO DEFINIDA");
        }

        printf("\n===============================================\n");
        printf("               REGISTRO EXITOSO\n");
        printf("===============================================\n");
        printf("Linea registrada con ID: %d\n", lineas[*total].id);

        (*total)++;
    } else {
        printf("\nNo se pueden registrar mas lineas.\n");
    }
}

// Función para buscar una línea telefónica
void buscarLinea(struct LineaTelefonica lineas[], int total) {
    int criterio;
    int i;
    int idBuscado;
    int encontrado = 0;
    char curpBuscada[20];

    printf("\n===============================================\n");
    printf("            BUSCAR LINEA TELEFONICA\n");
    printf("===============================================\n");
    printf("Criterios de busqueda:\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por CURP\n");
    printf("Seleccione el criterio de busqueda (1-2): ");
    scanf("%d", &criterio);

    if (criterio == 1) {
        printf("Ingrese el ID: ");
        scanf("%d", &idBuscado);

        for (i = 0; i < total; i++) {
            if (lineas[i].id == idBuscado && lineas[i].activa == 1) {
                printf("\n===============================================\n");
                printf("              INFORMACION DE LA LINEA\n");
                printf("===============================================\n");
                printf("ID: %d\n", lineas[i].id);
                printf("CURP: %s\n", lineas[i].curp);
                printf("Nombre: %s\n", lineas[i].nombre);
                printf("Telefono: %s\n", lineas[i].telefono);
                printf("Operadora: %s\n", lineas[i].operadora);
                printf("===============================================\n");
                encontrado = 1;
                break;
            }
        }
    } else if (criterio == 2) {
        printf("Ingrese la CURP: ");
        scanf("%s", curpBuscada);

        for (i = 0; i < total; i++) {
            if (strcmp(lineas[i].curp, curpBuscada) == 0 && lineas[i].activa == 1) {
                printf("\n===============================================\n");
                printf("              INFORMACION DE LA LINEA\n");
                printf("===============================================\n");
                printf("ID: %d\n", lineas[i].id);
                printf("CURP: %s\n", lineas[i].curp);
                printf("Nombre: %s\n", lineas[i].nombre);
                printf("Telefono: %s\n", lineas[i].telefono);
                printf("Operadora: %s\n", lineas[i].operadora);
                printf("===============================================\n");
                encontrado = 1;
                break;
            }
        }
    }

    if (encontrado == 0) {
        printf("\nNo se encontro la linea.\n");
    }
}

// Función para eliminar una línea telefónica
void eliminarLinea(struct LineaTelefonica lineas[], int total) {
    int criterio;
    int i;
    int idBuscado;
    int encontrado = 0;
    char curpBuscada[20];
    char confirmar;

    printf("\n===============================================\n");
    printf("            ELIMINAR LINEA TELEFONICA\n");
    printf("===============================================\n");
    printf("Eliminar linea por:\n");
    printf("1. ID\n");
    printf("2. CURP\n");
    printf("Seleccione opcion (1-2): ");
    scanf("%d", &criterio);

    if (criterio == 1) {
        printf("Ingrese el ID: ");
        scanf("%d", &idBuscado);

        for (i = 0; i < total; i++) {
            if (lineas[i].id == idBuscado && lineas[i].activa == 1) {
                printf("\nLinea encontrada para eliminar:\n");
                printf("===============================================\n");
                printf("              INFORMACION DE LA LINEA\n");
                printf("===============================================\n");
                printf("ID: %d\n", lineas[i].id);
                printf("CURP: %s\n", lineas[i].curp);
                printf("Nombre: %s\n", lineas[i].nombre);
                printf("Telefono: %s\n", lineas[i].telefono);
                printf("Operadora: %s\n", lineas[i].operadora);
                printf("===============================================\n");

                printf("¿Esta seguro de eliminar esta linea? (S/N): ");
                scanf(" %c", &confirmar);

                if (confirmar == 'S' || confirmar == 's') {
                    lineas[i].activa = 0;
                    printf("\n===============================================\n");
                    printf("              ELIMINACION EXITOSA\n");
                    printf("===============================================\n");
                    printf("Linea eliminada correctamente.\n");
                }
                encontrado = 1;
                break;
            }
        }
    } else if (criterio == 2) {
        printf("Ingrese la CURP: ");
        scanf("%s", curpBuscada);

        for (i = 0; i < total; i++) {
            if (strcmp(lineas[i].curp, curpBuscada) == 0 && lineas[i].activa == 1) {
                printf("\nLinea encontrada para eliminar:\n");
                printf("===============================================\n");
                printf("              INFORMACION DE LA LINEA\n");
                printf("===============================================\n");
                printf("ID: %d\n", lineas[i].id);
                printf("CURP: %s\n", lineas[i].curp);
                printf("Nombre: %s\n", lineas[i].nombre);
                printf("Telefono: %s\n", lineas[i].telefono);
                printf("Operadora: %s\n", lineas[i].operadora);
                printf("===============================================\n");

                printf("¿Esta seguro de eliminar esta linea? (S/N): ");
                scanf(" %c", &confirmar);

                if (confirmar == 'S' || confirmar == 's') {
                    lineas[i].activa = 0;
                    printf("\n===============================================\n");
                    printf("              ELIMINACION EXITOSA\n");
                    printf("===============================================\n");
                    printf("Linea eliminada correctamente.\n");
                }
                encontrado = 1;
                break;
            }
        }
    }

    if (encontrado == 0) {
        printf("\nNo se encontro la linea.\n");
    }
}