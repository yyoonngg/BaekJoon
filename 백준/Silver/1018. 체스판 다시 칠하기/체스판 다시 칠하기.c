#include <stdio.h>
#include <string.h>

int n, m;
int a[54][54], temp[54][54];
char c;
int ret = 987654321;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &c);
            a[i][j] = (c == 'W') ? 0 : 1;
        }
    }

    for(int y = 0; y + 8 <= n; y++) {
        for(int x = 0; x + 8 <= m; x++) {
            for(int color = 0; color < 2; color++) {
                memcpy(temp, a, sizeof(a));
                int sum = 0;
                int here = color;

                for(int i = y; i < y + 8; i++) {
                    for(int j = x; j < x + 8; j++) {
                        if(temp[i][j] != here) {
                            sum++;
                            temp[i][j] ^= 1;
                        }
                        here ^= 1;
                    }
                    here ^= 1;
                }
                if(sum < ret) ret = sum; 
            }
        }
    }

    printf("%d\n", ret);
    return 0;
}
