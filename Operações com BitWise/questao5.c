#include <stdio.h>

int countBits(int number) {
    int count = 0;
    while (number > 0) {
        if(number & 1) 
        count++;
        number >>= 1;
    }
    
    return count;
}

int main() {
    int number = 0;
    printf("Digite um numero: ");
    scanf("%d", &number);
    printf("O numero %d possui %d bit(s) definidos.\n",number, countBits(number));

    return 0;
}