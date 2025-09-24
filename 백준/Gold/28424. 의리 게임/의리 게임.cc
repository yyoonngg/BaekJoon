#include <bits/stdc++.h>
using namespace std;
int N, Q, n[100004], die[100004], parent[100004];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) { cin >> n[i]; die[i] = n[i]; }
    for(int i = 0; i <= N; i++) parent[i] = i;

    while(Q--) {
        int q;
        cin >> q;
        if(q == 1) {
            int a, b;
            cin >> a >> b;
            int i = find(a-1); // 아직 남은 첫 학생으로 점프
            while(b > 0 && i < N) {
                if(die[i] > b) { // 이번 학생이 다 마시고도 남은
                    die[i] -= b;
                    b = 0;
                    break;
                }
                else {          // 만취 -> 다음 살아있는 학생으로 연결
                    b -= die[i];
                    die[i] = 0;
                    parent[i] = find(i+1); // i는 스킵되도록
                    i = parent[i];
                }
            }
        }
        else if(q == 2) {
            int a;
            cin >> a;
            cout << (n[a-1] - die[a-1]) << "\n";
        }
    }
    return 0;
}