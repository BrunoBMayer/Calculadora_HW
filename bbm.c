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



int main() {
    int num, escolha;

    printf("Digite um número em base 10: ");
    scanf("%d", &num);

    printf("Escolha a conversão:\n");
    printf("1 - Para binário\n");
    printf("2 - Para octal\n");
    printf("3 - Para hexadecimal\n");
    printf("4 - Para BCD\n");
    printf("5 - De base 10  para base com sinal com 16 bits: \n");
    printf("Converter real em decimal para float e double: \n");
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
