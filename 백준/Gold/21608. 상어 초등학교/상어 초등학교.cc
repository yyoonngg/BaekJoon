#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int total = n * n;

    // 학생 배치 순서와 각 학생이 좋아하는 4명의 번호를 저장합니다.
    vector<int> order(total);
    // friends[i]는 학생 i가 좋아하는 학생 4명의 번호를 저장
    vector<vector<int>> friends(total + 1, vector<int>(4));
    
    for (int i = 0; i < total; i++){
        int stu;
        cin >> stu;
        order[i] = stu;
        for (int j = 0; j < 4; j++){
            cin >> friends[stu][j];
        }
    }
    
    // 교실의 좌석을 1-indexed로 사용 (행, 열 모두 1 ~ n)
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    
    // 네 방향 (상, 우, 하, 좌)
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    // 각 학생을 순서대로 자리 배치
    for (int idx = 0; idx < total; idx++){
        int stu = order[idx];
        int bestFriendCount = -1;
        int bestEmptyCount = -1;
        int bestRow = 0, bestCol = 0;
        
        // 모든 빈 좌석에 대해 후보 평가
        for (int r = 1; r <= n; r++){
            for (int c = 1; c <= n; c++){
                if(board[r][c] != 0) continue;  // 이미 배정된 자리
                
                int friendCount = 0;
                int emptyCount = 0;
                
                // 인접 4칸 검사
                for (int d = 0; d < 4; d++){
                    int nr = r + dy[d];
                    int nc = c + dx[d];
                    if(nr < 1 || nr > n || nc < 1 || nc > n) continue;
                    
                    if(board[nr][nc] == 0) {
                        emptyCount++;
                    } else {
                        // board[nr][nc]에 앉은 학생이 stu가 좋아하는 학생인지 검사
                        int seated = board[nr][nc];
                        for (int k = 0; k < 4; k++){
                            if(friends[stu][k] == seated){
                                friendCount++;
                                break;
                            }
                        }
                    }
                }
                
                // 조건 1: 좋아하는 학생 수 우선
                // 조건 2: 인접 빈 칸 수
                // 조건 3: 행, 열 번호 (작은 순)
                if(friendCount > bestFriendCount ||
                   (friendCount == bestFriendCount && emptyCount > bestEmptyCount) ||
                   (friendCount == bestFriendCount && emptyCount == bestEmptyCount && r < bestRow) ||
                   (friendCount == bestFriendCount && emptyCount == bestEmptyCount && r == bestRow && c < bestCol))
                {
                    bestFriendCount = friendCount;
                    bestEmptyCount = emptyCount;
                    bestRow = r;
                    bestCol = c;
                }
            }
        }
        board[bestRow][bestCol] = stu;
    }
    
    // 자리 배치가 끝났으므로, 만족도 점수 계산 (인접 좋아하는 학생 수에 따라 0, 1, 10, 100, 1000)
    int answer = 0;
    for (int r = 1; r <= n; r++){
        for (int c = 1; c <= n; c++){
            int stu = board[r][c];
            int friendCount = 0;
            for (int d = 0; d < 4; d++){
                int nr = r + dy[d];
                int nc = c + dx[d];
                if(nr < 1 || nr > n || nc < 1 || nc > n) continue;
                int neighbor = board[nr][nc];
                for (int k = 0; k < 4; k++){
                    if(friends[stu][k] == neighbor){
                        friendCount++;
                        break;
                    }
                }
            }
            if(friendCount == 1) answer += 1;
            else if(friendCount == 2) answer += 10;
            else if(friendCount == 3) answer += 100;
            else if(friendCount == 4) answer += 1000;
        }
    }
    
    cout << answer << "\n";
    return 0;
}
