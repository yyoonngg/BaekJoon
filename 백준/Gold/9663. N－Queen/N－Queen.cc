#include <bits/stdc++.h>
using namespace std;
int n, ret;
vector<int> row;

bool is_promising(int x) {
    for(int i = 0; i < x; i++) {
        if(row[x] == row[i] || abs(row[x] - row[i]) == abs(x - i)) {
            return false;
        }
    }
    return true;
}

void n_queens(int x) {
    if(x == n) {
        ret++;
        return;
    }
    else {
        for(int i = 0; i < n; i++) {
            row[x] = i;
            if(is_promising(x)) {
                n_queens(x + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    row.resize(n);
    n_queens(0);
    cout << ret << "\n";
    return 0;
}