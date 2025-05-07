#include <bits/stdc++.h>
using namespace std;
int n, m, a[10004];
vector<int> v;
bool used[8];
set<vector<int>> ret;

void backtrack(int idx) {
    if((int)v.size() == m) {
        ret.insert(v);
        return;
    }

    for(int i = idx; i < n; i++) {
        if(used[i]) continue;

        used[i] = true;        
        v.push_back(a[i]);
        backtrack(i + 1);
        v.pop_back();
        used[i] = false;
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

    backtrack(0);

    for(auto _ret: ret) {
        for(int x : _ret) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

