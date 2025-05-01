#include<bits/stdc++.h>
using namespace std;
int n, a[1004];
deque<int> dq;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dq.push_back(i);

    int dist = 0;
    int dir = 1;
    int here;
    while(!dq.empty()) {
        if(dist > 0) {
            here = dq.front();
            dq.pop_front();
            dq.push_back(here);
            dist--;
        }
        else if(dist < 0) {
            here = dq.back();
            dq.pop_back();
            dq.push_front(here);
            dist++;
        }
        else {
            if(dir) {
                here = dq.front();
                cout << here << " ";
                dq.pop_front();
            }
            else {
                here = dq.back();
                cout << here << " ";
                dq.pop_back();
            }
            dist = a[here - 1];
            if(dist > 0) dist--, dir = 1;
            else dist++, dir = 0;
        }
    }


    return 0;
}