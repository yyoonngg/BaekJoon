#include <bits/stdc++.h>
using namespace std;
int t, n, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        
        int ret = 0;
        vector<int> v;
        map<int, int> mp;

        for(int i = 1; i <= n; i++) {
            cin >> tmp;
            v.push_back(tmp);
            mp[tmp]++;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int first = v[i];
                int second = v[j];
                auto it = mp.find(second + abs(first - second));
                if(it != mp.end()) {
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }    
    return 0;
}