#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string expr;
    cin >> expr;

    vector<double> values(n);  // 각 피연산자 값 저장

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    stack<double> s;

    for (char ch : expr) {
        if (ch >= 'A' && ch <= 'Z') {
            // 피연산자라면 values에서 가져와 push
            s.push(values[ch - 'A']);
        } else {
            // 연산자라면 두 개 pop
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();

            if (ch == '+') {
                s.push(a + b);
            } else if (ch == '-') {
                s.push(a - b);
            } else if (ch == '*') {
                s.push(a * b);
            } else if (ch == '/') {
                s.push(a / b);
            }
        }
    }

    // 결과 출력: 소숫점 둘째자리까지
    cout << fixed << setprecision(2) << s.top() << endl;

    return 0;
}
