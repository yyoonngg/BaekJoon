#include <bits/stdc++.h>
using namespace std;
int n, m, a[100004], psum[100004];
struct Jisi {
    int a, b, k;
};
vector<Jisi> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        int ta, tb, tk;
        cin >> ta >> tb >> tk;
        v.push_back({ta, tb, tk});
    }
    for(int i = 0; i < m; i++) {
        Jisi here = v[i];
        psum[here.a] += here.k;
        if(here.b < n) psum[here.b + 1] -= here.k;
    }
    for(int i = 1; i <= n; i++) {
        psum[i] += psum[i - 1];
    }

    for(int i = 1; i <= n; i++) cout << a[i] + psum[i] << " ";
    
    return 0;
}