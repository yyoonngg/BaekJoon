#include <bits/stdc++.h>
using namespace std;

int n, x, tmp, cnt;
vector<int> nodeList[50];

void go(int x) {
    if(nodeList[x].size()){
        for(int i : nodeList[x]) {
            go(i);
        }
        nodeList[x].clear();
    }
    nodeList[x].push_back(-1);
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp != -1) {
            nodeList[tmp].push_back(i);
        } 
    }
    cin >> x;

    go(x);

    for(int i = 0; i < n; i++) {
        auto it = nodeList[i].begin();
        while(it != nodeList[i].end()) {
            if(*it == x) {
                it = nodeList[i].erase(it);
            }
            else {
                it++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(nodeList[i].size() == 0) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}