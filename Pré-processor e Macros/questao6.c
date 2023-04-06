#include <stdio.h>
#define divide_por_10(x) (((x) % 10 == 0) ? "TRUE" : "FALSE")

int main() {
    int num = 0;
    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("%s\n", divide_por_10(num));
    
    return 0;
}