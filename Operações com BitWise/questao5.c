#include <stdio.h>
#include <stdbool.h>

int countBits(bool w,unsigned int value) {
    int count = 0;
    if(w) {
        while (value > 0) {
            if(value & 1) 
                count++;
        
            value >>= 1;
        }
    }
    else {
        
    }
    return count;
}

int main() {
    unsigned int value = 0;
    int w;
    scanf("%d %d", &w, &value);
    bool w_bool = (bool) w;
    printf("%d", countBits(w_bool, value));

    return 0;
}