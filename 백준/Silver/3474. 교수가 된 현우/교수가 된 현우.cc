#include<bits/stdc++.h>
using namespace std;

int n, a;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while(n--) {
        cin >> a;
        int cnt5 = 0;
        for(int i = 5; i <= a; i *= 5){
            cnt5 += a / i;
        }
        cout << cnt5 << "\n";
    }
    return 0;
}