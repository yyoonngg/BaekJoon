#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100004], ret = 2000000004;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int s = 0, e = 0;
    while(s <= e && e < n) {
        ll diff = abs(a[s] - a[e]);
        if(diff < m) e++;
        else{
            ret = min(ret, diff);
            s++;
        }  
    }
    cout << ret << "\n";
    return 0;
}
