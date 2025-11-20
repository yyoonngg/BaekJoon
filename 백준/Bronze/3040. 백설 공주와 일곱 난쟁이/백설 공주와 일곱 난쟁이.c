#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[10], bidx = 0, b[10];

void go(int idx, int cnt, int sum) {
    // printf("%d, %d, %d\n", idx, cnt, sum);
    if(idx > 9) return;
    if(cnt == 7) {
        if(sum == 100) {
            for(int i = 0; i < 7; i++) printf("%d\n", b[i]);
            return;
        }
        else {
            return;
        }
    }   

    go(idx+1, cnt, sum);
    
    b[bidx++] = a[idx];
    go(idx+1, cnt+1, sum+a[idx]);
    b[bidx--] = 0;
}

int main() {
    for(int i = 0; i < 9; i++) {
        scanf("%d", &a[i]);
    }    

    go(1, 0, 0);

    b[bidx++] = a[0];
    go(1, 1, a[0]);
    return 0;
}