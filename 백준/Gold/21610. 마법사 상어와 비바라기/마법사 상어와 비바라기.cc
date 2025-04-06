#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m, a[54][54], cloudMap[54][54], d, s, ret;
vector<pair<int, int>> moveList, cloudList;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> d >> s;
        d--;
        moveList.push_back({d, s});
    }

    // LOGIC
    cloudList.push_back({n - 1, 0}); cloudList.push_back({n - 1, 1});
    cloudList.push_back({n - 2, 0}); cloudList.push_back({n - 2, 1});
    for(auto move: moveList) {
        int hereD = move.first; int hereS = move.second;
        fill(&cloudMap[0][0], &cloudMap[0][0] + 54 * 54, 0);

        // 1, 2번 조건
        for(int c = 0; c < cloudList.size(); c++) {
            int ny = ((cloudList[c].first + (dy[hereD] * hereS) + (n * 25)) % n);
            int nx = ((cloudList[c].second + (dx[hereD] * hereS) + (n * 25)) % n);
            a[ny][nx] += 1;
            cloudList[c].first = ny;
            cloudList[c].second = nx;
            cloudMap[ny][nx] = 1;
        }

        // 4번 조건
        for(int i = 0; i < cloudList.size(); i++) {
            int cy = cloudList[i].first;
            int cx = cloudList[i].second;
            int sum = 0;
            for(int i = 1; i <= 7; i += 2) {
                int nearY = cy + dy[i];
                int nearX = cx + dx[i];
                if(nearY < 0 || nearX < 0 || nearY >= n || nearX >= n) continue;
                if(a[nearY][nearX] > 0) sum++;
            }
            a[cy][cx] += sum;
        }

        // 3번 조건
        cloudList.clear();

        // 5번 조건
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] >= 2 && cloudMap[i][j] == 0) {
                    cloudList.push_back({i, j});
                    a[i][j] -= 2;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret += a[i][j];
        }
    }
    cout << ret << "\n";

    return 0;
}