#include <bits/stdc++.h>
using namespace std;
int n, m, a[10004];
vector<int> v;
set<vector<int>> ret;

void backtrack() {
    if((int)v.size() == m) {
        ret.insert(v);
        return;
    }

    for(int i = 0; i < n; i++) {
        v.push_back(a[i]);
        backtrack();
        v.pop_back();
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

    backtrack();

    for(auto _ret: ret) {
        for(int x : _ret) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

