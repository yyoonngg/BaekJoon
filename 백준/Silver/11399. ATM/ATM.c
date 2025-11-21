#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, a[1004], psum[1004], ret;

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    scanf(" %d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    qsort(a, n, sizeof(int), cmp);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        ret += sum;
    }

    printf("%d\n", ret);
    return 0;
}