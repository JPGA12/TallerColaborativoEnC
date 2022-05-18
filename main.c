#include <stdio.h>
int menuOption;
char *menu = "\tTaller Colaborativo en C \n\n"
             "1.Convertir cadena a nombre propio\n"
             "2. Buscar cadena de caracteres\n"
             "3. Contar vocales\n"
             "4. Anio nuevo\n"
             "5. Llenar caracteres\n"
             "6. Borrar caracteres\n"
             "7. Interseccion\n"
             "8. Eliminar repetidos\n"
             "9. Desplazamiento\n"
             "0. Salir\n\n"
             "Dijite una opcion\n";

int main() {

    do {
        printf(menu);
        fflush(stdin);
        scanf("%i",&menuOption);


        switch (menuOption) {

            case 0:
                printf("SALIENDO...\n");
                break;
            case 1:
                printf("Convertir cadena a nombre propio\n");
                break;
            case 2:
                printf("Buscar cadena de caracteres\n");
                break;
            case 3:
                printf("Contar vocales\n");
                break;
            case 4:
                printf("Año nuevo\n");
                break;
            case 5:
                printf("Llenar caracteres\n");
                break;
            case 6:
                printf("Borrar caracteres\n");
                break;
            case 7:
                printf("Interseccion\n");
                break;
            case 8:
                printf("Eliminar repetidos\n");
                break;
            case 9:
                printf("Desplazamiento");
                break;

            default:
                printf("\n\n SELECCIONE UNA OPCION EXISTENTE \n\n\n");


        }
    } while (menuOption != 0 );




    return 0;
}