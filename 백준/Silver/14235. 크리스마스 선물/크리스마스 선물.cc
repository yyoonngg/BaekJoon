#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num) {
            for(int j = 0; j < num; j++) {
                int gift;
                cin >> gift;
                pq.push(gift);
            }
        }
        else if(!pq.empty()) {
            cout << pq.top() << "\n";
            pq.pop();
        }   
        else {
            cout << "-1\n";
        }
    }
    return 0;
}