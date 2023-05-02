#include <stdio.h>
#include <stdbool.h>

int setBits(bool w, unsigned int i, unsigned int j, unsigned int value) {
    if((i >= 0 && i < 32) && (j >= 0 && j < 32)) {
        if(w) {
            for(unsigned int bit_i = i; bit_i <= j; bit_i++) {
                value |= (1 << bit_i);
            }
        }
        else {
            for(unsigned int bit_i = i; bit_i <= j; bit_i++) {
                value |= (1 << bit_i);
            }
            value = ~value;
        }
    }
    else{
        value = -1;
    }
    return value;

}
int main() {
    int w;
    unsigned int value, i, j;
    scanf("%d %d %d %d", &w, &i, &j, &value);
    bool w_bool = (bool) w;
    printf("%d", setBits(w, i, j, value));
}