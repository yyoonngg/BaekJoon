#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
struct Row {
    int totalSum, prefixMax, suffixMax, maxArr;
    bool operator<(const Row& other) const {
        return tie(totalSum, prefixMax, suffixMax, maxArr) <
               tie(other.totalSum, other.prefixMax, other.suffixMax, other.maxArr);
    }
};
vector<vector<int>> sub;
vector<Row> rows;

Row go(const vector<int> & seq) {
    int total = 0;
    int prefix = INT_MIN, suffix = INT_MIN, max_sub = INT_MIN;
    int temp = 0;

    int current = 0;
    for(int x : seq) {
        total += x;
        current = max(x, current + x);
        max_sub = max(max_sub, current);
    }

    current = 0;
    for(int x : seq) {
        current += x;
        prefix = max(prefix, current);
    }

    current = 0;
    for(int i = seq.size() - 1; i >= 0; i--) {
        current += seq[i];
        suffix = max(suffix, current);
    }

    return {total, max(0, prefix), max(0, suffix), max(0, max_sub)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    sub.resize(n);
    for(int i = 0; i < n; i++) {
        sub[i].resize(m);
        for(int j = 0; j < m; j++) {
            cin >> sub[i][j];
        }
    }
    rows.resize(n);
    for(int i = 0; i < n; i++) {
        rows[i] = go(sub[i]);
    }

    sort(rows.begin(), rows.end());

    do {
        int suffix = 0, max_sum = 0;
        for(int i = 0; i < n; i++) {
            Row row = rows[i];
            max_sum = max({max_sum, row.maxArr, suffix + row.prefixMax});
            suffix = max(row.suffixMax, suffix + row.totalSum);
        }
        ret = max(ret, max_sum);
    } while(next_permutation(rows.begin(), rows.end()));

    cout << ret << "\n";

    return 0;
}