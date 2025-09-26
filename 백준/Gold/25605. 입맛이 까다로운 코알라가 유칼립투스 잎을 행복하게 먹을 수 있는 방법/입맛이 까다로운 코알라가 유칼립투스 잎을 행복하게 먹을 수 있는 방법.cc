#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
vector<pair<int, int>> v;
int dp[101][1001][101]; // day, cnt, dok

int go(int day, int cnt, int dok) {
    if(day == m || cnt == n) { // 날짜가 다 되거나, 유칼립투스 끝
        return 0;
    }
    
    if(dp[day][cnt][dok] != -1) return dp[day][cnt][dok];
    
    int ret = 0;
    
    // 엎어버리기 - 다음 잎으로 넘어가지만 하루는 지나지 않음
    ret = max(ret, go(day, cnt+1, dok));
    
    // 그냥 자기 - 하루가 지나고 독 해독
    ret = max(ret, go(day+1, cnt, max(0, dok-b)));

    // 고분고분 먹기 - 잎을 먹고 하루가 지나서 독 해독
    int newDok = dok + v[cnt].first;
    if(newDok <= a) { // 독 최대 한계 넘지 않으면
        ret = max(ret, v[cnt].second + go(day+1, cnt+1, max(0, newDok-b)));
    }
    
    return dp[day][cnt][dok] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> a >> b >> c;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }    

    // DP 배열 초기화
    memset(dp, -1, sizeof(dp));
    
    cout << go(0, 0, c) << "\n";
}