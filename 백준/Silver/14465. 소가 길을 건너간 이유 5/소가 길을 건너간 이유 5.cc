#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, b, a[100004], psum[100004], ret = 987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> b;
    for(int i = 1; i <= b; i++) cin >> a[i];
    sort(a, a + b + 1);

    int idx = 1;
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1];
        if(a[idx] == i) {
            idx++;
            psum[i]++;
        }
    }

    int s = 1, e = k;
    while(e <= n) {
        int sum = psum[e] - psum[s - 1];
        ret = min(ret, sum);
        s++; e++;
    }

    cout << ret << "\n";

    return 0;
}