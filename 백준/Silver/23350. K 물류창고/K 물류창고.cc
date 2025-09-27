#include <bits/stdc++.h>
using namespace std;
int n, m;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> v(n+1, 0);

    for(int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        q.push({p, w});
        v[p]++;
    }    

    int ww = m;
    int ret = 0;
    stack<pair<int, int>> stk;

    while(!q.empty()){
        pair<int, int> here = q.front(); q.pop();
        
        // 1. 우선순위가 안 맞음
        if(here.first < ww) {
            ret += here.second;
            q.push(here);
        }
        // 2. 우선순위는 맞음
        else {
            if(stk.empty()) {
                v[here.first]--;
                ret += here.second;
                stk.push(here);
            }
            else {
                stack<pair<int, int>> tmp;
                while(!stk.empty() && stk.top().second < here.second && stk.top().first == here.first) {
                    tmp.push(stk.top());
                    ret += stk.top().second;
                    stk.pop();
                }             
                ret += here.second;
                v[here.first]--;
                stk.push(here);
                while(!tmp.empty()) {
                    ret += tmp.top().second;
                    stk.push(tmp.top()); tmp.pop();
                }   
            }
        }

        if(v[ww] == 0) ww--;

    }

    cout << ret << "\n";

}