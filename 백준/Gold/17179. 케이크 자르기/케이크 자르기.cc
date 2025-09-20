#include<bits/stdc++.h>
using namespace std;
int n, m, l, s[1004], q[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> l;
    for(int i = 0; i < m; i++) {
        cin >> s[i];
    }    
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }

    for(int t = 0; t < n; t++) {
        int low = 1, high = l;
        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;
            int last = 0, cnt = 0;

            for(int i = 0; i < m; i++) {
                if((s[i] - last) >= mid) {
                    cnt++;
                    last = s[i];
                }
            }
            if((l - last) >= mid) cnt++;

            if(cnt >= q[t] + 1) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }

}