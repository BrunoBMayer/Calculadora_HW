// Criado por Bruno Mayer
// Criação da função convertToBinary (16h22 dia 29/08)
// Criação da função convertToOctal (17h01 dia 29/08)
// Criação da função convertToHexadecimal (17h34 dia 29/08)
// Criação da função convertToBCD (18h31 dia 29/08)
// Criação da função convertTo16Bits (19h55 dia 29/08)
// Criação da função printFloatRepresentation (20h15 dia 29/08)
// Criação da função printDoubleRepresentation (20h44 dia 29/08)
// Otimização e organização do codigo (22h10 dia 30/08)

#include <stdio.h>
#include <stdint.h>

void baseDois(int n);
void baseOito(int n);
void baseDezesseis(int n);
void baseBCD(int n);
void complemento2(int n);
void printFloat(uint32_t num);
void printDouble(uint64_t num);
void floatToBinary(float f);
void doubleToBinary(double d);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int escolha, numero;
    float numFloat;
    double numDouble;

    do {
        printf("\nMenu:\n");
        printf("1. Converter para Binário\n");
        printf("2. Converter para Octal\n");
        printf("3. Converter para Hexadecimal\n");
        printf("4. Converter para BCD\n");
        printf("5. Converter para Complemento de 2\n");
        printf("6. Converter Float para Binário\n");
        printf("7. Converter Double para Binário\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        printf("\n");

        switch(escolha) {
            case 1:
                printf("Digite um número inteiro: ");
                scanf("%d", &numero);
                printf("Binário: ");
                baseDois(numero);
                printf("\n");
                break;
            case 2:
                printf("Digite um número inteiro: ");
                scanf("%d", &numero);
                printf("Octal: ");
                baseOito(numero);
                printf("\n");
                break;
            case 3:
                printf("Digite um número inteiro: ");
                scanf("%d", &numero);
                printf("Hexadecimal: ");
                baseDezesseis(numero);
                printf("\n");
                break;
            case 4:
                printf("Digite um número inteiro: ");
                scanf("%d", &numero);
                printf("BCD: ");
                baseBCD(numero);
                printf("\n");
                break;
            case 5:
                printf("Digite um número inteiro: ");
                scanf("%d", &numero);
                printf("Complemento de 2: ");
                complemento2(numero);
                printf("\n");
                break;
            case 6:
                printf("Digite um número float: ");
                scanf("%f", &numFloat);
                floatToBinary(numFloat);
                break;
            case 7:
                printf("Digite um número double: ");
                scanf("%lf", &numDouble);
                doubleToBinary(numDouble);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
}

void baseDois(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }
    int binario[32];
    int i = 0;

    while (numero > 0) {
        binario[i] = numero % 2;
        printf("%d / 2 = %d, resto = %d\n", numero, numero / 2, binario[i]);
        numero = numero / 2;
        i++;
    }
    
    printf("Considere os números de trás para frente!\n");

    printf("Resultado final em binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void baseOito(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }
    int octal[32];
    int i = 0;

    while (numero > 0) {
        octal[i] = numero % 8;
        printf("%d / 8 = %d, resto = %d\n", numero, numero / 8, octal[i]);
        numero = numero / 8;
        i++;
    }
    
    printf("Considere os números de trás para frente!\n");
    
    printf("Resultado final em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void baseDezesseis(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }
    char hexadecimal[32];
    int i = 0;

    while (numero > 0) {
        int resto = numero % 16;
        printf("%d / 16 = %d, resto = ", numero, numero / 16);
        if (resto < 10) {
            hexadecimal[i] = 48 + resto;
            printf("%d\n", resto);
        } else {
            hexadecimal[i] = 55 + resto;
            printf("%c\n", hexadecimal[i]);
        }
        numero = numero / 16;
        i++;
    }
    
    printf("Para o resto de divisão: 10-A, 11-B, 12-C, 13-D, 14-E, 15-F\n");
    printf("Considere os números de trás para frente!\n");

    printf("Resultado final em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void baseBCD(int numero) {
    if (numero == 0) {
        printf("0000\n");
        return;
    }
    int digitos[10];
    int i = 0;
    
    printf("O processo é fazer a conversão de binário de cada dígito separado (trás pra frente).\n");

    while (numero > 0) {
        digitos[i] = numero % 10;
        printf("Dígito: %d\n", digitos[i]);
        numero /= 10;
        i++;
    }

    printf("Resultado final em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        int binario[4] = {0, 0, 0, 0};
        int num = digitos[j];
        int k = 3;

        while (num > 0) {
            binario[k] = num % 2;
            num /= 2;
            k--;
        }

        for (k = 0; k < 4; k++) {
            printf("%d", binario[k]);
        }
        printf(" ");
    }
    printf("\n");
}

void complemento2(int numero){
    if (numero < -32768 || numero > 32767) {
        return;
    }
    
    int novoNumero = -numero;
    
    uint16_t complemento;

    if (novoNumero < 0) {
        complemento = (uint16_t)(~(-novoNumero) + 1);
    } else {
        complemento = (uint16_t)novoNumero;
    }

    for (int i = 15; i >= 0; i--) {
        printf("%d", (complemento >> i) & 1);
    }
}

void printFloat(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 31 || i == 23) {
            printf(" ");
        }
    }
    printf("\n");
}

void printDouble(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 63 || i == 52) {
            printf(" ");
        }
    }
    printf("\n");
}

void floatToBinary(float numeroFloat) {
    uint32_t *num = (uint32_t*)&numeroFloat;
    uint32_t sinal = (*num >> 31) & 1;
    uint32_t expoente = (*num >> 23) & 0xFF;
    uint32_t fracao = *num & 0x7FFFFF;

    printf("Float: %f\n", numeroFloat);
    printf("Bits: ");
    printFloat(*num);

    printf("Sinal: %d\n", sinal);
    printf("Expoente: %u\n", expoente);
    printf("Expoente com viés: %d\n", expoente - 127);
    printf("Fração: 0x%X\n", fracao);
}

void doubleToBinary(double numeroDouble) {
    uint64_t *num = (uint64_t*)&numeroDouble;
    uint64_t sinal = (*num >> 63) & 1;
    uint64_t expoente = (*num >> 52) & 0x7FF;
    uint64_t fracao = *num & 0xFFFFFFFFFFFFF;

    printf("Double: %lf\n", numeroDouble);
    printf("Bits: ");
    printDouble(*num);

    printf("Sinal: %llu\n", sinal);
    printf("Expoente: %llu\n", expoente);
    printf("Expoente com viés: %lld\n", (long long)(expoente - 1023));
    printf("Fração: 0x%llX\n", fracao);
}
