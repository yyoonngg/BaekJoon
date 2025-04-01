#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret;

void go(ll sum, vector<int> v) {
    if(v.size() == 2) {
        ret = max(ret, sum);
        return;
    }
    for(int i = 1; i < v.size() - 1; i++) {
        vector<int> temp = v;
        temp.erase(temp.begin() + i);
        go(sum + (v[i - 1] * v[i + 1]), temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    go(0, a);

    cout << ret << "\n";
    
    return 0;
}