#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    // 예외처리
    if(people.size() == 1) return 1;
    
    int answer = 0;
    
    sort(people.begin(), people.end());
    int s = 0, e = people.size() - 1;
    while(s <= e) {
        if(s == e) {
            answer++;
            break;
        }
        int sum = people[s] + people[e];
        if(sum > limit) {
            answer++;
            e--;
        }
        else {
            answer++;
            s++; e--;
        }
    }
    return answer;
}