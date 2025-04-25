#include <bits/stdc++.h>
using namespace std;
int n, a[2000001], p, lo, hi, ret, sum;
bool che[4000004];

int main() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(che[i]) continue;
        for(int j = 2*i; j <= n; j += i) {
            che[j] = 1;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(!che[i]) a[p++] = i;
    }
    while(1) {
        if(sum >= n) sum -= a[lo++];
        else if(hi == p) break;
        else sum += a[hi++];
        if(sum == n) ret++;
    }

    cout << ret << "\n";
    return 0;
}