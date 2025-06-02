#include <bits/stdc++.h>
using namespace std;
int n, ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int vv: v) {
        ret += (sum + vv);
        sum += vv;
    }
    cout << ret << "\n";
    return 0;   
}