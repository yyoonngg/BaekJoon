#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    
    while(cin >> n) {
        int ret = 1;
        int cnt = 1;
        while(true) {
            if(ret % n == 0) {
                cout << cnt << "\n";
                break;
            }
            else {
                ret = 1 + ret % n * 10 % n;
                cnt++;
            }
        }
        
    }

    return 0;
}