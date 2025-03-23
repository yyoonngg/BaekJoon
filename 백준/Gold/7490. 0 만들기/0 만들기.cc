#include <bits/stdc++.h>
using namespace std;

int n;

// 수식을 계산하는 함수 (수식 결과가 0인지 확인)
bool evaluate(const string& expr) {
    int sum = 0, num = 0;
    char op = '+';

    for (char c : expr) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // 숫자 조합
        } else if (c == '+' || c == '-') {
            sum += (op == '+') ? num : -num; // 이전 연산을 수행
            op = c; // 연산자 변경
            num = 0; // 숫자 초기화
        }
    }
    sum += (op == '+') ? num : -num; // 마지막 수 처리

    return sum == 0;
}

// DFS로 수식 조합을 생성하는 함수
void dfs(int num, string expr) {
    if (num == n) { // 수식이 끝나면 계산 후 출력
        if (evaluate(expr)) cout << expr << "\n";
        return;
    }

    // 숫자 추가, 덧셈, 뺄셈 세 가지 경우를 DFS로 탐색
    dfs(num + 1, expr + " " + to_string(num + 1));
    dfs(num + 1, expr + "+" + to_string(num + 1));
    dfs(num + 1, expr + "-" + to_string(num + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t; // 테스트 케이스 수 입력

    while (t--) {
        cin >> n; // n 값 입력
        dfs(1, "1"); // 첫 번째 숫자 1부터 시작
        cout << "\n";
    }

    return 0;
}
