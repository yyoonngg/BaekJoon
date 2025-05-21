#include<bits/stdc++.h>
using namespace std;
int m, n, a[15004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == m) {
                ret++;
            }
        }
    }
    cout << ret << "\n";
    return 0;
} 