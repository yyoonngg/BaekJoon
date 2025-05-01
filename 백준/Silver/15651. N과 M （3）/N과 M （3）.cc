#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;

void backtrack() {
    if((int)v.size() == m) {
        for(int num : v) cout << num << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        v.push_back(i);
        backtrack();
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    backtrack();

    return 0;
}
