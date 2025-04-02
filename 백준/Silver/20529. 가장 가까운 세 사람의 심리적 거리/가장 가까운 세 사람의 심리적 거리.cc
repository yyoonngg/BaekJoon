#include<bits/stdc++.h>
using namespace std;
int t, n;

int diff(string a, string b) {
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        if(a[i] != b[i]) sum++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<string> v(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        if(n > 32) {
            cout << "0\n";
            continue;
        }

        int min_dist = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int dist = diff(v[i], v[j]) + diff(v[j], v[k]) + diff(v[k], v[i]);
                    min_dist = min(min_dist, dist);
                }
            }
        }

        cout << min_dist << "\n";
    }
    return 0;
}