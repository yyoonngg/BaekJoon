#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, ret;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= (n/2); i++) {
        int here = i;
        int sum = 0;
        while(sum <= n) {
            sum += here;

            if(sum == n) { ret++; break; }
            here++;
        }
    }
    printf("%d", ret+1);
    return 0;
}