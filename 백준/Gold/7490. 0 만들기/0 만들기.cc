#include <bits/stdc++.h>
using namespace std;
int t, n;

bool check(vector<int> &numList, vector<char> &operList) {
    vector<int> numTemp;
    vector<int> operTemp;
    int sum = 0;

    numTemp.push_back(numList[0]);
    for(int i = 0; i < operList.size(); i++) {
        if(operList[i] == ' ') {
            int tmp = numTemp[numTemp.size() - 1];
            numTemp.pop_back();
            numTemp.push_back(tmp*10 + numList[i + 1]);
        }
        else {
            operTemp.push_back(operList[i]);
            numTemp.push_back(numList[i + 1]);
        }
    }

    sum += numTemp[0];
    for(int i = 0; i < operTemp.size(); i++) {
        if(operTemp[i] == '+') sum += numTemp[i + 1];
        else if(operTemp[i] == '-') sum -= numTemp[i + 1];
    }
    return sum == 0 ? true : false;
}

void print(vector<int> &numList, vector<char> &operList) {
    for(int i = 0; i < numList.size() - 1; i++) {
        cout << numList[i] << operList[i];
    }
    cout << numList[numList.size() - 1] << "\n";
    return;
}

void dfs(int cnt, vector<int> &numList, vector<char> &operList) {
    if(cnt == n - 1) {
        numList.push_back(n);
        if(check(numList, operList)) {
            print(numList, operList);
        }
        numList.pop_back();
        return;
    }
    numList.push_back(cnt + 1);

    operList.push_back(' ');
    dfs(cnt + 1, numList, operList);
    operList.pop_back();
    operList.push_back('+');
    dfs(cnt + 1, numList, operList);
    operList.pop_back();
    operList.push_back('-');
    dfs(cnt + 1, numList, operList);
    operList.pop_back();

    numList.pop_back();
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> numList;
        vector<char> operList;
        dfs(0, numList, operList);
        cout << "\n";
    }
    return 0;
}