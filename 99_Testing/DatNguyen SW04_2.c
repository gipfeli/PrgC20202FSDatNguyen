#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "board.h"
#include "delay.h"

int main(void){
    uint8_t n = 0;
    do
    {
        int code = n^(n/2);
        int converted = dec_to_bin(code);
        find_1(converted);

        printf("\n n: %3d", n); // ^: Bitwise XOR operator: n-th code = n XOR n/2
        // Change to bitshifting-approach for cleaner code.
        if(n<2){
            printf(" => 0000000%d", converted);
        } else if(n>=2 && n<4) {
            printf(" => 000000%d", converted);
        } else if(n>=4 && n<8) {
            printf(" => 00000%d", converted);
        } else if(n>=8 && n<16) {
            printf(" => 0000%d", converted);
        } else if(n>=16 && n<32) {
            printf(" => 000%d", converted);
        } else if(n>=32 && n<64) {
            printf(" => 00%d", converted);
        } else if(n>=64 && n<128) {
            printf(" => 0%d", converted);
        } else {
            printf(" => %d", converted);
        }

        n = n + 1;
    } while (n != 0);

    return 0;    
}

int dec_to_bin(int n){
    long binnum = 0;
    int rem, temp = 1;

    while(n!=0){
        rem = n%2;
        n = n/2;
        binnum = binnum + rem*temp;
        temp = temp*10;
    }
    
    return binnum;
}

int find_1(int n){
    while(n>0){
        int digit = n % 10;
        if (digit == 1){
            setSSEG1A();
            delay();
            clearSSEG1A();
            delay();
        }
        n/=10;
    }
}