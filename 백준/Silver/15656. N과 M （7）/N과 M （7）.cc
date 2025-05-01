#include <bits/stdc++.h>
using namespace std;
int n, m, a[10];
vector<int> v;

void backtrack() {
    if((int)v.size() == m) {
        for(int num : v) cout << num << " ";
        cout << "\n";
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

    return 0;
}
