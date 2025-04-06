#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int t;
string s;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> s;
        int x = 0, y = 0, dir = 0;
        v.clear();
        v.push_back({y, x});
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'F') {
                y += dy[dir];
                x += dx[dir];
                v.push_back({y, x});
            }
            else if(s[i] == 'B') {
                y += dy[(dir + 2) % 4];
                x += dx[(dir + 2) % 4];
                v.push_back({y, x});
            }
            else if(s[i] == 'L') {
                dir = (dir + 3) % 4;
            }
            else if(s[i] == 'R') {
                dir = (dir + 1) % 4;
            }
        }

        int maxX = 0, maxY = 0, minX = 0, minY = 0;
        for(auto route: v) {
            if(maxY < route.first) maxY = route.first;            
            if(maxX < route.second) maxX = route.second;
            if(minY > route.first) minY = route.first;            
            if(minX > route.second) minX = route.second;            
        }
        cout << abs(maxY - minY) * abs(maxX - minX) << "\n";
    }
    return 0;
}