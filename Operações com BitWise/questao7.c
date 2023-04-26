#include <stdio.h>

void printBit(unsigned int number){
    for(int i = 0x80; i != 0; i >>= 1) {
        if((number & i) != 0)
            printf("1");
        else
            printf("0");
    }
}

int movBitsLeft(unsigned int number) {
    int leftBits = 0xFF;
	for(int i = 0x80; i != 0; i >>= 1) {
		if((number & i) == 0)
            leftBits <<= 1;
	}
    return leftBits;
}

int main() {

	unsigned int number = 0;
    printf("Digite um numero: ");
    scanf("%d", &number);
    printf("O numero em binario eh: ");
    printBit(number);
	printf("\nAgora o numero eh: ");
    printBit(movBitsLeft(number));
    printf("\n");

	return(0);
}

