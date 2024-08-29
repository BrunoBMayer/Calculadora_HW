#include <stdio.h>

void convertToBinary(int num) {
    int binary[32];
    int index = 0;

    while (num > 0) {
        binary[index] = num % 2;
        num /= 2;
        index++;
    }

    printf("Resultado em binário: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n\n");
}

void convertToOctal(int num) {
    int octal[32];
    int index = 0;

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
    char hexDigits[] = "0123456789ABCDEF";

    while (num > 0) {
        hex[index] = hexDigits[num % 16];
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

int main() {
    int num, escolha;

    printf("Digite um número em base 10: ");
    scanf("%d", &num);

    printf("Escolha a conversão:\n");
    printf("1 - Para binário\n");
    printf("2 - Para octal\n");
    printf("3 - Para hexadecimal\n");
    printf("4 - Para BCD\n");
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
        default:
            printf("Escolha inválida!\n");
            break;
    }

    return 0;
}

