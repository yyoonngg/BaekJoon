#include <bits/stdc++.h>
using namespace std;
int n, a[204], lis[204], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    fill(lis, lis + 204, 1);
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            if(a[i] > a[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ret = max(ret, lis[i]);
    }
    cout << n - ret << "\n";
    return 0;   
}