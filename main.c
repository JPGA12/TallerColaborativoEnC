#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


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


int Buscar( char Cadena[], char Caracter){
    int contCarc=0;
    for(int i = 0; Cadena[i] != '\0'; ++i){
        Cadena[i]= tolower(Cadena[i]);
        Caracter= tolower(Caracter);
        if(Cadena[i]==Caracter){
            contCarc++;
        }
    }
    return contCarc;
}


int contarVocales(char palabra []){
    int count=0;

    for(int i = 0; palabra[i] != '\0'; ++i){
        palabra[i]= tolower(palabra[i]);
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

char* newYear() {
    char string;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int hour = 23 - tm.tm_hour;
    int month = tm.tm_mon;
    int dayActually = tm.tm_mday;
    int minute = 60 - tm.tm_min;
    int timeInDays = ((month) * 30) + dayActually;
    int day = 365 - timeInDays;


    printf("Fecha actual: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
           tm.tm_min, tm.tm_sec);
    printf("El tiempo para que llegue anio nuevo es: \nDias: %i \nHoras: %i \nMinutos: %i \n", day, hour, minute);


    return string;
}

char *interseccion(char cadena[], char cadena2[]) {
    int tamano1, tamano2, cont = 0, contador = 0;
    char aux[255], aux2[255];
    char *cadenaSalida = "";

    tamano2 = strlen(cadena2);
    for (int i = tamano2 - 1; i >= 0; --i) {
        for (int j = 0; j < tamano2 - 1; ++j) {
            if (cadena2[i] == cadena2[j]) {
                cont++;
            }
        }
        if (cont > 1) {
            memset(aux, 0, 255);
            memset(aux2, 0, 255);

            for (int j = i + 1; j < tamano2 - 1; ++j) {
                aux[contador] = cadena2[j];
                contador++;
            }
            contador = 0;
            for (int j = 0; j < i; ++j) {
                aux2[j] = cadena2[j];
            }
            memset(cadena2, 0, 255);
            strcat(strcpy(cadena2, aux2), aux);

            tamano2 = strlen(cadena2);
        }
        cont = 0;
    }
    tamano1 = strlen(cadena);
    tamano2 = strlen(cadena2);
    memset(aux, 0, 255);
    cont = 0;
    contador = 0;
    for (int i = 0; i < tamano2; ++i) {
        for (int j = 0; j < tamano1; ++j) {
            if (cadena2[i] == cadena[j]) {
                cont++;
            }
        }
        if (cont > 0) {
            aux[contador] = cadena2[i];
            contador++;
            cont = 0;
        }
    }

    cadenaSalida = aux;
    return cadenaSalida;
}

char* deleteRepeat(char palabra[],char *resultado){
    int i=0,j=0;
    while(palabra[i])
    {
        if(!strchr(resultado,palabra[i]))
            resultado[j++]=palabra[i];
        i++;
    }
    resultado[j]='\0';
    printf("\nEl resultado seria!\n%s",resultado);

    return NULL;
}

char *desplazamiento(char *palabra,int indice,int nVeces,int direccion){
    char aux[strlen(palabra)],aux2;
    int cont = 0,cont2 = indice,i=0;
    if(direccion == 1){
        while (i < nVeces){
            if(cont2 == 0){
                cont2= strlen(palabra)-1;
            } else{
                cont2--;
            }
            i++;
        }


        printf("%d\n",cont2);
        aux2 = palabra[indice];
        printf("%c\n",aux2);

        for (int i = 0; i <= strlen(palabra); ++i) {
            if(cont2 == i){
                aux[cont]=aux2;
                cont++;
                aux[cont] = palabra[i];
                cont++;
            }else if(indice != i){
                aux[cont]=palabra[i];
                cont++;
            } else{
                aux[i]=palabra[i-1];
            }
        }
        printf("%s\n",&aux);

    } else if(direccion == 2){
        while (i < nVeces){
            if(cont2 == strlen(palabra)-1){
                cont2=0;
            } else{
                cont2++;
            }
            i++;
        }

        cont2++;

        printf("%d\n",cont2);
        aux2 = palabra[indice];
        printf("%c\n",aux2);

        for (int i = 0; i <= strlen(palabra); ++i) {
            if(cont2 == i){
                aux[cont]=aux2;
                cont++;
                aux[cont] = palabra[i];
                cont++;
            }else if(indice != i){
                aux[cont]=palabra[i];
                cont++;
            } else{
                aux[i]=palabra[i+1];
            }
        }
        printf("%s\n",&aux);

    }else{
        printf("error");
    }

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
                printf("Convertir cadena a nombre propio\n");
                char sentence[0];
                printf("Convertir cadena a nombre propio\n");
                printf("Ingresa una cadena\n");
                sentenceUp(gets(sentence));
                fflush(stdin);
                printf("La cadena en nombre propio es: %s\n",sentence);
                break;
            case 2:
                printf("Buscar cadena de caracteres\n");

                char cad[0];
                char caracter;
                printf("Ingrese una Cadena \n");
                fflush(stdin);
                gets( cad);

                printf("Ingrese el caracter a buscar\n");
                scanf("%c", &caracter);

                printf("La cadena %s tiene %i caracteres %c", cad, Buscar(cad,caracter),caracter);

                break;
            case 3:
                printf("Contar vocales\n");

                char palabra[0];
                printf("Ingrese la cadena\n");
                fflush(stdin);
                gets(palabra);

                printf("La cadena %s tiene una cantidad de %i vocales\n",palabra,contarVocales(palabra));
                break;
            case 4:
                printf("Anio nuevo\n");
                newYear();
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
                printf("\n>>Diferencia entre dos cadenas<<");

                char cadena7[255], cadena27[255];

                printf("\nDigite la cadena de texto uno...");
                fgets(cadena7, 255, stdin);

                printf("\nDigite la cadena de texto dos...");
                fgets(cadena27, 255, stdin);

                printf("\nLa Interseccion es: %s \n", interseccion(cadena7, cadena27));
                printf("\nPresione una tecla para continuar . . .");
                getchar();
                break;
            case 8:
                printf("\n>>Eliminar  repetidos<<");
                char cadena6[255], caracter1[1];
                printf("\nIngrese la cadena...");
                gets(cadena6);

                printf("\n%s \n", deleteRepeat(cadena6, caracter1));

                printf("\nPresione una tecla para continuar . . .");
                getchar();
                break;
            case 9:
                printf("\n HA SELECCIONADO LA OPCION 9: desplazamiento \n\nIngrese u oracion una palabra para desplazar un elemento de este\n");
                char words[50];
                int y,y1,x1;
                //scanf("%s",words);
                fgets(words,500,stdin );
                printf("%s",words);
                printf("\nIngrese el indice del caracter que desea desplazar (el indice empieza a contar desde 0 de izquierda a derecha)\n");
                scanf("%d",&y);
                printf("\nIngrese cuantas posiciones se desplazara el caracter\n");
                scanf("%d",&y1);
                fflush(stdin);
                printf("\nIngrese hacia donde va a insertar el caracter ( 1 izquierda o 2 derecha)\n");
                scanf("%d",&x1);
                while (x1 != 1 && x1 != 2){
                    printf("error, seleccione una opcion valida\n");
                    printf("\nIngrese hacia donde va a insertar el caracter ( 1 izquierda o 2 derecha)\n");
                    scanf("%d",&x1);
                }
                desplazamiento(words,y,y1,x1);
                break;
            case 10:
                printf("Verificacion de E-mail \n");
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