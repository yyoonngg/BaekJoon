#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        string original = to_string(N);
        string reversed = original;
        reverse(reversed.begin(), reversed.end());
        
        int revNumber = stoi(reversed);
        
        int sum = N + revNumber;
        
        string sumStr = to_string(sum);
        if (isPalindrome(sumStr))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
    return 0;
}
