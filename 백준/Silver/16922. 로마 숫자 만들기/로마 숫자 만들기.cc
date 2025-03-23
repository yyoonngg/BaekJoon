#include <bits/stdc++.h>
using namespace std;

int N;
set<int> _set;
vector<int> v = {1, 5, 10, 50};

void go(int d, int sum, int s) {
    if (d == N) {
        _set.insert(sum);
        return;
    }

    for (int i = s; i < 4; i++) {
        go(d + 1, sum + v[i], i);
    }
}

int main() {
    cin >> N;
    go(0, 0, 0);
    cout << _set.size() << "\n";
    return 0;
}
