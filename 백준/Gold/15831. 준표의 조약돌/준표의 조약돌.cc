#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, b, w, l, r, bSum, wSum, ret;
char a[300004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> b >> w;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(r = 0; r < n; r++) {
        if(a[r] == 'W') wSum++;
        else bSum++;

        while(bSum > b && l <= r) {
            if(a[l] == 'W') wSum--;
            else bSum--;
            l++;
        }

        if(wSum >= w) ret = max(ret, r - l + 1);
    }

    cout << ret << "\n";

    return 0;
}