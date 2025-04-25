#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1004], lis[1004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fill(lis, lis + 1004, 1);
    for(int i = 0; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(a[i] > a[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ret = max(ret, lis[i]);
    }
    
    cout << ret << "\n";

    return 0;
}