#include <bits/stdc++.h>
using namespace std;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
const int dsy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dsx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, ay, ax, dir;
char a[20][20], sw[20][20];
string s;
struct Zombi {
    int y, x, d;
};
vector<pair<int, int>> switchList;
vector<Zombi> zombiList;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') switchList.push_back({i, j});
            if(a[i][j] == 'Z') zombiList.push_back({i, j, 0});
        }
    }

    for(int i = 0; i < s.size(); i++) {
        // 아리 이동
        if(s[i] == 'F') {
            int nay = ay + dy[dir];
            int nax = ax + dx[dir];

            if(nay >= 0 && nay < n && nax >= 0 && nax < n) {
                ay = nay; ax = nax;
                // 스위치?
                if(a[ay][ax] == 'S') {
                    sw[ay][ax] = 1;
                    for(int j = 0; j < 8; j++) {
                        int ny = ay + dsy[j];
                        int nx = ax + dsx[j];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                        sw[ny][nx] = 1;
                    }
                }
                // 좀비?
                if(a[ay][ax] == 'Z' && sw[ay][ax] == 0) {
                    cout << "Aaaaaah!\n";
                    exit(0);
                }
            }
        }
        else if(s[i] == 'L') {
            dir = (dir + 1) % 4;
        }
        else if(s[i] == 'R') {
            dir = (dir + 3) % 4;
        }

        // 좀비 이동
        for(Zombi &z: zombiList) {
            if((z.y == 0 && z.d == 2) || (z.y == (n - 1) && z.d == 0)) {
                z.d = (z.d + 2) % 4;
            }
            else {
                int nzy = z.y + dy[z.d];
                int nzx = z.x + dx[z.d];
                // 아리? 불off?
                if(nzy == ay && nzx == ax && sw[nzy][nzx] == 0) {
                    cout << "Aaaaaah!\n";
                    exit(0);
                }
                if(a[nzy][nzx] != 'S') a[nzy][nzx] = 'Z';
                if(a[z.y][z.x] != 'S') a[z.y][z.x] = 'O'; 
                z.y = nzy; z.x = nzx;
            }
        }
    }

    cout << "Phew...\n";

    return 0;
}