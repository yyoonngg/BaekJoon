#include <bits/stdc++.h>
using namespace std;
int N, M, visited[10004], NN;
vector<int> a, v;

void go(int n, int num) {
    if(num == M) {
        for(int nn : v) cout << a[nn] << " ";
        cout << "\n";
        return;
    }

    for(int i = n; i < NN; i++) {
        v.push_back(i);
        go(i, num + 1);
        v.pop_back();    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if(!visited[tmp]) {
            a.push_back(tmp);
            visited[tmp]++;
        }
    }

    sort(a.begin(), a.end());

    NN = a.size();

    for(int i = 0; i < NN; i++) {
        v.push_back(i);
        go(i, 1);
        v.pop_back();
    }

}