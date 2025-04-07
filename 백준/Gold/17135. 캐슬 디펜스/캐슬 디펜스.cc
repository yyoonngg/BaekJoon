#include <bits/stdc++.h>
using namespace std;

int n, m, d, boardOrig[20][20];
int ans = 0;

int simulate(int a1, int a2, int a3) {
    int board[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = boardOrig[i][j];
    
    int killCount = 0;
    while (true) {
        // 남은 적이 있는지 확인
        bool exist = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(board[i][j] == 1){
                    exist = true;
                    break;
                }
            }
            if(exist) break;
        }
        if(!exist) break;
        
        set<pair<int,int>> targets;
        vector<int> archers = {a1, a2, a3};
        for (int ac : archers) {
            int bestDist = 1e9, targetRow = -1, targetCol = -1;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if(board[i][j] == 1){
                        int dist = abs(n - i) + abs(ac - j);
                        if(dist <= d){
                            if(dist < bestDist){
                                bestDist = dist;
                                targetRow = i;
                                targetCol = j;
                            } else if(dist == bestDist){
                                if(j < targetCol){ 
                                    targetRow = i;
                                    targetCol = j;
                                }
                            }
                        }
                    }
                }
            }
            if(targetRow != -1)
                targets.insert({targetRow, targetCol});
        }
        
        for (auto pos : targets) {
            int r = pos.first, c = pos.second;
            if(board[r][c] == 1) {
                board[r][c] = 0;
                killCount++;
            }
        }
        
        for (int i = n - 1; i >= 1; i--){
            for (int j = 0; j < m; j++){
                board[i][j] = board[i-1][j];
            }
        }
        for (int j = 0; j < m; j++){
            board[0][j] = 0;
        }
    }
    
    return killCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> boardOrig[i][j];
        }
    }
    
    for (int i = 0; i < m; i++){
        for (int j = i + 1; j < m; j++){
            for (int k = j + 1; k < m; k++){
                int kills = simulate(i, j, k);
                ans = max(ans, kills);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
