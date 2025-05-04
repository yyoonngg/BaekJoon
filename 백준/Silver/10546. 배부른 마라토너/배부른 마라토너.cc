#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v.resize(n);
    
    for(int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    for(int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        auto it = lower_bound(v.begin(), v.end(), s);

        if(it != v.end() && *it == s) {
            mp[s]--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(mp[v[i]]) {
            cout << v[i] << "\n";
            break;
        }
    }

    return 0;
}