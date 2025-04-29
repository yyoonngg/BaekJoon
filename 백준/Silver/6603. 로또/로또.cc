#include <bits/stdc++.h>
using namespace std;
vector<int> v, picked;

void go(int idx) {
    if(picked.size() == 6) {
        for(int i = 0; i < 6; i++) {
            cout << picked[i] << " ";
        }
        cout << "\n";
        return;
    }
    if(idx == v.size()) return;
    
    picked.push_back(v[idx]);
    go(idx + 1);
    picked.pop_back();

    go(idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    while(true) {
        int k;
        cin >> k;
        if(k == 0) break;

        v.resize(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
        }

        picked.clear();
        go(0);
        cout << "\n";
    }
    return 0;
}