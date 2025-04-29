#include <bits/stdc++.h>
using namespace std;
int n, m, a[10], tmp, ret;
string s;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> m;
    fill(a, a + 10, 1);
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        a[tmp] = 0;
    }

    for(int i = 0; i <= 1000000; i++) {
        string ss = to_string(i);
        bool flag = false;
        for(int j = 0; j < ss.size(); j++) {
            if(a[(int)ss[j]-'0'] == 0) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        else v.push_back(i);
    }

    // 1. N근처 숫자로 이동
    // 2. +와 -로 하나씩 이동

    ret = abs(100 - atoi(s.c_str()));
    
    for(int it: v) {
        ret = min(ret, abs(it - atoi(s.c_str())) + (int)to_string(it).size());
    }
    cout << ret << "\n";
    return 0;
}