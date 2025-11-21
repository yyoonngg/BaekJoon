#include <stdio.h>
#include <string.h>
int n, m, aidx;
int a[12], visited[12];

void go(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            visited[i]++;
            a[aidx++] = i;
            go(cnt+1);
            visited[i]--;
            aidx--;
        }
    }
    return;
}
int main() {
    scanf("%d %d", &n, &m);
    
    go(0);
    
    return 0;
}
