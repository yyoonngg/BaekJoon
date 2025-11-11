#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[24][24];
ll ret = LLONG_MAX;
vector<int> A, B;
ll sumA, sumB;

void dfs(int i) {
    if(i == n) {
        if(!A.empty() && !B.empty()) {
            ret = min(ret, llabs(sumA - sumB));
        }
        return;
    }

    ll addA = 0;
    for(int j : A) addA += a[i][j] + a[j][i];
    A.push_back(i);
    sumA += addA;
    dfs(i + 1);
    sumA -= addA;
    A.pop_back();

    ll addB = 0;
    for(int j : B) addB += a[i][j] + a[j][i];
    B.push_back(i);
    sumB += addB;
    dfs(i + 1);
    sumB -= addB;
    B.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    A.push_back(0);
    dfs(1);

    cout << ret << "\n";

    return 0;
}