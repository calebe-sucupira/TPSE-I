#include <stdio.h>
#define is_digit(x) (((x) >= '0') && ((x) <= '9') ? 1 : 0)
#define is_hex(x) (is_digit(x) || ((x) >= 'A') && ((x) <= 'F') || ((x) >= 'a') && ((x) <= 'f') ? "TRUE" : "FALSE")

int main() {
    char digito;
    printf("Digite um numero: ");
    scanf("%c", &digito);

    printf("%s\n", is_hex(digito));

    return 0;
}