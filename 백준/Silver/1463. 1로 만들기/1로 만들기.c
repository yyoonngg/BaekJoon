#include <stdio.h>
#include <string.h>

int dp[1000004];
int n;

int go(int m) {
    if (m == 1) return 0;

    if (dp[m] != -1) return dp[m];

    int ret = __INT_MAX__;

    if (m % 3 == 0) {
        int temp = go(m / 3);
        if (temp < ret) ret = temp;
    }
    if (m % 2 == 0) {
        int temp = go(m / 2);
        if (temp < ret) ret = temp;
    }

    int temp = go(m - 1);
    if (temp < ret) ret = temp;

    return dp[m] = ret + 1;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    printf("%d\n", go(n));
    return 0;
}
