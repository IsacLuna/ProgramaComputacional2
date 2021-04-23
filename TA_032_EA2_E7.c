#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char w[] = {'d', 'h'};
char iM[] = {'1', '9', '0', '8', '6', '9', '9'};
char j2[] = {'a', 'n', 'e', 'l'};
int nextposicion = 0;
int auxw = 0;
int auxwi = 0;

char inicialesI(char cadena[]);
char iniciales(char cadena[]);
char matricula(char cadena[], int centinela);
char validacion(char cadena[]);
char nombre(char cadena[]);
char repetir(); 

int main(int argc, char const *argv[]){
    char cadenaI[' '];
    char valid = 'N';
    do{

        printf("Cadena: ");
        gets(cadenaI);
        fflush(stdin);

        if(strlen(cadenaI) < 28){

            printf("\n\tCadena inv%clida. Favor de ingresar una cadena m%cnima de 28 caracteres.\n\n", 160, 161);
            valid = repetir();

        }else{

            valid = validacion(cadenaI);

            if(valid == 'S'){

                printf("\n\tCadena inv%clida.\n", 160);
                valid = repetir(); 
                nextposicion = 0;
                auxw = 0;
                auxwi = 0;
            
            } else{
                
                printf("\n\tCadena v%clida.\n", 160);
                valid = repetir();
                nextposicion = 0;
                auxw = 0;
                auxwi = 0;
            }

        }

    } while (valid == 'S');

    return 0;
}
//1908699dhdhdh1908699hdhdhdhdhdhdhdhdhdhdanelanel
char validacion(char cadena[]){

    if(matricula(cadena, 1) == 'N')
        return 'S';
    else
        if(iniciales(cadena) == 'N')
            return 'S';
        else
            if(matricula(cadena, 2) == 'N')
                return 'S';
            else  
                if(inicialesI(cadena) == 'N')
                    return 'S';
                else
                    if(nombre(cadena) == 'N')
                        return 'S';
                    else 
                        return 'N';

}

char nombre(char cadena[]){

    int j = 0;
    for(int i = nextposicion+ auxwi + 7; i < strlen(cadena); i++){
            
        if(cadena[i] == j2[j])
            j++;
        else
            return 'N';

        if(j == 4)
            j = 0;

    }

}

char matricula(char cadena[], int centinela){
    int j = 0;
    switch (centinela){
        case 1: {
            for(int i = 0; i < 7; i++){

                if(cadena[i] == iM[i]){
                    if( i == 6)
                        return 'S'; 
                } else
                    return 'N';

            }
        }
            break;
        case 2: {
            for(int i = nextposicion; i < nextposicion + 7; i++){
                if(cadena[i] == iM[j]){

                    if( j == 6)
                        return 'S';
                } else
                    return 'N';
                j++;

            }
        }
            break;
    }
}

char inicialesI(char cadena[]){

    int n = 1;
    int i = 0;

    for(i = nextposicion + 7; i < nextposicion + 7 + auxw*2; i++){

        if(cadena[i] == w[n]){
            n--;
            auxwi++;
        } else
            return 'N';

        if( n == -1)
            n = 1;
    }   


}

char iniciales(char cadena[]){

    int n = 0;
    int i = 7;
    while(cadena[i] != '1'){

        if(cadena[i] == w[n]){
            n++;
            i++;
            auxw++;
            nextposicion++;
        } else
            return 'N';

        if( n == 2){
            n = 0;
        }

    }
    nextposicion = nextposicion + 7;

}

char repetir(){

    int aux;
    do{

        printf("\t\t\t\t%cQuiere ingresar otra cadena%c\t(1. S%c/2. No)\n\t\t\t>", 168, 63, 161);
        scanf("%d", &aux);
        fflush(stdin);

    }while(aux < 1 || aux > 2);
    if(aux == 1)
        return 'S';
    else
        return 'N';

}