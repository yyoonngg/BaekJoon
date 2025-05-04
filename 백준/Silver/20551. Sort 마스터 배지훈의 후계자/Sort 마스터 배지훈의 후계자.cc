#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++) {
        int d;
        cin >> d;

        auto it = lower_bound(a.begin(), a.end(), d);

        if(it != a.end() && *it == d) {
            cout << (it - a.begin()) << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}