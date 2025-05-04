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

        int left = 0, right = n - 1;
        int ans = -1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(a[mid] < d) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if(left < n && a[left] == d) {
            cout << left << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}