#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int K, N;
    cin >> K >> N;
    
    long long cable;
    long long maxCable = 0;
    long long cables[10000]; 

    for (int i = 0; i < K; i++) {
        cin >> cable;
        cables[i] = cable;
        if (cable > maxCable)
            maxCable = cable;
    }
    
    long long low = 1, high = maxCable;
    long long result = 0;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;
        for (int i = 0; i < K; i++) {
            count += cables[i] / mid;
        }
        
        if (count >= N) {
            result = mid;
            low = mid + 1;
        } else { 
            high = mid - 1;
        }
    }
    
    cout << result << "\n";
    return 0;
}