#include <bits/stdc++.h>
using namespace std;
int n, m, a[200004];
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        if(!mp[a[i]]) mp[a[i]] = i + 1;
    }
    for(int i = 0; i < m; i++) {
        int d;
        cin >> d;
        if(mp[d]) {
            cout << mp[d] - 1 << "\n";
        }
        else {
            cout << "-1\n";
        }  
    }
    return 0;
}