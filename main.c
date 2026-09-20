#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* palavraValida = "1044";
char* palavraInvalida = "0.00";

#define ZERO_A_ESQUERDA "ERR0: A palavra inserida possui um zero a esquerda de forma invalida\nUse uma virgula ou elimine-o"
#define PONTO_FLUTUANTE "ERRO: O ponto '.' não é válido como separado de ponto flutuante\nSubstitue por vírgula use como divisor para milhares"

char* scanner(char* palavra[]) {

    char* controle = palavra[0];
    while (controle != '\0') {

    }

}

int main(void) {

    char* palavra = palavraValida;
    scanner(palavra);

    return 0;
}