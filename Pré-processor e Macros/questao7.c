#include <stdio.h>
#define is_digit(x) (((x) >= 0) && ((x) <= 9) ? "TRUE" : "FALSE")

int main() {
    char digito;
    printf("Digite um numero: ");
    scanf("%c", &digito);

    printf("%s\n", is_digit(digito));

    return 0;
}