#include <bits/stdc++.h>
using namespace std;
int n, m, a[10];
vector<int> v;
map<int, int> mp;

void backtrack(int start) {
    if((int)v.size() == m) {
        for(int num : v) cout << num << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < n; i++) {
        if(mp[i] == 1) continue;
        v.push_back(a[i]);
        mp[i] = 1;
        backtrack(i);
        v.pop_back();
        mp[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for(int i = 0; i < n; i++) {
        v.push_back(a[i]);
        mp[i] = 1;
        backtrack(i);
        v.pop_back();
        mp[i] = 0;
    }
    return 0;
}
