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
    
    if(a[0] == 'W') wSum++;
    else bSum++;

    while(l <= r && r < n) {
        int tmpW = wSum, tmpB = bSum;
        if(wSum >= w && bSum <= b) {
            ret = max(ret, (r - l + 1));
            r++;
            if(a[r] == 'W') wSum++;
            else bSum++;
            continue;
        }

        if(wSum < w) {
            r++;
            if(a[r] == 'W') tmpW++;
            else tmpB++;
        }

        if(bSum > b) {
            if(a[l] == 'W') tmpW--;
            else tmpB--;
            l++;
        }
        wSum = tmpW; bSum = tmpB;
    }

    cout << ret << "\n";

    return 0;
}