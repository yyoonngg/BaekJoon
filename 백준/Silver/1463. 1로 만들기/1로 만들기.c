#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
int dp[1000004];

int go(int m, int cnt) {
    if(m == 1) {
        return 0;
    }
    
    int ret = __INT_MAX__;
    if(m % 3 == 0) {
        int *_ret = &dp[m / 3];
        if(*_ret == -1) *_ret = go(m / 3, cnt + 1);
        if(ret > *_ret) ret = *_ret;
    } 
    if(m % 2 == 0) {
        int *_ret = &dp[m / 2];
        if(*_ret == -1) *_ret = go(m / 2, cnt + 1);
        if(ret > *_ret) ret = *_ret;
    }
    int *_ret = &dp[m-1];
    if(*_ret == -1) *_ret = go(m - 1, cnt + 1);
    if(ret > *_ret) ret = *_ret;

    return ret + 1;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf(" %d", &n);    
    printf("%d\n", go(n, 0));
    return 0;
}