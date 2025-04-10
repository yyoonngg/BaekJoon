#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    string result = "";

    while (N > 0) {
        int remainder = N % B;

        if (remainder < 10)
            result += (char)(remainder + '0');
        else
            result += (char)(remainder - 10 + 'A');

        N /= B;
    }

    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}