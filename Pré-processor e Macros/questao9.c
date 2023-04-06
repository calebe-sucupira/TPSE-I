#include <stdio.h>
#define SWAP(x, y) \
    (x) += (y); \
    (y) = (x) - (y); \
    (x) -= (y); \

int main() {
    int a = 0, b = 0;

    printf("Digite um numero para a: ");
    scanf("%d", &a);
    printf("Digite um numero para b: ");
    scanf("%d", &b);

    SWAP(a, b);

    printf("\nO numero de a agora eh: %d", a);
    printf("\nO numero de b agora eh: %d\n", b);

    return 0;
}