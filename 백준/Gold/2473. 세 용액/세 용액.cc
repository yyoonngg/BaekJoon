#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100004], l, r, ret = 9876543210;
vector<ll> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    
    for(int here = 0; here < n; here++) {
        int l = 0, r = n - 1;
        if(l == here) l++;
        if(r == here) r--;

        while(l < r) {
            ll sum = a[here] + a[l] + a[r];
            if(abs(sum) < abs(ret)) {
                ret = sum;
                ans.clear();
                ans.push_back(a[here]);
                ans.push_back(a[l]);
                ans.push_back(a[r]);
            }

            if(sum < 0) {
                l++;
                if(l == here) l++;
            }
            else if(sum >= 0) {
                r--;
                if(r == here) r--;
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(ll a : ans) cout << a << " ";
}