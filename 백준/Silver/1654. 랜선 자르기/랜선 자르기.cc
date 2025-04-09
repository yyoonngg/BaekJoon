#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;
    
    long long cable;
    long long maxCable = 0;
    long long cables[10000]; // K의 최대 개수인 10,000에 맞게 배열 선언

    for (int i = 0; i < K; i++) {
        cin >> cable;
        cables[i] = cable;
        if (cable > maxCable)
            maxCable = cable;
    }
    
    // 이진 탐색을 위한 경계 설정
    long long low = 1, high = maxCable;
    long long result = 0;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;
        // 각 랜선을 mid 길이로 잘라 몇 개의 랜선을 만들 수 있는지 계산
        for (int i = 0; i < K; i++) {
            count += cables[i] / mid;
        }
        
        // 필요한 랜선 개수를 만들 수 있다면, 길이를 늘려본다.
        if (count >= N) {
            result = mid;
            low = mid + 1;
        } else { // 필요한 랜선 개수를 만들 수 없다면, 길이를 줄인다.
            high = mid - 1;
        }
    }
    
    cout << result << "\n";
    return 0;
}
