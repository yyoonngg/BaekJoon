#include <stdio.h>
#include <string.h>
int n, m, psum[100004];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf(" %d", &a);
        psum[i] = psum[i-1] + a; 
    }    
    for(int i = 1; i <= m; i++) {
        int b, c;
        scanf(" %d %d", &b, &c);
        printf("%d\n", (psum[c]-psum[b-1]));
    }
    return 0;
}
