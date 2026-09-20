#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTEIRO                  "INTEIRO"
#define INTEIRO_COM_SINAL        "INTEIRO COM SINAL"
#define PONTO_FLUTUANTE          "P.FLUTUANTE"
#define PFLUTUANTE_COM_SINAL     "P.FLUTUANTE COM SINAL"
#define VALOR_MONETARIO          "VALOR MONETARIO"
#define ZERO                     "ZERO"

#define VALOR_MONETARIO_INVALIDO "VALOR MONETARIO INVALIDO"
#define ZERO_A_ESQUERDA          "ERRO: ZERO A ESQUERDA"
#define PONTO_FLUTUANTE_INV      "ERRO: PONTO FLUTUANTE COM '.' ACEITO SOMENTE COM ','"
#define ERRO                     "ERRO: ENTRADA INVALIDA"

#define PROXIMO_ELEMENTO p++; caractere = *p

const char* scanner(const char* palavra) {

    const char* p = palavra;
    char caractere = *p;

    int sinal = 0;

    estadoInicialQ0:
        if (caractere == '0') {
            PROXIMO_ELEMENTO;
            goto estadoQ1;
        }
        if (caractere == '-') {
            PROXIMO_ELEMENTO;
            sinal = 1;
            goto estadoQ5;
        }
        if (caractere >= '1' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ7;
        }
        if (caractere == '$') {
            PROXIMO_ELEMENTO;
            goto estadoQ8;
        }
        return ERRO;

    estadoQ1:
        if (caractere == '\0') {
            return ZERO;
        }
        if (caractere >= '0' && caractere <= '9') {
            return ZERO_A_ESQUERDA;
        }
        if (caractere == '.') {
            return PONTO_FLUTUANTE_INV;
        }
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ3;
        }
        return ERRO;

    estadoQ3:
        if (caractere == '0') {
            return ERRO;
        }
        if (caractere >= '1' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ4;
        }
        return ERRO;

    estadoQ4:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ4;
        }
        if (caractere == '\0') {
            if (sinal) {
                return PFLUTUANTE_COM_SINAL;
            }
            return PONTO_FLUTUANTE;
        }
        return ERRO;

    estadoQ5:
        if (caractere >= '1' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ7;
        }
        if (caractere == '0') {
            PROXIMO_ELEMENTO;
            goto estadoQ6;
        }
        return ERRO;

    estadoQ6:
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ3;
        }
        if (caractere == '\0') {
            return ERRO;
        }
        if (caractere == '.') {
            return PONTO_FLUTUANTE_INV;
        }
        return ERRO;

    estadoQ7:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ7;
        }
        if (caractere == '\0') {
            if (sinal) {
                return INTEIRO_COM_SINAL;
            }
            return INTEIRO;
        }
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ3;
        }
        if (caractere == '.') {
            return PONTO_FLUTUANTE_INV;
        }
        return ERRO;

    estadoQ8:
        if (caractere >= '1' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ9;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ9:
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ10;
        }
        if (caractere == '.') {
            PROXIMO_ELEMENTO;
            goto estadoQ18;
        }
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ20;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ10:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ12;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ12:
        if (caractere == '.') {
            PROXIMO_ELEMENTO;
            goto estadoQ18;
        }
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ15;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ15:
        if (caractere == '\0') {
            return VALOR_MONETARIO;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ16:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ17;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ17:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ19;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ18:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ16;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ19:
        if (caractere == '.') {
            PROXIMO_ELEMENTO;
            goto estadoQ18;
        }
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ10;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ20:
        if (caractere >= '0' && caractere <= '9') {
            PROXIMO_ELEMENTO;
            goto estadoQ16;
        }
        if (caractere == '.') {
            PROXIMO_ELEMENTO;
            goto estadoQ18;
        }
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ10;
        }
        return VALOR_MONETARIO_INVALIDO;

    estadoQ21:
        if (caractere == ',') {
            PROXIMO_ELEMENTO;
            goto estadoQ10;
        }
        return VALOR_MONETARIO_INVALIDO;
}

int main(void) {

    char* teste1 = "21"; // valido
    char* teste2 = "-21"; // valido
    char* teste3 = "021"; // nao valido
    char* teste4 = "2.1"; // nao valido
    char* teste5 = "2,1"; // valido
    char* teste6 = "-0,34"; // valido
    char* teste7 = "-0.34"; // nao valido
    char* teste8 = "$5.567,78"; // valido
    char* teste9 = "$5,567.78";
    char* teste10 = "-2.1"; // nao valido
    char* teste11 = "$5.5"; // nao valido

    printf("%s = %s\n", teste1, scanner(teste1));
    printf("%s = %s\n", teste2, scanner(teste2));
    printf("%s = %s\n", teste3, scanner(teste3));
    printf("%s = %s\n", teste4, scanner(teste4));
    printf("%s = %s\n", teste5, scanner(teste5));
    printf("%s = %s\n", teste6, scanner(teste6));
    printf("%s = %s\n", teste7, scanner(teste7));
    printf("%s = %s\n", teste8, scanner(teste8));
    printf("%s = %s\n", teste9, scanner(teste9));
    printf("%s = %s\n", teste10, scanner(teste10));
    printf("%s = %s\n", teste11, scanner(teste11));

    return 0;
}