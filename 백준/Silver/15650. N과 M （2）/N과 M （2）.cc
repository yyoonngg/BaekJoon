#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> sequence;

void backtrack(int start) {
    if (sequence.size() == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = start; i <= N; i++) {
        sequence.push_back(i);
        backtrack(i + 1);
        sequence.pop_back();
    }
}

int main() {
    cin >> N >> M;
    backtrack(1);
    return 0;
}