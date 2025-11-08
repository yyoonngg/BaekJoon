#include <bits/stdc++.h>
using namespace std;
int n, m, a[104];
vector<pair<int, int>> v;

void boy(int here) {
    for(int i = 1; here * i <= n; i++) {
        a[here*i] ^= 1;
    }
}

void girl(int here) {
    a[here] ^= 1;

    int idx = 1;
    while(1) {
        if((here - idx) < 1 || (here + idx) > n) break;
        if(a[here - idx] != a[here + idx]) break;
        a[here - idx] ^= 1; a[here + idx] ^= 1;
        idx++;
    }
    
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});        
    }

    for(auto here : v) {
        if(here.first == 1) boy(here.second);
        else girl(here.second);
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
    return 0;
}