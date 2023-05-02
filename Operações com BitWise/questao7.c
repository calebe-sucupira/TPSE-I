#include <stdio.h>
#define MASK_FULL_BIT 0xFF
#define MASK_SIGNIFICANT_BIT 0x80

void printBit(unsigned int number){
    for(int i = MASK_SIGNIFICANT_BIT; i != 0; i >>= 1) {
        if((number & i) != 0)
            printf("1");
        else
            printf("0");
    }
}

int movBitsLeft(unsigned int number) {
    int leftBits = MASK_FULL_BIT;
	for(int i = MASK_SIGNIFICANT_BIT; i != 0; i >>= 1) {
		if((number & i) == 0)
            leftBits <<= 1;
	}
    return leftBits;
}

int main() {
	unsigned int number = 0;
    scanf("%d", &number);
    printBit(movBitsLeft(number));

	return 0;
}

