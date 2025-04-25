#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1004], lis[1004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(a[i] > a[j]) {
                lis[i] = max(lis[j] + a[i], lis[i]);
            } 
        } 
        ret = max(ret, lis[i]);
    }

    cout << ret << "\n";

    return 0;
}