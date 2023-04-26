#include <stdio.h>
#define MASK 0xF

void splitLongInt(long int number) {
    for(int i = 0; i < 8; i++) {
        int values = (number >> (4*i)) & MASK;
        printf("Valor%d: %d\n", i+1, values);
    }
}


int main() {
    long int number = 0;
    printf("Digite um numero: ");
    scanf("%ld", &number);
    splitLongInt(number);

    return 0;
}