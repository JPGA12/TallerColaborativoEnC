#include <stdio.h>
#include <string.h>
#include <ctype.h>


int menuOption;
char *menu = "\tTaller Colaborativo en C \n\n"
             "1. Convertir cadena a nombre propio\n"
             "2. Buscar cadena de caracteres\n"
             "3. Contar vocales\n"
             "4. Anio nuevo\n"
             "5. Llenar caracteres\n"
             "6. Borrar caracteres\n"
             "7. Interseccion\n"
             "8. Eliminar repetidos\n"
             "9. Desplazamiento\n"
             "10. Validacion Email\n"
             "0. Salir\n\n"
             "Dijite una opcion\n";

int validateEmail(char email []){
    email = strchr( email, '@' );

    if( email == NULL ) {
        return 1;
    }else{
        if(strchr( email, '.' )==NULL){
            return 1;
        } else{
            return 0;
        }
    }
}

char sentenceUp(char sentence []){
    strlwr(sentence);
    for (int i = 0; sentence[i] != '\0'; ++i){
        if( sentence[i-1]==NULL && isspace(sentence[i+1] ) || strlen(sentence)<=1){

        }else if( sentence[i-1]==NULL || isspace(sentence[i-1] ) && !isspace(sentence[i+1] ) && sentence[i+1] != NULL){
            sentence[i] = toupper(sentence[i]);
        }
    }
    return sentence;
}

int contarVocales(char palabra []){
    int count=0;

    for(int i = 0; palabra[i] != '\0'; ++i){
        if(palabra[i]=='a' || palabra[i]=='e' || palabra[i]=='i' || palabra[i]=='o' || palabra[i]=='u'){
            count++;

        }
    }
    return count;
}

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
            printf("DIGITO INVALIDO, INTENTE DE NUEVO...\n\n");


    }
    return string;
}

char *borrarCaracteres(char input[100], char character) {

    char *string;
    char aux[100];
    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        char ci = tolower(input[i]), c = tolower(character);
        if (ci != c) {
            aux[index] = input[i];
            index++;
        } else {

        }
    }
    string = aux;
    printf("\n\nCadena final: %s \n\n", string);
    return string;

}


int main() {

    do {

        printf(menu);
        scanf("%i", &menuOption);
        fflush(stdin);
        switch (menuOption) {

            case 0:
                printf("SALIENDO...\n");
                break;
            case 1:
                char sentence[0];
                printf("Convertir cadena a nombre propio\n");
                printf("Ingresa una cadena\n");
                sentenceUp(gets(sentence));
                fflush(stdin);
                printf("La cadena en nombre propio es: %s\n",sentence);
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

                char inputDelete[100], characterDelete;

                printf("Digite una cadenass: \n");
                fflush(stdin);
                gets(inputDelete);

                printf("Digite caracter a borrar de la cadena \n");
                scanf("%c", &characterDelete);

                borrarCaracteres(inputDelete, characterDelete);

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
            case 10:
                char email [30] ;
                printf("Ingresa el email\n");
                scanf("%s",email);
                fflush(stdin);
                printf((validateEmail(email)==0)?"direccion valida\n":"direccion invalida\n");

                break;

            default:
                printf("\n\n SELECCIONE UNA OPCION EXISTENTE \n\n\n");


        }
    } while (menuOption != 0);


    return 0;
}