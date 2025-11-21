#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n, map[104][104];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = a; i < a + 10; i++) {
            for(int j = b; j < b + 10; j++) {
                map[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(map[i][j] == 1) cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
