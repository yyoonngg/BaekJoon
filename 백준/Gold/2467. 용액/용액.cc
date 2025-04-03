#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100004], ret_s, ret_e, ret = 2000000004;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0, e = n - 1;
    while(s < e) {
        int sum = a[s] + a[e];
        int sum_abs = abs(sum);
        if(sum_abs <= ret) {
            ret = sum_abs;
            ret_s = s; ret_e = e;
        }
        if(sum < 0) s++;
        else e--;
    }

    cout << a[ret_s] << " " << a[ret_e] << "\n";

    return 0;
}
