#include <bits/stdc++.h>
using namespace std;
int n, ret;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back({num, i});
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(auto vv: v) {
        ret += (sum + vv.first);
        sum += vv.first;
    }
    cout << ret << "\n";
    return 0;   
}