#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> a, v;

void go(int start, int depth) {
    if(depth == M) {
        for(int x : v) cout << x << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < (int)a.size(); i++) {
        v.push_back(a[i]);
        go(i, depth + 1);
        v.pop_back();    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    a.resize(N);

    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    go(0, 0);
}