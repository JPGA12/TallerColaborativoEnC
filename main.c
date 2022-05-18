#include <stdio.h>
#include <string.h>


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

char *llenarCaracteres(char input[100], char character, int repetition, int direction) {
    char *string;
    printf("Cadena: %s \nCaracter %c \n", input, character);
    printf("repeticiones %i \nDireccion %i \n", repetition, direction);


    char chars[repetition - 1];
    for (int i = 0; i < repetition; ++i) {
        chars[i] = character;
    }

    switch (direction) {
        case 0:
            printf("\n\n DERECHA\n\n");
            string = strcat(input, chars);
            printf("%s \n\n", string);

            break;
        case 1:
            printf("\n\n IZQUIERDA\n\n");
            string = strcat(chars, input);
            printf("%s \n\n", string);
            break;
        default:
            printf("DIGITO INVALIDO, INTENTE DE NUEVO...\n");


    }
    return string;
}


int main() {

    do {

        printf(menu);
        scanf("%i", &menuOption);

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

                char input[100], character;
                int repetition, direction;

                printf("Digite una cadena: \n");
                gets(input);
                gets(input);

                printf("Digite un caracter: \n");
                scanf("%s", &character);

                printf("Digite el numero de veces que se reptie el caracter: \n");
                scanf("%i", &repetition);

                printf("Seleccione la direccion: \n [0] Derecha \n [1] Izquierda \n");
                scanf("%i", &direction);

                llenarCaracteres(input, character, repetition, direction);

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
    } while (menuOption != 0);


    return 0;
}