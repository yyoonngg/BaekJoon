#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c, a[200004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }    

    sort(a, a + n);
    ll low = 0, high = a[n-1] - a[0];

    while(low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = 1; // 1번째 집엔 일단 설치하고 시작
        ll last = a[0];
        for(ll i = 1; i < n; i++) {
            if((a[i] - last) >= mid) {
                cnt++;
                last = a[i];
            }
        }

        if(cnt >= c) {
            low = mid + 1;
            ret = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ret << "\n";
}