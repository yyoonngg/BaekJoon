#include <bits/stdc++.h>
using namespace std;

int get_clock_number(vector<int> nums) {
    int min_number = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int num = nums[i] * 1000 + nums[(i + 1) % 4] * 100 + nums[(i + 2) % 4] * 10 + nums[(i + 3) % 4];
        min_number = min(min_number, num);
    }
    return min_number;
}

int main() {
    vector<int> a(4);
    for (int i = 0; i < 4; i++) cin >> a[i];

    int min_clock_number = get_clock_number(a);

    set<int> clock_numbers;

    for (int i = 1111; i <= 9999; i++) {
        string s = to_string(i);
        if (s.find('0') != string::npos) continue; 

        vector<int> digits = {s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0'};
        clock_numbers.insert(get_clock_number(digits));
    }

    int rank = distance(clock_numbers.begin(), clock_numbers.find(min_clock_number)) + 1;
    cout << rank << "\n";

    return 0;
}
