// Criado por Bruno Mayer
// Criação da função convertToBinary (16h22 dia 29/08)
// Criação da função convertToOctal (17h01 dia 29/08)
// Criação da função convertToHexadecimal (17h34 dia 29/08)
// Criação da função convertToBCD (18h31 dia 29/08)
// Criação da função convertTo16Bits (19h55 dia 29/08)
// Criação da função printFloatRepresentation (20h15 dia 29/08)
// Criação da função printDoubleRepresentation (20h44 dia 29/08)

#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int num) {
    int binary[32];
    int index = 0;

    printf("Conversao de %d para binario:\n", num);
    if (num == 0) {
        printf("Resultado em binario: 0\n\n");
        return;
    }

    while (num > 0) {
        binary[index] = num % 2;
        num /= 2;
        index++;
    }

    printf("Resultado em binario: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n\n");
}

void convertToOctal(int num) {
    int octal[32];
    int index = 0;

    printf("Conversao de %d para octal:\n", num);
    if (num == 0) {
        printf("Resultado em octal: 0\n\n");
        return;
    }

    while (num > 0) {
        octal[index] = num % 8;
        num /= 8;
        index++;
    }

    printf("Resultado em octal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n\n");
}

void convertToHexadecimal(int num) {
    char hex[32];
    int index = 0;

    printf("Conversao de %d para hexadecimal:\n", num);
    if (num == 0) {
        printf("Resultado em hexadecimal: 0\n\n");
        return;
    }

    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10)
            hex[index] = '0' + remainder;
        else
            hex[index] = 'A' + (remainder - 10);
        num /= 16;
        index++;
    }

    printf("Resultado em hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n\n");
}

void convertToBCD(int num) {
    int digits[10];
    int index = 0;

    printf("Conversao de %d para BCD:\n", num);
    if (num == 0) {
        printf("Resultado em BCD: 0000\n\n");
        return;
    }

    while (num > 0) {
        digits[index] = num % 10;
        num /= 10;
        index++;
    }

    printf("Resultado em BCD: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%04d ", digits[i]);
    }
    printf("\n\n");
}

void convertTo16Bits(int num) {
    unsigned short int result;

    printf("Conversao de %d para complemento de dois (16 bits):\n", num);

    if (num >= 0) {
        result = (unsigned short)num;
    } else {
        result = (unsigned short)(65536 + num); 
    }

    printf("Resultado em binario: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (result >> i) & 1);
    }
    printf("\n\n");
}

void printFloatRepresentation(float num) {
    unsigned int* ptr = (unsigned int*)&num;
    unsigned int bits = *ptr;

    printf("Representacao de %.6f em float:\n", num);
    printf("Bits: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n\n");
}

void printDoubleRepresentation(double num) {
    unsigned long long* ptr = (unsigned long long*)&num;
    unsigned long long bits = *ptr;

    printf("Representacao de %.6lf em double:\n", num);
    printf("Bits: ");
    for (int i = 63; i >= 0; i--) {
        printf("%lld", (bits >> i) & 1);
    }
    printf("\n\n");
}

int main() {
    int num, escolha;
    float fnum;
    double dnum;

    printf("Digite um numero inteiro em base 10: ");
    scanf("%d", &num);

    printf("Escolha a conversao:\n");
    printf("1 - Para binario\n");
    printf("2 - Para octal\n");
    printf("3 - Para hexadecimal\n");
    printf("4 - Para BCD\n");
    printf("5 - Para complemento de dois (16 bits)\n");
    printf("6 - Para representar float\n");
    printf("7 - Para representar double\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            convertToBinary(num);
            break;
        case 2:
            convertToOctal(num);
            break;
        case 3:
            convertToHexadecimal(num);
            break;
        case 4:
            convertToBCD(num);
            break;
        case 5:
            convertTo16Bits(num);
            break;
        case 6:
            printf("Digite um numero real para float: ");
            scanf("%f", &fnum);
            printFloatRepresentation(fnum);
            break;
        case 7:
            printf("Digite um numero real para double: ");
            scanf("%lf", &dnum);
            printDoubleRepresentation(dnum);
            break;
        default:
            printf("Escolha inválida!\n");
            break;
    }

    return 0;
}

