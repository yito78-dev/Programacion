#include <stdio.h>
#include <time.h>
#include <string.h>
// constantes
const int costo_ingreso = 1200;
const int dias_entrega = 3;

int main()
{

    // Datos del estudiante

    char nombre_estudiante[] = "Erik Ridriguez Torres";
    char matricula[] = "ES261129259";
    char grupo[] = "DS-DFPR-2601-B1-023";

    printf("Nombre del estudiante: %s\n", nombre_estudiante);
    printf("Matricula: %s\n", matricula);
    printf("Grupo: %s\n", grupo);

    printf("\n");

    printf("----DATOS DE ENTRADA DEL TALLER----\n");

    // Variables de entrada

    char A1[] = "Juan Rulfo ";
    char A2[] = "Octavio Paz ";
    char A3[] = "Gabriel Marquez ";
    char A4[] = "Paulo Cohelo ";
    char B1[] = "Juan Villoro ";
    char B2[] = "Carlos Fuentes ";

    char M001[] = "(M001)";
    char M002[] = "(M002)";
    char M003[] = "(M003)";
    char M004[] = "(M004)";
    char M005[] = "(M005)";
    char M006[] = "(M006)";

    char empleado_asignado[50];
    char empleado_clave[20];
    char fechaingreso[15];
    char fechaentrega[15];
    int dia, mes, anio;
    char horaingreso[10];
    char nombrecliente[50];
    char apellido[50];
    char marcavehiculo[15];
    char modelovehiculo[15];
    char colorvehiculo[15];
    char numeroplaca[10];
    char tiposervicio[25];
    int porcentajeservicio;
    char registroespacio[10];
    char claveempleado[6];
    char nombreencargado[50];
    char empleadonombre[15];
    char empleadoapellido[15];
    char encargado[] = "Erik Rodriguez";
    // Solicitud de datos

    printf("Fecha de ingreso (DD/MM/AAAA): ");
    scanf("%s", fechaingreso);

    // ===== Calcular fecha de entrega = fecha de ingreso + 3 días =====

    sscanf(fechaingreso, "%d/%d/%d", &dia, &mes, &anio);

    struct tm f = {0};
    f.tm_mday = dia;
    f.tm_mon = mes - 1;
    f.tm_year = anio - 1900;

    time_t t = mktime(&f);
    t += dias_entrega * 86400;

    struct tm *e = localtime(&t);

    sprintf(fechaentrega, "%02d/%02d/%04d",
            e->tm_mday, e->tm_mon + 1, e->tm_year + 1900);
    // ================================================================

    printf("Hora de ingreso (HH:MM): ");
    scanf("%s", horaingreso);
    printf("Nombre del cliente: ");
    scanf("%s %s", nombrecliente, apellido);
    printf("Marca del vehiculo: ");
    scanf("%s", marcavehiculo);
    printf("Modelo del vehiculo: ");
    scanf("%s", modelovehiculo);
    printf("Color del vehiculo: ");
    scanf("%s", colorvehiculo);
    printf("Numero de placas: ");
    scanf("%s", numeroplaca);
    printf("Tipo de servicio (reparacion/servicio): ");
    scanf("%s", tiposervicio);
    printf("Porsentaje de servicio: ");
    scanf("%d", &porcentajeservicio);

    printf("Registro del espacio (A1, A2, A3, A4 o B1, B2): ");
    scanf("%s", registroespacio);
    if (strcmp(registroespacio, "A1") == 0)
        strcpy(empleado_asignado, A1);
    else if (strcmp(registroespacio, "A2") == 0)
        strcpy(empleado_asignado, A2);
    else if (strcmp(registroespacio, "A3") == 0)
        strcpy(empleado_asignado, A3);
    else if (strcmp(registroespacio, "A4") == 0)
        strcpy(empleado_asignado, A4);
    else if (strcmp(registroespacio, "B1") == 0)
        strcpy(empleado_asignado, B1);
    else if (strcmp(registroespacio, "B2") == 0)
        strcpy(empleado_asignado, B2);
    else
        strcpy(empleado_asignado, "Desconocido");

    printf("Clave de empleado (M001, M002, M003, M004, M005, M006): ");
    scanf("%s", claveempleado);
    if (strcmp(claveempleado, "M001") == 0)
        strcpy(empleado_clave, M001);
    else if (strcmp(claveempleado, "M002") == 0)
        strcpy(empleado_clave, M002);
    else if (strcmp(claveempleado, "M003") == 0)
        strcpy(empleado_clave, M003);
    else if (strcmp(claveempleado, "M004") == 0)
        strcpy(empleado_clave, M004);
    else if (strcmp(claveempleado, "M005") == 0)
        strcpy(empleado_clave, M005);
    else if (strcmp(claveempleado, "M006") == 0)
        strcpy(empleado_clave, M006);
    else
        strcpy(empleado_clave, "Clave invalida");

    printf("Nombre del encargado: %s\n", encargado);

    printf("__________________________________________________________________\n");

    // Expreciones matematicas

    // procentaje de aumento y precio final
    float aumento = 0.0f;
    float precio_final = 0.0f;

    aumento = costo_ingreso * (porcentajeservicio / 100.0f);
    precio_final = costo_ingreso + aumento;

    // Comprobantes

    printf("----------COMPROBANTE DEL CLIENTE----------\n");

    printf("Taller: Hermanos Benavidez\n");
    printf("Cliente:%s %s\n", nombrecliente, apellido);
    printf("Fecha de ingreso: %s\n", fechaingreso);
    printf("Hora de ingreso: %s\n", horaingreso);
    printf("Placas del vehiculo: %s\n", numeroplaca);
    printf("Tipo de servicio: %s\n", tiposervicio);
    printf("Precio final: $%2.f\n", precio_final);
    printf("Vehiculo:%s %s\n", marcavehiculo, modelovehiculo);
    printf("Color: %s\n", colorvehiculo);
    printf("Fecha de entrega:%s\n", fechaentrega);

    printf("\n");

    printf("----COMPROBANTE DE LA EMPRESA----\n");
    printf("Fecha de ingreso: %s\n", fechaingreso);
    printf("Vehiculo: %s %s\n", marcavehiculo, modelovehiculo);
    printf("Espacio asignado: %s\n", registroespacio);
    printf("Empleado asignado: %s %s\n", empleado_asignado, empleado_clave);
    printf("Nombre encargado: %s\n", encargado);
    printf("Fecha de entrega:%s\n", fechaentrega);

    return 0;
}
