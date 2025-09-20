#include <bits/stdc++.h>
using namespace std;
int n, k, a[100004], sum, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int low = 0, high = sum / k;

    while(low <= high) {
        int mid = (low + high) / 2;

        int psum = 0;
        int groups = 0;
        for(int i = 0; i < n; i++) {
            psum += a[i];
            if(psum >= mid) {
                groups++;
                psum = 0;
            }
        }

        if(groups >= k) {
            low = mid + 1;
            ret = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ret << "\n";
}